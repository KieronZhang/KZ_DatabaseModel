//
//  KZ_Database.h
//  KZ_Database
//
//  Created by Kieron Zhang on 2016/12/24.
//  Copyright © 2016年 Kieron Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KZ_DatabaseNode.h"

@interface KZ_Database : NSObject

+ (KZ_DatabaseNode *)CREATE;
+ (KZ_DatabaseNode *)ALTER;
+ (KZ_DatabaseNode *)DROP;
+ (KZ_DatabaseNode *)INSERT;
+ (KZ_DatabaseNode *)REPLACE;
+ (KZ_DatabaseNode *)DELETE;
+ (KZ_DatabaseNode *(^)(id parameter))UPDATE;
+ (KZ_DatabaseNode *(^)(id parameter))SELECT;

+ (KZ_DatabaseNode *(^)(id parameter))TABLE;
+ (KZ_DatabaseNode *(^)(id parameter))TRIGGER;
+ (KZ_DatabaseNode *(^)(id parameter))INDEX;
+ (KZ_DatabaseNode *(^)(id parameter))VIEW;
+ (KZ_DatabaseNode *(^)(id parameter))INTO;
+ (KZ_DatabaseNode *(^)(id parameter))FROM;

+ (KZ_DatabaseNode *)VALUES;
+ (KZ_DatabaseNode *(^)(id parameter))IF_NOT_EXISTS;
+ (KZ_DatabaseNode *(^)(id parameter))SET;
+ (KZ_DatabaseNode *(^)(id condition))WHERE;

+ (KZ_DatabaseNode *)IS;
+ (KZ_DatabaseNode *)NOT;
+ (KZ_DatabaseNode *)NOT_NULL;
+ (KZ_DatabaseNode *)ASC;
+ (KZ_DatabaseNode *)DESC;
+ (KZ_DatabaseNode *(^)(int limit))LIMIT;
+ (KZ_DatabaseNode *(^)(int offset))OFFSET;
+ (KZ_DatabaseNode *(^)(id parameter))LIKE;
+ (KZ_DatabaseNode *(^)(id parameter))GLOB;
+ (KZ_DatabaseNode *(^)(id parameter))BETWEEN;
+ (KZ_DatabaseNode *(^)(id parameter))ORDER_BY;
+ (KZ_DatabaseNode *(^)(id parameter))GROUP_BY;
+ (KZ_DatabaseNode *(^)(id parameter))DISTINCT;
+ (KZ_DatabaseNode *(^)(id condition))AND;
+ (KZ_DatabaseNode *(^)(id condition))OR;
+ (KZ_DatabaseNode *(^)(id condition))EXISTS;
+ (KZ_DatabaseNode *(^)(id condition))HAVING;
+ (KZ_DatabaseNode *(^)(id condition1, id condition2))IN;
+ (KZ_DatabaseNode *(^)(id condition1, id condition2))AS;

+ (KZ_DatabaseNode *)CROSS;
+ (KZ_DatabaseNode *)INNER;
+ (KZ_DatabaseNode *)NATURAL;
+ (KZ_DatabaseNode *)OUTER;
+ (KZ_DatabaseNode *)LEFT;
+ (KZ_DatabaseNode *)UNION;
+ (KZ_DatabaseNode *)ALL;
+ (KZ_DatabaseNode *)AFTER;
+ (KZ_DatabaseNode *)BEFORE;
+ (KZ_DatabaseNode *(^)(id parameter))JOIN;
+ (KZ_DatabaseNode *(^)(id parameter))USING;
+ (KZ_DatabaseNode *(^)(id parameter))RENAME_TO;
+ (KZ_DatabaseNode *(^)(id parameter))ADD_COLUMN;
+ (KZ_DatabaseNode *(^)(id parameter))INDEXED_BY;
+ (KZ_DatabaseNode *(^)(id condition))ON;

+ (KZ_DatabaseNode *)PRIMARY_KEY;
+ (KZ_DatabaseNode *)AUTOINCREMENT;
+ (KZ_DatabaseNode *)UNIQUE;
+ (KZ_DatabaseNode *(^)(id parameter))PRIMARY_KEYS;
+ (KZ_DatabaseNode *(^)(id condition))DEFAULT;
+ (KZ_DatabaseNode *(^)(id condition))CHECK;
+ (KZ_DatabaseNode *(^)(NSString *name))TEXT;
+ (KZ_DatabaseNode *(^)(NSString *name))INTEGER;
+ (KZ_DatabaseNode *(^)(NSString *name))REAL;
+ (KZ_DatabaseNode *(^)(NSString *name))BLOB;

+ (KZ_DatabaseNode *(^)(id parameters))parameters;
+ (KZ_DatabaseNode *(^)(BOOL desc))IS_DESC;

@end
