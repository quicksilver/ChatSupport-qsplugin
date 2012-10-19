//
//  QSRegistry+QSChatMediator.h
//  Chat Support
//
//  Created by Rob McBroom on 2012/10/19.
//

#import "QSChatMediator.h"

NSString *defaultChatClientID();

@interface QSRegistry (QSChatMediator)

- (id <QSChatMediator>)QSChatMediator;

@end
