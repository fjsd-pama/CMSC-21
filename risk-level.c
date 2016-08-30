#include <stdio.h>

//int, int -> int
//Returns the risk level for a person:
//1 - Low, 2 - Medium, 3 - High.

/*stub
int risk_level(int BMI, int age){
    return 0;
}*/


#define BMI_CONSTANT 22.0
#define AGE_CONSTANT 45

/*template
 int risk_level(int BMI, int age){
    return ... BMI_CONSTANT AGE_CONSTANT BMI age;
 }*/

 int risk_level(int BMI, int age){
	if ((BMI >= BMI_CONSTANT) && (age >= AGE_CONSTANT)){
		return 3;
	}else if (((BMI >= BMI_CONSTANT) && (age < AGE_CONSTANT)) || ((BMI < BMI_CONSTANT) && (age >= AGE_CONSTANT))){
		return 2;
    }

    return 1;
}


int main(){
	printf("Your risk level is %d.\n", risk_level(21, 44)); //low
	printf("Your risk level is %d.\n", risk_level(21, 45)); //medium
	printf("Your risk level is %d.\n", risk_level(21, 46)); //medium
	printf("Your risk level is %d.\n", risk_level(22, 44)); //medium
    printf("Your risk level is %d.\n", risk_level(23, 44)); //medium
    printf("Your risk level is %d.\n", risk_level(22, 45)); //high
    printf("Your risk level is %d.\n", risk_level(22, 46)); //high
    printf("Your risk level is %d.\n", risk_level(23, 45)); //high
    printf("Your risk level is %d.\n", risk_level(23, 46)); //high
	return 0;
}