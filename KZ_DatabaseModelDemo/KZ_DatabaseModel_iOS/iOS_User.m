//
//  iOS_User.m
//  KZ_DatabaseModel_iOS
//
//  Created by Kieron Zhang on 2018/4/23.
//  Copyright © 2018年 Kieron Zhang. All rights reserved.
//

#import "iOS_User.h"

@implementation iOS_User

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
