/** @file kinect_grabber.h
 *
 * implementation - Kinect Grabber
 *
 */

#ifndef KINECT_GRABBER_H_INCLUDED
#define KINECT_GRABBER_H_INCLUDED

#include "grabber.h"
#include <memory>
#include <iostream>
#include <string>
#include <sstream>

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/io/openni_grabber.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/point_cloud.h>
#include <pcl/filters/filter.h>

namespace handest {
	/// create a single grabber (Kinect)
	Grabber* createGrabberKinect(void);
};

using namespace handest;

/// Grabber implementation
class KinectGrabber : public Grabber {
    public:
	/// Pointer
	typedef std::unique_ptr<KinectGrabber> Ptr;

	/// Construction
	KinectGrabber(void);

	/// Name of the grabber
    const std::string& getName() const;

      /// grabs a single cloud from kinect
    void run();

	/// Returns the current point cloud
    void getCloud(Point3D::Cloud& current_cloud) const;

	/// load point cloud from file
    void LoadFromFile(std::string path);

    private:
    /// callback function
    void cloud_cb_ (const pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr &cloud);
    /// needed when loading several clouds
    int frame_no;
	///output from run() and LoadFromFile()
    pcl::PointCloud<pcl::PointXYZRGBA> cloud_temp; 
	/// RGBZXYZ Point cloud
    Point3D::Cloud cloud_3D;
	/// Grabber name
	const std::string name;
};

#endif // KINECT_GRABBER_H_INCLUDED
