/*
 * Copyright 2019-present Open Networking Foundation
 * Copyright (c) 2003-2018, Great Software Laboratory Pvt. Ltd.
 * Copyright (c) 2017 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#include "err_codes.h"
#include "options.h"
#include "ipc_api.h"
#include "s11.h"
#include "s11_config.h"
#include "msgType.h"

#include <gtpV2StackWrappers.h>
/*Globals and externs*/
extern int g_resp_fd;

/*End : globals and externs*/

int
s11_DS_resp_handler(MsgBuffer* message, GtpV2MessageHeader* hdr)
{


	struct gtp_incoming_msg_data_t dsr_info;
	dsr_info.msg_type = delete_session_response;

	/*****Message structure****/
	log_msg(LOG_INFO, "Parse S11 DS resp message\n");

	//TODO : check cause for the result verification

	/*Check whether has teid flag is set.
	 * Also check whether this check is needed for DSR.
	 * */
	dsr_info.ue_idx = hdr->teid;	

	dsr_info.destInstAddr = htonl(mmeAppInstanceNum_c);
	dsr_info.srcInstAddr = htonl(s11AppInstanceNum_c);

	/*Send CS response msg*/
	send_tipc_message(g_resp_fd, mmeAppInstanceNum_c, (char *)&dsr_info,
			GTP_READ_MSG_BUF_SIZE);
	log_msg(LOG_INFO, "Send DS resp to mme-app stage8.\n");

	return SUCCESS;
}
