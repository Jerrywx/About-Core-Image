//
//  JRBaseController.swift
//  CoreImage
//
//  Created by 王潇 on 2017/1/10.
//  Copyright © 2017年 王潇. All rights reserved.
//

import UIKit
import CoreImage

class JRBaseController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
		
        view.backgroundColor = #colorLiteral(red: 0.9254902005, green: 0.2352941185, blue: 0.1019607857, alpha: 1)
		
    }
	
	func demo() {
		let context = CIContext()                                           // 1
		
		let filter	= CIFilter(name: "CISepiaTone")!                         // 2
		filter.setValue(0.8, forKey: kCIInputIntensityKey)
		//		let image	= CIImage(contentsOfURL: myURL)                           // 3
		let img		= #imageLiteral(resourceName: "a")
		let image   = img.ciImage
		filter.setValue(image, forKey: kCIInputImageKey)
		let result	= filter.outputImage!                                    // 4
		let cgImage = context.createCGImage(result, from: result.extent)    // 5
	}
}

extension JRBaseController {
	
	func createCIimage() {
		
	}
}

