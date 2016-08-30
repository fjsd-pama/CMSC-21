#include <stdio.h>

//float arr[] -> int
//Determines if an array of floats is sorted from smallest to largest values
int is_sorted(float arr[], int len){
	float base = arr[0];
	for (int i = 0; i < len; i++){
		if (arr[i] < base){
			return 0;
		}
		base = arr[i];
	}

	return 1;
}



int main(){
	float list_1[] = {1.99, 2.0, 3.4, 4.9, 5.3};
    float list_2[] = {2, 2, 3, 4, 5};
    float list_3[] = {2, 2, 1, 4, 3};
    float list_4[] = {2, 2, 2, 2, 2};
    float list_5[] = {4, 2, 3, 4};
    float list_6[] = {1, 8, 3, 5};    
    float list_7[] = {3, 0, 4, 3};
    printf("1 == %d\n", is_sorted(list_1, 5));
    printf("1 == %d\n", is_sorted(list_2, 5));
    printf("0 == %d\n", is_sorted(list_3, 5));
    printf("1 == %d\n", is_sorted(list_4, 5));
    printf("0 == %d\n", is_sorted(list_5, 4));
    printf("0 == %d\n", is_sorted(list_6, 4));
    printf("0 == %d\n", is_sorted(list_7, 4));
	return 0;
}