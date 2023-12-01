	//
	//  MapViewController.swift
	//  Sample
	//
	//  Created by Daniel on 2021-12-09.
	//  Copyright © 2021 Mapsted. All rights reserved.
	//

import UIKit
//import MapstedCore
//import MapstedMap

@objc class MapViewController : UIViewController {
	
  public override func viewDidLoad() {
    super.viewDidLoad()
    let width = UIScreen.main.bounds.width;
    let height = UIScreen.main.bounds.height;
    let mapView = RCNMapViewTest(frame: CGRect(x: 0, y: 0, width: 320, height: 700));
    
    view.addSubview(mapView);
  }
}
