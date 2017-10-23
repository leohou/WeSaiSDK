//
//  WSSecurityIP.h
//  WSUserSDK
//
//  Created by lcyu on 2017/9/14.
//  Copyright © 2017年 leohou. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WSSecurityIP : NSObject

+(instancetype)sharedInstance;
/*
 获取ip
 ClientID：标准UUID形式的客户端唯一标识。
 AppDeviceID：App端的设备ID。如果获取不到，由客户端生成。（格式为：15位以上的随机字符串）
 userAge:（用户游戏年龄)代表用户注册之时至此时此刻的相对时间，单位为秒钟。
 
 */
+ (NSURLSessionDataTask *)getAvailableIPWithAppDeviceID:(NSString *)appDeviceID ClientID:(NSString *)clientID userAge:(long)userAge completion:(void(^)(id data))completion;

//加入ip缓存策略
- (void)getCacheAvailableIPWithAppDeviceID:(NSString *)appDeviceID ClientID:(NSString *)clientID userAge:(long)userAge completion:(void(^)(NSString *data, NSString * extra))completion;

+ (void)setIPHostUrl:(NSString *)url;

+ (void)setIPCount:(NSString *)count;
@end
