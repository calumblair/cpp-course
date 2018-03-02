/*
 * Instant.cpp
 *
 *  Created on: 28 Feb 2018
 *      Author: feabhas
 */

#include "Instant.h"
#include <iostream>

namespace Time {

Instant::Instant(uint8_t new_hour, uint8_t new_minute)
{

	if (new_hour<24 && new_hour>=0 && new_minute<60 && new_minute>=0 ){
			hour =new_hour;
			minute=new_minute;
	}
	else{
		std::cout<<"Time is set to 00:00"<<std::endl;
	}

}

Instant::~Instant() {
	// TODO Auto-generated destructor stub
}

bool Instant::is_equal(const Instant& inst) const{

	if( inst.hour == hour && inst.minute==minute){
		return true;
	}
	else{
		return false;
	}
}
void Instant::advance(){
	minute++;
	if (minute == 60){
		minute = 0;
		hour++;
		if(hour == 24){
			hour = 0;
		}
	}
	std::cout<< "tick " << (int) hour <<":" << (int) minute <<std::endl;
}
} /* namespace Time */
