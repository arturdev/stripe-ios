//
//  STPRedirectContext+Private.h
//  Stripe
//
//  Created by Daniel Jackson on 7/12/18.
//  Copyright © 2018 Stripe, Inc. All rights reserved.
//

#import "STPRedirectContext.h"
#import <SafariServices/SafariServices.h>

NS_ASSUME_NONNULL_BEGIN

@protocol STPSafariViewControllerDismissalDelegate <NSObject>
- (void)safariViewControllerDidCompleteDismissal:(SFSafariViewController *)controller;
@end

@interface STPRedirectContext() <STPSafariViewControllerDismissalDelegate>

/// Optional URL for a native app. This is passed directly to `UIApplication openURL:`, and if it fails this class falls back to `redirectURL`
@property (nonatomic, nullable, copy) NSURL *nativeRedirectURL;
/// The URL to redirect to, assuming `nativeRedirectURL` is nil or fails to open. Cannot be nil if `nativeRedirectURL` is.
@property (nonatomic, nullable, copy) NSURL *redirectURL;
/// The expected `returnURL`, passed to STPURLCallbackHandler
@property (nonatomic, copy) NSURL *returnURL;
/// Completion block to execute when finished redirecting, with optional error parameter.
@property (nonatomic, copy) STPErrorBlock completion;
/// Error parameter for completion block.
@property (nonatomic, nullable, copy) NSError *completionError;

@end

NS_ASSUME_NONNULL_END
