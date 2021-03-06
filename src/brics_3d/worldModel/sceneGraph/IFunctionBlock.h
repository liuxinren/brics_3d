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

#ifndef RSG_IFUNCTIONBLOCK_H_
#define RSG_IFUNCTIONBLOCK_H_

#include <vector>
#include <brics_3d/core/ParameterSet.h>
#include <brics_3d/worldModel/WorldModel.h>

namespace brics_3d {

namespace rsg {

/**
 * A function block as it will be used for percetion algorithms within the world model.
 */
class IFunctionBlock {
public:
	IFunctionBlock(brics_3d::WorldModel* wmHandle){
		this->wm = wmHandle;
	};
	virtual ~IFunctionBlock(){};

	virtual void configure(brics_3d::ParameterSet parameters) = 0;

	virtual void setData(std::vector<Id>& inputDataIds) {
		this->inputDataIds = inputDataIds;
	}
	virtual void execute() = 0;

	virtual void getData(std::vector<Id>& newDataIds) {
		newDataIds = this->outputDataIds;
	}


protected:
	/// Handle to the world model that stores all 3D data.
	brics_3d::WorldModel* wm;

	std::vector<Id> inputDataIds;
	std::vector<Id> outputDataIds;

private:
	IFunctionBlock(){};

};

}

}

#endif /* RSG_IFUNCTIONBLOCK_H_ */

/* EOF */
