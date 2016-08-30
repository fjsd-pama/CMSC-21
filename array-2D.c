#include <stdio.h>
#include <stdbool.h>

//int, int, int arr[][], int, int -> bool
//Determines if if a row and column index (i and j) is at the corner
//of a 2D array
bool isCorner(int rowLen, int colLen, int grid[rowLen][rowLen], int i, int j){
	return ((i == 0 && j == 0) || (i == (rowLen - 1) && j == 0) || (i == 0 && j == (colLen - 1)) || (i == (rowLen - 1) && j == (colLen - 1)));
}

bool isAroundCorner(int rowLen, int colLen, int grid[rowLen][colLen], int i, int j){
	// int ColIndex1 = i + 1;
	// int ColIndex2 = i - 1;
	// int RowIndex1 = j + 1;
	// int RowIndex2 = j - 1;
	if (((i + 1) >= rowLen) && ((j + 1) >= colLen) && ((i - 1) < 0) && ((j - 1) < 0)){
		return false;
	}
	return (isCorner(rowLen, colLen, grid, i + 1, j) ||
		isCorner(rowLen, colLen, grid, i, j + 1) ||
		isCorner(rowLen, colLen, grid, i - 1, j) ||
		isCorner(rowLen, colLen, grid, i, j - 1));
}

int main(){
	int grid1[5][5] = {
		{1, 2, 3, 4, 5},
		{1, 2, 3, 4, 5},
		{1, 2, 3, 4, 5},
		{1, 2, 3, 4, 5},
		{1, 2, 3, 4, 5}
	};
	printf("%d\n", isAroundCorner(5, 5, grid1, 5, 1));
	return 0;
}