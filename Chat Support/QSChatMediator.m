//
//  QSChatMediator.m
//  Chat Support
//
//  Created by Rob McBroom on 2012/10/18.
//

#import "QSChatMediator.h"
#import "QSRegistry+QSChatMediator.h"

@implementation QSChatMediator

+ (id <QSChatMediator>)defaultMediator
{
	return [QSReg QSChatMediator];
}

@end
