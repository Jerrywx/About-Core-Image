//
//  jr_CIColor.h
//  CoreImage_Down
//
//  Created by 王潇 on 2017/1/11.
//  Copyright © 2017年 王潇. All rights reserved.
//

#ifndef jr_CIColor_h
#define jr_CIColor_h

@available(iOS 5.0, *)
open class CIColor : NSObject, NSSecureCoding, NSCopying {
	
	
	public convenience init(red r: CGFloat, green g: CGFloat, blue b: CGFloat)
	
	
	/* Create a new color object, 'representation' should be a string in one of
	 * the formats returned by the stringRepresentation method. */
	public convenience init(string representation: String)
	
	
	/* Initialize a new color object. */
	/// 使用 CGColor
	public init(cgColor c: CGColor)
	
	
	/* Initialize a new color object in CI's default RGB colorspace
	 which is kCGColorSpaceSRGB or, if running on OSX before 10.10,
	 kCGColorSpaceGenericRGB. */
	public convenience init(red r: CGFloat, green g: CGFloat, blue b: CGFloat, alpha a: CGFloat)
	
	
	/* Initialize a new color object in a given colorspace.
	 * Will return null if the colorspace is not kCGColorSpaceModelRGB. */
	@available(iOS 10.0, *)
	public convenience init?(red r: CGFloat, green g: CGFloat, blue b: CGFloat, alpha a: CGFloat, colorSpace: CGColorSpace)
	
	@available(iOS 10.0, *)
	public convenience init?(red r: CGFloat, green g: CGFloat, blue b: CGFloat, colorSpace: CGColorSpace)
	
	
	/* Return the number of color components (including alpha). */
	open var numberOfComponents: Int { get }
	
	
	/* Return the color components (including alpha). */
	open var components: UnsafePointer<CGFloat> { get }
	
	
	/* Return the alpha value of the color. */
	open var alpha: CGFloat { get }
	
	
	/* Return the color space object associated with the color. */
	open var colorSpace: CGColorSpace { get }
	
	
	/* Return the (unpremultiplied) red, green or blue components of the color. */
	open var red: CGFloat { get }
	
	open var green: CGFloat { get }
	
	open var blue: CGFloat { get }
	
	
	/* Returns a formatted string with the components of the color.
	 * The string is suitable for passing to [CIColor colorWithString:].
	 * This property is not KVO-safe because it returns a new NSString each time.
	 * The value of the NSString will be the same each time it is called. */
	open var stringRepresentation: String { get }
	
	
	// Some convenience methods to create CIColors in the sRGB colorspace.
	@available(iOS 10.0, *)
	open class func black() -> Self
	
	@available(iOS 10.0, *)
	open class func white() -> Self
	
	@available(iOS 10.0, *)
	open class func gray() -> Self
	
	@available(iOS 10.0, *)
	open class func red() -> Self
	
	@available(iOS 10.0, *)
	open class func green() -> Self
	
	@available(iOS 10.0, *)
	open class func blue() -> Self
	
	@available(iOS 10.0, *)
	open class func cyan() -> Self
	
	@available(iOS 10.0, *)
	open class func magenta() -> Self
	
	@available(iOS 10.0, *)
	open class func yellow() -> Self
	
	@available(iOS 10.0, *)
	open class func clear() -> Self
}



#endif /* jr_CIColor_h */
