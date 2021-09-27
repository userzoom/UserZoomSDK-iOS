//
//  Filename: UserzoomSDK.h
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

#import <UIKit/UIKit.h>

#import <Foundation/Foundation.h>
#import <UserNotifications/UserNotifications.h>
#import "UZTypedefs.h"
#import "UZDelegate.h"
#import "UZShowCustomInterceptDelegate.h"

#import <Foundation/Foundation.h>

//! Project version number for sdk.
FOUNDATION_EXPORT double sdkVersionNumber;

//! Project version string for sdk.
FOUNDATION_EXPORT const unsigned char sdkVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <sdk/PublicHeader.h>



#define UZ_TAG @""

@interface UserzoomSDK : NSObject

/**
 *  Retrieve the current version of the UserZoom SDK
 *
 *  @return String containing a "x.y.z.y" format version
 */
+ (NSString * _Nonnull)currentVersion;

/**
 *  Initialize the UserzoomSDK with the given tag.
 *
 *  If the study is configured to be shown at 'Start APP', this method
 *  will also start the study.
 *
 *  Usage Example:
 *  didFinishLaunchingWithOptions -> [UserzoomSDK initWithTag:@"QzRUNjAg"];
 *
 *  @param tag of the study (ex. @"QzRUNjAg")
 */
+ (void)initWithTag:(NSString * _Nullable) tag;

/**
 *  Initialize the UserzoomSDK with the given tag, and the launch options
 *
 *  @param tag of the study (ex. @"QzRUNjAg")
 *  @param launchOptions
 */
+ (void)initWithTag:(NSString * _Nullable)tag options:(NSDictionary * _Nullable)launchOptions;

/**
 *  It processes the launchOptions of the AppDelegate, defines if the
 *  applications start from a notification and, if so, if the notification
 *  comes from UserZoom.
 *
 *  @param launchOptions
 *
 *  @return BOOL
 */
+ (BOOL)processLaunchOptions:(NSDictionary * _Nullable)launchOptions;

/**
 *  Tracks custom events.
 *
 *  Usage Example:
 *
 *  [UserzoomSDK sendEvent:@"TAG1" tag2:@"TAG2" tag3:@"TAG3"];
 *
 *  @param tag1 @"CustomEventParameter 1"
 *  @param tag2 @"CustomEventParameter 2"
 *  @param tag3 @"CustomEventParameter 3"
 */
+ (void)sendEvent:(NSString * _Nullable)tag1 tag2:(NSString * _Nullable)tag2 tag3:(NSString * _Nullable)tag3;

/**
 *  Send information of the search keywords
 *
 *  @param keywords Strings with the search
 */
+ (void)sendKeywords:(NSString * _Nullable) keywords;

/**
 *  Enables/disables view recording.
 *
 *  Usage Example:
 *  On viewDidAppear    -> [UserzoomSDK blockRecord:YES];
 *  On viewDidDisappear -> [UserzoomSDK blockRecord:NO];
 *
 *  @param value YES (disable recording) or NO (enable recording)
 */
+ (void)blockRecord:(BOOL)value;

/**
 *  Starts the study initialized with initWithTag:(NSString*) if it is configured
 *  to be shown as 'Customized'. If it is configured as 'Start APP', this method
 *  does nothing
 */
+ (void)show;

/**
 *  Starts a study with a different tags than the initialized one
 *
 *  @param tag of the new study to be started
 */
+ (void)show:(NSString * _Nullable)tag;

/**
 *  Finalizes the current study
 *
 *  Usage Example:
 *  On viewDidAppear    -> [UserzoomSDK finalizeStudy];
 */
+ (void)finalizeStudy;

/**
 *  Sets the Debug level of the SDK:
 *
 *  - SILENT: Does not LOG anything.
 *  - INFO: Logs basic information
 *  - WARNING: Logs basic information and some warnings
 *  - ERROR: Logs basic information, some warnings and errors. Errors are also sent to the server.
 *  - VERBOSE:  Logs everything. Errors are also sent to the server.
 *
 *  @warning Remember to set debug level to SILENT for release (is the default one)
 *
 *  @param level The desirev level
 */
+ (void)setDebugLevel:(UZLogLevel)level;

/**
 *  Starts study using an invitation
 *
 *  mimic the openURL:sourceApplication:annotation method of UIApplicationDelegate
 *  to execute the init of the study when the url is valid.
 *
 *  @param url               url from the appdelegate
 *
 *  @return true if the url is valid for start a userzoom study
 */
+ (BOOL)openURL:(NSURL * _Nullable)url;

/**
 * Clear UserZoom expiration data stored in the App.
 */
+ (void)clearExpirationData;

/**
 * Developer callbacks for the current state of the study
 */
+ (void)setDeveloperCallback:(id<UZDelegate> _Nullable)delegate;

/**
 * Activate the invitation exclusive mode, where the app will close unless the sdk is started from 
 * an invitation link
 */
+ (void)deactivateAppAfterStudy:(NSDictionary * _Nullable)launchOptions;

/**
 * Activate the invitation exclusive mode, where the app will close unless the sdk is started from 
 * an invitation link, specifying the alert's message and button text
 */
+ (void)deactivateAppAfterStudyWithMessage:(NSString * _Nullable)message andButtonText:(NSString * _Nullable)buttonText andOptions:(NSDictionary * _Nullable) launchOptions;

/**
 * Set the ShowInterceptDelegate to get notified when custom intercept needs to be displayed.
 */
+ (void)setShowCustomInterceptDelegate:(id<UZShowCustomInterceptDelegate> _Nullable)delegate;

/**
 *  Appends a single custom var with key/value pair
 */
+ (void)addCustomVarWithKey:(NSString * _Nullable)key andValue:(NSString * _Nullable)value;

/**
 *  Appends a bunch of custom vars inside the given dictionary
 */
+ (void)addCustomVars:(NSDictionary * _Nonnull)dictionary;

/**
 *  Obtains the custom vars
 *
 *  @return NSDictionary containing all custom vars input in the system
 */
+ (NSDictionary * _Nonnull)customVars;

/**
 *  Removes all key-values previously input as custom vars
 */
+ (void)clearCustomVars;


#pragma mark - UNUserNotification iOS 10.0+

/**
 *  Resumes the study flow after returning from a local notification (for iOS 10.0+)
 */
+ (void)didReceiveNotificationResponse:(UNNotificationResponse* _Nullable) notificationResponse;

/**
 *  Resumes the study flow after returning from a local notification (for iOS 10.0+)
 */
+ (void)didReceiveNotificationResponse:(UNNotificationResponse* _Nullable) notificationResponse withCompletionHandler:(nullable void(^)(void))completionHandler;

@end
