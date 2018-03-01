/*
 * Appliance.h
 *
 *  Created on: 1 Mar 2018
 *      Author: feabhas
 */

#ifndef APPLIANCE_H_
#define APPLIANCE_H_

#include "Module.h"

namespace Home {

class Appliance: public Module {
public:

	Appliance()=default;
	Appliance( HouseCode house_code, int unit_code);
	~Appliance();

	virtual void on(void) override;
	virtual void off(void);
};

} /* namespace Home */

#endif /* APPLIANCE_H_ */
