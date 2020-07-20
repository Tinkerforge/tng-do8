/* tng-do8
 * Copyright (C) 2019 Olaf Lüke <olaf@tinkerforge.com>
 *
 * do8.c: Driver for 8 digital outputs
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

#include "do8.h"

#include "configs/config_do8.h"
#include "bricklib2/os/coop_task.h"
#include "bricklib2/logging/logging.h"

DO8 do8;
CoopTask do8_task;

void do8_task_tick(void) {
	while(true) {
		coop_task_sleep_ms(1);
	}
}

void do8_init(void) {
	memset(&do8, 0, sizeof(DO8));

	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();

	// USB Reset
	GPIO_InitTypeDef gpio_out = {
		.Mode  = GPIO_MODE_OUTPUT_PP,
		.Speed = GPIO_SPEED_FREQ_LOW
	};

	gpio_out.Pin = GPIO_PIN_8;
	HAL_GPIO_Init(GPIOA, &gpio_out);

	gpio_out.Pin = GPIO_PIN_9;
	HAL_GPIO_Init(GPIOA, &gpio_out);

	gpio_out.Pin = GPIO_PIN_10;
	HAL_GPIO_Init(GPIOA, &gpio_out);
}

void do8_tick(void) {
	static uint32_t last_time = 0;
	static uint32_t led_counter = 0;

	if(system_timer_is_time_elapsed_ms(last_time, 500)) {
		last_time = system_timer_get_ms();
		switch(led_counter % 3) {
			case 0: {
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,  GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9,  GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
				break;
			}

			case 1: {
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,  GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9,  GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
				break;
			}

			case 2: {
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,  GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9,  GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
				break;
			}
		}

		led_counter++;
	}
//	coop_task_tick(&do8_task);
}
