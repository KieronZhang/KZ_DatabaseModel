//
//  KZ_ModelMapped.h
//  KZ_Model
//
//  Created by Kieron Zhang on 2016/12/24.
//  Copyright © 2016年 Kieron Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>

#define kDefaultDateFormate @"yyyy-MM-dd'T'HH:mm:ss'Z'"

@class KZ_ModelProperty;
@class KZ_Model;

@interface KZ_ModelMapped : NSObject

+ (NSMutableDictionary *)getCurrentPropertyDictionaryWithClass:(Class)aClass;
+ (void)setObject:(id)value key:(NSString *)key model:(KZ_Model *)model property:(KZ_ModelProperty *)property;
+ (id)getObjectWithModel:(KZ_Model *)model property:(KZ_ModelProperty *)property;

@end
