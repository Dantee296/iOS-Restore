//
//  JRIPSWUnzipper.h
//  iOS Restore
//
//  Created by John Heaton on 4/17/11.
//  Copyright 2011 Springfield High School. All rights reserved.
//

#import <Foundation/Foundation.h>

#define JRIPSWPreferredInflationDirectoryForFirmware [NSString stringWithFormat:@"%@/iOSRestoreRestoreBundle", [@"~/Library/Caches/Cleanup At Startup" stringByExpandingTildeInPath]]
@protocol JRIPSWUnzipperDelegate;

@interface JRIPSWUnzipper : NSObject {
@private
    NSString *_inflationPath;
    NSString *_ipswPath;
    id<JRIPSWUnzipperDelegate> _delegate;
}

- (id)initWithIPSWPath:(NSString *)ipswPath inflationPath:(NSString *)inflationPath;

- (void)beginUnzipping;

@property (assign) id<JRIPSWUnzipperDelegate> delegate;

@end


@protocol JRIPSWUnzipperDelegate <NSObject>

@optional
- (void)ipswUnzipperFailedToUnzip:(JRIPSWUnzipper *)unzipper;
- (void)ipswUnzipperFinishedUnzipping:(JRIPSWUnzipper *)unzipper;

@end