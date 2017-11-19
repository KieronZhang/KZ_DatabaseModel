//
//  KZ_ModelProperty.h
//  KZ_Model
//
//  Created by Kieron Zhang on 2016/12/24.
//  Copyright © 2016年 Kieron Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>

typedef NS_OPTIONS(NSInteger, KZ_PropertyAttribute) {
    KZ_PropertyAttribute_Readonly = 1 << 0,
    KZ_PropertyAttribute_Copy = 1 << 1,
    KZ_PropertyAttribute_Retain = 1 << 2,
    KZ_PropertyAttribute_Nonatomic = 1 << 3,
    KZ_PropertyAttribute_Weak = 1 << 4,
    KZ_PropertyAttribute_Dynamic = 1 << 5,
    KZ_PropertyAttribute_CustomGetter = 1 << 6,
    KZ_PropertyAttribute_CustomSetter = 1 << 7,
};

typedef NS_ENUM(NSInteger, KZ_PropertyType) {
    KZ_PropertyType_Unknown = 0, //   unknown
    KZ_PropertyType_Void = 1, //   void
    KZ_PropertyType_Bool = 2, //   bool
    KZ_PropertyType_Int8 = 3, //   char / BOOL
    KZ_PropertyType_UInt8 = 4, //   unsigned char
    KZ_PropertyType_Int16 = 5, //   short
    KZ_PropertyType_UInt16 = 6, //   unsigned short
    KZ_PropertyType_Int32 = 7, //   int
    KZ_PropertyType_UInt32 = 8, //   unsigned int
    KZ_PropertyType_Int64 = 9, //   long long
    KZ_PropertyType_UInt64 = 10, //   unsigned long long
    KZ_PropertyType_Float = 11, //   float
    KZ_PropertyType_Double = 12, //   double
    KZ_PropertyType_LongDouble = 13, //   long double
    KZ_PropertyType_Object = 14, //   id
    KZ_PropertyType_Class = 15, //   Class
    KZ_PropertyType_Block = 16, // block
    KZ_PropertyType_Selector = 17, //  Selector
    KZ_PropertyType_Pointer = 18, //   void*
    KZ_PropertyType_CString = 19, //   char*
    KZ_PropertyType_Union = 20, // union
    KZ_PropertyType_CArray = 21, //    char[10]
    KZ_PropertyType_Struct = 22, //    struct
};

typedef NS_ENUM (NSUInteger, KZ_PropertyObjectType) {
    KZ_PropertyObjectType_NSUnknown = 0,
    KZ_PropertyObjectType_NSString,
    KZ_PropertyObjectType_NSMutableString,
    KZ_PropertyObjectType_NSValue,
    KZ_PropertyObjectType_NSNumber,
    KZ_PropertyObjectType_NSDecimalNumber,
    KZ_PropertyObjectType_NSData,
    KZ_PropertyObjectType_NSMutableData,
    KZ_PropertyObjectType_NSDate,
    KZ_PropertyObjectType_NSURL,
    KZ_PropertyObjectType_NSArray,
    KZ_PropertyObjectType_NSMutableArray,
    KZ_PropertyObjectType_NSDictionary,
    KZ_PropertyObjectType_NSMutableDictionary,
    KZ_PropertyObjectType_NSSet,
    KZ_PropertyObjectType_NSMutableSet,
    KZ_PropertyObjectType_Custom,
    KZ_PropertyObjectType_NSObject,
};

@interface KZ_ModelProperty : NSObject

@property (nonatomic, assign, readonly) KZ_PropertyAttribute propertyAttribute;
@property (nonatomic, assign, readonly) KZ_PropertyType propertyType;
@property (nonatomic, assign, readonly) KZ_PropertyObjectType propertyObjectType;
@property (nonatomic, copy, readonly) NSString *typeString;
@property (nonatomic, copy, readonly) NSString *propertyName;
@property (nonatomic, assign, readonly) Class currentClass;
@property (nonatomic, assign, readonly) SEL getter;
@property (nonatomic, assign, readonly) SEL setter;
@property (nonatomic, assign, readonly) BOOL isNumber;
@property (nonatomic, copy) NSString *mappedProperty;

- (id)initWithProperty:(objc_property_t)property;

@end
