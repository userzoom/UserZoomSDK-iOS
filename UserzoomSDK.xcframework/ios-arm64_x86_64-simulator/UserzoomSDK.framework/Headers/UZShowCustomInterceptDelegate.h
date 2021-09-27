//
//  Filename: UZShowCustomInterceptDelegate.h
//  Project:  sdk
//  Company:  UserZoom Technologies SL
//  Author:   UserZoom R&D
//  Date:     01/11/16
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
//  Summary:
//  =======
//
//  Delegate to be notified when intercept must be shown
//

#ifndef UZShowCustomInterceptDelegate_h
#define UZShowCustomInterceptDelegate_h

#import "UZInterceptProtocol.h"

@protocol UZShowCustomInterceptDelegate <NSObject>

- (void) showCustomIntercept: (id<UZInterceptProtocol> _Nullable) delegate;

@end

#endif /* UZShowCustomInterceptDelegate_h */
