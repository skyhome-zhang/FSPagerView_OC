//
//  FSPagerViewLayoutAttributes.m
//  FSPagerView_OC
//
//  Created by  skyhome on 2019/6/14.
//  Copyright © 2019 mobile. All rights reserved.
//

#import "FSPagerViewLayoutAttributes.h"

@implementation FSPagerViewLayoutAttributes

- (BOOL)isEqual:(FSPagerViewLayoutAttributes *)object {
    if (![object isKindOfClass:[FSPagerViewLayoutAttributes class]]) {
        return NO;
    }
    
    BOOL isEqual = [super isEqual:object];
    isEqual = isEqual && (self.position == object.position);
    return isEqual;
}

- (id)copyWithZone:(NSZone *)zone {
    FSPagerViewLayoutAttributes *copy = [super copyWithZone:zone];
    copy.position = self.position;
    return copy;
}

@end
