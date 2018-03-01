/*
 * lamp.h
 *
 *  Created on: 26 Feb 2018
 *      Author: feabhas
 */


#ifndef LAMP_H_
#define LAMP_H_
#include <iostream>
#include <utility>
#include <array>
#include "Module.h"


namespace Home{

class Lamp: public Module{
	public:
		Lamp()=default;
		Lamp( HouseCode house_code, int unit_code);
		~Lamp();

		virtual void on(void);
		virtual void off(void);
	};


}
#endif /* LAMP_H_ */
