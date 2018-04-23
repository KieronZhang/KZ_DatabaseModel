//
//  KZ_Model.h
//  KZ_Model
//
//  Created by Kieron Zhang on 2016/12/24.
//  Copyright © 2016年 Kieron Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KZ_Model : NSObject

- (id)initWithJSON:(NSDictionary *)json;

/**
 * overwrite
 *	@brief	按照json字段和自定义property的映射字典 @{json字段:自定义property}
 *
 */
+ (NSDictionary *)JSONDictionary;

/**
 * overwrite
 *	@brief 自定义property解析成特殊类，此类必须是KZ_Model的子类
 *
 *	@param propertyName 要解析成特殊类的自定义property字段名字
 */
+ (Class)classToProperty:(NSString *)propertyName;

/**
 * overwrite
 *	@brief 当属性是NSDate时，返回对应的dateFormat @{属性名称：dateFormat}
 *
 */
+ (NSDictionary *)dateFormatDictionary;

/**
 * overwrite
 *	@brief 返回不解析的字段
 *
 */
+ (NSArray<NSString *> *)modelBlackList;

/**
 * overwrite
 *	@brief 返回解析的字段
 *
 */
+ (NSArray<NSString *> *)modelWhiteList;

/**
 * overwrite
 *	@brief 解析成功之后调取方法，默认不做处理
 *
 */
- (void)modelParseDone;

/**
 *	@brief	把此类按照JSONDictionary的字段解析成json
 *
 */
+ (id)transModelToJSONObject:(id)model;

/**
 *	@brief	复制一个对象
 *
 */
- (id)modelCopy;

@end

@interface KZ_ModelArray : NSObject

/**
 *	@brief 把json数组按照aClass类解析成array aClass必须是KZ_Model的子类
 *
 *	@param json 要解析的json数组
 *              aClass 要解析数组的类
 */
+ (NSArray *)JSONWithClass:(Class)aClass json:(NSArray *)json;

@end
