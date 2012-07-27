//
//  AppDelegate.h
//  candpiosapp
//
//  Created by David Mojdehi on 12/30/11.
//  Copyright (c) 2011 Coffee and Power Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Settings.h"
#import "UAirship.h"
#import "UAPush.h"
#import "SettingsMenuController.h"
#import "CPTabBarController.h"
#import <CoreLocation/CoreLocation.h>
#import "FlurryAnalytics.h"

@class AFHTTPClient;
@class SignupController;
@class User;

@interface AppDelegate : UIResponder <UIApplicationDelegate, UIAlertViewDelegate, CLLocationManagerDelegate>

@property (nonatomic, strong) UIWindow *window;
@property (nonatomic, strong, readonly) Settings *settings;
@property (nonatomic, strong, readonly) AFHTTPClient *urbanAirshipClient;
@property (nonatomic, strong, readonly) CLLocationManager *locationManager;
@property (nonatomic, strong) SettingsMenuController *settingsMenuController;
@property (nonatomic, strong) CPTabBarController *tabBarController;
@property (nonatomic, strong) NSTimer *checkOutTimer;
           
-(void)saveSettings;
- (void)loadVenueView:(NSString *)venueName;
-(void)logoutEverything;
-(void)storeUserLoginDataFromDictionary:(NSDictionary *)userDictionary;
- (void)updatePastVenue:(CPVenue *)venue;
- (CPVenue *)venueWithName:(NSString *)name;
- (void)toggleSettingsMenu;
- (void)promptForCheckout;
- (void)setCheckedOut;
- (void)autoCheckinForVenue:(CPVenue *)venue;
- (void)autoCheckoutForCLRegion:(CLRegion *)region;
- (void)showSignupModalFromViewController:(UIViewController *)viewController animated:(BOOL)animated;
- (void)showEnterInvitationCodeModalFromViewController:(UIViewController *)viewController
         withDontShowTextNoticeAfterLaterButtonPressed:(BOOL)dontShowTextNoticeAfterLaterButtonPressed
                                          pushFromLeft:(BOOL)pushFromLeft
                                              animated:(BOOL)animated;
- (void)syncCurrentUserWithWebAndCheckValidLogin;

- (void)showLoginBanner;
- (void)hideLoginBannerWithCompletion:(void (^)(void))completion;

- (CLRegion *)getRegionForVenue:(CPVenue *)venue;
- (void)startMonitoringVenue:(CPVenue *)venue;
- (void)stopMonitoringVenue:(CPVenue *)venue;

void uncaughtExceptionHandler(NSException *exception);
void SignalHandler(int sig);

@end

