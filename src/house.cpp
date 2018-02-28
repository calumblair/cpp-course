//============================================================================
// Name        : house.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "lamp.h"
#include "Room.h"
#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
using namespace Home;

int main() {
	Lamp study{HouseCode::G, 5};
	//study.on();

	Lamp_status( study);

	Room room { "living room"};
	room.add(study);
	room.all_on();
	room.status();
	return 0;
}
