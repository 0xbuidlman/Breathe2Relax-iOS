//
//  AudioController.h
//  iBreathe110
//
//  Created by Roger Reeder on 8/4/10.
//  Copyright 2010 National Center for Telehealth & Technology. All rights reserved.
//
/*
 *
 * Breathe2Relax
 *
 * Copyright © 2009-2012 United States Government as represented by
 * the Chief Information Officer of the National Center for Telehealth
 * and Technology. All Rights Reserved.
 *
 * Copyright © 2009-2012 Contributors. All Rights Reserved.
 *
 * THIS OPEN SOURCE AGREEMENT ("AGREEMENT") DEFINES THE RIGHTS OF USE,
 * REPRODUCTION, DISTRIBUTION, MODIFICATION AND REDISTRIBUTION OF CERTAIN
 * COMPUTER SOFTWARE ORIGINALLY RELEASED BY THE UNITED STATES GOVERNMENT
 * AS REPRESENTED BY THE GOVERNMENT AGENCY LISTED BELOW ("GOVERNMENT AGENCY").
 * THE UNITED STATES GOVERNMENT, AS REPRESENTED BY GOVERNMENT AGENCY, IS AN
 * INTENDED THIRD-PARTY BENEFICIARY OF ALL SUBSEQUENT DISTRIBUTIONS OR
 * REDISTRIBUTIONS OF THE SUBJECT SOFTWARE. ANYONE WHO USES, REPRODUCES,
 * DISTRIBUTES, MODIFIES OR REDISTRIBUTES THE SUBJECT SOFTWARE, AS DEFINED
 * HEREIN, OR ANY PART THEREOF, IS, BY THAT ACTION, ACCEPTING IN FULL THE
 * RESPONSIBILITIES AND OBLIGATIONS CONTAINED IN THIS AGREEMENT.
 *
 * Government Agency: The National Center for Telehealth and Technology
 * Government Agency Original Software Designation: Breathe2Relax001
 * Government Agency Original Software Title: Breathe2Relax
 * User Registration Requested. Please send email
 * with your contact information to: robert.kayl2@us.army.mil
 * Government Agency Point of Contact for Original Software: robert.kayl2@us.army.mil
 *
 */
#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <AVFoundation/AVAudioPlayer.h>

typedef enum {
	enSCIn = 0,
	enSCEx,
	enSCSay,
	enSCThink,
	enSCNumber,
	enSCYourself,
	enSCOut,
	enSCDef,
	enSCRelax,
	enSCEasy,
	enSCFocus,
	enSCBackward,
	enSCPause,
    enSCMusic,
	enSCAmbient
} enSoundChannels;

@class RootViewController;
@interface AudioController : NSObject <AVAudioPlayerDelegate> {
    AVAudioPlayer *players[enSCAmbient+1];
	RootViewController *parentController;
	
}
@property (nonatomic, retain) RootViewController *parentController;

//TODO: why is players not a retained property?

- (void) preparePlayer:(enSoundChannels)soundChannel andMP3File:(NSString *)mp3File andMP3Volume:(float) mp3Volume andMP3Pan:(float)mp3Pan andNumberOfLoops:(NSInteger) numberOfLoops delegate:(id)delegate;
- (BOOL) isPlaying:(enSoundChannels)soundChannel;
- (void) play:(enSoundChannels)soundChannel;
- (void) stop:(enSoundChannels)soundChannel;
- (void) stopAll;
- (void) stopAllButMusic;
- (void) fade:(NSNumber *)whatChannel;
- (void) fadeSlow:(NSNumber *)whatChannel;
@end
