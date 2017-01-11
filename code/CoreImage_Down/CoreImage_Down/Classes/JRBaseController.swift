//
//  JRBaseController.swift
//  CoreImage
//
//  Created by 王潇 on 2017/1/10.
//  Copyright © 2017年 王潇. All rights reserved.
//

import UIKit
import CoreImage
import Metal
import MetalKit

class JRBaseController: UIViewController {

	// Use of undeclared type 'MTLDevice'
	
	// Metal resources
	var device: MTLDevice!
	var commandQueue: MTLCommandQueue!
	var sourceTexture: MTLTexture!                         // 2
	
	// Core Image resources
	var context: CIContext!
	let filter = CIFilter(name: "CIGaussianBlur")!
	let colorSpace = CGColorSpaceCreateDeviceRGB()
	
    override func viewDidLoad() {
        super.viewDidLoad()
		
//        view.backgroundColor = #colorLiteral(red: 0.9254902005, green: 0.2352941185, blue: 0.1019607857, alpha: 1)
		
		device = MTLCreateSystemDefaultDevice()            // 3
		commandQueue = device.makeCommandQueue()
		
		let view = self.view as! MTKView                   // 4
//		view.delegate = self
		view.device = device
		view.framebufferOnly = false
		
		context = CIContext(mtlDevice: device)             // 5
		
		// other setup
		
    }
	
	override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
		
		/// demo 1
		//		let cgImage		= demo()
		/// demo 2
		let image		= #imageLiteral(resourceName: "b")
		let ciImage		= CIImage(cgImage: image.cgImage!)
		let cgImage		= applyFilterChain(to: ciImage)
		
		/// 创建展示图片
		let imgView		= UIImageView(frame: CGRect(x: 10, y: 80, width: image.size.width * 0.5, height: image.size.height * 0.5))
		imgView.image	= UIImage(ciImage: cgImage)
		view.addSubview(imgView)
		
		
		/// 获取滤镜
//		let filterNames = CIFilter.filterNames(inCategory: kCICategoryBuiltIn) as [String]
//		for filt in filterNames {
//			print(filt)
//		}
//		print(filterNames.count)
		
	}
}

extension JRBaseController {
	
	/// 创建一个 CGImage
	///
	/// - Returns: CGImage 对象
	func demo() -> CGImage {
		let context = CIContext()                                           // 1
		let filter	= CIFilter(name: "CISepiaTone")!						// 2
		filter.setValue(0.8, forKey: kCIInputIntensityKey)
		let img		= #imageLiteral(resourceName: "a")
		let image   = CIImage(cgImage: img.cgImage!)
		
		filter.setValue(image, forKey: kCIInputImageKey)
		let result	= filter.outputImage!									// 4
		let cgImage = context.createCGImage(result, from: result.extent)    // 5
		
		return cgImage!
	}
	
	func applyFilterChain(to image: CIImage) -> CIImage {
		
		/// 初始化滤镜 输入图片
		let colorFilter = CIFilter(name: "CIBloom", withInputParameters:
			[kCIInputImageKey		: image,
			 kCIInputRadiusKey		: 10.0,
			 kCIInputIntensityKey	: 0.5])!
		
		let keys	= colorFilter.inputKeys
		let values	= colorFilter.outputKeys
		let attri	= colorFilter.attributes
		
		
		print(keys)
		print(values)
		print(attri)
		
		///
//		let bloomImage = colorFilter.outputImage!.applyingFilter("CIBloom",
//		                                                         withInputParameters: [
//																	kCIInputRadiusKey: 0.0,
//																	kCIInputIntensityKey: 0.0])
		
		let bloomImage = colorFilter.outputImage!
		
		// imageByCroppingToRect is a convenience method for
		// creating the CICrop filter and accessing its outputImage.
		let cropRect = CGRect(x: 0, y: 0, width: bloomImage.extent.size.width, height: bloomImage.extent.size.height)
		let croppedImage = bloomImage.cropping(to: cropRect)
		
		return croppedImage
	}
}

