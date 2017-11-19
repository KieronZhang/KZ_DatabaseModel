//
//  KZ_DatabaseModel.h
//  KZ_DatabaseModel
//
//  Created by Kieron Zhang on 2016/12/24.
//  Copyright © 2016年 Kieron Zhang. All rights reserved.
//

#import <KZ_ModelFramework/KZ_Model.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

@interface KZ_DatabaseModel : KZ_Model

//以下是需要重写的方法
/**
 *	@brief	返回创建数据库时的primaryKey，支持返回字符串和数组
 *              要写入数据库的字段而非类字段
 *
 */
+ (id)primaryKey;

/**
 *	@brief	返回创建数据库时的Dictionary
 *              key:要写入数据库的字段，value:对应存入的字段名 支持keyPath的'.'格式
 *              可选，如不重写，则按照对应属性名返回
 *              只需要写入不同的字段名即可
 *
 */
+ (NSDictionary *)databaseDictionary;

/**
 *	@brief	不写入数据库的字段
 *              可选，如不重写，则无不写入数据库字段
 *              要写入数据库的字段而非类字段
 *
 */
+ (NSArray *)databaseModelBlackList;

/**
 * @brief 只写入数据库的字段
 *              可选，如不重写，则无只写入数据库字段
 *              要写入数据库的字段而非类字段
 *
 */
+ (NSArray *)databaseModelWhiteList;

/**
 *	@brief  按照数据库的Dictionary解析成字段，不需要重写
 *
 *	@param JSON : 解析模型JSON
 */
- (id)initWithDatabaseJSON:(NSDictionary *)JSON;

//以下是数据库操作，数据库操作都会在一个队列线程中，不需要另外增加线程
#pragma mark CreateDatabase
/**
 *	@brief	创建数据库
 *              默认在更改数据库时会查找是否存在该数据库，如果不存在则会默认创建。
 *
 *	@param tableName 表明，如果传空或者nil则默认以类名作为表明
 *               primaryKey 主键，如果为空取类方法的primaryKey;
 *               success 返回调取的block，finished:是否成功，resultCode:返回数据库操作的code
 */
+ (void)createDatabase;
+ (void)createDatabaseWithTableName:(NSString *)tableName;
+ (void)createDatabaseWithTableName:(NSString *)tableName primaryKey:(id)primaryKey;
+ (void)createDatabaseWithTableName:(NSString *)tableName primaryKey:(id)primaryKey success:(void (^)(BOOL finished, int resultCode))success;

#pragma mark InsertDatabase
/**
 *	@brief	把当前对象插入数据库，调用insert语句
 *
 *	@param tableName 表明，如果传空或者nil则默认以类名作为表明
 *               primaryKey 主键，如果为空取类方法的primaryKey;
 *               success 返回调取的block，finished:是否成功，resultCode:返回数据库操作的code
 */
- (void)insertToDatabase;
- (void)insertToDatabaseWithTableName:(NSString *)tableName;
- (void)insertToDatabaseWithTableName:(NSString *)tableName success:(void (^)(BOOL finished, int resultCode))success;

- (void)insertToDatabaseWithPrimaryKey:(id)primaryKey;
- (void)insertToDatabaseWithTableName:(NSString *)tableName primaryKey:(id)primaryKey;
- (void)insertToDatabaseWithTableName:(NSString *)tableName primaryKey:(id)primaryKey success:(void (^)(BOOL finished, int resultCode))success;

/**
 *	@brief	批量插入数据库，调用insert语句
 *
 *	@param tableName 表明，如果传空或者nil则默认以类名作为表明
 *               models 要插入的数据数组，数组里面必须是同一种数据类型
 *               primaryKey 主键，如果为空取类方法的primaryKey;
 *               success 返回调取的block，finished:是否成功，resultCode:返回数据库操作的code
 */
+ (void)insertToDatabaseWithTableName:(NSString *)tableName models:(NSArray *)models success:(void (^)(BOOL finished, int resultCode))success;
+ (void)insertToDatabaseWithTableName:(NSString *)tableName models:(NSArray *)models primaryKey:(id)primaryKey success:(void (^)(BOOL finished, int resultCode))success;

#pragma mark ReplaceDatabase
/**
 *	@brief	把当前对象插入数据库，调用replace语句
 *
 *	@param tableName 表明，如果传空或者nil则默认以类名作为表明
 *               primaryKey 主键，如果为空取类方法的primaryKey;
 *               success 返回调取的block，finished:是否成功，resultCode:返回数据库操作的code
 */
- (void)replaceToDatabase;
- (void)replaceToDatabaseWithTableName:(NSString *)tableName;
- (void)replaceToDatabaseWithTableName:(NSString *)tableName success:(void (^)(BOOL finished, int resultCode))success;

- (void)replaceToDatabaseWithPrimaryKey:(id)primaryKey;
- (void)replaceToDatabaseWithTableName:(NSString *)tableName primaryKey:(id)primaryKey;
- (void)replaceToDatabaseWithTableName:(NSString *)tableName primaryKey:(id)primaryKey success:(void (^)(BOOL finished, int resultCode))success;

/**
 *	@brief	批量插入数据库，调用replace语句
 *
 *	@param tableName 表明，如果传空或者nil则默认以类名作为表明
 *               models 要插入的数据数组，数组里面必须是同一种数据类型
 *               primaryKey 主键，如果为空取类方法的primaryKey;
 *               success 返回调取的block，finished:是否成功，resultCode:返回数据库操作的code
 */
+ (void)replaceToDatabaseWithTableName:(NSString *)tableName models:(NSArray *)models success:(void (^)(BOOL finished, int resultCode))success;
+ (void)replaceToDatabaseWithTableName:(NSString *)tableName models:(NSArray *)models primaryKey:(id)primaryKey success:(void (^)(BOOL finished, int resultCode))success;

#pragma mark UpdateDatabase
/**
 *	@brief	以当前对象更新数据库操作，调用update语句
 *
 *	@param tableName 表明，如果传空或者nil则默认以类名作为表明
 *               sets 要更改的数据参数名的数组，不需要添加参数值，会以当前的参数值赋值
 *               where 要更改的条件，如果为nil或者为空，则默认按照primaryKey查找
 *               primaryKey 主键，如果为空取类方法的primaryKey;
 *               success 返回调取的block，finished:是否成功，resultCode:返回数据库操作的code
 */
- (void)updateToDatabaseSets:(NSArray *)sets;
- (void)updateToDatabaseWithTableName:(NSString *)tableName sets:(NSArray *)sets;
- (void)updateToDatabaseWithTableName:(NSString *)tableName sets:(NSArray *)sets where:(NSString *)where;
- (void)updateToDatabaseWithTableName:(NSString *)tableName sets:(NSArray *)sets where:(NSString *)where success:(void (^)(BOOL finished, int resultCode))success;

- (void)updateToDatabaseSets:(NSArray *)sets primaryKey:(id)primaryKey;
- (void)updateToDatabaseWithTableName:(NSString *)tableName sets:(NSArray *)sets primaryKey:(id)primaryKey;
- (void)updateToDatabaseWithTableName:(NSString *)tableName sets:(NSArray *)sets where:(NSString *)where primaryKey:(id)primaryKey;
- (void)updateToDatabaseWithTableName:(NSString *)tableName sets:(NSArray *)sets where:(NSString *)where primaryKey:(id)primaryKey success:(void (^)(BOOL finished, int resultCode))success;

/**
 *	@brief	以当前对象更新数据库操作，调用update语句
 *
 *	@param tableName 表明，如果传空或者nil则默认以类名作为表明
 *               sets 要更改的语句
 *               where 要更改的条件，必传，不能为空
 *               primaryKey 主键，如果为空取类方法的primaryKey;
 *               success 返回调取的block，finished:是否成功，resultCode:返回数据库操作的code
 */
+ (void)updateToDatabaseSet:(NSString *)set where:(NSString *)where;
+ (void)updateToDatabaseWithTableName:(NSString *)tableName set:(NSString *)set where:(NSString *)where;
+ (void)updateToDatabaseWithTableName:(NSString *)tableName set:(NSString *)set where:(NSString *)where success:(void (^)(BOOL finished, int resultCode))success;

+ (void)updateToDatabaseSet:(NSString *)set where:(NSString *)where primaryKey:(id)primaryKey;
+ (void)updateToDatabaseWithTableName:(NSString *)tableName set:(NSString *)set where:(NSString *)where primaryKey:(id)primaryKey;
+ (void)updateToDatabaseWithTableName:(NSString *)tableName set:(NSString *)set where:(NSString *)where primaryKey:(id)primaryKey success:(void (^)(BOOL finished, int resultCode))success;

#pragma mark DeleteDatabase
/**
 *	@brief	从数据库中删除当前对象，调用delete语句
 *
 *	@param tableName 表明，如果传空或者nil则默认以类名作为表明
 *               primaryKey 主键
 *               success 返回调取的block，finished:是否成功，resultCode:返回数据库操作的code
 */
- (void)deleteFromDatabase;
- (void)deleteFromDatabaseWithTableName:(NSString *)tableName;
- (void)deleteFromDatabaseWithTableName:(NSString *)tableName success:(void (^)(BOOL finished, int resultCode))success;

- (void)deleteFromDatabaseWithPrimaryKey:(NSString *)primaryKey;
- (void)deleteFromDatabaseWithTableName:(NSString *)tableName primaryKey:(id)primaryKey;
- (void)deleteFromDatabaseWithTableName:(NSString *)tableName primaryKey:(id)primaryKey success:(void (^)(BOOL finished, int resultCode))success;

/**
 *	@brief	从数据库中删除当前对象，调用delete语句
 *
 *	@param tableName 表明，如果传空或者nil则默认以类名作为表明
 *               where 要更改的条件，必传，不能为空
 *               success 返回调取的block，finished:是否成功，resultCode:返回数据库操作的code
 */
+ (void)deleteFromDatabaseWithWhere:(NSString *)where;
+ (void)deleteFromDatabaseWithTableName:(NSString *)tableName where:(NSString *)where;
+ (void)deleteFromDatabaseWithTableName:(NSString *)tableName where:(NSString *)where success:(void (^)(BOOL finished, int resultCode))success;

#pragma mark DeleteWholeDatabase
/**
 *	@brief	删除整个表
 *
 *	@param tableName 表明，如果传空或者nil则默认以类名作为表明
 *               success 返回调取的block，finished:是否成功，resultCode:返回数据库操作的code
 */
+ (void)deleteWholeDatabase;
+ (void)deleteWholeDatabaseWithTableName:(NSString *)tableName;
+ (void)deleteWholeDatabaseWithTableName:(NSString *)tableName success:(void (^)(BOOL finished, int resultCode))success;

#pragma mark SelectDatabase
/**
 *	@brief	 查询数据库
 *
 *	@param tableName 表明，如果传空或者nil则默认以类名作为表明
 *               where 要更改的条件，如果为nil或者为空，则查找全部
 *               groupBy 分组的字段
 *               having 分组条件
 *               orderBy 排序的字段
 *               desc 是否倒序排列
 *               limit 最多返回多少条
 *               offset 从第几条开始返回
 *               success 返回调取的block，resultArray:查找结果，resultCode:返回数据库操作的code
 */
+ (void)selectModelInDatabaseWithSuccess:(void (^)(NSArray *resultArray, int resultCode))success;
+ (void)selectModelInDatabaseWithTableName:(NSString *)tableName success:(void (^)(NSArray *resultArray, int resultCode))success;
+ (void)selectModelInDatabaseWithTableName:(NSString *)tableName where:(NSString *)where orderBy:(NSString *)orderBy desc:(BOOL)desc success:(void (^)(NSArray *resultArray, int resultCode))success;
+ (void)selectModelInDatabaseWithTableName:(NSString *)tableName where:(NSString *)where orderBy:(NSString *)orderBy desc:(BOOL)desc limit:(int)limit offset:(int)offset success:(void (^)(NSArray *resultArray, int resultCode))success;
+ (void)selectModelInDatabaseWithTableName:(NSString *)tableName where:(NSString *)where groupBy:(NSString *)groupBy orderBy:(NSString *)orderBy desc:(BOOL)desc limit:(int)limit offset:(int)offset success:(void (^)(NSArray *resultArray, int resultCode))success;
+ (void)selectModelInDatabaseWithTableName:(NSString *)tableName where:(NSString *)where groupBy:(NSString *)groupBy having:(NSString *)having orderBy:(NSString *)orderBy desc:(BOOL)desc limit:(int)limit offset:(int)offset success:(void (^)(NSArray *resultArray, int resultCode))success;

+ (void)selectModelCountInDataBaseWithSuccess:(void (^)(int count, int resultCode))success;
+ (void)selectModelCountInDatabaseWithTableName:(NSString *)tableName success:(void (^)(int count, int resultCode))success;
+ (void)selectModelCountInDatabaseWithTableName:(NSString *)tableName where:(NSString *)where orderBy:(NSString *)orderBy success:(void (^)(int count, int resultCode))success;
+ (void)selectModelCountInDatabaseWithTableName:(NSString *)tableName where:(NSString *)where orderBy:(NSString *)orderBy limit:(int)limit offset:(int)offset success:(void (^)(int count, int resultCode))success;
+ (void)selectModelCountInDatabaseWithTableName:(NSString *)tableName where:(NSString *)where groupBy:(NSString *)groupBy orderBy:(NSString *)orderBy limit:(int)limit offset:(int)offset success:(void (^)(int count, int resultCode))success;
+ (void)selectModelCountInDatabaseWithTableName:(NSString *)tableName where:(NSString *)where groupBy:(NSString *)groupBy having:(NSString *)having orderBy:(NSString *)orderBy limit:(int)limit offset:(int)offset success:(void (^)(int count, int resultCode))success;

#pragma mark AddDatabaseColumn
/**
 *	@brief	在表中增加一个列
 *
 *	@param tableName 表明，如果传空或者nil则默认以类名作为表明
 *               columnName 要增加的列名
 *               primaryKey 主键，如果为空取类方法的primaryKey;
 *               success 返回调取的block，finished:是否成功，resultCode:返回数据库操作的code
 */
+ (void)addColumnWithColumnName:(NSString *)columnName;
+ (void)addColumnWithColumnName:(NSString *)columnName tableName:(NSString *)tableName;
+ (void)addColumnWithColumnName:(NSString *)columnName tableName:(NSString *)tableName success:(void (^)(BOOL finished, int resultCode))success;

+ (void)addColumnWithColumnName:(NSString *)columnName primaryKey:(id)primaryKey;
+ (void)addColumnWithColumnName:(NSString *)columnName tableName:(NSString *)tableName primaryKey:(id)primaryKey;
+ (void)addColumnWithColumnName:(NSString *)columnName tableName:(NSString *)tableName primaryKey:(id)primaryKey success:(void (^)(BOOL finished, int resultCode))success;

#pragma mark DatabaseColumnNames
/**
 *	@brief	 查找一个表中所有的列名
 *
 *	@param tableName 表明，如果传空或者nil则默认以类名作为表明
 *               success 返回调取的block，resultArray:查找结果，resultCode:返回数据库操作的code
 */
+ (void)tableColumnNamesWithSuccess:(void (^)(NSArray *resultArray, int resultCode))success;
+ (void)tableColumnNamesWithTableName:(NSString *)tableName success:(void (^)(NSArray *resultArray, int resultCode))success;

@end
