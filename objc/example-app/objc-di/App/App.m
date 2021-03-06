/**
 Copyright (c) 2016 Upstart Illustration LLC. All rights reserved.
 */

#import "App.h"
#import "di.h"
#import "MainServiceContainer.h"
#import "ProductService.h"
#import "ProductDetailsModel.h"

@interface App ()

di_property(ProductService, productService)

@end

static App *sInstance;

@implementation App

di_inject(ProductService, productService)

+ (instancetype)appWithConfig:(NSDictionary *)config {
    if (sInstance) {
        @throw [NSException exceptionWithName:@"Double Invocation" reason:@"Attempting to init app more than once" userInfo:@{NSLocalizedDescriptionKey: @"Attempting to init app more than once. Stop it!"}];
    }
    
    [DIServiceLocator registerContainer:[[MainServiceContainer alloc] initWithConfiguration:config]];
    
    sInstance = [[App alloc] init];
    return sInstance;
}

- (KSPromise<ProductDetailsModel *> *)productDetailsModelWithProductId:(NSString *)productId {
    return [[self.productService promiseForProductWithId:productId] then:^ProductDetailsModel *(Product *product) {
        return [[ProductDetailsModel alloc] initWithProduct:product];
    } error:^id(NSError *error) {
        return error;
    }];
}

@end
