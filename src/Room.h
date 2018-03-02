/*
 * Room.h
 *
 *  Created on: 28 Feb 2018
 *      Author: feabhas
 */

#ifndef ROOM_H_
#define ROOM_H_
#include <vector>
#include <string>

namespace Home{
class I_switchable;

class Room {
private:
	static constexpr unsigned initial_switches{4};
	std::vector<I_switchable*> switches {{nullptr}} ;
	std::string name;
public:

	void all_on(void);
	void all_off(void);
	void status(void);
	bool add(I_switchable& device);
	void set_name(const char* new_name);
	void dim(uint32_t percent);


	Room()=default;
	Room(const char* name);
	virtual ~Room();
};


}

#endif /* ROOM_H_ */
