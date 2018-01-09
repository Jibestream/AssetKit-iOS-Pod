//
//  JMapAsset.h
//  JMapAsset
//
//  Created by Louie Yuen on 2016-12-20.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JMapRenderingKit/JMapMovingObject.h>

@interface JMapAssetObject : JMapMovingObject

@property (nonatomic, nonnull) NSString *type;
@property (nonatomic, assign, nullable) id delegate;

/*!
 * Init method for creating an asset
 * @param assetId NSNumber unique Id of the asset
 * @param type NSString defining the type of asset
 * @return An instance of the JMapAsset
 */
- (nonnull instancetype)initWithId:(NSInteger)assetId andType:(nonnull NSString *)type;

@end

