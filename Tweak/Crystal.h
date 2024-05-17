//
// Crystal.h
//  Crystal
//
//  Created by Alexandra Aurora Göttlicher
//

#import <substrate.h>
#import <UIKit/UIKit.h>
#import "../Preferences/PreferenceKeys.h"
#import "../Preferences/NotificationKeys.h"

NSUserDefaults* preferences;
BOOL pfEnabled;
CGFloat pfVolumeThreshold;
NSString* pfBelowThresholdMode;
NSString* pfAboveThresholdMode;
BOOL pfPauseMusicAtZeroVolume;

@interface SBVolumeControl : NSObject
- (float)_effectiveVolume;
@end

@interface SBMediaController : NSObject
+ (id)sharedInstance;
- (NSDictionary *)_nowPlayingInfo;
- (BOOL)playForEventSource:(long long)arg1;
- (BOOL)pauseForEventSource:(long long)arg1;
@end

@interface AVOutputDevice : NSObject
- (void)setCurrentBluetoothListeningMode:(NSString *)listeningMode;
@end

@interface MRAVOutputDevice : NSObject
@end

@interface MRAVConcreteOutputDevice : MRAVOutputDevice
@end

@interface MPAVRoute : NSObject
- (MRAVConcreteOutputDevice *)logicalLeaderOutputDevice;
@end

@interface MPAVRoutingController : NSObject
@property(nonatomic, readonly)MPAVRoute* pickedRoute;
@end

void setListeningMode(NSString* mode);
