//
//  WSPay.h
//  PayDemo
//
//  Created by lcyu on 2017/3/30.
//  Copyright © 2017年 you520t. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

typedef void(^ProductList)(NSArray *);
typedef void(^WSPCommonBlock)(void); // 通用的回调SDK

@protocol WSPPaySDKDelegate <NSObject>

@required
/**
 这个方法是虚拟货品当在SDK生成了订单id(未在app端服务器生成订单id)，app接收到订单id上传给服务器，上传完成回调SDK走后面的逻辑
 
 @param action 获取订单id
 @param completion 这个是app将订单id上传给服务器之后回调SDK
 */
-(void)sdkHasProduceOrderId:(NSString *)orderId uploadToServerCompletion:(WSPCommonBlock)completion;

@end

@interface WSPay : NSObject

@property (nonatomic,weak)id<WSPPaySDKDelegate>delegate;

+ (instancetype)shardInstance;


/**
 这个方法是获取App在苹果后台注册的IAP项目列表，也可以自行通过后端获取
 @param businessId 对应app的商户id
 @param completion 回调给app的IAP项目列表(存储的是字典,productId:项目id,itemName:项目名称,itemPrice:项目价格(分))
 */
-(void)getAppProductListByBusinessId:(NSString *)businessId productList:(ProductList)completion;

/**
 这个是IAP恢复购买非消耗品的方法（暂时还未启用）
 */
-(void)restoreTranscation;

//  这个是暴露给开发人员清除所有交易使用，使用一次之后记得关闭这个方法
-(void)setAllTranscationFailed;

- (void)refreshseOrderStatue;

@end
