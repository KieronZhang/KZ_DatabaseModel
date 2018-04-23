//
//  macOS_User.h
//  KZ_DatabaseModel_macOS
//
//  Created by Kieron Zhang on 2018/4/23.
//  Copyright © 2018年 Kieron Zhang. All rights reserved.
//

#import <KZ_DatabaseModel_macOS/KZ_DatabaseModel.h>

@interface macOS_User : KZ_DatabaseModel

@property (nonatomic, strong) NSString *userId;
@property (nonatomic, strong) NSString *username;
@property (nonatomic, strong) NSString *age;
@property (nonatomic, strong) NSString *sex;
@property (nonatomic, strong) NSString *address;
//@property (nonatomic, strong) User *father;
//@property (nonatomic, strong) User *mother;

@end
