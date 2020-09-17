//
//  KZ_DatabaseManager.h
//  KZ_Database
//
//  Created by Kieron Zhang on 2016/12/24.
//  Copyright © 2016年 Kieron Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KZ_DatabaseNode.h"

@class KZ_DatabaseModel;

@interface KZ_DatabaseManager : NSObject

@property (nonatomic, assign) BOOL logSqlString;

+ (KZ_DatabaseManager *)sharedManager;
+ (KZ_DatabaseManager *)sharedManagerWithFile:(NSString *)filename;
+ (NSString *)tablePath;

- (id)executeWithSqlString:(NSString *)sqlString type:(KZ_DatabaseNodeType)type values:(NSArray *)values;
- (BOOL)executeUpdateDatabaseWithSqlString:(NSString *)sqlString values:(NSArray *)values;
- (NSArray *)executeQueueDatabaseWithSqlString:(NSString *)sqlString values:(NSArray *)values;

@end
