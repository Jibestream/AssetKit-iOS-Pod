//
//  JMapAsset.h
//  JMapAssetKit
//
//  Created by Louie Yuen on 2016-12-20.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <JMapCoreKit/JMapCoreKit.h>
#import <JMapControllerKit/JMapController.h>
#import "JMapAssetObject.h"

@class JMapAsset;

/**
 * The JMapAssetDelegate object
 */
@protocol JMapAssetDelegate <NSObject>

@optional

/**
 * Detect Tap Gesture on Asset
 * @param asset A JMapAsset object that was tapped on
 */
- (void)assetTapped:(nonnull JMapAssetObject *)asset;

/**
 * Detect Double Tap Gesture on Asset
 * @param asset A JMapAsset object that was tapped on
 */
- (void)assetDoubleTapped:(nonnull JMapAssetObject *)asset;

/**
 * Detect Long Press Gesture on Asset
 * @param asset A JMapAsset object that was tapped on
 */
- (void)assetLongPressed:(nonnull JMapAssetObject *)asset;
    
/**
 * Listener For When The Asset Wayfinding To Has Been Updated
 * @param asset A JMapAsset object that was updated
 */
- (void)wayfindAssetUpdated:(nonnull JMapAssetObject *)asset;

@end

/**
 * The JMapAsset model
 */
@interface JMapAsset : NSObject

/**
 * The JMapController Instance
 */
@property (nonatomic, nonnull, readonly) JMapController *controller;
/**
 * The Asset Dictionary Containing All Stored Assets
 */
@property (nonatomic, nonnull, readonly) NSMutableDictionary *assetsDictionary;
/**
 * The JMapAssetDelegate Instance
 */
@property (nonatomic, assign, nullable) id <JMapAssetDelegate> delegate;

/**
 * Init Method For The Asset Kit
 * @param controller A JMapController object passed in for communicating with the SDK's controller instance
 */
- (nonnull instancetype)initWithController:(nonnull JMapController *)controller;

/**
 * Update Method For Changing Asset's Position
 * @param asset A JMapAsset object to be updated
 * @param point A JMapPoint updated location
 */
- (void)updateAsset:(nonnull JMapAssetObject *)asset withPosition:(nonnull JMapPoint *)point;

/**
 * Method For Removing An Asset
 * @param asset A JMapAsset object to be removed
 */
- (void)removeAsset:(nonnull JMapAssetObject *)asset;

/**
 * Get Asset By Id
 * @param id A NSInteger unique identifier associated to the asset
 * @return A JMapAssetObject with matching id input
 */
- (nullable JMapAssetObject *)getAssetById:(NSInteger)id;

/**
 * Get Assets By Type
 * @param type A NSString associated to the assets type
 * @return An NSArray of JMapAssetObjects with matching type input
 */
- (nonnull NSArray <JMapAssetObject*> *)getAssetsByType:(nonnull NSString *)type;

/**
 * Get Nearest Asset Of Type To Point
 * @param type A NSString associated to the asset's type
 * @param point A JMapPoint reference to indicate user location
 * @return A JMapAssetObject that is closest to the input point on map
 */
- (nullable JMapAssetObject *)getNearestAssetOfType:(nonnull NSString *)type toPoint:(nonnull JMapPoint *)point;

/**
 * Show Asset Of Type
 * @param type A NSString associated to the asset's type
 */
- (void)showAssetOfType:(nonnull NSString *)type;

/**
 * Hide Asset Of Type
 * @param type A NSString associated to the asset's type
 */
- (void)hideAssetOfType:(nonnull NSString *)type;

/**
 * Wayfind to Asset From Point
 * @param asset A JMapAssetObject wayfinding to
 * @param point A JMapPoint to wayfind from
 */
- (void)wayfindToAsset:(nonnull JMapAssetObject *)asset fromPoint:(nonnull JMapPoint *)point;

/**
 * Wayfind to Asset From User's Location
 * @param asset A JMapAssetObject wayfinding to
 */
- (void)wayfindFromUserLocationToAsset:(nonnull JMapAssetObject *)asset;

/**
 * Wayfind to Asset From User's Location with Rerouting Option
 * @param asset A JMapAssetObject wayfinding to
 * @param interval An NSNumber set to decide the interval between rerouting as the asset updates
 */
- (void)wayfindFromUserLocationToAsset:(nonnull JMapAssetObject *)asset withRerouteInterval:(nullable NSNumber *)interval;

/**
 * Wayfind to Nearest Asset Of Type From Point
 * @param type A NSString indicating the asset type
 * @param point A JMapPoint to wayfind from
 * @return The nearest JMapAssetObject of given type
 */
- (nullable JMapAssetObject *)wayfindToNearestAssetOfType:(nonnull NSString *)type fromPoint:(nonnull JMapPoint *)point;

/**
 * Stop Wayfinding and Remove Wayfind Paths
 */
- (void)clearWayfindingPath;

@end
