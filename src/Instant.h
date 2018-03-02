/*
 * Instant.h
 *
 *  Created on: 28 Feb 2018
 *      Author: feabhas
 */

#ifndef INSTANT_H_
#define INSTANT_H_
#include <cstdint>

namespace Time {

class Instant {
private:
	uint8_t hour {0};
	uint8_t minute {0};
public:
	Instant(uint8_t hour, uint8_t minute);
	void advance(void);
	virtual ~Instant();
	bool is_equal(const Instant& inst)const;
	bool operator==(const Instant& inst) {return is_equal(inst);}
};

} /* namespace Time */

#endif /* INSTANT_H_ */
