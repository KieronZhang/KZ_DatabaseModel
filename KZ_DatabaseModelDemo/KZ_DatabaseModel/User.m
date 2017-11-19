//
//  User.m
//  KZ_DatabaseModel
//
//  Created by Kieron Zhang on 2016/12/24.
//  Copyright © 2016年 Kieron Zhang. All rights reserved.
//

#import "User.h"

@implementation User

+ (id)primaryKey {
    return @"user_id";
}

+ (NSArray *)databaseModelWhiteList {
    return @[@"user_id", @"username"];
}

+ (NSDictionary *)databaseDictionary {
    return @{@"user_id" : @"userId"
//             @"user_age" : @"age",
//             @"user_sex" : @"sex",
//             @"user_father_name" : @"father.username",
//             @"user_mother_name" : @"mother.username"
             };
}

@end
