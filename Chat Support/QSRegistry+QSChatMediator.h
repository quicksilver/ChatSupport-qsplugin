//
//  QSRegistry+QSChatMediator.h
//  Chat Support
//
//  Created by Rob McBroom on 2012/10/19.
//  Copyright (c) 2012 Quicksilver. All rights reserved.
//

#import "QSChatMediator.h"

@interface QSRegistry (QSChatMediator)

- (id <QSChatMediator>)QSChatMediator;

@end
