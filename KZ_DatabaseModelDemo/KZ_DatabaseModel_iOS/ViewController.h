//
//  ViewController.h
//  KZ_DatabaseModel_iOS
//
//  Created by Kieron Zhang on 2018/4/23.
//  Copyright © 2018年 Kieron Zhang. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController <UITableViewDelegate, UITableViewDataSource> {
    UITableView *databaseTableView;
    NSArray *databaseArray;
}

@end
