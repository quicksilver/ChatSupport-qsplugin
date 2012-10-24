//
//  QSChatActions.h
//  Chat Support
//
//  Created by Rob McBroom on 2012/10/20.
//

@interface QSChatActions : QSActionProvider

- (QSObject *)messageAccount:(QSObject *)account;
- (QSObject *)messageAccounts:(QSObject *)account withItem:(QSObject *)item;
- (QSObject *)inviteAccountToAudioChat:(QSObject *)account;
- (QSObject *)inviteAccountToVideoChat:(QSObject *)account;

@end
