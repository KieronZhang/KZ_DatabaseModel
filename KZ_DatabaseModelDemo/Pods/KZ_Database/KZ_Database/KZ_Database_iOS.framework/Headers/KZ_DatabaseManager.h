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
+ (NSString *)tablePath;

- (void)executeWithSqlString:(NSString *)sqlString type:(KZ_DatabaseNodeType)type values:(NSArray *)values execute:(void (^)(id result, int resultCode))execute;
- (void)executeUpdateDatabaseWithSqlString:(NSString *)sqlString values:(NSArray *)values execute:(void (^)(BOOL finished, int resultCode))execute;
- (void)executeQueueDatabaseWithSqlString:(NSString *)sqlString values:(NSArray *)values execute:(void (^)(NSArray *resultArray, int resultCode))execute;

@end
