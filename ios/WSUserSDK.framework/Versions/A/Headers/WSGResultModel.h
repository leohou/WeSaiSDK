//
//  WSGResultModel.h
//  WSUserSDK_Example
//
//  Created by houli on 2018/4/13.
//  Copyright © 2018年 leohou. All rights reserved.
//

@interface WSGResultModel : NSObject
@property (nonatomic, strong) NSString * msg; // 提示信息
@property (nonatomic, assign) int code; // 状态码
@property (nonatomic, strong) NSDictionary * data; // 返回信息

@end
