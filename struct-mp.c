#include <stdio.h>
#include <stdbool.h>

typedef struct{
	int x;
	int y;
} Coord;

//int, int, int, int -> boolean
//Determines if the given rowIndex and colIndex can have a valid neighbor
bool validNeighbor(int rowIndex, int colIndex, int rowLen, int colLen){
	return ((rowIndex + 1) < rowLen) && ((rowIndex - 1) >= 0) && ((colIndex + 1) < colLen) && ((colIndex - 1) >= 0);
}

//int, int, int arr[][], int, int -> Coord
//Finds the coordinates of the nearest queen
Coord nearestOne(int rowLen, int colLen, int map[rowLen][colLen], int currentRow, int currentCol){
	int finalRow = currentRow; //represents final row index, also the x
	int finalCol = currentCol; //represents final col index, also the y
	int x = currentRow;
	int y = currentCol;

	if ((map[x - 1][y] == 1) && ((x - 1) >= 0)){
		finalRow = x - 1;
	} else if ((map[x - 1][y + 1] == 1) && ((x - 1) >= 0) && ((y + 1) < colLen)){
		finalRow = x - 1;
		finalCol = y + 1;
	} else if ((map[x][y + 1] == 1) && ((y + 1) < colLen)){
		finalCol = y + 1;
	} else if ((map[x + 1][y + 1] == 1) && ((x + 1) < rowLen) && ((y + 1) < colLen)){
		finalRow = x + 1;
		finalCol = y + 1;
	} else if ((map[x + 1][y] == 1) && ((x + 1) < rowLen)){
		finalRow = x + 1;
	} else if ((map[x + 1][y - 1] == 1) && ((x + 1) < rowLen) && ((y - 1) >= 0)){
		finalRow = x + 1;
			finalCol = y - 1;
	} else if ((map[x][y + 1] == 1) && ((y + 1) < colLen)){
		finalCol = y - 1;
	} else if ((map[x - 1][y - 1] == 1) && ((x - 1) >= 0) && ((y - 1) >= 0)){
		finalRow = x - 1;
		finalCol = y - 1;
	}

	return (Coord){finalRow, finalCol};
}

Coord finalCoords(int rowLen, int colLen, int map[rowLen][colLen]){
	int finalX = 0;
	int finalY = 0;
	Coord neighbor = nearestOne(rowLen, colLen, map, 0, 0);
	while(map[finalX][finalY] != 0){
		finalX = neighbor.x;
		finalY = neighbor.y;
		neighbor = nearestOne(rowLen, colLen, map, finalX, finalY);
	}

	return (Coord){finalX, finalY};
}

int main(){
	int map1[8][6] = {
		{1, 1, 1, 0, 0, 0},
		{0, 0, 1, 1, 0, 0},
		{0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 1},
		{0, 0, 0, 1, 1, 0},
		{1, 1, 1, 0, 0, 0},
		{0, 1, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0}
	};

	printf("The coordinates are [%d, %d].", finalCoords(8, 6, map1));

	return 0;
}
