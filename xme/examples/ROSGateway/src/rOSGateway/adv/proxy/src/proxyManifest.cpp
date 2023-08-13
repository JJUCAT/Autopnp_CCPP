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
 * $Id: proxyManifest.cpp 7769 2014-03-11 15:27:13Z geisinger $
 */

/**
 * \file
 *         Defines function for creation of component type manifest
 *         for 'proxy'.
 *
 * \author
 *         This file has been generated by the CHROMOSOME Modeling Tool (XMT)
 *         (fortiss GmbH).
 */

/******************************************************************************/
/***   Includes                                                             ***/
/******************************************************************************/
#include "rOSGateway/adv/proxy/include/proxyManifest.h"

#include "../include/proxyComponentWrapper.h"
#include "rOSGateway/adv/proxy/include/askSumFunction.h"
#include "rOSGateway/adv/proxy/include/askSumFunctionWrapper.h"
#include "rOSGateway/adv/proxy/include/getDifferenceFunction.h"
#include "rOSGateway/adv/proxy/include/getDifferenceFunctionWrapper.h"
#include "rOSGateway/adv/proxy/include/proxyComponent.h"
#include "rOSGateway/adv/proxy/include/receiveMessageFunction.h"
#include "rOSGateway/adv/proxy/include/receiveMessageFunctionWrapper.h"
#include "rOSGateway/adv/proxy/include/receiveSumFunction.h"
#include "rOSGateway/adv/proxy/include/receiveSumFunctionWrapper.h"
#include "rOSGateway/topic/dictionary.h"
#include "xme/core/log.h"
#include "xme/hal/include/time.h"

/******************************************************************************/
/***   Implementation                                                       ***/
/******************************************************************************/
xme_status_t
rOSGateway_adv_proxy_manifest_createComponentTypeManifest
(
    xme_core_componentManifest_t* componentManifest
)
{
    XME_CHECK
    (
        NULL != componentManifest,
        XME_STATUS_INVALID_PARAMETER
    );

    (void)xme_hal_mem_set(componentManifest, 0U, sizeof(xme_core_componentManifest_t));

    componentManifest->componentType = (xme_core_componentType_t)4097;
    componentManifest->componentWrapperInit = rOSGateway_adv_proxy_proxyComponentWrapper_init;
    componentManifest->componentWrapperReceivePort = rOSGateway_adv_proxy_proxyComponentWrapper_receivePort;
    componentManifest->componentWrapperFini = rOSGateway_adv_proxy_proxyComponentWrapper_fini;
    componentManifest->componentInit = (xme_core_componentManifest_componentInit_t)rOSGateway_adv_proxy_proxyComponent_init;
    (void)xme_hal_safeString_strncpy(componentManifest->name, "proxy", sizeof(componentManifest->name));
    componentManifest->configStructSize = sizeof(rOSGateway_adv_proxy_proxyComponent_config_t);

    {
        uint32_t functionArrayLength = sizeof(componentManifest->functionManifests) / sizeof(componentManifest->functionManifests[0]);

        // Function 'receiveMessage'
        {
            if (0U >= functionArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (0U == functionArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'proxy' defines more functions (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                       4,
                       functionArrayLength
                    );
                }
            }
            else
            {
                xme_core_functionManifest_t* functionManifest;
                
                functionManifest = &componentManifest->functionManifests[0];
                functionManifest->functionId = (xme_core_component_functionId_t)1;
                functionManifest->wcet = xme_hal_time_timeIntervalFromMilliseconds(1ull);
                functionManifest->alphaCurve.alphaCurve = 0;
                functionManifest->completion = true;
                functionManifest->requiredPortIndicesLength = 1;
                functionManifest->requiredPortIndices[0] = (rOSGateway_adv_proxy_proxyComponentWrapper_internalPortId_t)ROSGATEWAY_ADV_PROXY_PROXYCOMPONENTWRAPPER_PORT_MESSAGE;
                functionManifest->optionalPortIndicesLength = 0;
                functionManifest->functionInit = (xme_core_exec_initCallback_t)rOSGateway_adv_proxy_receiveMessageFunction_init;
                functionManifest->functionFini = (xme_core_exec_finiCallback_t)rOSGateway_adv_proxy_receiveMessageFunction_fini;
                functionManifest->functionWrapperExecute = rOSGateway_adv_proxy_receiveMessageFunctionWrapper_execute;
            }
        }
        // Function 'askSum'
        {
            if (1U >= functionArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (1U == functionArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'proxy' defines more functions (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                       4,
                       functionArrayLength
                    );
                }
            }
            else
            {
                xme_core_functionManifest_t* functionManifest;
                
                functionManifest = &componentManifest->functionManifests[1];
                functionManifest->functionId = (xme_core_component_functionId_t)2;
                functionManifest->wcet = xme_hal_time_timeIntervalFromMilliseconds(1ull);
                functionManifest->alphaCurve.alphaCurve = 0;
                functionManifest->completion = true;
                functionManifest->requiredPortIndicesLength = 1;
                functionManifest->requiredPortIndices[0] = (rOSGateway_adv_proxy_proxyComponentWrapper_internalPortId_t)ROSGATEWAY_ADV_PROXY_PROXYCOMPONENTWRAPPER_PORT_GETSUM;
                functionManifest->optionalPortIndicesLength = 0;
                functionManifest->functionInit = (xme_core_exec_initCallback_t)rOSGateway_adv_proxy_askSumFunction_init;
                functionManifest->functionFini = (xme_core_exec_finiCallback_t)rOSGateway_adv_proxy_askSumFunction_fini;
                functionManifest->functionWrapperExecute = rOSGateway_adv_proxy_askSumFunctionWrapper_execute;
            }
        }
        // Function 'receiveSum'
        {
            if (2U >= functionArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (2U == functionArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'proxy' defines more functions (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                       4,
                       functionArrayLength
                    );
                }
            }
            else
            {
                xme_core_functionManifest_t* functionManifest;
                
                functionManifest = &componentManifest->functionManifests[2];
                functionManifest->functionId = (xme_core_component_functionId_t)3;
                functionManifest->wcet = xme_hal_time_timeIntervalFromMilliseconds(1ull);
                functionManifest->alphaCurve.alphaCurve = 0;
                functionManifest->completion = true;
                functionManifest->requiredPortIndicesLength = 1;
                functionManifest->requiredPortIndices[0] = (rOSGateway_adv_proxy_proxyComponentWrapper_internalPortId_t)ROSGATEWAY_ADV_PROXY_PROXYCOMPONENTWRAPPER_PORT_RECEIVEDSUM;
                functionManifest->optionalPortIndicesLength = 0;
                functionManifest->functionInit = (xme_core_exec_initCallback_t)rOSGateway_adv_proxy_receiveSumFunction_init;
                functionManifest->functionFini = (xme_core_exec_finiCallback_t)rOSGateway_adv_proxy_receiveSumFunction_fini;
                functionManifest->functionWrapperExecute = rOSGateway_adv_proxy_receiveSumFunctionWrapper_execute;
            }
        }
        // Function 'getDifference'
        {
            if (3U >= functionArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (3U == functionArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'proxy' defines more functions (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                       4,
                       functionArrayLength
                    );
                }
            }
            else
            {
                xme_core_functionManifest_t* functionManifest;
                
                functionManifest = &componentManifest->functionManifests[3];
                functionManifest->functionId = (xme_core_component_functionId_t)4;
                functionManifest->wcet = xme_hal_time_timeIntervalFromMilliseconds(1ull);
                functionManifest->alphaCurve.alphaCurve = 0;
                functionManifest->completion = true;
                functionManifest->requiredPortIndicesLength = 1;
                functionManifest->requiredPortIndices[0] = (rOSGateway_adv_proxy_proxyComponentWrapper_internalPortId_t)ROSGATEWAY_ADV_PROXY_PROXYCOMPONENTWRAPPER_PORT_GETDIFFERENCE;
                functionManifest->optionalPortIndicesLength = 0;
                functionManifest->functionInit = (xme_core_exec_initCallback_t)rOSGateway_adv_proxy_getDifferenceFunction_init;
                functionManifest->functionFini = (xme_core_exec_finiCallback_t)rOSGateway_adv_proxy_getDifferenceFunction_fini;
                functionManifest->functionWrapperExecute = rOSGateway_adv_proxy_getDifferenceFunctionWrapper_execute;
            }
        }
    }

    {
        uint32_t portArrayLength;
        portArrayLength = sizeof(componentManifest->portManifests) / sizeof(componentManifest->portManifests[0]);

        // Subscription 'message'
        {
            if (0 >= portArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (0 == portArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'proxy' defines more ports (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                        6,
                        portArrayLength
                    );
                }
            }
            else
            {
                xme_core_componentPortManifest_t* portManifest;
            
                portManifest = &componentManifest->portManifests[0];
                portManifest->portType = XME_CORE_COMPONENT_PORTTYPE_DCC_SUBSCRIPTION;
                portManifest->topic = ROSGATEWAY_TOPIC_MESSAGE; 
                portManifest->lowerConnectionBound = 0u;
                portManifest->upperConnectionBound = XME_CORE_COMPONENT_CONNECTIONBOUND_UNBOUNDED;
                portManifest->queueSize = 1;
                portManifest->persistent = false;
        
                portManifest->attrSet = XME_CORE_ATTRIBUTE_EMPTY_ATTRIBUTE_SET;
            }
        }
        // Subscription 'receivedSum'
        {
            if (1 >= portArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (1 == portArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'proxy' defines more ports (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                        6,
                        portArrayLength
                    );
                }
            }
            else
            {
                xme_core_componentPortManifest_t* portManifest;
            
                portManifest = &componentManifest->portManifests[1];
                portManifest->portType = XME_CORE_COMPONENT_PORTTYPE_RR_RESPONSE_HANDLER;
                portManifest->topic = ROSGATEWAY_TOPIC_SUMRESPONSE; 
                portManifest->lowerConnectionBound = 0u;
                portManifest->upperConnectionBound = XME_CORE_COMPONENT_CONNECTIONBOUND_UNBOUNDED;
                portManifest->queueSize = 1;
                portManifest->persistent = false;
        
                portManifest->attrSet = XME_CORE_ATTRIBUTE_EMPTY_ATTRIBUTE_SET;
            }
        }
        // Subscription 'getDifference'
        {
            if (2 >= portArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (2 == portArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'proxy' defines more ports (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                        6,
                        portArrayLength
                    );
                }
            }
            else
            {
                xme_core_componentPortManifest_t* portManifest;
            
                portManifest = &componentManifest->portManifests[2];
                portManifest->portType = XME_CORE_COMPONENT_PORTTYPE_RR_REQUEST_HANDLER;
                portManifest->topic = ROSGATEWAY_TOPIC_DIFFERENCEREQUEST; 
                portManifest->lowerConnectionBound = 0u;
                portManifest->upperConnectionBound = XME_CORE_COMPONENT_CONNECTIONBOUND_UNBOUNDED;
                portManifest->queueSize = 1;
                portManifest->persistent = false;
        
                portManifest->attrSet = XME_CORE_ATTRIBUTE_EMPTY_ATTRIBUTE_SET;
            }
        }
        // Publication 'receivedMessage'
        {
            if (3 >= portArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (3 == portArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'proxy' defines more ports (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                        6,
                        portArrayLength
                    );
                }
            }
            else
            {
                xme_core_componentPortManifest_t* portManifest;
            
                portManifest = &componentManifest->portManifests[3];
                portManifest->portType = XME_CORE_COMPONENT_PORTTYPE_DCC_PUBLICATION;
                portManifest->topic = ROSGATEWAY_TOPIC_STATUS; 
                portManifest->lowerConnectionBound = XME_CORE_COMPONENT_CONNECTIONBOUND_INVALID;
                portManifest->upperConnectionBound = XME_CORE_COMPONENT_CONNECTIONBOUND_INVALID;
                portManifest->queueSize = 1;
                portManifest->persistent = false;
        
                portManifest->attrSet = XME_CORE_ATTRIBUTE_EMPTY_ATTRIBUTE_SET;
                
            }
        }
        // Publication 'getSum'
        {
            if (4 >= portArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (4 == portArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'proxy' defines more ports (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                        6,
                        portArrayLength
                    );
                }
            }
            else
            {
                xme_core_componentPortManifest_t* portManifest;
            
                portManifest = &componentManifest->portManifests[4];
                portManifest->portType = XME_CORE_COMPONENT_PORTTYPE_RR_REQUEST_SENDER;
                portManifest->topic = ROSGATEWAY_TOPIC_SUMREQUEST; 
                portManifest->lowerConnectionBound = 0u;
                portManifest->upperConnectionBound = XME_CORE_COMPONENT_CONNECTIONBOUND_UNBOUNDED;
                portManifest->queueSize = 1;
                portManifest->persistent = false;
        
                portManifest->attrSet = XME_CORE_ATTRIBUTE_EMPTY_ATTRIBUTE_SET;
                
            }
        }
        // Publication 'sendDifference'
        {
            if (5 >= portArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (5 == portArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'proxy' defines more ports (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                        6,
                        portArrayLength
                    );
                }
            }
            else
            {
                xme_core_componentPortManifest_t* portManifest;
            
                portManifest = &componentManifest->portManifests[5];
                portManifest->portType = XME_CORE_COMPONENT_PORTTYPE_RR_RESPONSE_SENDER;
                portManifest->topic = ROSGATEWAY_TOPIC_DIFFERENCERESPONSE; 
                portManifest->lowerConnectionBound = XME_CORE_COMPONENT_CONNECTIONBOUND_INVALID;
                portManifest->upperConnectionBound = XME_CORE_COMPONENT_CONNECTIONBOUND_INVALID;
                portManifest->queueSize = 1;
                portManifest->persistent = false;
        
                portManifest->attrSet = XME_CORE_ATTRIBUTE_EMPTY_ATTRIBUTE_SET;
                
            }
        }
    }
    return XME_STATUS_SUCCESS;
}
