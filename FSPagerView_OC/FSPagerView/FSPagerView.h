//
//  FSPagerView.h
//  FSPagerView_OC 把FSPagerView(https://github.com/WenchaoD)转成 OC 代码
//
//  Created by  skyhome on 2019/6/14.
//  Copyright © 2019 mobile. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FSPagerViewCell.h"
#import "FSPagerViewTransformer.h"
#import "FSPageControl.h"

@class FSPagerView;

@protocol FSPagerViewDataSource <NSObject>

/// item 数量
- (NSInteger)numberOfItemsInPagerView:(FSPagerView *)pagerView;

/// 每个 item 的控件
- (FSPagerViewCell *)pagerView:(FSPagerView *)pagerView cellForItemAtIndex:(NSInteger)index;

@end

@protocol FSPagerViewDelegate <NSObject>

@optional

/// 是否应该高亮
- (BOOL)pagerView:(FSPagerView *)pagerView shouldHighlightItemAtIndex:(NSInteger)index;

/// 高亮 item
- (void)pagerView:(FSPagerView *)pagerView didHighlightItemAtIndex:(NSInteger)index;

/// 是否应该选中
- (BOOL)pagerView:(FSPagerView *)pagerView shouldSelectItemAtIndex:(NSInteger)index;

/// 选中 item
- (void)pagerView:(FSPagerView *)pagerView didSelectItemAtIndex:(NSInteger)index;

/// 即将显示的 cell
- (void)pagerView:(FSPagerView *)pagerView willDisplayCell:(FSPagerViewCell *)cell forItemAtIndex:(NSInteger)index;

/// 已经显示的 cell
- (void)pagerView:(FSPagerView *)pagerView didEndDisplayingCell:(FSPagerViewCell *)cell forItemAtIndex:(NSInteger)index;

/// 即将拖拽
- (void)pagerViewWillBeginDragging:(FSPagerView *)pagerView;

/// 结束拖拽
- (void)pagerViewWillEndDragging:(FSPagerView *)pagerView targetIndex:(NSInteger)targetIndex;

/// 用户滚动了 pager
- (void)pagerViewDidScroll:(FSPagerView *)pagerView;

/// 动画停止滚动 pager
- (void)pagerViewDidEndScrollAnimation:(FSPagerView *)pagerView;

/// pager 已经完成减速
- (void)pagerViewDidEndDecelerating:(FSPagerView *)pagerView;

@end

typedef NS_ENUM(NSInteger, FSPagerViewScrollDirection){
    FSPagerViewScrollDirectionHorizontal,
    FSPagerViewScrollDirectionVertical,
};

IB_DESIGNABLE @interface FSPagerView : UIView

@property (nonatomic, weak) IBOutlet id<FSPagerViewDataSource> dataSource;
@property (nonatomic, weak) IBOutlet id<FSPagerViewDelegate> delegate;

/// The scroll direction of the pager view. Default is horizontal.
@property (nonatomic, assign) FSPagerViewScrollDirection scrollDirection;

/// The time interval of automatic sliding. 0 means disabling automatic sliding. Default is 0.
@property (nonatomic, assign) IBInspectable CGFloat automaticSlidingInterval;

/// The spacing to use between items in the pager view. Default is 0.
@property (nonatomic, assign) IBInspectable CGFloat interitemSpacing;

/// The item size of the pager view. .zero means always fill the bounds of the pager view. Default is .zero.
@property (nonatomic, assign) IBInspectable CGSize itemSize;

/// A Boolean value indicates that whether the pager view has infinite items. Default is false.
@property (nonatomic, assign) IBInspectable BOOL isInfinite;

/// The scrollEnabled of the the pager view. Default is YES.
@property (nonatomic, assign) IBInspectable BOOL scrollEnabled;

/// A Boolean value that determines whether bouncing always occurs when horizontal scrolling reaches the end of the content view.
@property (nonatomic, assign) IBInspectable BOOL alwaysBounceHorizontal;

/// A Boolean value that determines whether bouncing always occurs when vertical scrolling reaches the end of the content view.
@property (nonatomic, assign) IBInspectable BOOL alwaysBounceVertical;

/// The background view of the pager view.
@property (nonatomic, strong) IBInspectable UIView *backgroundView;

/// The transformer of the pager view.
@property (nonatomic, strong) FSPagerViewTransformer *transformer;

/// Returns whether the user has touched the content to initiate scrolling.
@property (nonatomic, assign) BOOL isTracking;

/// Remove the infinite loop if there is only one item. default is NO
@property (nonatomic, assign) IBInspectable BOOL removesInfiniteLoopForSingleItem;

/// The percentage of x position at which the origin of the content view is offset from the origin of the pagerView view.
@property (nonatomic, assign, readonly) CGFloat scrollOffset;

/// The underlying gesture recognizer for pan gestures.
@property (nonatomic, assign, readonly) UIPanGestureRecognizer *panGestureRecognizer;

@property (nonatomic, assign) NSInteger currentIndex;
@property (nonatomic, assign, readonly) NSInteger numberOfItems;

- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView;
- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section;

/// Register a class for use in creating new pager view cells.
///
/// - Parameters:
///   - cellClass: The class of a cell that you want to use in the pager view.
///   - identifier: The reuse identifier to associate with the specified class. This parameter must not be nil and must not be an empty string.
- (void)registerClass:(Class)class forCellWithReuseIdentifier:(NSString *)identifier;

/// Register a nib file for use in creating new pager view cells.
///
/// - Parameters:
///   - nib: The nib object containing the cell object. The nib file must contain only one top-level object and that object must be of the type FSPagerViewCell.
///   - identifier: The reuse identifier to associate with the specified nib file. This parameter must not be nil and must not be an empty string.
- (void)registerNib:(UINib *)nib forCellWithReuseIdentifier:(NSString *)identifier;

/// Returns a reusable cell object located by its identifier
///
/// - Parameters:
///   - identifier: The reuse identifier for the specified cell. This parameter must not be nil.
///   - index: The index specifying the location of the cell.
/// - Returns: A valid FSPagerViewCell object.
- (__kindof FSPagerViewCell *)dequeueReusableCellWithReuseIdentifier:(NSString *)identifier atIndex:(NSInteger)index;

/// Reloads all of the data for the collection view.
- (void)reloadData;


/// Selects the item at the specified index and optionally scrolls it into view.
///
/// - Parameters:
///   - index: The index path of the item to select.
///   - animated: Specify true to animate the change in the selection or false to make the change without animating it.
- (void)selectItemAtIndex:(NSInteger)index animated:(BOOL)animated;

/// Deselects the item at the specified index.
///
/// - Parameters:
///   - index: The index of the item to deselect.
///   - animated: Specify true to animate the change in the selection or false to make the change without animating it.
- (void)deselectItemAtIndex:(NSInteger)index animated:(BOOL)animated;

/// Scrolls the pager view contents until the specified item is visible.
///
/// - Parameters:
///   - index: The index of the item to scroll into view.
///   - animated: Specify true to animate the scrolling behavior or false to adjust the pager view’s visible content immediately.
- (void)scrollToItemAtIndex:(NSInteger)index animated:(BOOL)animated;

/// Returns the index of the specified cell.
///
/// - Parameter cell: The cell object whose index you want.
/// - Returns: The index of the cell or NSNotFound if the specified cell is not in the pager view.
- (NSInteger)indexForCell:(FSPagerViewCell *)cell;





@end
