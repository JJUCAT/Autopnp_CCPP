/*
 * Copyright (c) 2011-2014, fortiss GmbH.
 * Licensed under the Apache License, Version 2.0.
 *
 * Use, modification and distribution are subject to the terms specified
 * in the accompanying license file LICENSE.txt located at the root directory
 * of this software distribution. A copy is available at
 * http://chromosome.fortiss.org/.
 *
 * This file is part of CHROMOSOME.
 *
 * $Id: plugAndPlayManagerGenerateRuntimeGraphsFunctionWrapper.c 7631 2014-02-28 13:27:17Z wiesmueller $
 */

/**
 * \file
 *         Function wrapper - a generic abstraction for one executable function
 *              scheduled by the execution manager.
 *
 * \author
 *         This file has been generated by the CHROMOSOME Modeling Tool (XMT)
 *         (fortiss GmbH).
 */

/******************************************************************************/
/***   Includes                                                             ***/
/******************************************************************************/
#include "xme/core/plugAndPlay/include-gen/plugAndPlayManagerGenerateRuntimeGraphsFunctionWrapper.h"

#include "xme/core/plugAndPlay/include-gen/plugAndPlayManagerComponentWrapper.h"
#include "xme/core/plugAndPlay/include-gen/plugAndPlayManagerGenerateRuntimeGraphsFunction.h"

#include "xme/core/executionManager/include/executionManagerWrapperInterface.h"

/******************************************************************************/
/***   Implementation                                                       ***/
/******************************************************************************/
void
xme_core_pnp_pnpManagerGenerateRuntimeGraphsFunctionWrapper_execute
(
    void* userFunctionDescRaw
)
{
    xme_status_t status;
    xme_core_exec_functionDescriptor_t* funDesc;
    void* functionParameter;

    funDesc = (xme_core_exec_functionDescriptor_t*)userFunctionDescRaw;
    functionParameter = NULL;

    status = xme_core_exec_dispatcher_initializeTask
    (
        funDesc->componentId,
        funDesc->functionId
    );
    XME_CHECK_MSG_REC
    (
        XME_STATUS_SUCCESS == status,
        XME_CHECK_RVAL_VOID,
        {
            funDesc->state = XME_CORE_EXEC_FUNCTION_STATE_INVALID_STATE;
        },
        XME_LOG_FATAL,
        "Dispatcher [%d|%d] initialization returned an error code %d\n",
        funDesc->componentId,
        funDesc->functionId,
        status
    );

    if (NULL != funDesc->init)
    {
        status = funDesc->init(funDesc->taskArgs);
        XME_CHECK_MSG_REC
        (
            XME_STATUS_SUCCESS == status,
            XME_CHECK_RVAL_VOID,
            {
                funDesc->state = XME_CORE_EXEC_FUNCTION_STATE_INVALID_STATE;
            },
            XME_LOG_FATAL,
            "Function [%d|%d] initialization returned an error code %d\n",
            funDesc->componentId,
            funDesc->functionId,
            status
        );
    }

    while (XME_CORE_EXEC_FUNCTION_STATE_TERMINATED != funDesc->state)
    {
        status = xme_core_exec_dispatcher_waitForStart
        (
            funDesc->componentId,
            funDesc->functionId,
            &functionParameter
        );
        if (XME_STATUS_SUCCESS != status)
        {
            XME_LOG
            (
                XME_LOG_FATAL,
                "Dispatcher_waitForStart failed for function [%d|%d] returned an error code %d\n",
                funDesc->componentId,
                funDesc->functionId,
                status
            );
            funDesc->state = XME_CORE_EXEC_FUNCTION_STATE_INVALID_STATE;
            break;
        }

        if
        (
            (XME_CORE_EXEC_FUNCTION_STATE_PAUSED != funDesc->state) && 
            (XME_CORE_EXEC_FUNCTION_STATE_TERMINATED != funDesc->state)
        )
        {
            xme_core_pnp_pnpManagerGenerateRuntimeGraphsFunction_step((xme_core_pnp_pnpManagerComponent_config_t* const) functionParameter);
            xme_core_pnp_pnpManagerComponentWrapper_completeReadOperations();
            xme_core_pnp_pnpManagerComponentWrapper_completeWriteOperations();
        }

        status = xme_core_exec_dispatcher_executionCompleted
        (
            funDesc->componentId,
            funDesc->functionId
        );
        if (XME_STATUS_SUCCESS != status)
        {
            XME_LOG
            (
                XME_LOG_FATAL,
                "Dispatcher_executionCompleted failed for function [%d|%d] returned an error code %d\n",
                funDesc->componentId,
                funDesc->functionId,
                status
            );
            funDesc->state = XME_CORE_EXEC_FUNCTION_STATE_INVALID_STATE;
            break;
        }
    }
    
    if (NULL != funDesc->fini)
    {
        funDesc->fini(funDesc->taskArgs);
    }
}
