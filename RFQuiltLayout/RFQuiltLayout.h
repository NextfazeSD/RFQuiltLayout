//
//  RFQuiltLayout.h
//  
//  Created by Bryce Redd on 12/7/12.
//  Copyright (c) 2012. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PSTCollectionView.h"

@protocol RFQuiltLayoutDelegate <PSUICollectionViewDelegate>
@optional
- (CGSize) blockSizeForItemAtIndexPath:(NSIndexPath *)indexPath; // defaults to 1x1
@end

@interface RFQuiltLayout : PSUICollectionViewLayout
@property (nonatomic, weak) IBOutlet NSObject<RFQuiltLayoutDelegate>* delegate;

@property (nonatomic, assign) CGSize blockPixels; // defaults to 100x100
@property (nonatomic, assign) PSTCollectionViewScrollDirection direction; // defaults to vertical

// only use this if you don't have more than 1000ish items.
// this will give you the correct size from the start and
// improve scrolling speed, at the cost of time at the beginning
@property (nonatomic) BOOL predrawEverything;

// Inter-item spacing like Flow Layout
@property (nonatomic) CGFloat minimumInteritemSpacing;
@end
