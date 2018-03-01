/*
 * Appliance.cpp
 *
 *  Created on: 1 Mar 2018
 *      Author: feabhas
 */

#include "Appliance.h"
using namespace std;
namespace Home {



Appliance::Appliance(HouseCode house_code, int unit_code):
						Module {house_code, unit_code}
{
	std::cout<<"Constructing an Appliance: ";
	status();
}

Appliance::~Appliance(){
	cout<<"Destroying an appliance ";
	status();
}


void Appliance::on (void){
state=true;
cout<<"Appliance turned on ";
status();


}
void Appliance::off (void){
	state=false;
	cout<<"Appliance turned off ";
	status();

}
} /*
namespace Home */
