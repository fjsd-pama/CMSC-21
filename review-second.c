#include <stdio.h>

//int arr[][] -> void
void display2DArray(int rowLen, int colLen, int arr[rowLen][colLen]){
	for (int i = 0; i < rowLen; i++){
		for (int j = 0; j <colLen; i++){
			printf("%d ", arr[i][j]);
			if(j == (colLen - 1)){
				printf("\n");
			}
		}
	}
}


int main(){
	printf("YEHEY! 2D ARRAYS NA TA :D\nThank You, Lord.\nYou are so marvelous.\n");
	int arr1[3][3] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	display2DArray(3, 3, arr1);
	return 0;
}
