//
//  positioning.h
//  positioning
//
//  Created by Tianyun Shan on 2017-10-26.
//  Copyright © 2017 Mapsted. All rights reserved.
//



#import <UIKit/UIKit.h>

//! Project version number for positioning.
FOUNDATION_EXPORT double positioningVersionNumber;

//! Project version string for positioning.
FOUNDATION_EXPORT const unsigned char positioningVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <positioning/PublicHeader.h>

#import "MapstedCore/MNMapstedLib.h"
#import "MapstedCore/MNGPSLoc.h"
#import "MapstedCore/MNWifiDataBridge.h"
#import "MapstedCore/MNBleDataBridge.h"
#import "MapstedCore/MNObjcUnitUtils.h"
#import "MapstedCore/MNMercator.h"
#import "MapstedCore/MNMercatorBoundary.h"
#import "MapstedCore/MNMercatorLoc.h"
#import "MapstedCore/MNMercatorZone.h"
#import "MapstedCore/MNLatLng.h"
#import "MapstedCore/MNTrajectory.h"
#import "MapstedCore/MNPolygonHighlight.h"
#import "MapstedCore/MNMapstedTestingKey.h"
#import "MapstedCore/MNSDKPermissions.h"
#import "MapstedCore/MapPackageManagerWrapper.h"

// New Model

// Enum
#import "MapstedCore/MNDataType.h"
#import "MapstedCore/MNMapPerspective.h"
#import "MapstedCore/MNLanguageType.h"
#import "MapstedCore/MNZoneType.h"
#import "MapstedCore/MNIdType.h"
#import "MapstedCore/MNContentType.h"
#import "MapstedCore/MNEvent.h"
#import "MapstedCore/MNPositioningMode.h"
#import "MapstedCore/EnumSensorType.h"
#import "MapstedCore/EnumSdkMode.h"
#import "MapstedCore/EnumSdkError.h"
#import "MapstedCore/EnumSdkUpdate.h"
#import "MapstedCore/EnumValidBlueDotError.h"
#import "MapstedCore/MNPackageType.h"
#import "MapstedCore/MNPackageStatus.h"
#import "MapstedCore/MNConfidence.h"

// Positioning
#import "MapstedCore/MNPosition.h"
#import "MapstedCore/MNZone.h"
#import "MapstedCore/MNPbZone.h"

// Style
#import "MapstedCore/MNColour.h"
#import "MapstedCore/MNLineStyle.h"
#import "MapstedCore/MNTextStyle.h"
#import "MapstedCore/MNIconStyle.h"
#import "MapstedCore/MNPolygonStyle.h"
#import "MapstedCore/MNPointStyle.h"
#import "MapstedCore/MNLayerStyle.h"

// General
#import "MapstedCore/MNObjectDataMap.h"
#import "MapstedCore/MNMapPolygon.h"
#import "MapstedCore/MNMapPolyline.h"
#import "MapstedCore/MNMapPoint.h"
#import "MapstedCore/MNSearchEntity.h"
#import "MapstedCore/MNZoneLabel.h"
#import "MapstedCore/MNPropertySearchFilters.h"
#import "MapstedCore/MNMapEntity.h"
#import "MapstedCore/MNEntityZone.h"

// Building
#import "MapstedCore/MNParsedBuildingDataResponse.h"
#import "MapstedCore/MNParsedBuildingDataItem.h"
#import "MapstedCore/MNParsedBuildingLanguageDataItem.h"
#import "MapstedCore/MNBuildingInfo.h"
#import "MapstedCore/MNFloorInfo.h"
#import "MapstedCore/MNBuildingData.h"
#import "MapstedCore/MNBuildingEntities.h"
#import "MapstedCore/MNBuildingPolygons.h"
#import "MapstedCore/MNBuildingPolylines.h"
#import "MapstedCore/MNBuildingPoints.h"
#import "MapstedCore/MNBuildingSearchEntities.h"

// Category

#import "MapstedCore/MNParsedPropertyListAndCategoryResponse.h"

// Marketing
#import "MapstedCore/MNParsedContentResponse.h"

// Property
#import "MapstedCore/MNPropertyInfo.h"
#import "MapstedCore/MNParsedPropertyDataResponse.h"
#import "MapstedCore/MNParsedPropertyDataItem.h"
#import "MapstedCore/MNParsedPropertyLanguageDataItem.h"
#import "MapstedCore/MNPropertyData.h"
#import "MapstedCore/MNPropertyEntities.h"
#import "MapstedCore/MNPropertyPolygons.h"
#import "MapstedCore/MNPropertyPolylines.h"
#import "MapstedCore/MNPropertyPoints.h"
#import "MapstedCore/MNDailyBusinessHour.h"
#import "MapstedCore/MNHoursOfOperation.h"
#import "MapstedCore/MNPropertySearchEntities.h"

//Routing
#import "MapstedCore/MNRouteRequest.h"
#import "MapstedCore/MNRouteOptions.h"
#import "MapstedCore/MNRouteResponse.h"
#import "MapstedCore/MNRouteNode.h"
#import "MapstedCore/MNRouteSegment.h"
#import "MapstedCore/MNRoute.h"
#import "MapstedCore/MNRegion.h"
#import "MapstedCore/MNRouteDistanceTime.h"
#import "MapstedCore/MNRouteUserProgress.h"

//Tag
#import "MapstedCore/MNTag.h"

//Analytics
#import "MapstedCore/MapstedAnalyticsApi.h"
#import "MapstedCore/MNAnalyticsBundle.h"
#import "MapstedCore/MapstedAnalyticsManager.h"

//Triggers
#import "MapstedCore/CppGeofenceTriggerBuilder.h"
#import "MapstedCore/CppBuildingLocationCriteria.h"
#import "MapstedCore/CppFloorLocationCriteria.h"
#import "MapstedCore/CppPoiVicinityLocationCriteria.h"
#import "MapstedCore/CppPropertyLocationCriteria.h"
#import "MapstedCore/EnumLocationCriteriaTriggerDirection.h"
#import "MapstedCore/EnumLocationCriteriaTriggerType.h"
#import "MapstedCore/ICppLocationCriteria.h"
