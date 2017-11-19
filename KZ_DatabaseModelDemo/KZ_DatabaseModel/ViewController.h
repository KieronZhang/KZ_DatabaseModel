//
//  ViewController.h
//  KZ_DatabaseModel
//
//  Created by Kieron Zhang on 2016/12/24.
//  Copyright © 2016年 Kieron Zhang. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController <UITableViewDelegate, UITableViewDataSource> {
    UITableView *databaseTableView;
    NSArray *databaseArray;
}

@end

