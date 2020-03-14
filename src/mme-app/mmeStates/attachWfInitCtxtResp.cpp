  
/*
 * Copyright 2019-present Infosys Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 */
 
/**************************************
 * attachWfInitCtxtResp.cpp
 * This is an auto generated file.
 * Please do not edit this file.
 * All edits to be made through template source file
 * <TOP-DIR/scripts/SMCodeGen/templates/stateMachineTmpls/state.cpp.tt>
 **************************************/

#include "smEnumTypes.h"
#include "actionTable.h"
#include "actionHandlers/actionHandlers.h"

#include "mmeStates/attachWfInitCtxtResp.h"	
#include "mmeStates/attachWfMbResp.h"

using namespace mme;
using namespace SM;

/******************************************************************************
* Constructor
******************************************************************************/
AttachWfInitCtxtResp::AttachWfInitCtxtResp():State(State_e::attach_wf_init_ctxt_resp)
{
}

/******************************************************************************
* Destructor
******************************************************************************/
AttachWfInitCtxtResp::~AttachWfInitCtxtResp()
{
}

/******************************************************************************
* creates and returns static instance
******************************************************************************/
AttachWfInitCtxtResp* AttachWfInitCtxtResp::Instance()
{
        static AttachWfInitCtxtResp state;
        return &state;
}

/******************************************************************************
* initializes eventToActionsMap
******************************************************************************/
void AttachWfInitCtxtResp::initialize()
{
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::process_init_ctxt_resp);
                actionTable.addAction(&ActionHandlers::send_mb_req_to_sgw);
                actionTable.setNextState(AttachWfMbResp::Instance());
                eventToActionsMap.insert(pair<Event_e, ActionTable>(Event_e::INIT_CTXT_RESP_FROM_UE, actionTable));
        }
}