//
//  KZ_DatabaseHeader.h
//  KZ_Database
//
//  Created by Kieron Zhang on 2017/2/10.
//  Copyright © 2017年 Kieron Zhang. All rights reserved.
//

#import "KZ_Database.h"
#import "KZ_DatabaseManager.h"

#define KZ_CREATE                        KZ_Database.CREATE
#define KZ_ALTER                          KZ_Database.ALTER
#define KZ_DROP                            KZ_Database.DROP
#define KZ_INSERT                        KZ_Database.INSERT
#define KZ_REPLACE                       KZ_Database.REPLACE
#define KZ_DELETE                        KZ_Database.DELETE
#define KZ_UPDATE                        KZ_Database.UPDATE
#define KZ_SELECT                        KZ_Database.SELECT

#define KZ_TABLE                          KZ_Database.TABLE
#define KZ_TRIGGER                      KZ_Database.TRIGGER
#define KZ_INDEX                         KZ_Database.INDEX
#define KZ_VIEW                           KZ_Database.VIEW
#define KZ_INTO                           KZ_Database.INTO
#define KZ_FROM                           KZ_Database.FROM

#define KZ_VALUES                       KZ_Database.VALUES
#define KZ_IF_NOT_EXISTS        KZ_Database.IF_NOT_EXISTS
#define KZ_SET                              KZ_Database.SET
#define KZ_WHERE                         KZ_Database.WHERE

#define KZ_IS                                 KZ_Database.IS
#define KZ_NOT                             KZ_Database.NOT
#define KZ_NOT_NULL                  KZ_Database.NOT_NULL
#define KZ_ASC                              KZ_Database.ASC
#define KZ_DESC                            KZ_Database.DESC
#define KZ_LIMIT                           KZ_Database.LIMIT
#define KZ_OFFSET                        KZ_Database.OFFSET
#define KZ_LIKE                              KZ_Database.LIKE
#define KZ_GLOB                             KZ_Database.GLOB
#define KZ_BETWEEN                     KZ_Database.BETWEEN
#define KZ_ORDER_BY                    KZ_Database.ORDER_BY
#define KZ_GROUP_BY                    KZ_Database.GROUP_BY
#define KZ_DISTINCT                    KZ_Database.DISTINCT
#define KZ_AND                              KZ_Database.AND
#define KZ_OR                                 KZ_Database.OR
#define KZ_EXISTS                        KZ_Database.EXISTS
#define KZ_HAVING                        KZ_Database.HAVING
#define KZ_IN                                 KZ_Database.IN
#define KZ_AS                                 KZ_Database.AS

#define KZ_CROSS                           KZ_Database.CROSS
#define KZ_INNER                           KZ_Database.INNER
#define KZ_NATURAL                      KZ_Database.NATURAL
#define KZ_OUTER                           KZ_Database.OUTER
#define KZ_LEFT                               KZ_Database.LEFT
#define KZ_UNION                           KZ_Database.UNION
#define KZ_ALL                                 KZ_Database.ALL
#define KZ_AFTER                            KZ_Database.AFTER
#define KZ_BEFORE                          KZ_Database.BEFORE
#define KZ_JOIN                              KZ_Database.JOIN
#define KZ_USING                            KZ_Database.USING
#define KZ_RENAME_TO                  KZ_Database.RENAME_TO
#define KZ_ADD_COLUMN               KZ_Database.ADD_COLUMN
#define KZ_INDEXED_BY                 KZ_Database.INDEXED_BY
#define KZ_ON                                  KZ_Database.ON

#define KZ_PRIMARY_KEY                KZ_Database.PRIMARY_KEY
#define KZ_AUTOINCREMENT         KZ_Database.AUTOINCREMENT
#define KZ_UNIQUE                         KZ_Database.UNIQUE
#define KZ_PRIMARY_KEYS              KZ_Database.PRIMARY_KEYS
#define KZ_DEFAULT                        KZ_Database.DEFAULT
#define KZ_CHECK                             KZ_Database.CHECK
#define KZ_TEXT                               KZ_Database.TEXT
#define KZ_INTEGER                        KZ_Database.INTEGER
#define KZ_REAL                               KZ_Database.REAL
#define KZ_BLOB                               KZ_Database.BLOB

#define KZ_parameters                      KZ_Database.parameters
