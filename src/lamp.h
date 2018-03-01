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

class Lamp{
	private:
		DeviceCode device {HouseCode::INVALID, 0};
		bool state {false};

	public:
		Lamp()=default;
		Lamp( HouseCode house_code, int unit_code);
		~Lamp();
		void set_id(DeviceCode);
		DeviceCode id(void);
		virtual void on(void);
		virtual void off(void);
		virtual bool is_on(void)  const;
		virtual void status(void);
	};

using Lamp_Array=std::array<Lamp,10>;

Lamp Make_lamp(void);
void Lamp_array_on(Lamp_Array& lamp_array);
void Lamp_array_off(Lamp_Array& lamp_array);

void Lamp_status(Lamp* lmp);
void Lamp_status(const Lamp& lmp);


}
#endif /* LAMP_H_ */
