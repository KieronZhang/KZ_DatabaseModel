//
//  KZ_DatabaseNode.h
//  KZ_Database
//
//  Created by Kieron Zhang on 2016/12/24.
//  Copyright © 2016年 Kieron Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, KZ_DatabaseSubSqlType) {
    KZ_DatabaseSubSqlType_Unknown,
    KZ_DatabaseSubSqlType_SubSql,
    KZ_DatabaseSubSqlType_NotSubSql
};

typedef NS_ENUM(NSInteger, KZ_DatabaseNodeType) {
    KZ_DatabaseNodeType_Unknown,
    
    KZ_DatabaseNodeType_Create,
    KZ_DatabaseNodeType_Alter,
    KZ_DatabaseNodeType_Drop,
    KZ_DatabaseNodeType_Insert,
    KZ_DatabaseNodeType_Replace,
    KZ_DatabaseNodeType_Delete,
    KZ_DatabaseNodeType_Update,
    KZ_DatabaseNodeType_Select,
    
    KZ_DatabaseNodeType_Table,
    KZ_DatabaseNodeType_Trigger,
    KZ_DatabaseNodeType_Index,
    KZ_DatabaseNodeType_View,
    KZ_DatabaseNodeType_Into,
    KZ_DatabaseNodeType_From,
    
    KZ_DatabaseNodeType_Values,
    KZ_DatabaseNodeType_IfNotExists,
    KZ_DatabaseNodeType_Set,
    KZ_DatabaseNodeType_Where,
    
    KZ_DatabaseNodeType_Is,
    KZ_DatabaseNodeType_Not,
    KZ_DatabaseNodeType_NotNull,
    KZ_DatabaseNodeType_Asc,
    KZ_DatabaseNodeType_Desc,
    KZ_DatabaseNodeType_Limit,
    KZ_DatabaseNodeType_Offset,
    KZ_DatabaseNodeType_Like,
    KZ_DatabaseNodeType_Glob,
    KZ_DatabaseNodeType_Between,
    KZ_DatabaseNodeType_Orderby,
    KZ_DatabaseNodeType_Groupby,
    KZ_DatabaseNodeType_Distinct,
    KZ_DatabaseNodeType_And,
    KZ_DatabaseNodeType_Or,
    KZ_DatabaseNodeType_Exists,
    KZ_DatabaseNodeType_Having,
    KZ_DatabaseNodeType_In,
    KZ_DatabaseNodeType_As,
    
    KZ_DatabaseNodeType_Cross,
    KZ_DatabaseNodeType_Inner,
    KZ_DatabaseNodeType_Natural,
    KZ_DatabaseNodeType_Outer,
    KZ_DatabaseNodeType_Left,
    KZ_DatabaseNodeType_Union,
    KZ_DatabaseNodeType_All,
    KZ_DatabaseNodeType_After,
    KZ_DatabaseNodeType_Before,
    KZ_DatabaseNodeType_Join,
    KZ_DatabaseNodeType_Using,
    KZ_DatabaseNodeType_RenameTo,
    KZ_DatabaseNodeType_AddColumn,
    KZ_DatabaseNodeType_IndexedBy,
    KZ_DatabaseNodeType_On,
    
    KZ_DatabaseNodeType_PrimaryKey,
    KZ_DatabaseNodeType_Autoincrement,
    KZ_DatabaseNodeType_Unique,
    KZ_DatabaseNodeType_PrimaryKeys,
    KZ_DatabaseNodeType_Default,
    KZ_DatabaseNodeType_Check,
    KZ_DatabaseNodeType_Text,
    KZ_DatabaseNodeType_Integer,
    KZ_DatabaseNodeType_Real,
    KZ_DatabaseNodeType_Blob,
    
    KZ_DatabaseNodeType_Parameters,
};

@interface KZ_DatabaseNode : NSObject

@property (nonatomic, assign) KZ_DatabaseNodeType type;
@property (nonatomic, strong) KZ_DatabaseNode *lastNode;
@property (nonatomic, strong) id nodeObject;
@property (nonatomic, strong, readonly) NSString *databaseString;
@property (nonatomic, strong, readonly) NSString *sqlString;
@property (nonatomic, strong, readonly) NSString *subSqlString;
@property (nonatomic, assign, readonly) KZ_DatabaseSubSqlType isSubSqlString;

//id类型会转化成NSString 具体规则如下
//如果是KZ_DatabaseNode类则转化对应的sqlString，如果是子语句，则转化对应的subSqlString。是否强制设定或者取消子语句可以调用isSub和isNotSub方法
//如果是NSString类则原样返回
//如果是NSArray类则用', '分割成字符串返回
//如果是NSDictionary类则用'key = value'的形式返回
- (KZ_DatabaseNode *)CREATE;
- (KZ_DatabaseNode *)ALTER;
- (KZ_DatabaseNode *)DROP;
- (KZ_DatabaseNode *)INSERT;
- (KZ_DatabaseNode *)REPLACE;
- (KZ_DatabaseNode *)DELETE;
- (KZ_DatabaseNode *(^)(id parameter))UPDATE;
- (KZ_DatabaseNode *(^)(id parameter))SELECT;

- (KZ_DatabaseNode *(^)(id parameter))TABLE;
- (KZ_DatabaseNode *(^)(id parameter))TRIGGER;
- (KZ_DatabaseNode *(^)(id parameter))INDEX;
- (KZ_DatabaseNode *(^)(id parameter))VIEW;
- (KZ_DatabaseNode *(^)(id parameter))INTO;
- (KZ_DatabaseNode *(^)(id parameter))FROM;

- (KZ_DatabaseNode *)VALUES;
- (KZ_DatabaseNode *(^)(id parameter))IF_NOT_EXISTS;
- (KZ_DatabaseNode *(^)(id parameter))SET;
- (KZ_DatabaseNode *(^)(id condition))WHERE;

- (KZ_DatabaseNode *)IS;
- (KZ_DatabaseNode *)NOT;
- (KZ_DatabaseNode *)NOT_NULL;
- (KZ_DatabaseNode *)ASC;
- (KZ_DatabaseNode *)DESC;
- (KZ_DatabaseNode *(^)(int limit))LIMIT;
- (KZ_DatabaseNode *(^)(int offset))OFFSET;
- (KZ_DatabaseNode *(^)(id parameter))LIKE;
- (KZ_DatabaseNode *(^)(id parameter))GLOB;
- (KZ_DatabaseNode *(^)(id parameter))BETWEEN;
- (KZ_DatabaseNode *(^)(id parameter))ORDER_BY;
- (KZ_DatabaseNode *(^)(id parameter))GROUP_BY;
- (KZ_DatabaseNode *(^)(id parameter))DISTINCT;
- (KZ_DatabaseNode *(^)(id condition))AND;
- (KZ_DatabaseNode *(^)(id condition))OR;
- (KZ_DatabaseNode *(^)(id condition))EXISTS;
- (KZ_DatabaseNode *(^)(id condition))HAVING;
- (KZ_DatabaseNode *(^)(id condition1, id condition2))IN;
- (KZ_DatabaseNode *(^)(id condition1, id condition2))AS;

- (KZ_DatabaseNode *)CROSS;
- (KZ_DatabaseNode *)INNER;
- (KZ_DatabaseNode *)NATURAL;
- (KZ_DatabaseNode *)OUTER;
- (KZ_DatabaseNode *)LEFT;
- (KZ_DatabaseNode *)UNION;
- (KZ_DatabaseNode *)ALL;
- (KZ_DatabaseNode *)AFTER;
- (KZ_DatabaseNode *)BEFORE;
- (KZ_DatabaseNode *(^)(id parameter))JOIN;
- (KZ_DatabaseNode *(^)(id parameter))USING;
- (KZ_DatabaseNode *(^)(id parameter))RENAME_TO;
- (KZ_DatabaseNode *(^)(id parameter))ADD_COLUMN;
- (KZ_DatabaseNode *(^)(id parameter))INDEXED_BY;
- (KZ_DatabaseNode *(^)(id condition))ON;

- (KZ_DatabaseNode *)PRIMARY_KEY;
- (KZ_DatabaseNode *)AUTOINCREMENT;
- (KZ_DatabaseNode *)UNIQUE;
- (KZ_DatabaseNode *(^)(id parameter))PRIMARY_KEYS;
- (KZ_DatabaseNode *(^)(id condition))DEFAULT;
- (KZ_DatabaseNode *(^)(id condition))CHECK;
- (KZ_DatabaseNode *(^)(NSString *name))TEXT;
- (KZ_DatabaseNode *(^)(NSString *name))INTEGER;
- (KZ_DatabaseNode *(^)(NSString *name))REAL;
- (KZ_DatabaseNode *(^)(NSString *name))BLOB;

//用于返回参数，会在外层加一个括号。id转化类型和上述一致
- (KZ_DatabaseNode *(^)(id parameters))parameters;
- (KZ_DatabaseNode *(^)(BOOL desc))IS_DESC;

- (KZ_DatabaseNode *)isSub;
- (KZ_DatabaseNode *)isNotSub;

- (id)execute;
- (id)executeWithValues:(NSArray *)values;
- (NSString *)getStringValueWithObject:(id)object;

@end
