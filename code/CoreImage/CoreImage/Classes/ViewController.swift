//
//  ViewController.swift
//  CoreImage
//
//  Created by 王潇 on 2017/1/10.
//  Copyright © 2017年 王潇. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

	var tableView : UITableView?

	var dataSource : [[String : String]]?
	
	override func viewDidLoad() {
		super.viewDidLoad()
		
		/// 设置标题
		title = "😋Core Image😏"
		
		/// 数据源
		dataSource = [["title" : "CoreImage", "controller" : "JRBaseController"],
		              ["title" : "Test 😆", "controller" : "JRTestViewController"]];

		/// tableView
		tableView = UITableView(frame: view.frame, style: .grouped)
		tableView?.delegate		= self
		tableView?.dataSource	= self
		tableView?.rowHeight	= 55
		tableView?.register(UITableViewCell.self, forCellReuseIdentifier: "cell")
		view.addSubview(tableView!)
	}
}

// MARK: - UITableViewDataSource, UITableViewDelegate
extension ViewController : UITableViewDataSource, UITableViewDelegate {
	
	func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
		return dataSource?.count ?? 0
	}
	
	func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
		let cell = tableView.dequeueReusableCell(withIdentifier: "cell")
		let dic  = dataSource?[indexPath.row]
		cell?.textLabel?.text = dic?["title"]
		return cell!
	}
	
	func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
		tableView.deselectRow(at: indexPath, animated: true)

		let dic		= dataSource?[indexPath.row]
		let viewVC	= getClassWithName2(clsName: dic?["controller"])
		self.navigationController?.pushViewController(viewVC, animated: true)
	}
}

// MARK: - Private Methond
extension ViewController {
	
	/// 根据类名实例化对象
	///
	/// - Parameter clsName: 控制器名称
	/// - Returns: 控制器对象
	func getClassWithName2(clsName: String?) -> UIViewController{
		
		guard
			/// Initializer for conditional binding must have Optional type, not 'String'
			let clsName = clsName
			else {
				return UIViewController()
		}
		
		/// 获取命名空间
		let spaceName = Bundle.main.infoDictionary?["CFBundleName"] as! String
		/// 获取空控制器名
		let className = spaceName + "." + clsName
		/// 创建控制器
		let vc = NSClassFromString(className) as! UIViewController.Type
		let viewVC = vc.init()
		
		return viewVC
	}
	
}


