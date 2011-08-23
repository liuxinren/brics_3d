/*
 * @file: SACMethodALMeDS.h
 *
 * @date: Apr 21, 2011
 * @author: reon
 */

#ifndef SACMETHODALMEDS_H_
#define SACMETHODALMEDS_H_

#include "ISACMethods.h"


namespace BRICS_3D {
//ToDo add reference to the method
class SACMethodALMeDS : public ISACMethods {

public:

	SACMethodALMeDS();
	bool computeModel ();
	virtual ~SACMethodALMeDS();
};

}

#endif /* SACMETHODALMEDS_H_ */
