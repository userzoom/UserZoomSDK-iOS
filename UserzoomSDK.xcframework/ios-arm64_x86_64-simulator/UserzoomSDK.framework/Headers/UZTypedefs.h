//
//  Filename: UZTypedefs.h
//  Project:  sdk
//  Company:  UserZoom Technologies SL
//  Copyright:
//
//  Proprietary and confidential
//
//  NOTICE: All information contained herein is, and remains the property
//  of UserZoom Technologies SL. The intellectual and technical concepts
//  contained herein are proprietary to UserZoom Technologies SL and
//  may be covered by U.S. and Foreign Patents, patents in process, and are
//  protected by trade secret or copyright law. Dissemination of this
//  information or reproduction of this material is strictly forbidden unless
//  prior written permission is obtained from UserZoom Technologies SL.
//


#ifndef sdk_UZTypedefs_h
#define sdk_UZTypedefs_h

#import <Foundation/Foundation.h>

/**
 *  Typedef used to identify the LOG_LEVEL of the SDK.
 */
typedef enum
{
    UZLogSilent      = 1000,
    UZLogError       = 50,
    UZLogWarning     = 40,
    UZLogInfo        = 30,
    UZLogVerbose     = 20,
    UZLogDeveloper   = 10
} UZLogLevel;

/**
 *  Typedef used to defined types of screen edge.
 */
typedef enum {
    UZScreenEdgeTop,
    UZScreenEdgeLeft,
    UZScreenEdgeBottom,
    UZScreenEdgeRight
} UZScreenEdge;

#endif
