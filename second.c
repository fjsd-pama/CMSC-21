#include <stdio.h>

typedef struct{
	int red;
	int blue;
	int green;
} Pixel;

//int, int, int arr[][], int -> int
//Calculates the sum of a specified row index
int rowSum(int rowLen, int colLen, int grid[rowLen][colLen], int rowIndex) {
    int sum = 0;
    for (int i = 0; i < colLen; i++){
        sum += grid[rowIndex][i];
    }
    
    return sum;

}

//int, int, Pixel arr[][] -> void
//Converts an image to grayscale
void toGrayscale(int rowLen, int colLen, Pixel img[rowLen][colLen]){
	float row_sum = 0;
	for (int i = 0; i < rowLen; i++){
		row_sum = rowSum(rowLen, colLen, img[0].red);
	}
}


