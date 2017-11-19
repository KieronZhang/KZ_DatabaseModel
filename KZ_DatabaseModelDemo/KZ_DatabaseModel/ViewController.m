//
//  ViewController.m
//  KZ_DatabaseModel
//
//  Created by Kieron Zhang on 2016/12/24.
//  Copyright © 2016年 Kieron Zhang. All rights reserved.
//

#import "ViewController.h"
#import "User.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    databaseArray = @[@"SQLite 创建表", @"SQLite 删除表", @"SQLite Insert 语句", @"SQLite 批量 Insert 语句", @"SQLite Replace 语句", @"SQLite 批量 Replace 语句", @"SQLite Select 语句", @"SQLite Select Count 语句", @"SQLite Update 语句", @"SQLite Delete 语句"];
    
    databaseTableView = [[UITableView alloc] initWithFrame:self.view.bounds];
    databaseTableView.delegate = self;
    databaseTableView.dataSource = self;
    [self.view addSubview:databaseTableView];
}

#pragma mark UITableViewDelegate
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return databaseArray.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString *NameCell = @"NameCell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:NameCell];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:NameCell];
    }
    cell.textLabel.text = databaseArray[indexPath.row];
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    if (indexPath.row == 0) {
        [User createDatabaseWithTableName:nil primaryKey:nil success:^(BOOL finished, int resultCode) {
            NSLog(@"0-1 %@", finished ? @"创建数据库成功" : [NSString stringWithFormat:@"创建数据库失败 %d", (int)resultCode]);
        }];
    }
    else if (indexPath.row == 1) {
        [User deleteWholeDatabaseWithTableName:nil success:^(BOOL finished, int resultCode) {
            NSLog(@"1-1 %@", finished ? @"删除数据库成功" : [NSString stringWithFormat:@"删除数据库失败 %d", (int)resultCode]);
        }];
    }
    else if (indexPath.row == 2) {
        User *user = [[User alloc] init];
        user.userId = @"1";
        user.username = @"Kieron";
        user.age = @"15";
        user.sex = @"Male";
        [user insertToDatabaseWithTableName:nil success:^(BOOL finished, int resultCode) {
            NSLog(@"2-1 %@", finished ? @"插入数据库成功" : [NSString stringWithFormat:@"插入数据库失败 %d", (int)resultCode]);
        }];
    }
    else if (indexPath.row == 3) {
        NSMutableArray *array = [NSMutableArray arrayWithCapacity:0];
        for (int i = 0; i < 5; i ++) {
            User *user = [[User alloc] init];
            user.userId = @(i + 100).stringValue;
            user.username = @"Kieron";
            user.age = @"15";
            user.sex = @"Male";
            [array addObject:user];
        }
        [User insertToDatabaseWithTableName:nil models:array success:^(BOOL finished, int resultCode) {
            NSLog(@"3-1 %@", finished ? @"插入数据库成功" : [NSString stringWithFormat:@"插入数据库失败 %d", (int)resultCode]);
        }];
    }
    else if (indexPath.row == 4) {
        User *user = [[User alloc] init];
        user.userId = @"10";
        user.username = @"Kieron";
        user.age = @"15";
        user.sex = @"Male";
        [user replaceToDatabaseWithTableName:nil success:^(BOOL finished, int resultCode) {
            NSLog(@"4-1 %@", finished ? @"替换数据库成功" : [NSString stringWithFormat:@"替换数据库失败 %d", (int)resultCode]);
        }];
    }
    else if (indexPath.row == 5) {
        NSMutableArray *array = [NSMutableArray arrayWithCapacity:0];
        for (int i = 0; i < 5; i ++) {
            User *user = [[User alloc] init];
            user.userId = @(i + 200).stringValue;
            user.username = @"Kieron";
            user.age = @"15";
            user.sex = @"Male";
            [array addObject:user];
        }
        [User replaceToDatabaseWithTableName:nil models:array success:^(BOOL finished, int resultCode) {
            NSLog(@"5-1 %@", finished ? @"替换数据库成功" : [NSString stringWithFormat:@"替换数据库失败 %d", (int)resultCode]);
        }];
    }
    else if (indexPath.row == 6) {
        [User selectModelInDatabaseWithSuccess:^(NSArray *resultArray, int resultCode) {
            for (User *user in resultArray) {
                NSLog(@"6-1 %@", [KZ_Model transModelToJSONObject:user]);
            }
        }];
    }
    else if (indexPath.row == 7) {
        [User selectModelCountInDataBaseWithSuccess:^(int count, int resultCode) {
            NSLog(@"7-1 %d", count);
        }];
    }
    else if (indexPath.row == 8) {
        User *user = [[User alloc] init];
        user.userId = @"1";
        user.username = @"Kieron2";
        user.age = @"15";
        user.sex = @"Male";
        [user updateToDatabaseWithTableName:nil sets:@[@"username"] where:nil success:^(BOOL finished, int resultCode) {
            NSLog(@"8-1 %@", finished ? @"更新数据库成功" : [NSString stringWithFormat:@"更新数据库失败 %d", (int)resultCode]);
        }];
        [User updateToDatabaseWithTableName:nil set:@"username = 'KieronZhang'" where:@"user_id = '10'" success:^(BOOL finished, int resultCode) {
            NSLog(@"8-2 %@", finished ? @"更新数据库成功" : [NSString stringWithFormat:@"更新数据库失败 %d", (int)resultCode]);
        }];
    }
    else if (indexPath.row == 9) {
        User *user = [[User alloc] init];
        user.userId = @"10";
        user.username = @"Kieron";
        user.age = @"15";
        user.sex = @"Male";
        [user deleteFromDatabaseWithTableName:nil success:^(BOOL finished, int resultCode) {
            NSLog(@"9-1 %@", finished ? @"删除数据库成功" : [NSString stringWithFormat:@"删除数据库失败 %d", (int)resultCode]);
        }];
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

@end