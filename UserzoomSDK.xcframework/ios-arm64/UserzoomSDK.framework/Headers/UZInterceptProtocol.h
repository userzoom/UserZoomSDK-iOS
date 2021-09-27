//
//  Filename: UZInterceptProtocol.h
//  Project:  sdk
//  Company:  UserZoom Technologies SL
//  Author:   Froi
//  Date:     07/05/14
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
//  <# Summary of this class #>
//
		
//

#import <Foundation/Foundation.h>

@protocol UZInterceptProtocol <NSObject>
-(void) allowIntercept;
-(void) closeIntercept;

@end
