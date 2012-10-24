//
//  QSChatActions.m
//  Chat Support
//
//  Created by Rob McBroom on 2012/10/20.
//

#import "QSChatActions.h"
#import "QSChatMediator.h"

@implementation QSChatActions

- (QSObject *)messageAccount:(QSObject *)account
{
    [[QSChatMediator defaultMediator] initiateChat:QSChatTextType withAccounts:[account arrayForType:QSIMAccountType] info:nil];
    return nil;
}

- (QSObject *)messageAccounts:(QSObject *)accounts withItem:(QSObject *)item
{
    [[QSChatMediator defaultMediator] sendItem:item toAccounts:[accounts splitObjects]];
    return nil;
}

- (QSObject *)inviteAccountToAudioChat:(QSObject *)account
{
    return nil;
}

- (QSObject *)inviteAccountToVideoChat:(QSObject *)account
{
    return nil;
}

- (NSArray *)validActionsForDirectObject:(QSObject *)dObject indirectObject:(QSObject *)iObject
{
    // see if accounts are available
    BOOL available = YES;
    for (QSObject *contact in [dObject splitObjects]) {
        // all contacts must be available
        if (![[QSChatMediator defaultMediator] contactIsAvailable:contact]) {
            available = NO;
        }
    }
    // return IM actions that fit
    if (available) {
        return [NSArray arrayWithObjects:@"QSIMAccountSendMessageAction", @"QSIMAccountSendItemAction", nil];
    }
    return nil;
}

@end
