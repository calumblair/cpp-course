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

using Lamp_Array=std::array<Lamp,10>;

Lamp Make_lamp(void);
void Lamp_array_on(Lamp_Array& lamp_array);
void Lamp_array_off(Lamp_Array& lamp_array);

void Lamp_status(Lamp* lmp);
void Lamp_status(const Lamp& lmp);


}
#endif /* LAMP_H_ */
