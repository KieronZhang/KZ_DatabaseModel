//
//  User.h
//  KZ_DatabaseModel
//
//  Created by Kieron Zhang on 2016/12/24.
//  Copyright © 2016年 Kieron Zhang. All rights reserved.
//

#import <KZ_DatabaseModelFramework/KZ_DatabaseModel.h>

@interface User : KZ_DatabaseModel

@property (nonatomic, strong) NSString *userId;
@property (nonatomic, strong) NSString *username;
@property (nonatomic, strong) NSString *age;
@property (nonatomic, strong) NSString *sex;
@property (nonatomic, strong) NSString *address;
//@property (nonatomic, strong) User *father;
//@property (nonatomic, strong) User *mother;

@end
