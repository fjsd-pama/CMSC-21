#include <stdio.h>
#include <stdbool.h>

//int, int -> int
//Returns the maximum number given two numbers
int maxOf2(int num1, int num2){
	if (num1 > num2){
		return num1;
	}

	return num2;
}

//int, int -> int
//Returns the greatest common factor of two numbers
//Returns 0 if two numbers have no gcf
int gcf(int num1, int num2){
	int gcf_factor = 0;
	int max_num = maxOf2(num1, num2);
	for (int i = 2; i <= max_num; i++){
		if ((num1 % i == 0 && num2 % i == 0) && i > gcf_factor){
			gcf_factor = i;
		}
	}
	return gcf_factor;
}

typedef struct{
	int numerator;
	int denominator;
} Fraction;

Fraction toLowestTerm(Fraction f){
	int gcf_factor = gcf(f.numerator, f.denominator);
	if (gcf_factor != 0){
		f.numerator /= gcf_factor;
		f.denominator /= gcf_factor;
	}

	return (Fraction){f.numerator, f.denominator};
}

int LCM(int num1, int num2){
	int max_num = maxOf2(num1, num2);
	for (int i = 2; i <= max_num; i++){
		if ((i % num1 == 0 && i % num2 == 0)){
			return i;
		}
	}
	return (num1 * num2);
}

//number 2
Fraction addTwoFraction(Fraction f1, Fraction f2){
	int lcm = LCM(f1.denominator, f2.denominator);
	int numerator = ((lcm / f1.denominator) * f1.numerator) + ((lcm / f2.denominator) * f2.numerator);
	Fraction fractn = {numerator, lcm};
	Fraction result = toLowestTerm(fractn);

	return (Fraction){result.numerator, result.denominator};
}


//number 3
Fraction subtractTwoFraction(Fraction f1, Fraction f2){
	int lcm = LCM(f1.denominator, f2.denominator);
	int numerator = ((lcm / f1.denominator) * f1.numerator) - ((lcm / f2.denominator) * f2.numerator);
	Fraction fractn = {numerator, lcm};
	Fraction result = toLowestTerm(fractn);

	return (Fraction){result.numerator, result.denominator};
}

//number 4
Fraction multiplyTwoFraction(Fraction f1, Fraction f2){
	int numerator = f1.numerator * f2.numerator;
	int denominator = f1.denominator * f2.denominator;
	Fraction fractn = {numerator, denominator};
	Fraction result = toLowestTerm(fractn);

	return (Fraction){result.numerator, result.denominator};
}

//number 5
Fraction divideTwoFraction(Fraction f1, Fraction f2){
	int numerator = f1.numerator * f2.denominator;
	int denominator = f1.denominator * f2.numerator;
	Fraction fractn = {numerator, denominator};
	Fraction result = toLowestTerm(fractn);

	return (Fraction){result.numerator, result.denominator};
}



int main(){
	Fraction one;
	one.numerator = 8;
	one.denominator = 24;

	Fraction two;
	two.numerator = 7;
	two.denominator = 6;

	Fraction three;
	three.numerator = 15;
	three.denominator = 30;

	printf("%d/%d\n", toLowestTerm(three));
	printf("%d/%d\n", addTwoFraction(three, two));
	printf("%d/%d\n", subtractTwoFraction(three, two));
	printf("%d/%d\n", multiplyTwoFraction(three, two));
	printf("%d/%d\n", divideTwoFraction(three, two));
	printf("%d\n", LCM(6, 30));
	return 0;
}