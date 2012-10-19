//
//  QSRegistry+QSChatMediator.m
//  Chat Support
//
//  Created by Rob McBroom on 2012/10/19.
//

#import "QSRegistry+QSChatMediator.h"

NSString *defaultChatClientID(){
    NSURL *appURL = nil;
    OSStatus err = LSGetApplicationForURL((CFURLRef)[NSURL URLWithString:@"im://example"], kLSRolesAll, NULL, (CFURLRef *)&appURL);
    if (err != noErr) {
        NSLog(@"No default chat client found. Error %ld", (long)err);
        return nil;
    }
    NSDictionary *infoDict = (NSDictionary *)CFBundleCopyInfoDictionaryForURL((CFURLRef)appURL);
    [infoDict autorelease];
    return [infoDict objectForKey:(NSString *)kCFBundleIdentifierKey];
}

@implementation QSRegistry (QSChatMediator)

- (id <QSChatMediator>)QSChatMediator
{
    id <QSChatMediator> mediator = [prefInstances objectForKey:kQSChatMediators];
    if (!mediator){
        mediator = [self instanceForKey:[self QSChatMediatorID] inTable:kQSChatMediators];
    }
    if (!mediator) {
        NSDictionary *chatMediatorsDict = [QSReg tableNamed:kQSChatMediators];
        NSString *errorMessage = nil;
        // if only one mediator is available, use it
        if ([chatMediatorsDict count] == 1) {
            NSString *defaultMediator = [[chatMediatorsDict allKeys] lastObject];
            mediator = [self instanceForKey:defaultMediator inTable:kQSChatMediators];
            errorMessage = [NSString stringWithFormat:@"Chat mediator %@ not found, using %@ instead", [self QSChatMediatorID], defaultMediator];
        } else {
            errorMessage = [NSString stringWithFormat:@"Chat mediator %@ not found", [self QSChatMediatorID]];
            NSLog(@"%@", errorMessage);
        }
        QSShowNotifierWithAttributes([NSDictionary dictionaryWithObjectsAndKeys:@"MailMediatorMissingNotification", QSNotifierType, [QSResourceManager imageNamed:@"AlertStopIcon"], QSNotifierIcon, @"Quicksilver Chat Support", QSNotifierTitle, errorMessage, QSNotifierText, nil]);
    }
    if (mediator) {
        [prefInstances setObject:mediator forKey:kQSChatMediators];
    }
    return mediator;
}

- (NSString *)QSChatMediatorID
{
    NSString *key = [[NSUserDefaults standardUserDefaults] stringForKey:kQSChatMediators];
    if (!key) key = defaultChatClientID();
    return key;
}

@end
