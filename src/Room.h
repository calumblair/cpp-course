/*
 * Room.h
 *
 *  Created on: 28 Feb 2018
 *      Author: feabhas
 */

#ifndef ROOM_H_
#define ROOM_H_
#include <array>


namespace Home{
class Lamp;

class Room {
private:
	static constexpr unsigned max_lamps{4};
	unsigned int idx {0};
	std::array<Lamp*, max_lamps> lamp_array {{nullptr}} ;
	std::string name;
public:

	void all_on(void);
	void all_off(void);
	void status(void);
	bool add(Lamp& device);
	void set_name(const char* new_name);
	void dim(uint32_t percent);


	Room()=default;
	Room(const char* name);
	virtual ~Room();
};


}

#endif /* ROOM_H_ */
