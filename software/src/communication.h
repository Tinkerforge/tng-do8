/* tng-do8
 * Copyright (C) 2019 Olaf Lüke <olaf@tinkerforge.com>
 *
 * communication.h: TFP protocol message handling
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

#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <stdint.h>
#include <stdbool.h>

#include "bricklib2/protocols/tfp/tfp.h"
#include "bricklib2/tng/tng.h"

// Default functions
TNGHandleMessageResponse handle_message(const void *data, void *response);
void communication_tick(void);
void communication_init(void);

// Constants
#define DO8_COPY_STATUS_OK 0
#define DO8_COPY_STATUS_DEVICE_IDENTIFIER_INCORRECT 1
#define DO8_COPY_STATUS_MAGIC_NUMBER_INCORRECT 2
#define DO8_COPY_STATUS_LENGTH_MALFORMED 3
#define DO8_COPY_STATUS_CRC_MISMATCH 4

// Function and callback IDs and structs
#define FID_SET_VALUE 1
#define FID_GET_VALUE 2
#define FID_SET_SELECTED_VALUE 3
#define FID_GET_SELECTED_VALUE 4
#define FID_SET_QUEUE_VALUE 5


typedef struct {
	TFPMessageHeader header;
	uint8_t value[1];
} __attribute__((__packed__)) SetValue;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetValue;

typedef struct {
	TFPMessageHeader header;
	uint8_t value[1];
} __attribute__((__packed__)) GetValue_Response;

typedef struct {
	TFPMessageHeader header;
	uint8_t channel;
	bool value;
} __attribute__((__packed__)) SetSelectedValue;

typedef struct {
	TFPMessageHeader header;
	uint8_t channel;
} __attribute__((__packed__)) GetSelectedValue;

typedef struct {
	TFPMessageHeader header;
	bool value;
} __attribute__((__packed__)) GetSelectedValue_Response;

typedef struct {
	TFPMessageHeader header;
	uint64_t timestamp;
	uint8_t value[1];
	uint8_t mask[1];
} __attribute__((__packed__)) SetQueueValue;

typedef struct {
	TFPMessageHeader header;
	uint8_t queue_status;
} __attribute__((__packed__)) SetQueueValue_Response;


// Function prototypes
TNGHandleMessageResponse set_value(const SetValue *data);
TNGHandleMessageResponse get_value(const GetValue *data, GetValue_Response *response);
TNGHandleMessageResponse set_selected_value(const SetSelectedValue *data);
TNGHandleMessageResponse get_selected_value(const GetSelectedValue *data, GetSelectedValue_Response *response);
TNGHandleMessageResponse set_queue_value(const SetQueueValue *data, SetQueueValue_Response *response);

// Callbacks


#define COMMUNICATION_CALLBACK_TICK_WAIT_MS 1
#define COMMUNICATION_CALLBACK_HANDLER_NUM 0
#define COMMUNICATION_CALLBACK_LIST_INIT \


#endif
