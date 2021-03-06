/******************************************************************************
* BRICS_3D - 3D Perception and Modeling Library
* Copyright (c) 2011, GPS GmbH
*
* Author: Sebastian Blumenthal
*
*
* This software is published under a dual-license: GNU Lesser General Public
* License LGPL 2.1 and Modified BSD license. The dual-license implies that
* users of this code may choose which terms they prefer.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU Lesser General Public License LGPL and the BSD license for
* more details.
*
******************************************************************************/

// PCL includes for kinect interface
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/openni_grabber.h>

// BRICS_3D includes
#include <brics_3d/core/PointCloud3D.h>
#include <brics_3d/core/Logger.h>
#include <brics_3d/util/PCLTypecaster.h>
#include <brics_3d/util/OSGPointCloudVisualizer.h>

using brics_3d::Logger;

//typedef pcl::PointXYZ PointType;
typedef pcl::PointXYZRGB PointType;


/**
 * Example class to visualize a point cloud captured from a Kinect camera
 */
class KinectTest {
public:
	KinectTest(){
		count = 0;
		brics_3d::Logger::setMinLoglevel(brics_3d::Logger::LOGDEBUG);
	}

	/**
	 * Function to be executed on arrival of a new point cloud from the sensor.
	 * @param cloud The point cloud data.
	 */
	void callback (const pcl::PointCloud<PointType>::ConstPtr &cloud)
	{
//		if (count > 2) {
		if (viewer.done()) {
			LOG(INFO) <<  "Done.";
			interface->stop();
			return;
		}

		LOG(INFO) <<  "Receiving new point cloud.";
		brics_3d::PointCloud3D* viewerCloud = new brics_3d::PointCloud3D();
		converter.convertToBRICS3DDataType(cloud, viewerCloud, true); // the bool toggles if color information will be copoied over to BRICS_3D type or not
//		std::string name = "kinect_pointcloud.txt";
//		viewerCloud->storeToTxtFile(name);
//		viewer.addPointCloud(viewerCloud);
		viewer.addColoredPointCloud(viewerCloud);
		viewer.clearButLast();
		delete viewerCloud;
		count++;
	}

	/**
	 * Start the capturing.
	 */
	void run () {
	    interface = new pcl::OpenNIGrabber();
	    boost::function<void (const pcl::PointCloud<PointType>::ConstPtr&)> f = boost::bind (&KinectTest::callback, this, _1);
	    interface->registerCallback (f);
	    interface->start ();
	}

	/// Kinect interface
	pcl::Grabber* interface;

	/// Helper tool to convert point clouds
	brics_3d::PCLTypecaster converter;

	/// A simple viwer
	brics_3d::OSGPointCloudVisualizer viewer;

	/// For stats & debugging
	int count;

};


int main(int argc, char **argv) {

	KinectTest kinectTest;
	kinectTest.run();

    while (!kinectTest.viewer.done()) // Wait until GUI is closed.
    {
      sleep (1);
    }

}



/* EOF */
