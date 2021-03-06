/**
 Copyright (c) 2016 Upstart Illustration LLC. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "DIServiceContainer.h"

@class ShoppingCartService;

@interface ShoppingCartServiceContainer : NSObject <DIServiceContainer>

@property (nonatomic, strong, readonly) ShoppingCartService *shoppingCartService;

@end
