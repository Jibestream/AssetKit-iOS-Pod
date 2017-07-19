//
//  JMapAssetKit.h
//  JMapAssetKit
//
//  Created by Louie Yuen on 2016-12-20.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <JMapAssetKit/JMapAsset.h>
#import <JMapCoreKit/JMapCoreKit.h>
#import <JMapControllerKit/JMapController.h>

@class JMapAsset;

@protocol JMapAssetKitDelegate <NSObject>

@optional

/*!
 * Detect Tap Gesture on Asset
 * @param asset A JMapAsset object that was tapped on
 */
- (void)assetTapped:(nonnull JMapAsset *)asset;

- (void)assetDoubleTapped:(nonnull JMapAsset *)asset;

- (void)assetLongPressed:(nonnull JMapAsset *)asset;

- (void)wayfindAssetUpdated:(nonnull JMapAsset *)asset;

@end

@interface JMapAssetKit : NSObject

@property (nonatomic, nonnull, readonly) JMapController *controller;
@property (nonatomic, nonnull, readonly) NSMutableDictionary *assetsDictionary;
@property (nonatomic, assign, nullable) id <JMapAssetKitDelegate> delegate;

/*!
 * Init Method For The Asset Kit
 * @param controller A JMapController object passed in for communicating with the SDK's controller instance
 */
- (nonnull instancetype)initWithController:(nonnull JMapController *)controller;

/*!
 * Update Method For Changing Asset's Position
 * @param asset A JMapAsset object to be updated
 * @param point A JMapPoint updated location
 */
- (void)updateAsset:(nonnull JMapAsset *)asset withPosition:(nonnull JMapPoint *)point;

/*!
 * Method For Removing An Asset
 * @param asset A JMapAsset object to be removed
 */
- (void)removeAsset:(nonnull JMapAsset *)asset;

/*!
 * Get Asset By Id
 * @param id A NSInteger unique identifier associated to the asset
 * @return A JMapAsset object with matching id input
 */
- (nullable JMapAsset *)getAssetById:(NSInteger)id;

/*!
 * Get Assets By Type
 * @param type A NSString associated to the assets type
 * @return An NSArray of JMapAsset objects with matching type input
 */
- (nonnull NSArray <JMapAsset*> *)getAssetsByType:(nonnull NSString *)type;

/*!
 * Get Nearest Asset Of Type To Point
 * @param type A NSString associated to the asset's type
 * @param point A JMapPoint reference to indicate user location
 * @return A JMapAsset that is closest to the input point on map
 */
- (nullable JMapAsset *)getNearestAssetOfType:(nonnull NSString *)type toPoint:(nonnull JMapPoint *)point;

/*!
 * Show Asset Of Type
 * @param type A NSString associated to the asset's type
 */
- (void)showAssetOfType:(nonnull NSString *)type;

/*!
 * Hide Asset Of Type
 * @param type A NSString associated to the asset's type
 */
- (void)hideAssetOfType:(nonnull NSString *)type;

/*!
 * Wayfind to Asset From Point
 * @param asset A JMapAsset object wayfinding to
 * @param point A JMapPoint to wayfind from
 */
- (void)wayfindToAsset:(nonnull JMapAsset *)asset fromPoint:(nonnull JMapPoint *)point;

/*!
 * Wayfind to Asset From User's Location
 * @param asset A JMapAsset object wayfinding to
 */
- (void)wayfindFromUserLocationToAsset:(nonnull JMapAsset *)asset;

/*!
 * Wayfind to Asset From User's Location with Rerouting Option
 * @param asset A JMapAsset object wayfinding to
 * @param interval An NSNumber set to decide the interval between rerouting as the asset updates
 */
- (void)wayfindFromUserLocationToAsset:(nonnull JMapAsset *)asset withRerouteInterval:(nullable NSNumber *)interval;

/*!
 * Wayfind to Nearest Asset Of Type From Point
 * @param type A NSString indicating the asset type
 * @param point A JMapPoint to wayfind from
 * @return The nearest JMapAsset object of given type
 */
- (nullable JMapAsset *)wayfindToNearestAssetOfType:(nonnull NSString *)type fromPoint:(nonnull JMapPoint *)point;

/*!
 * Stop Wayfinding and Remove Wayfind Paths
 */
- (void)clearWayfindingPath;

@end
