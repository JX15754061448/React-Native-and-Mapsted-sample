//
//  MapsViewController.swift
//  SampleObjC
//
//  Created by Parth Bhatt on 07/12/23.
//

import UIKit
import MapstedCore
import MapstedMap
import MapstedMapUi


class MapsViewController: UIViewController {
    
    @IBOutlet weak var containerView: UIView!
    @IBOutlet weak var spinnerView: UIActivityIndicatorView!
    
    var mapViewController = MNMapViewController()
    
    //MARK: - View Lifecycle Methods

    override func viewDidLoad() {
        super.viewDidLoad()
        self.navigationController?.navigationBar.tintColor = .white
        self.view.backgroundColor = .gray
        self.showSpinner()
        // Do any additional setup after loading the view.
        if CoreApi.hasInit() {
            self.onSuccess()
        }
        else {
            MapstedMapApi.shared.setUp(prefetchProperties: false, callback: self)
        }
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        MapstedMapApi.shared.removeProperty(propertyId: 504)
        MapstedMapApi.shared.unloadMapResources()
        CoreApi.PropertyManager.unload(propertyId:504, listener: self)
    }
    
    //MARK: - Setup UI
    
    func setupUI() {
        //Whether or not you want to show compass
        MapstedMapMeta.showCompass = true
        
        //UI Stuff
        addChild(mapViewController)
        mapViewController.view.translatesAutoresizingMaskIntoConstraints = false
        self.containerView.addSubview(mapViewController.view)
        addParentsConstraints(view: mapViewController.view)
        mapViewController.didMove(toParent: self)
        self.startDownload(propertyId: 504)
    }
    
    func addParentsConstraints(view: UIView?) {
        guard let superview = view?.superview else {
            return
        }
        
        guard let view = view else {return}
        
        view.translatesAutoresizingMaskIntoConstraints = false
        
        let viewDict: [String: Any] = Dictionary(dictionaryLiteral: ("self", view))
        let horizontalLayout = NSLayoutConstraint.constraints(
            withVisualFormat: "|[self]|", options: NSLayoutConstraint.FormatOptions.directionLeadingToTrailing, metrics: nil, views: viewDict)
        let verticalLayout = NSLayoutConstraint.constraints(
            withVisualFormat: "V:|[self]|", options: NSLayoutConstraint.FormatOptions.directionLeadingToTrailing, metrics: nil, views: viewDict)
        superview.addConstraints(horizontalLayout)
        superview.addConstraints(verticalLayout)
    }
    
    //MARK: - Download and Draw Property Methods
    
    func startDownload(propertyId: Int) {
        CoreApi.PropertyManager.startDownload(propertyId: propertyId, propertyDownloadListener: self)
    }
    
    func drawProperty(propertyId: Int, completion: @escaping (() -> Void)) {
        
        guard let propertyData = CoreApi.PropertyManager.getCached(propertyId: propertyId) else {
            print("No property Data")
            self.hideSpinner()
            return
        }
        DispatchQueue.main.async {
            MapstedMapApi.shared.drawProperty(isSelected: true, propertyData: propertyData)
            if let propertyInfo = PropertyInfo(propertyId: propertyId) {
                MapstedMapApi.shared.mapView()?.moveToLocation(mercator: propertyInfo.getCentroid(), zoom: 18, duration: 0.2)
                completion();
            }
            self.hideSpinner()
        }
    }
    
    //MARK: - Show & Hide Spinner
    
        //Start progress indicator
    func showSpinner() {
        DispatchQueue.main.async {
            self.spinnerView?.startAnimating()
        }
    }
    
        //Stop progress indicator
    func hideSpinner() {
        DispatchQueue.main.async {
            self.spinnerView?.stopAnimating()
        }
    }
}

//MARK: - Core Init Callback Methods

extension MapsViewController: CoreInitCallback {
    func onSuccess() {
        print("onSuccess called")
        DispatchQueue.main.async {
            let propertyInfos = CoreApi.PropertyManager.getAll()
            for propertyInfo in propertyInfos {
                print("propertyInfo - name - \(propertyInfo.displayName) - Id: \(propertyInfo.propertyId)")
            }
            self.setupUI()
        }
    }
    
    func onFailure(errorCode: EnumSdkError) {
        print("onFailure errorCode: \(errorCode)")
    }
    
    func onStatusUpdate(update: EnumSdkUpdate) {
        print("onStatusUpdate update: \(update)")
    }
    
    func onStatusMessage(messageType: MapstedCore.StatusMessageType) {
        print("onStatusMessage messageType: \(messageType)")
    }
}

//MARK: - Property Download Listener Methods

extension MapsViewController: PropertyDownloadListener {
    func onSuccess(propertyId: Int) {
        self.drawProperty(propertyId: propertyId, completion: {
            //self.findEntityByName(name: "ar", propertyId: propertyId)
        })
    }
    
    func onSuccess(propertyId: Int, buildingId: Int) {
        
    }
    
    func onFailureWithProperty(propertyId: Int) {
        
    }
    
    func onFailureWithBuilding(propertyId: Int, buildingId: Int) {
        
    }
    
    func onProgress(propertyId: Int, percentage: Float) {
        
    }
}

//MARK: - Property Action Complete Listener Methods

extension MapsViewController : PropertyActionCompleteListener {
    func completed(action: MapstedCore.PropertyAction, propertyId: Int, sucessfully: Bool, error: Error?) {
        print("Property: \(propertyId) Unloaded successfully: \(sucessfully)")
    }
}
