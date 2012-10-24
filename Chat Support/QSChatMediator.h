//
//  QSChatMediator.h
//  Chat Support
//
//  Created by Rob McBroom on 2012/10/18.
//  Most code taken from the header in the original version.
//

typedef enum _QSChatType {
	QSChatInitType		= 1, // Plain chat initiaton
	QSChatTextType		= 2, // Send text
	QSChatFileType		= 3, // Send file
	QSChatAudioType		= 4, // Start audio chat
	QSChatVideoType		= 5, // Start video chat
	QSChatRoomType      = 6, // Invite to chat room
} QSChatType;

/* Associated info for each type is:
 QSChatInitType:   nil
 QSChatTextType:   message to be sent
 QSChatFileType:   array of file paths
 QSChatAudioType:	any relevant argument (nil)
 QSChatVideoType:	any relevant argument (nil)
 QSChatRoomType:   name of the room (@"AIM.qsdevmeeting")
 */

enum {
	QSChatInitMask		= 1 << QSChatInitType,
	QSChatTextMask		= 1 << QSChatTextType,
	QSChatFileMask		= 1 << QSChatFileType,
	QSChatAudioMask 	= 1 << QSChatAudioType,
	QSChatVideoMask		= 1 << QSChatVideoType,
	QSChatRoomMask    	= 1 << QSChatRoomType,
	QSChatAnyMask		= 0xffffffffU
};

// this will work for groups and meta contacts
#define QSIMMultiAccountType @"qs.im.multi"

#define kQSChatMediators @"QSChatMediators"

@protocol QSChatMediator
// Returns a mask
+ (int)supportedChatTypes;
+ (NSArray *)supportedAccountTypes;
// can the account do audio, video?
- (int)capabilitiesOfAccount:(NSString *)accountID;
// open a new chat with the account, but send nothing
- (BOOL)initiateChat:(QSChatType)serviceType withAccounts:(NSArray *)accountIDs info:(id)info;
// send text or file(s) to the account(s)
- (BOOL)sendItem:(QSObject *)item toAccounts:(NSArray *)accounts;
// Status and Icon
// gets a flat list of available accounts as QSObjects for populating the third field of an indirect action
// this is not neccesarily the same as the children of the chat app
- (NSArray *)availableAccounts;
// check availability for a specific account
- (BOOL)accountIsAvailable:(NSString *)accountID;
// check availability from an overall contact
- (BOOL)contactIsAvailable:(QSObject *)contact;
- (NSString *)statusForAccount:(NSString *)accountID;
//- (NSImage *) imageForAccount;
@end

@interface QSChatMediator : NSObject

+ (id <QSChatMediator>)defaultMediator;

@end
