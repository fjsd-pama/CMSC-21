#include <stdio.h>
#include <string.h>


// 1
int multipleOf3and5(int n){
	int num = n;
	while (((num % 3 != 0) || (num % 5 != 0)) || (num < 0)){
		num --;
	}
	return num;
}


// 2
int str_equal(char strA[], char strB[]){
	if (strlen(strA) != strlen(strB)){
		return 0;
	}
	
	for (int i = 0; strA[i] != '\0'; i++){
		if (strA[i] != strB[i]){
			return 0;
		}
	}
	
	return 1;
}

// 3
int in_array(int arr[], int length, int n){
	for (int i = 0; i < length; i++){
		if (arr[i] == n){
			return 1;
		}
	}
	return 0;
}



// 4
int sumOfCubes(int n){
	int sum = 0;
	for (int i = 0; i <= n; i++){
		sum += (i * i * i);
	}
	return sum;
}


// 5

int in(float arr[], int length, int n){
	for (int i = 0; i < length; i++){
		if (arr[i] == n){
			return 1;
		}
	}
	return 0;
}



int all_present(float arr1[], int len1, float arr2[], int len2) {
	for (int i = 0; i < len1; i++) {
		int found = 0;
		for (int j = 0; j < len2; j++) {
			if (arr1[i] == arr2[j]) {
				found = 1;
			}
		}

		if (found != 1) {
		    return 0;
	    }
	}
	return 1;
}


int main(){
	printf("test for multipleOf3and5\n");
	printf("15 == %d\n", multipleOf3and5(15));
	printf("15 == %d\n", multipleOf3and5(16));
	printf("0 == %d\n", multipleOf3and5(9));
	printf("test for str_equal\n");
	printf("0 == %d\n", str_equal("this", "that"));
	printf("1 == %d\n", str_equal("this", "this"));
	printf("0 == %d\n", str_equal("this", "this is it"));
	printf("test for in_array\n");
	int arr1[] = {1, 4, 5};
	printf("1 == %d\n", in_array(arr1, 3, 5));
	printf("0 == %d\n", in_array(arr1, 3, 3));
	printf("test for sumOfCubes\n");
	printf("36 == %d\n", sumOfCubes(3));
	printf("test for all_present\n");
	float arrA[] = {1.0, 2.0, 3.0};
	float arrB[] = {7.0, 9.0, 1.0, 5.0, 2.0, 3.0};
	float arrC[] = {1.0, 4.0, 3.0};
	float arrD[] = {2.0, 1.0, 3.0, 2.0};
	printf("0 == %d\n", all_present(arrB, 6, arrC, 3));
	printf("1 == %d\n", all_present(arrA, 3, arrB, 6));
	printf("0 == %d\n", all_present(arrC, 3,  arrA, 6));
	printf("1 == %d\n", all_present(arrD, 4, arrA, 3));
	// printf("0 == %d\n", all_present(arrB, arrC));
	// printf("1 == %d\n", all_present(arrA, arrB));
	// printf("0 == %d\n", all_present(arrC, arrA));
	// printf("1 == %d\n", all_present(arrD, arrA));
	return 0;
}

