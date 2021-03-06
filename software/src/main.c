/* tng-do8
 * Copyright (C) 2019 Olaf Lüke <olaf@tinkerforge.com>
 *
 * main.c: Initialization for TNG DO8
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

#include "configs/config.h"
#include "configs/config_iso8200.h"

#include "bricklib2/tng/tng.h"
#include "bricklib2/logging/logging.h"

#include "do8.h"
#include "iso8200.h"

int main(void) {
	logging_init();
	logd("Start TNG DO8\n\r");

//	do8_init();
	iso8200_init();

	while(true) {
		tng_tick();
		iso8200_tick();
//		do8_tick();
	}
}
