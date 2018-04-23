//
//  ViewController.m
//  KZ_DatabaseModel_macOS
//
//  Created by Kieron Zhang on 2018/4/23.
//  Copyright © 2018年 Kieron Zhang. All rights reserved.
//

#import "ViewController.h"
#import "macOS_User.h"

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    databaseArray = @[@"SQLite 创建表", @"SQLite 删除表", @"SQLite Insert 语句", @"SQLite 批量 Insert 语句", @"SQLite Replace 语句", @"SQLite 批量 Replace 语句", @"SQLite Select 语句", @"SQLite Select Count 语句", @"SQLite Update 语句", @"SQLite Delete 语句"];
    
    NSScrollView *tableContainer = [[NSScrollView alloc] initWithFrame:self.view.bounds];
    databaseTableView = [[NSTableView alloc] initWithFrame:self.view.bounds];
    databaseTableView.delegate = self;
    databaseTableView.dataSource = self;
    
    NSTableColumn *column = [[NSTableColumn alloc] initWithIdentifier:@"TableColumn"];
    column.width = CGRectGetWidth(tableContainer.frame) / 2;
    column.minWidth = CGRectGetWidth(tableContainer.frame) / 2;
    column.maxWidth = CGRectGetWidth(tableContainer.frame) / 2;
    column.title = @"SQLite 操作";
    [databaseTableView addTableColumn:column];
    
    tableContainer.documentView = databaseTableView;
    tableContainer.hasVerticalScroller = YES;
    [self.view addSubview:tableContainer];
}

#pragma mark NSTableViewDelegate
- (NSInteger)numberOfRowsInTableView:(NSTableView *)tableView {
    return databaseArray.count;
}

- (BOOL)tableView:(NSTableView *)tableView shouldEditTableColumn:(NSTableColumn *)tableColumn row:(NSInteger)row {
    return NO;
}

- (id)tableView:(NSTableView *)tableView objectValueForTableColumn:(NSTableColumn *)tableColumn row:(NSInteger)row {
    return databaseArray[row];
}

- (BOOL)tableView:(NSTableView *)tableView shouldTrackCell:(NSCell *)cell forTableColumn:(NSTableColumn *)tableColumn row:(NSInteger)row {
    [tableView deselectRow:row];
    switch (row) {
        case 0: {
            [macOS_User createDatabaseWithTableName:nil primaryKey:nil success:^(BOOL finished, int resultCode) {
                NSLog(@"0-1 %@", finished ? @"创建数据库成功" : [NSString stringWithFormat:@"创建数据库失败 %d", (int)resultCode]);
            }];
        }
            break;
        case 1: {
            [macOS_User deleteWholeDatabaseWithTableName:nil success:^(BOOL finished, int resultCode) {
                NSLog(@"1-1 %@", finished ? @"删除数据库成功" : [NSString stringWithFormat:@"删除数据库失败 %d", (int)resultCode]);
            }];
        }
            break;
        case 2: {
            macOS_User *user = [[macOS_User alloc] init];
            user.userId = @"1";
            user.username = @"Kieron";
            user.age = @"15";
            user.sex = @"Male";
            [user insertToDatabaseWithTableName:nil success:^(BOOL finished, int resultCode) {
                NSLog(@"2-1 %@", finished ? @"插入数据库成功" : [NSString stringWithFormat:@"插入数据库失败 %d", (int)resultCode]);
            }];
        }
            break;
        case 3: {
            NSMutableArray *array = [NSMutableArray arrayWithCapacity:0];
            for (int i = 0; i < 5; i ++) {
                macOS_User *user = [[macOS_User alloc] init];
                user.userId = @(i + 100).stringValue;
                user.username = @"Kieron";
                user.age = @"15";
                user.sex = @"Male";
                [array addObject:user];
            }
            [macOS_User insertToDatabaseWithTableName:nil models:array success:^(BOOL finished, int resultCode) {
                NSLog(@"3-1 %@", finished ? @"插入数据库成功" : [NSString stringWithFormat:@"插入数据库失败 %d", (int)resultCode]);
            }];
        }
            break;
        case 4: {
            macOS_User *user = [[macOS_User alloc] init];
            user.userId = @"10";
            user.username = @"Kieron";
            user.age = @"15";
            user.sex = @"Male";
            [user replaceToDatabaseWithTableName:nil success:^(BOOL finished, int resultCode) {
                NSLog(@"4-1 %@", finished ? @"替换数据库成功" : [NSString stringWithFormat:@"替换数据库失败 %d", (int)resultCode]);
            }];
        }
            break;
        case 5: {
            NSMutableArray *array = [NSMutableArray arrayWithCapacity:0];
            for (int i = 0; i < 5; i ++) {
                macOS_User *user = [[macOS_User alloc] init];
                user.userId = @(i + 200).stringValue;
                user.username = @"Kieron";
                user.age = @"15";
                user.sex = @"Male";
                [array addObject:user];
            }
            [macOS_User replaceToDatabaseWithTableName:nil models:array success:^(BOOL finished, int resultCode) {
                NSLog(@"5-1 %@", finished ? @"替换数据库成功" : [NSString stringWithFormat:@"替换数据库失败 %d", (int)resultCode]);
            }];
        }
            break;
        case 6: {
            [macOS_User selectModelInDatabaseWithSuccess:^(NSArray *resultArray, int resultCode) {
                for (macOS_User *user in resultArray) {
                    NSLog(@"6-1 %@", [KZ_Model transModelToJSONObject:user]);
                }
            }];
        }
            break;
        case 7: {
            [macOS_User selectModelCountInDataBaseWithSuccess:^(int count, int resultCode) {
                NSLog(@"7-1 %d", count);
            }];
        }
            break;
        case 8: {
            macOS_User *user = [[macOS_User alloc] init];
            user.userId = @"1";
            user.username = @"Kieron2";
            user.age = @"15";
            user.sex = @"Male";
            [user updateToDatabaseWithTableName:nil sets:@[@"username"] where:nil success:^(BOOL finished, int resultCode) {
                NSLog(@"8-1 %@", finished ? @"更新数据库成功" : [NSString stringWithFormat:@"更新数据库失败 %d", (int)resultCode]);
            }];
            [macOS_User updateToDatabaseWithTableName:nil set:@"username = 'KieronZhang'" where:@"user_id = '10'" success:^(BOOL finished, int resultCode) {
                NSLog(@"8-2 %@", finished ? @"更新数据库成功" : [NSString stringWithFormat:@"更新数据库失败 %d", (int)resultCode]);
            }];
        }
            break;
        case 9: {
            macOS_User *user = [[macOS_User alloc] init];
            user.userId = @"10";
            user.username = @"Kieron";
            user.age = @"15";
            user.sex = @"Male";
            [user deleteFromDatabaseWithTableName:nil success:^(BOOL finished, int resultCode) {
                NSLog(@"9-1 %@", finished ? @"删除数据库成功" : [NSString stringWithFormat:@"删除数据库失败 %d", (int)resultCode]);
            }];
        }
            break;
        default:
            break;
    }
    return YES;
}

- (BOOL)tableView:(NSTableView *)tableView shouldSelectRow:(NSInteger)row {
    return YES;
}

- (void)setRepresentedObject:(id)representedObject {
    [super setRepresentedObject:representedObject];
}

@end
