//
//  FSPagerViewTransformer.h
//  FSPagerView_OC
//
//  Created by  skyhome on 2019/6/14.
//  Copyright © 2019 mobile. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FSPagerViewLayoutAttributes.h"

@class FSPagerView;

typedef NS_ENUM(NSInteger, FSPagerViewTransformerType) {
    FSPagerViewTransformerTypeCrossFading,
    FSPagerViewTransformerTypeZoomOut,
    FSPagerViewTransformerTypeDepth,
    FSPagerViewTransformerTypeOverlap,
    FSPagerViewTransformerTypeLinear,
    FSPagerViewTransformerTypeCoverFlow,
    FSPagerViewTransformerTypeFerrisWheel,
    FSPagerViewTransformerTypeInvertedFerrisWheel,
    FSPagerViewTransformerTypeCubic,
};

@interface FSPagerViewTransformer : NSObject

@property (nonatomic, weak) FSPagerView *pagerView;
@property (nonatomic, assign, readonly) FSPagerViewTransformerType type;

@property (nonatomic, assign) CGFloat minimumScale;
@property (nonatomic, assign) CGFloat minimumAlpha;

- (instancetype)initWithType:(FSPagerViewTransformerType)type;

- (void)applyTransformToAttributes:(FSPagerViewLayoutAttributes *)attributes;

// An interitem spacing proposed by transformer class. This will override the default interitemSpacing provided by the pager view.
- (CGFloat)proposedInteritemSpacing;

@end
