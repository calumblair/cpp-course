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


namespace Home{
enum class HouseCode: unsigned char{
	INVALID = 0, A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P
};

using DeviceCode = std::pair <HouseCode, int>;
struct Lamp{
	DeviceCode device;
	bool state;
};

using Lamp_Array=std::array<Lamp,10>;

void Lamp_on(Lamp& lamp);
void Lamp_off(Lamp& lamp);
Lamp Make_lamp(void);
void PrintLamp(const Lamp& lamp);
void Lamp_array_on(Lamp_Array& lamp_array);
void Lamp_array_off(Lamp_Array& lamp_array);
bool is_lamp_on(const Lamp& lamp);

}
#endif /* LAMP_H_ */
