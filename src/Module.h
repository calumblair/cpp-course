/*
 * Module.h
 *
 *  Created on: 1 Mar 2018
 *      Author: feabhas
 */

#ifndef MODULE_H_
#define MODULE_H_
#include <iostream>
#include <utility>
#include <array>
#include "Iswitchable.h"

namespace Home {

enum class HouseCode: unsigned char{
	INVALID = 0, A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P
};

using DeviceCode = std::pair <HouseCode, int>;

class Module: public I_switchable {
private:
	DeviceCode device {HouseCode::INVALID, 0};

protected:
	bool state {false};
	bool is_on(void)  const;

public:
	Module()=default;
	Module( HouseCode house_code, int unit_code);
	virtual ~Module();
	void set_id(DeviceCode);
	DeviceCode id(void) ;
	virtual void status(void);

};

} /* namespace Home */

#endif /* MODULE_H_ */
