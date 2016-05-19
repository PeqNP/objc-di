/**
 Copyright (c) 2016 Upstart Illustration LLC. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIImage.h>
#import "KSPromise.h"

@class ProductDetailsDomain;
@class SKU;
@class SKUThumbnailViewModel;

@interface ProductDetailsViewModel : NSObject

@property (nonatomic, assign, readonly) BOOL isLoadingSelectedSkuImage;
@property (nonatomic, assign, readonly) BOOL isReserveProductButtonBusy;
@property (nonatomic, assign, readonly) BOOL isAddToShoppingCartButtonBusy;

@property (nonatomic, strong, readonly) NSString *productName;
@property (nonatomic, strong, readonly) NSString *productId;
@property (nonatomic, strong, readonly) UIImage *selectedSkuImage;

- (instancetype)initWithProductDetailsDomain:(ProductDetailsDomain *)productDetailsDomain NS_DESIGNATED_INITIALIZER;

- (NSArray<SKUThumbnailViewModel *> *)skus;
- (void)reserveProductForPickup;
- (void)addToShoppingCart;
- (void)selectSku:(SKU *)sku;

@end
