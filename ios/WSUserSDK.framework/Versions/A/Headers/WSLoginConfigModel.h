//
//  WSLoginConfigModel.h
//  WSUserSDK
//
//  Created by 龙洋 on 2017/9/1.
//  Copyright © 2017年 leohou. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WSLoginConfigModel : NSObject

@property (nonatomic, strong) NSString *marketId;
@property (nonatomic, strong) NSString *appSecret;
@property (nonatomic, strong) NSString *appid;
@property (nonatomic, strong) NSString *callbackUrl;
@property (nonatomic, strong) NSString *wxappId;
@property (nonatomic, strong) NSString *wxappSecret;

-(instancetype)initWithMarketId:(NSString *)marketId appSecret:(NSString *)appSecret appid:(NSString *)appid callbackUrl:(NSString *)callbackUrl wxappId:(NSString *)wxappId wxappSecret:(NSString *)wxappSecret;

@end
