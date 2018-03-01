/*
 * Iswitchable.h
 *
 *  Created on: 1 Mar 2018
 *      Author: feabhas
 */

#ifndef ISWITCHABLE_H_
#define ISWITCHABLE_H_

namespace Home {

class I_switchable {
public:
	virtual void on(void) =0;
	virtual void off(void) =0;
	virtual bool is_on(void)  const =0;

	virtual ~I_switchable()=default;
};

} /* namespace Home */

#endif /* ISWITCHABLE_H_ */
