/* tng-do8
 * Copyright (C) 2019-2020 Olaf Lüke <olaf@tinkerforge.com>
 *
 * iso8200.h: Driver for 8 digital outputs
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

#ifndef ISO8200_H
#define ISO8200_H

#include "configs/config.h"

#define ISO8200_CHANNEL_NUM 8

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t value;
    uint8_t fault;

    SPI_HandleTypeDef spi;
} ISO8200;

extern ISO8200 iso8200;

void iso8200_tick(void);
void iso8200_init(void);

#endif
