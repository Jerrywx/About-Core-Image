//
//  jr_CoreImage.h
//  CoreImage_Down
//
//  Created by 王潇 on 2017/1/11.
//  Copyright © 2017年 王潇. All rights reserved.
//

#ifndef jr_CoreImage_h
#define jr_CoreImage_h

@available(iOS 5.0, *)
open class CIImage : NSObject, NSSecureCoding, NSCopying {

	/* Initializers. */
	//// 使用 CGImage
	public init(cgImage image: CGImage)
	//// 使用 CGImage & options
	public init(cgImage image: CGImage, options: [String : Any]? = nil)
	
	//// 使用 Data
	public init?(data: Data)
	//// 使用 Data & options
	public init?(data: Data, options: [String : Any]? = nil)
	
	
	public init(bitmapData data: Data, bytesPerRow: Int, size: CGSize, format: CIFormat, colorSpace: CGColorSpace?)
	
	
	@available(iOS 6.0, *)
	public init(texture name: UInt32, size: CGSize, flipped: Bool, colorSpace: CGColorSpace?)
	
	
	// initWithMTLTexture will return nil if textureType is not MTLTextureType2D.
	//// 使用 URL
	public init?(contentsOf url: URL)
	//// 使用 URL & options
	public init?(contentsOf url: URL, options: [String : Any]? = nil)
	
	
	@available(iOS 9.0, *)
	public init(cvImageBuffer imageBuffer: CVImageBuffer)
	
	@available(iOS 9.0, *)
	public init(cvImageBuffer imageBuffer: CVImageBuffer, options: [String : Any]? = nil)
	
	
	@available(iOS 5.0, *)
	public init(cvPixelBuffer pixelBuffer: CVPixelBuffer)
	
	@available(iOS 5.0, *)
	public init(cvPixelBuffer pixelBuffer: CVPixelBuffer, options: [String : Any]? = nil)
	
	//// 使用 CIColor
	public init(color: CIColor)
	
	
	/* Returns a new image representing the original image with the transform
	 * 'matrix' appended to it. */
	open func applying(_ matrix: CGAffineTransform) -> CIImage
	
	
	/* Returns a new image representing the original image with a transform
	 * appied to it based on an orientation value.
	 * Orientation values from 1 to 8 as defined in the TIFF spec are supported.
	 * See also the CGImagePropertyOrientation type for what the 1 to 8 values do.
	 * Returns original image if the image is of infinite extent. */
	@available(iOS 8.0, *)
	open func applyingOrientation(_ orientation: Int32) -> CIImage
	
	
	/* Returns a CGAffineTransform for an orientation value that can be appied to an image.
	 * Orientation values from 1 to 8 as defined in the TIFF spec are supported.
	 * See also the CGImagePropertyOrientation type for what the 1 to 8 values do.
	 * Returns CGAffineTransformIdentity if the image is of infinite extent.*/
	@available(iOS 8.0, *)
	open func imageTransform(forOrientation orientation: Int32) -> CGAffineTransform
	
	
	/* Return a new image formed by compositing the receiver image over 'dest'.
	 * This is equivalent to the CISourceOverCompositing filter. */
	@available(iOS 8.0, *)
	open func compositingOverImage(_ dest: CIImage) -> CIImage
	

	/// 裁剪一个新的矩形图片
	open func cropping(to rect: CGRect) -> CIImage
	
	
	/* Return a new infinite image by replicating the edge pixels of the receiver image. */
	@available(iOS 8.0, *)
	open func clampingToExtent() -> CIImage
	
	
	/* Return a new infinite image by replicating the edge pixels of a rectangle.
	 * This is equivalent to the CICrop filter. */
	@available(iOS 10.0, *)
	open func clamping(to rect: CGRect) -> CIImage
	
	
	/// 添加过滤器
	open func applyingFilter(_ filterName: String, 
							 withInputParameters params: [String : Any]?) -> CIImage
	
	
	/* Return a new image by color matching from the colorSpace to the context's working space.
	 * This method will return nil if the CGColorSpace is not kCGColorSpaceModelRGB. */
	@available(iOS 10.0, *)
	open func matchedToWorkingSpace(from colorSpace: CGColorSpace) -> CIImage?
	
	
	/* Return a new image by color matching from the context's working space to the colorSpace.
	 * This method will return nil if the CGColorSpace is not kCGColorSpaceModelRGB. */
	@available(iOS 10.0, *)
	open func matchedFromWorkingSpace(to colorSpace: CGColorSpace) -> CIImage?
	
	
	/* Return a new image by multiplying the receiver's RGB values by its alpha. */
	@available(iOS 10.0, *)
	open func premultiplyingAlpha() -> CIImage
	
	
	/* Return a new image by dividing the receiver's RGB values by its alpha. */
	@available(iOS 10.0, *)
	open func unpremultiplyingAlpha() -> CIImage
	
	
	/* Return a new image with alpha set to 1 within the rectangle and 0 outside. */
	@available(iOS 10.0, *)
	open func settingAlphaOne(inExtent extent: CGRect) -> CIImage
	
	
	/* Return a new image by applying a gaussian blur to the receiver. */
	@available(iOS 10.0, *)
	open func applyingGaussianBlur(withSigma sigma: Double) -> CIImage
	
	
	/* Return a new image by changing the recevier's properties. */
	@available(iOS 10.0, *)
	open func settingProperties(_ properties: [AnyHashable : Any]) -> CIImage
	
	
	/* Return a rect the defines the bounds of non-(0,0,0,0) pixels */
	/// CGRect
	open var extent: CGRect { get }
	
	
	/* Returns the metadata properties of an image. If the image is the
	 * output of one or more CIFilters, then the metadata of the root inputImage
	 * will be returned. See also kCIImageProperties. */
	@available(iOS 5.0, *)
	open var properties: [String : Any] { get }
	
	
	/* Returns the URL of the image when the image was created using the imageWithContentsOfURL APIs.
	 * This method will return nil, if the URL cannot be determined. */
	@available(iOS 9.0, *)
	open var url: URL? { get }
	
	
	/* Returns if possible the color space of the image it was defined in.
	 * This method will return nil, if the color space cannot be determined. */
	@available(iOS 9.0, *)
	open var colorSpace: CGColorSpace? { get }
	
	
	/* Returns a CVPixelBufferRef if the CIImage was created with [CIImage imageWithCVPixelBuffer] and no options.
	 * Otherwise this property will be nil and calling [CIContext render:toCVPixelBuffer:] is recommended.
	 * Modifying the contents of this pixelBuffer will cause the CIImage to render with undefined results. */
	@available(iOS 10.0, *)
	open var pixelBuffer: CVPixelBuffer? { get }
	
	
	/* Returns a CGImageRef if the CIImage was created with [CIImage imageWithCGImage] or [CIImage imageWithURL] and no options.
	 * Otherwise this property will be nil and calling [CIContext createCGImage:fromRect:] is recommended. */
	@available(iOS 10.0, *)
	open var cgImage: CGImage? { get }
	
	
	/* Returns the rectangle of 'image' that is required to render the
	 * rectangle 'rect' of the receiver.  This may return a null rect. */
	@available(iOS 6.0, *)
	open func regionOfInterest(for image: CIImage, in rect: CGRect) -> CGRect
}


#endif /* jr_CoreImage_h */
