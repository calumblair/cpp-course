/*
 * Dimmablelamp.cpp
 *
 *  Created on: 1 Mar 2018
 *      Author: feabhas
 */

#include "Dimmablelamp.h"

namespace Home {

Dimmable_lamp::Dimmable_lamp() {
	// TODO Auto-generated constructor stub

}

Dimmable_lamp::Dimmable_lamp(HouseCode house_code, int unit_code):
		Lamp { house_code,  unit_code}{
	std::cout<<"Created a new dimmable lamp"<<std::endl;

}

Dimmable_lamp::~Dimmable_lamp() {
	// TODO Auto-generated destructor stub
}

void Dimmable_lamp::dim(uint32_t percent) {
	if (percent>100){
		percent=100;
	}

	if (percent>0){
		Lamp::on();
	}
	else{
        Lamp::off();
	}

	dim_level=percent;
	std::cout<<"The dim level was set to "<<percent<<" for lamp ";
	status();

}

void Dimmable_lamp::on(void){
  dim(100);

}
void Dimmable_lamp::off(void){
  dim(0);
}

void Dimmable_lamp::status() {
	if (is_on()){
			std::cout<<"dimmer level: " <<dim_level <<std::endl;
	}
		Lamp::status();
}

bool Dimmable_lamp::is_on(void) const {
	return (Lamp::is_on() && dim_level>0);
}

} /* namespace Home */
