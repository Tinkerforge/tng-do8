/* tng-do8
 * Copyright (C) 2019 Olaf Lüke <olaf@tinkerforge.com>
 *
 * config_iso8200.h: Configuration for 8 digital outputs 
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

#ifndef CONFIG_ISO8200_H
#define CONFIG_ISO8200_H


#include "configs/config.h"

#define ISO8200_OUT_EN_PIN         GPIO_PIN_0
#define ISO8200_OUT_EN_PORT        GPIOB
#define ISO8200_NFAULT_PIN         GPIO_PIN_1
#define ISO8200_NFAULT_PORT        GPIOB
#define ISO8200_NPGOOD_PIN         GPIO_PIN_2
#define ISO8200_NPGOOD_PORT        GPIOB
#define ISO8200_PWR_GOOD_PIN       GPIO_PIN_8
#define ISO8200_PWR_GOOD_PORT      GPIOB

#define ISO8200_SPI_CS_PIN         GPIO_PIN_15
#define ISO8200_SPI_CS_PORT        GPIOA
#define ISO8200_SPI_CS_AF          GPIO_AF0_SPI1
#define ISO8200_SPI_CLK_PIN        GPIO_PIN_3
#define ISO8200_SPI_CLK_PORT       GPIOB
#define ISO8200_SPI_CLK_AF         GPIO_AF0_SPI1
#define ISO8200_SPI_MISO_PIN       GPIO_PIN_4
#define ISO8200_SPI_MISO_PORT      GPIOB
#define ISO8200_SPI_MISO_AF        GPIO_AF0_SPI1
#define ISO8200_SPI_MOSI_PIN       GPIO_PIN_5
#define ISO8200_SPI_MOSI_PORT      GPIOB
#define ISO8200_SPI_MOSI_AF        GPIO_AF0_SPI1
#define ISO8200_SPI_INSTANCE       SPI1
#define ISO8200_SPI_TIMEOUT        1000

#endif
