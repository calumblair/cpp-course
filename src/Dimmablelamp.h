/*
 * Dimmablelamp.h
 *
 *  Created on: 1 Mar 2018
 *      Author: feabhas
 */

#ifndef DIMMABLELAMP_H_
#define DIMMABLELAMP_H_

#include "lamp.h"

namespace Home {

class Dimmable_lamp: public  Lamp {
public:
	Dimmable_lamp(HouseCode house_code, int unit_code);
	Dimmable_lamp();
	~Dimmable_lamp();
	void dim(uint32_t percent);
	void on() override;
	void off() override;
	void status() override;
	bool is_on(void)  const  ;
private:
	 uint32_t dim_level{0};
};

} /* namespace Home */

#endif /* DIMMABLELAMP_H_ */
