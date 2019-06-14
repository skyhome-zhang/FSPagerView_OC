//
//  FSPagerViewLayout.h
//  FSPagerView_OC
//
//  Created by  skyhome on 2019/6/14.
//  Copyright © 2019 mobile. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FSPagerView.h"

@interface FSPagerViewLayout : UICollectionViewLayout

@property (nonatomic, assign) CGSize contentSize;
@property (nonatomic, assign) CGFloat leadingSpacing;
@property (nonatomic, assign) CGFloat itemSpacing;
@property (nonatomic, assign) BOOL needsReprepare;

@property (nonatomic, assign) FSPagerViewScrollDirection scrollDirection;

- (void)forceInvalidate;
- (CGPoint)contentOffsetForIndexPath:(NSIndexPath *)indexPath;
- (CGRect)frameForIndexPath:(NSIndexPath *)indexPath;

@end
