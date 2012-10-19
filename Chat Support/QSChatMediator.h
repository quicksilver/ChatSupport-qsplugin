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

@interface QSChatMediator : NSObject

@end

@protocol QSChatMediator
+ (id <QSChatMediator>)defaultMediator;
// Returns a mask

+ (int)			supportedChatTypes;
+ (NSArray *)	supportedAccountTypes;

- (int)capabilitiesOfAccount:(NSString *)accountID;

- (BOOL)initiateChat:(QSChatType)serviceType withAccounts:(NSArray *)accountIDs info:(id)info;

// Status and Icon
// gets a flat list of available accounts as QSObjects for populating the third field of an indirect action
// this is not neccesarily the same as the children of the chat app
- (NSArray *) availableAccounts;
- (BOOL)accountIsAvailable:(NSString *)accountID;
- (NSString *) statusForAccount:(NSString *)accountID;
//- (NSImage *) imageForAccount;
@end
