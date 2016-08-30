#include <stdio.h>

//float, float -> int
//Determines whether the camera should be switched on given
//the light level and temperature

/*stub
int cameraSwitchOn(float lux, float temp){
	return 0;
}*/

#define LUX 0.0100
#define FREEZING_PT 0.000

/*template
int cameraSwitchOn(float light_level, float temp){
	return ... LUX FREEZING_PT light_level temp;
}*/


int cameraSwitchOn(float light_level, float temp){
	return ((light_level < LUX) != (temp > FREEZING_PT));
}


int main(){
	printf("1 == %d\n", cameraSwitchOn(0.0, 0.0));
	printf("0 == %d\n", cameraSwitchOn(0.001, 1.0));
	printf("1 == %d\n", cameraSwitchOn(0.001, 0.0));
	printf("1 == %d\n", cameraSwitchOn(0.001, -1.0));
	printf("1 == %d\n", cameraSwitchOn(0.02, 1.0));
	printf("0 == %d\n", cameraSwitchOn(0.02, 0.0));
	printf("0 == %d\n", cameraSwitchOn(0.02, -1.0));
	printf("1 == %d\n", cameraSwitchOn(0.01, 1.0));
	printf("0 == %d\n", cameraSwitchOn(0.01, 0.0));
	printf("0 == %d\n", cameraSwitchOn(0.01, -1.0));
	return 0;
}