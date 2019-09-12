//
//  ViewController.m
//  KZ_DatabaseModel_iOS
//
//  Created by Kieron Zhang on 2018/4/23.
//  Copyright © 2018年 Kieron Zhang. All rights reserved.
//

#import "ViewController.h"
#import "iOS_User.h"

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
    switch (indexPath.row) {
        case 0: {
            BOOL finished = [iOS_User createDatabaseWithTableName:nil primaryKey:nil];
            NSLog(@"0-1 %@", finished ? @"创建数据库成功" : @"创建数据库失败");
        }
            break;
        case 1: {
            BOOL finished = [iOS_User deleteWholeDatabaseWithTableName:nil];
            NSLog(@"1-1 %@", finished ? @"删除数据库成功" : @"删除数据库失败");
        }
            break;
        case 2: {
            iOS_User *user = [[iOS_User alloc] init];
            user.userId = @"1";
            user.username = @"Kieron";
            user.age = @"15";
            user.sex = @"Male";
            BOOL finished = [user insertToDatabaseWithTableName:nil];
            NSLog(@"2-1 %@", finished ? @"插入数据库成功" : @"插入数据库失败");
        }
            break;
        case 3: {
            NSMutableArray *array = [NSMutableArray arrayWithCapacity:0];
            for (int i = 0; i < 5; i ++) {
                iOS_User *user = [[iOS_User alloc] init];
                user.userId = @(i + 100).stringValue;
                user.username = @"Kieron";
                user.age = @"15";
                user.sex = @"Male";
                [array addObject:user];
            }
            BOOL finished = [iOS_User insertToDatabaseWithTableName:nil models:array];
            NSLog(@"3-1 %@", finished ? @"插入数据库成功" : @"插入数据库失败");
        }
            break;
        case 4: {
            iOS_User *user = [[iOS_User alloc] init];
            user.userId = @"10";
            user.username = @"Kieron";
            user.age = @"15";
            user.sex = @"Male";
            BOOL finished = [user replaceToDatabaseWithTableName:nil];
            NSLog(@"4-1 %@", finished ? @"替换数据库成功" : @"替换数据库失败");
        }
            break;
        case 5: {
            NSMutableArray *array = [NSMutableArray arrayWithCapacity:0];
            for (int i = 0; i < 5; i ++) {
                iOS_User *user = [[iOS_User alloc] init];
                user.userId = @(i + 200).stringValue;
                user.username = @"Kieron";
                user.age = @"15";
                user.sex = @"Male";
                [array addObject:user];
            }
            BOOL finished = [iOS_User replaceToDatabaseWithTableName:nil models:array];
            NSLog(@"5-1 %@", finished ? @"替换数据库成功" : @"替换数据库失败");
        }
            break;
        case 6: {
            NSArray *resultArray = [iOS_User selectModelInDatabase];
            for (iOS_User *user in resultArray) {
                NSLog(@"6-1 %@", [KZ_Model transModelToJSONObject:user]);
            }
        }
            break;
        case 7: {
            int count = [iOS_User selectModelCountInDataBase];
            NSLog(@"7-1 %d", count);
        }
            break;
        case 8: {
            iOS_User *user = [[iOS_User alloc] init];
            user.userId = @"1";
            user.username = @"Kieron2";
            user.age = @"15";
            user.sex = @"Male";
            BOOL finished = [user updateToDatabaseWithTableName:nil sets:@[@"username"] where:nil];
            NSLog(@"8-1 %@", finished ? @"更新数据库成功" : @"更新数据库失败");
            finished = [iOS_User updateToDatabaseWithTableName:nil set:@"username = 'KieronZhang'" where:@"user_id = '10'"];
            NSLog(@"8-2 %@", finished ? @"更新数据库成功" : @"更新数据库失败");
        }
            break;
        case 9: {
            iOS_User *user = [[iOS_User alloc] init];
            user.userId = @"10";
            user.username = @"Kieron";
            user.age = @"15";
            user.sex = @"Male";
            BOOL finished = [user deleteFromDatabaseWithTableName:nil];
            NSLog(@"9-1 %@", finished ? @"删除数据库成功" : @"删除数据库失败");
        }
            break;
        default:
            break;
    }
}

@end
