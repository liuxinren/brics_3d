/******************************************************************************
* BRICS_3D - 3D Perception and Modeling Library
* Copyright (c) 2011, GPS GmbH
*
* Author: Pinaki Sunil Banerjee
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

#ifndef BRICS_3D_IOBJECTMODELUSINGNORMALS_H_
#define BRICS_3D_IOBJECTMODELUSINGNORMALS_H_
#include <vector>
#include "brics_3d/algorithm/segmentation/objectModels/IObjectModel.h"
#include "brics_3d/core/NormalSet3D.h"
//using namespace std;
namespace brics_3d {


/**
 * @ingroup segmentation
 */
class IObjectModelUsingNormals : public IObjectModel{


protected:

	/** @brief The relative weight (between 0 and 1) to  corresponding to
	 * angular distance between point normals and the plane normal. 0 corresponds to 0 rad and
	 * 1 corresponds to pi/2 rad */
	double normalDistanceWeight;

	/** @brief A pointer to vector of normals. */
	NormalSet3D *normals;

	/** @brief Axis along which we need to search for a model perpendicular to */
	Eigen::Vector3d axis;

	/** @brief The maximum angle between the model normal and the given axis */
	double epsAngle;

public:

	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	IObjectModelUsingNormals(){};
	virtual ~IObjectModelUsingNormals(){};


	/** @brief Set the angle epsilon (delta) threshold.
	 *  @param epAngle the maximum allowed difference between the model normal and the given axis.
	 */
	inline void
	setEpsAngle (double epAngle)
	{
		this->epsAngle = epAngle;
	}


	/** @brief Get the angle threshold between the given axis and the model-normal. */
	inline double
	getEpsAngle ()
	{
		return (this->epsAngle);
	}


	/** @brief Set the pointer to the normal-set for the corresponding input point cloud
	 *  @param normalSet Pointer to brics_3d::NormalSet3D
	 */
	inline void
	setInputNormals (NormalSet3D *normalSet)
	{
		this->normals = normalSet;
	}


	/** @brief Get a pointer to brics_3d::NOrmalSet3D for input point cloud being segmented
	 *  @return Pointer to brics_3d::NormalSet3D
	 * */
	inline NormalSet3D*
	getInputNormals ()
	{
		return (this->normals);
	}


	/** @brief Set the relative weight variable indicating the angular distance
	 * between point normals and the plane normal.
	 *  @param distanceWeight the distance/angular weight between 0 and 1
	 */
	inline void
	setNormalDistanceWeight (double distanceWeight)
	{
		this->normalDistanceWeight = distanceWeight;
	}


	/** @brief Get the relative weight variable indicating the angular distance
	 * between point normals and the plane normal. */
	inline double
	getNormalDistanceWeight ()
	{
		return (this->normalDistanceWeight);
	}


	/** @brief Set the axis along which we need to search for a model perpendicular to.
	 *  @param axis the axis perpendicular to which the model parameters will be searched for
	 */
	inline void
	setAxis (const Eigen::Vector3d &axis)
	{
		this->axis = axis;
	}


	/** @brief Get the axis along which we need to search for a model perpendicular to. */
	inline Eigen::Vector3d
	getAxis ()
	{
		return (this->axis);
	}



};

}

#endif /* BRICS_3D_IOBJECTMODELUSINGNORMALS_H_ */
