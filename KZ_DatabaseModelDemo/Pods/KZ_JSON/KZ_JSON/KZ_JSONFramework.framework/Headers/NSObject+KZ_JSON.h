//
//  NSObject+KZ_JSON.h
//  KZ_JSON
//
//  Created by Kieron Zhang on 2016/12/23.
//  Copyright © 2016年 Kieron Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (KZ_JSON)

- (id)JSONValue;
- (NSData *)JSONData;
- (NSString *)JSONString;

@end
