/* tng-do8
 * Copyright (C) 2019-2020 Olaf Lüke <olaf@tinkerforge.com>
 *
 * iso8200.c: Driver for 8 digital outputs
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include "iso8200.h"

#include "configs/config_iso8200.h"
#include "bricklib2/os/coop_task.h"
#include "bricklib2/logging/logging.h"
#include "bricklib2/tng/tng_led.h"

ISO8200 iso8200;
CoopTask iso8200_task;

void iso8200_task_tick(void) {
	while(true) {
		coop_task_sleep_ms(1);
	}
}

// Sets output channel, returns fault condition
uint8_t iso8200_set_output(const uint8_t output) {
	uint8_t tx = output;
	uint8_t rx = 0;

	HAL_GPIO_WritePin(ISO8200_SPI_CS_PORT, ISO8200_SPI_CS_PIN, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&iso8200.spi, &tx, &rx, 1, ISO8200_SPI_TIMEOUT);
	HAL_GPIO_WritePin(ISO8200_SPI_CS_PORT, ISO8200_SPI_CS_PIN, GPIO_PIN_SET);

	return rx;
}

void iso8200_init_spi(void) {
	// Enable clocks
	__HAL_RCC_SPI1_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	// Configure CLK
	GPIO_InitTypeDef gpio_clk = {
		.Pin       = ISO8200_SPI_CLK_PIN,
		.Mode      = GPIO_MODE_AF_PP,
		.Pull      = GPIO_NOPULL,
		.Speed     = GPIO_SPEED_FREQ_HIGH,
		.Alternate = ISO8200_SPI_CLK_AF
	};
	HAL_GPIO_Init(ISO8200_SPI_CLK_PORT, &gpio_clk);

	// Configure MOSI
	GPIO_InitTypeDef gpio_mosi = {
		.Pin       = ISO8200_SPI_MOSI_PIN,
		.Mode      = GPIO_MODE_AF_PP,
		.Pull      = GPIO_NOPULL,
		.Speed     = GPIO_SPEED_FREQ_HIGH,
		.Alternate = ISO8200_SPI_MOSI_AF
	};
	HAL_GPIO_Init(ISO8200_SPI_MOSI_PORT, &gpio_mosi);

	// Configure MISO
	GPIO_InitTypeDef gpio_miso = {
		.Pin       = ISO8200_SPI_MISO_PIN,
		.Mode      = GPIO_MODE_AF_PP,
		.Pull      = GPIO_NOPULL,
		.Speed     = GPIO_SPEED_FREQ_HIGH,
		.Alternate = ISO8200_SPI_MISO_AF
	};
	HAL_GPIO_Init(ISO8200_SPI_MISO_PORT, &gpio_miso);

	// Configure CS
	GPIO_InitTypeDef gpio_cs = {
		.Pin       = ISO8200_SPI_CS_PIN,
		.Mode      = GPIO_MODE_OUTPUT_PP,
		.Pull      = GPIO_NOPULL,
		.Speed     = GPIO_SPEED_FREQ_HIGH,
	};
	HAL_GPIO_Init(ISO8200_SPI_CS_PORT, &gpio_cs);

	// Reset
	__HAL_RCC_SPI1_FORCE_RESET();
	__HAL_RCC_SPI1_RELEASE_RESET();

	iso8200.spi.Instance               = ISO8200_SPI_INSTANCE;
	iso8200.spi.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256;
	iso8200.spi.Init.Direction         = SPI_DIRECTION_2LINES;
	iso8200.spi.Init.CLKPhase          = SPI_PHASE_1EDGE;
	iso8200.spi.Init.CLKPolarity       = SPI_POLARITY_LOW;
	iso8200.spi.Init.CRCCalculation    = SPI_CRCCALCULATION_DISABLE;
	iso8200.spi.Init.CRCPolynomial     = 7;
	iso8200.spi.Init.DataSize          = SPI_DATASIZE_8BIT;
	iso8200.spi.Init.FirstBit          = SPI_FIRSTBIT_MSB;
	iso8200.spi.Init.NSS               = SPI_NSS_SOFT; 
	iso8200.spi.Init.NSSPMode          = SPI_NSS_PULSE_DISABLE;
	iso8200.spi.Init.TIMode            = SPI_TIMODE_DISABLE;
	iso8200.spi.Init.Mode              = SPI_MODE_MASTER;	
	HAL_SPI_Init(&iso8200.spi);
}

void iso8200_init(void) {
	memset(&iso8200, 0, sizeof(ISO8200));

	iso8200_init_spi();

	// Configure Output Enable
	GPIO_InitTypeDef gpio_out_en = {
		.Pin       = ISO8200_OUT_EN_PIN,
		.Mode      = GPIO_MODE_OUTPUT_PP,
		.Pull      = GPIO_NOPULL,
		.Speed     = GPIO_SPEED_FREQ_HIGH,
	};
	HAL_GPIO_Init(ISO8200_OUT_EN_PORT, &gpio_out_en);
	HAL_GPIO_WritePin(ISO8200_OUT_EN_PORT, ISO8200_OUT_EN_PIN, GPIO_PIN_SET);

	iso8200_set_output(0);
}

uint8_t test = 0;
void iso8200_tick(void) {
	iso8200.fault = iso8200_set_output(iso8200.value);
	if(iso8200.fault != 0) {
		logd("Fault: %b\n\r", iso8200.fault);
	}

	for(uint8_t i = 0; i < ISO8200_CHANNEL_NUM; i++) {
		tng_led_channel_set(i, iso8200.value & (1 << i));
	}

	if(iso8200.fault) {
		tng_led_status_set(255, 0, 0);
	} else {
		tng_led_status_set(0, 0, 0);
	}

//	coop_task_tick(&iso8200_task);
}
