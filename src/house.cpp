//============================================================================
// Name        : house.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "lamp.h"
#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
using namespace Home;

int main() {


	Lamp default_lamp;
	default_lamp.status();
	Lamp l2{HouseCode::G, 5};

	std::array<Lamp,8> lamps {{
		{ HouseCode::B, 6},
		{ HouseCode::B, 8},
		{ HouseCode::C, 6}
	}};
	lamps[0].on();
	lamps[2].on();

	for(auto& l: lamps)
		l.status();



	l2.status();

	return 0;
}
