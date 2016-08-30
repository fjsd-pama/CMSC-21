#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//int arr[][] -> void
//Displays the given matrix
void display2DArray(int rowLen, int colLen, int matrix[rowLen][colLen]){
	for (int i = 0; i < rowLen; i++){
		for (int j = 0; j < colLen; j++){
			printf("%d ", matrix[i][j]);
			if(j == (colLen - 1)){
				printf("\n");
			}
		}
	}
	printf("\n");
}

typedef struct{
	int rowLen;
	int colLen;
} RowCol;

//int, int, int arr[][], int, int, int arr[][] -> void
//Adds two matrices
void addTwoMatrices(int rowLen1, int colLen1, int matrix1[rowLen1][colLen1], int rowLen2, int colLen2, int matrix2[rowLen2][colLen2]){
	if((rowLen1 == rowLen2) && (colLen1 == colLen2)){
		for (int i = 0; i < rowLen1; i++){
			for (int j = 0; j < colLen1; j++){
				matrix1[i][j] = (matrix1[i][j] + matrix2[i][j]);
			}
		}
	}
}

//int, int, int arr[][], int, int, int arr[][] -> boolean
//Determines if two 2D arrays are equal
bool areEqual(int rowLen1, int colLen1, int matrix1[rowLen1][colLen1], int rowLen2, int colLen2, int matrix2[rowLen2][colLen2]){
	if ((rowLen1 == rowLen2) && (colLen1 == colLen2)){
		for (int i = 0; i < rowLen1; i++){
			for (int j = 0; j < colLen1; j++){
				if (matrix1[i][j] != matrix2[i][j]){
					return false;
				}
			}
		}
		return true;
	}
	return false;
}

//int, int, int arr[][]
//Determines if the given matrix is sorted from least to greatest
bool isFromLeastToGreatest(int rowLen, int colLen, int arr[rowLen][colLen]){
	int currentMin = arr[0][0];
	for (int i = 0; i < rowLen; i++){
		for (int j = 0; j < colLen; j++){
			if (arr[i][j] < currentMin){
				return false;
			}
			currentMin = arr[i][j];
		}
	}
	return true;
}

typedef struct{
	int numerator;
	int denominator;
} Fraction;

//float -> Fraction
//Converts a given decimal n to a fraction
/*Fraction toFraction(float n){
	int sth = n; //the integer counterpart of n
	int decimalPart = n - sth;
	if(decimalPart == 0){
		Fraction result = {n, 1};
		return toLowestTerm(result);
	}

	int ten = 10;
	int numerator = decimalPart;
	while(decimalPart != 0){
		decimalPart = (ten * n);
		numerator = (d)
		ten *= 10;

	}
	Fraction result = {(n * ten), ten};
	return toLowestTerm(result);
}*/

/*Fraction toFraction(float n){
	int sth = n; //the integer counterpart of n
	int decimalPart = n - sth;
	if(decimalPart == 0){
		Fraction result = {n, 1};
		// return toLowestTerm(result);
	}

	return(Fraction){(((sth - decimalPart) * pow(10, 10)) + (decimalPart * pow(10, 10))), pow(10, 10)};
}*/


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

Fraction toLowestTerm(Fraction f){
	int gcf_factor = gcf(f.numerator, f.denominator);
	if (gcf_factor != 0){
		f.numerator /= gcf_factor;
		f.denominator /= gcf_factor;
	}

	return (Fraction){f.numerator, f.denominator};
}


Fraction toFraction(float n){
	int num = n;
	// int decimalPart = n - num;
	int ten = 10;
	float sth = n / ten;
	while (sth != 0){
		ten *= 10;
		sth = sth / ten;
	}

	Fraction fractn = {((num * 10) + (sth * ten)), ten};
	Fraction result = toLowestTerm(fractn);
	return (Fraction){result.numerator, result.denominator};
}



int main(){
	printf("YEHEY! 2D ARRAYS NA TA :D\nThank You, Lord.\nYou are so marvelous.\n");
	int matrix1[4][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};

	RowCol one = {4, 4};
	RowCol two = {4, 4};
	RowCol three = {4, 4};

	int matrix2[4][4] = {
		{1, 1, 1, 1},
		{1, 1, 1, 1},
		{1, 1, 1, 1},
		{1, 1, 1, 1}
	};

	int matrix3[4][4] = {
		{1, 2, 3, 4},
		{1, 2, 3, 4},
		{1, 2, 3, 4},
		{1, 2, 3, 4}
	};

	display2DArray(3, 3, matrix1);
	// addTwoMatrices(one.rowLen, one.colLen, matrix1, two.rowLen, two.colLen, matrix2);
	// display2DArray(one.rowLen, one.colLen, matrix1);
	// addTwoMatrices(two.rowLen, two.colLen, matrix2, three.rowLen, three.colLen, matrix3);
	// display2DArray(two.rowLen, two.colLen, matrix2);
	// addTwoMatrices(three.rowLen, three.colLen, matrix3, one.rowLen, one.colLen, matrix1);
	// display2DArray(three.rowLen, three.colLen, matrix3);
	printf("%d\n", areEqual(4, 4, matrix2, 5, 4, matrix2));
	printf("%d\n", isFromLeastToGreatest(4, 4, matrix1));
	printf("%d/%d\n", toFraction(12.76));
	return 0;
}