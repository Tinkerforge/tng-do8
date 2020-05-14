/* tng-do8
 * Copyright (C) 2019 Olaf Lüke <olaf@tinkerforge.com>
 *
 * communication.c: TFP protocol message handling
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

#include "communication.h"

#include "bricklib2/utility/communication_callback.h"
#include "bricklib2/protocols/tfp/tfp.h"

TNGHandleMessageResponse handle_message(const void *message, void *response) {
	switch(tfp_get_fid_from_message(message)) {
		case FID_SET_VALUE: return set_value(message);
		case FID_GET_VALUE: return get_value(message, response);
		case FID_SET_SELECTED_VALUE: return set_selected_value(message);
		case FID_GET_SELECTED_VALUE: return get_selected_value(message, response);
		case FID_SET_QUEUE_VALUE: return set_queue_value(message, response);
		default: return HANDLE_MESSAGE_RESPONSE_NOT_SUPPORTED;
	}
}


TNGHandleMessageResponse set_value(const SetValue *data) {

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

TNGHandleMessageResponse get_value(const GetValue *data, GetValue_Response *response) {
	response->header.length = sizeof(GetValue_Response);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

TNGHandleMessageResponse set_selected_value(const SetSelectedValue *data) {

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

TNGHandleMessageResponse get_selected_value(const GetSelectedValue *data, GetSelectedValue_Response *response) {
	response->header.length = sizeof(GetSelectedValue_Response);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

TNGHandleMessageResponse set_queue_value(const SetQueueValue *data, SetQueueValue_Response *response) {
	response->header.length = sizeof(SetQueueValue_Response);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}





void communication_tick(void) {
//	communication_callback_tick();
}

void communication_init(void) {
//	communication_callback_init();
}
