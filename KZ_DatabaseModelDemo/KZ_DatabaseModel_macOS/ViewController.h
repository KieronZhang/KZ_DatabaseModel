//
//  ViewController.h
//  KZ_DatabaseModel_macOS
//
//  Created by Kieron Zhang on 2018/4/23.
//  Copyright © 2018年 Kieron Zhang. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ViewController : NSViewController <NSTableViewDelegate, NSTableViewDataSource> {
    NSTableView *databaseTableView;
    NSArray *databaseArray;
}

@end
