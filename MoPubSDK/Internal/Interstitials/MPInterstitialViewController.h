//
//  MPInterstitialViewController.h
//  MoPub
//
//  Copyright (c) 2012 MoPub, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

enum {
    MPInterstitialCloseButtonStyleAlwaysVisible,
    MPInterstitialCloseButtonStyleAlwaysHidden,
    MPInterstitialCloseButtonStyleAdControlled
};
typedef NSUInteger MPInterstitialCloseButtonStyle;

enum {
    MPInterstitialOrientationTypePortrait,
    MPInterstitialOrientationTypeLandscape,
    MPInterstitialOrientationTypeAll
};
typedef NSUInteger MPInterstitialOrientationType;

@protocol MPInterstitialViewControllerDelegate;

////////////////////////////////////////////////////////////////////////////////////////////////////

@interface MPInterstitialViewController : UIViewController

@property (nonatomic, assign) MPInterstitialCloseButtonStyle closeButtonStyle;
@property (nonatomic, assign) MPInterstitialOrientationType orientationType;
@property (nonatomic, retain) UIButton *closeButton;
@property (nonatomic, assign) id<MPInterstitialViewControllerDelegate> delegate;

- (void)presentInterstitialFromViewController:(UIViewController *)controller;
- (void)dismissInterstitialAnimated:(BOOL)animated;
- (BOOL)shouldDisplayCloseButton;
- (void)willPresentInterstitial;
- (void)didPresentInterstitial;
- (void)willDismissInterstitial;
- (void)didDismissInterstitial;
- (void)layoutCloseButton;

@end

////////////////////////////////////////////////////////////////////////////////////////////////////

@protocol MPInterstitialViewControllerDelegate <NSObject>

- (void)interstitialDidLoadAd:(MPInterstitialViewController *)interstitial;
- (void)interstitialDidFailToLoadAd:(MPInterstitialViewController *)interstitial;
- (void)interstitialWillAppear:(MPInterstitialViewController *)interstitial;
- (void)interstitialDidAppear:(MPInterstitialViewController *)interstitial;
- (void)interstitialWillDisappear:(MPInterstitialViewController *)interstitial;
- (void)interstitialDidDisappear:(MPInterstitialViewController *)interstitial;
- (void)interstitialWillLeaveApplication:(MPInterstitialViewController *)interstitial;

@end
