//
//  CPTabBarController.h
//  candpiosapp
//
//  Created by Stephen Birarda on 4/2/12.
//  Copyright (c) 2012 Coffee and Power Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CPThinTabBar.h"

@interface CPTabBarController : UITabBarController <UIAlertViewDelegate>

@property (nonatomic, assign) BOOL forcedCheckin;
@property (nonatomic, strong) NSString *currentVenueID;

- (IBAction)tabBarButtonPressed:(id)sender;
- (IBAction)updateButtonPressed:(id)sender;

@end
