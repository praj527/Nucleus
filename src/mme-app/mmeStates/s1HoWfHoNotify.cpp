  
/*
 * Copyright 2019-present Infosys Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 */
 
/**************************************
 * s1HoWfHoNotify.cpp
 * This is an auto generated file.
 * Please do not edit this file.
 * All edits to be made through template source file
 * <TOP-DIR/scripts/SMCodeGen/templates/stateMachineTmpls/state.cpp.tt>
 **************************************/

#include "mmeSmDefs.h"
#include "actionTable.h"
#include "actionHandlers/actionHandlers.h"

#include "mmeStates/s1HoWfHoNotify.h"	
#include "mmeStates/s1HoWfModifyBearerResponse.h"	
#include "mmeStates/s1HoWfHoNotify.h"

using namespace mme;
using namespace SM;

/******************************************************************************
* Constructor
******************************************************************************/
S1HoWfHoNotify::S1HoWfHoNotify():State(s1_ho_wf_ho_notify)
{
}

/******************************************************************************
* Destructor
******************************************************************************/
S1HoWfHoNotify::~S1HoWfHoNotify()
{
}

/******************************************************************************
* creates and returns static instance
******************************************************************************/
S1HoWfHoNotify* S1HoWfHoNotify::Instance()
{
        static S1HoWfHoNotify state;
        return &state;
}

/******************************************************************************
* initializes eventToActionsMap
******************************************************************************/
void S1HoWfHoNotify::initialize()
{
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::process_ho_notify);
                actionTable.addAction(&ActionHandlers::send_mb_req_to_sgw_for_ho);
                actionTable.setNextState(S1HoWfModifyBearerResponse::Instance());
                eventToActionsMap.insert(pair<uint16_t, ActionTable>(HO_NOTIFY_FROM_ENB, actionTable));
        }
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::send_mme_status_tranfer_to_target_enb);
                actionTable.setNextState(S1HoWfHoNotify::Instance());
                eventToActionsMap.insert(pair<uint16_t, ActionTable>(ENB_STATUS_TRANFER_FROM_SRC_ENB, actionTable));
        }
}