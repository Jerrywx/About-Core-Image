//
//  jr_CIFilter.h
//  CoreImage_Down
//
//  Created by 王潇 on 2017/1/11.
//  Copyright © 2017年 王潇. All rights reserved.
//

#ifndef jr_CIFilter_h
#define jr_CIFilter_h


/* Filter attributes keys */

/** Name of the filter */
public let kCIAttributeFilterName: String

/** Name of the filter intended for UI display (eg. localized) */
public let kCIAttributeFilterDisplayName: String

/** Description of the filter intended for UI display (eg. localized) */
@available(iOS 9.0, *)
public let kCIAttributeDescription: String

/** The version of OS X and iOS a filter was first available in. */
@available(iOS 9.0, *)
public let kCIAttributeFilterAvailable_Mac: String
@available(iOS 9.0, *)
public let kCIAttributeFilterAvailable_iOS: String

/** URL for the reference documentation of the filter. See localizedReferenceDocumentationForFilterName. */
@available(iOS 9.0, *)
public let kCIAttributeReferenceDocumentation: String

/** Array of filter category names (see below) */
public let kCIAttributeFilterCategories: String

/** Class name of the filter. */
public let kCIAttributeClass: String

/** The type of the attribute e.g. scalar, time, distance, etc. */
public let kCIAttributeType: String

/** Minimum value for the attribute. */
public let kCIAttributeMin: String

/** Maximum value for the attribute. */
public let kCIAttributeMax: String

/** Minimum value for the slider. */
public let kCIAttributeSliderMin: String

/** Maximum value for the slider. */
public let kCIAttributeSliderMax: String

/** Default value for the slider. */
public let kCIAttributeDefault: String

/** The identity value is the value at which the filter has no effect. */
public let kCIAttributeIdentity: String

/** The non-localized name of the attribute. */
public let kCIAttributeName: String

/** The localized name of the attribute to be used for display to the user. */
public let kCIAttributeDisplayName: String

/** Key to request the desired set of controls in a filter UIView. The defined values for this key are:
 CIUISetBasic, CIUISetIntermediate, CIUISetAdvanced and CIUISetDevelopment. */
@available(iOS 9.0, *)
public let kCIUIParameterSet: String

/** Constant for requesting controls that are appropiate in an basic user scenario, meaning the bare minimum of settings to control the filter. */
@available(iOS 9.0, *)
public let kCIUISetBasic: String

/** Constant for requesting controls that are appropiate in an intermediate user scenario. */
@available(iOS 9.0, *)
public let kCIUISetIntermediate: String

/** Constant for requesting controls that are appropiate in an advanced user scenario. */
@available(iOS 9.0, *)
public let kCIUISetAdvanced: String

/** Constant for requesting controls that should only be visible for development purposes. */
@available(iOS 9.0, *)
public let kCIUISetDevelopment: String

/* Types for numbers */
public let kCIAttributeTypeTime: String
public let kCIAttributeTypeScalar: String
public let kCIAttributeTypeDistance: String
public let kCIAttributeTypeAngle: String
public let kCIAttributeTypeBoolean: String

/** Indicates that the key uses integer values. */
@available(iOS 5.0, *)
public let kCIAttributeTypeInteger: String

/** Indicates that the key uses non negative integer values. */
@available(iOS 5.0, *)
public let kCIAttributeTypeCount: String

/* Types for 2-element vectors */
public let kCIAttributeTypePosition: String
public let kCIAttributeTypeOffset: String

/* Types for 3-element vectors */
public let kCIAttributeTypePosition3: String

/* Types for 4-element vectors */
public let kCIAttributeTypeRectangle: String

/* Types for colors */
@available(iOS 9.0, *)
public let kCIAttributeTypeOpaqueColor: String
@available(iOS 5.0, *)
public let kCIAttributeTypeColor: String

/* Types for images */
@available(iOS 9.0, *)
public let kCIAttributeTypeGradient: String
@available(iOS 5.0, *)
public let kCIAttributeTypeImage: String

/* Types for NSValue of CGAffineTransform */
@available(iOS 5.0, *)
public let kCIAttributeTypeTransform: String

/* Categories */
public let kCICategoryDistortionEffect: String
public let kCICategoryGeometryAdjustment: String
public let kCICategoryCompositeOperation: String
public let kCICategoryHalftoneEffect: String
public let kCICategoryColorAdjustment: String
public let kCICategoryColorEffect: String
public let kCICategoryTransition: String
public let kCICategoryTileEffect: String
public let kCICategoryGenerator: String
@available(iOS 5.0, *)
public let kCICategoryReduction: String
public let kCICategoryGradient: String
public let kCICategoryStylize: String
public let kCICategorySharpen: String
public let kCICategoryBlur: String
public let kCICategoryVideo: String
public let kCICategoryStillImage: String
public let kCICategoryInterlaced: String
public let kCICategoryNonSquarePixels: String
public let kCICategoryHighDynamicRange: String
public let kCICategoryBuiltIn: String
@available(iOS 9.0, *)
public let kCICategoryFilterGenerator: String

/* common filter parameter keys */

@available(iOS 5.0, *)
public let kCIOutputImageKey: String
@available(iOS 5.0, *)
public let kCIInputBackgroundImageKey: String
@available(iOS 5.0, *)
public let kCIInputImageKey: String
@available(iOS 7.0, *)
public let kCIInputTimeKey: String
@available(iOS 7.0, *)
public let kCIInputTransformKey: String
@available(iOS 7.0, *)
public let kCIInputScaleKey: String
@available(iOS 7.0, *)
public let kCIInputAspectRatioKey: String
@available(iOS 7.0, *)
public let kCIInputCenterKey: String
@available(iOS 7.0, *)
public let kCIInputRadiusKey: String
@available(iOS 7.0, *)
public let kCIInputAngleKey: String
@available(iOS 9.0, *)
public let kCIInputRefractionKey: String
@available(iOS 7.0, *)
public let kCIInputWidthKey: String
@available(iOS 7.0, *)
public let kCIInputSharpnessKey: String
@available(iOS 7.0, *)
public let kCIInputIntensityKey: String
@available(iOS 7.0, *)
public let kCIInputEVKey: String
@available(iOS 7.0, *)
public let kCIInputSaturationKey: String
@available(iOS 7.0, *)
public let kCIInputColorKey: String
@available(iOS 7.0, *)
public let kCIInputBrightnessKey: String
@available(iOS 7.0, *)
public let kCIInputContrastKey: String
@available(iOS 9.0, *)
public let kCIInputBiasKey: String
@available(iOS 9.0, *)
public let kCIInputWeightsKey: String
@available(iOS 9.0, *)
public let kCIInputGradientImageKey: String
@available(iOS 7.0, *)
public let kCIInputMaskImageKey: String
@available(iOS 9.0, *)
public let kCIInputShadingImageKey: String
@available(iOS 7.0, *)
public let kCIInputTargetImageKey: String
@available(iOS 7.0, *)
public let kCIInputExtentKey: String
@available(iOS 6.0, *)
public let kCIInputVersionKey: String


/** CIFilter are filter objects for Core Image that encapsulate the filter with its attributes
 
 The CIFilter class produces a CIImage object as output. Typically, a filter takes one or more images as input. Some filters, however, generate an image based on other types of input parameters. The parameters of a CIFilter object are set and retrieved through the use of key-value pairs. You use the CIFilter object in conjunction with the CIImage, CIContext, CIVector, CIImageAccumulator, and CIColor objects to take advantage of the built-in Core Image filters when processing images. CIFilter objects are also used along with CIKernel, CISampler, and CIFilterShape objects to create custom filters. */
@available(iOS 5.0, *)
open class CIFilter : NSObject, NSSecureCoding, NSCopying {
	
	
	@available(iOS 5.0, *)
	open var outputImage: CIImage? { get }
	
	
	/* The name of the filter. On OSX and iOS 10, this property is read-write.
	 * This can be useful when using CIFilters with CoreAnimation or SceneKit.
	 * For example, to set an attribute of a filter attached to a layer,
	 * a unique path such as "filters.myExposureFilter.inputEV" could be used.
	 * CALayer animations may also access filter attributes via key-paths. */
	open var name: String
	
	
	/** Returns an array containing the names of all inputs in the filter. */
	open var inputKeys: [String] { get }
	
	
	/** Returns an array containing the names of all outputs in the filter. */
	open var outputKeys: [String] { get }
	
	
	/** Sets all inputs to their default values (where default values are defined, other inputs are left as-is). */
	open func setDefaults()
	
	
	/** Returns a dictionary containing key/value pairs describing the filter. (see description of keys below) */
	open var attributes: [String : Any] { get }
}

/** Similar to above except that all argument values and option key-value are specified inline. The list of key-value pairs must be terminated by the 'nil' object. */

/** Methods to register a filter and get access to the list of registered filters
 Use these methods to create filters and find filters. */
extension CIFilter {
	
	
	/** Creates a new filter of type 'name'.
	 On OSX, all input values will be undefined.
	 On iOS, all input values will be set to default values. */
	public /*not inherited*/ init?(name: String)
	
	
	/** Creates a new filter of type 'name'.
	 The filter's input parameters are set from the list of key-value pairs which must be nil-terminated.
	 On OSX, any of the filter input parameters not specified in the list will be undefined.
	 On iOS, any of the filter input parameters not specified in the list will be set to default values. */
	
	/** Creates a new filter of type 'name'.
	 The filter's input parameters are set from the dictionary of key-value pairs.
	 On OSX, any of the filter input parameters not specified in the dictionary will be undefined.
	 On iOS, any of the filter input parameters not specified in the dictionary will be set to default values. */
	@available(iOS 8.0, *)
	public /*not inherited*/ init?(name: String, withInputParameters params: [String : Any]?)
	
	
	/** Returns an array containing all published filter names in a category. */
	open class func filterNames(inCategory category: String?) -> [String]
	
	
	/** Returns an array containing all published filter names that belong to all listed categories. */
	open class func filterNames(inCategories categories: [String]?) -> [String]
	
	
	/** Publishes a new filter called 'name'.
	 
	 The constructor object 'anObject' should implement the filterWithName: method.
	 That method will be invoked with the name of the filter to create.
	 The class attributes must have a kCIAttributeFilterCategories key associated with a set of categories.
	 @param   attributes    Dictionary of the registration attributes of the filter. See below for attribute keys.
	 */
	@available(iOS 9.0, *)
	open class func registerName(_ name: String, constructor anObject: CIFilterConstructor, classAttributes attributes: [String : Any] = [:])
	
	
	/** Returns the localized name of a filter for display in the UI. */
	@available(iOS 9.0, *)
	open class func localizedName(forFilterName filterName: String) -> String?
	
	
	/** Returns the localized name of a category for display in the UI. */
	@available(iOS 9.0, *)
	open class func localizedName(forCategory category: String) -> String
	
	
	/** Returns the localized description of a filter for display in the UI. */
	@available(iOS 9.0, *)
	open class func localizedDescription(forFilterName filterName: String) -> String?
	
	
	/** Returns the URL to the localized reference documentation describing the filter.
	 
	 The URL can be a local file or a remote document on a webserver. It is possible, that this method returns nil (like filters that predate this feature). A client of this API has to handle this case gracefully. */
	@available(iOS 9.0, *)
	open class func localizedReferenceDocumentation(forFilterName filterName: String) -> URL?
}

/** Methods to serialize arrays of filters to xmp. */
extension CIFilter {
	
	
	/* Given an array of filters, serialize the filters' parameters
	 into XMP form that is suitable for embedding in to an image.
	 At this time the only filters classes that are serialized
	 are, CIAffineTransform, CICrop, and the filters returned by
	 [CIImage autoAdjustmentFilters].
	 The parameters of other filter classes will not be serialized.
	 The return value will be null if none of the filters can be serialized.
	 */
	
	@available(iOS 6.0, *)
	open class func serializedXMP(from filters: [CIFilter], inputImageExtent extent: CGRect) -> Data?
	
	
	/* Return an array of CIFilters de-serialized from XMP data.
	 */
	@available(iOS 6.0, *)
	open class func filterArray(fromSerializedXMP xmpData: Data, inputImageExtent extent: CGRect, error outError: NSErrorPointer) -> [CIFilter]
}






#endif /* jr_CIFilter_h */
