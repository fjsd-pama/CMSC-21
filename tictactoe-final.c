#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COL 3

//int, int, int arr[][], int -> int
//Calculates the the sum of a specified row
int rowSum(int rowLen, int colLen, int grid[rowLen][colLen], int rowIndex) {
    int sum = 0;
    for (int i = 0; i < colLen; i++){
        sum += grid[rowIndex][i];
    }
    
    return sum;

}

//int, int, int arr[][], int -> int
//Calculates the sum of a specified column
int colSum(int grid_size_rows, int grid_size_cols, int grid[grid_size_rows][grid_size_cols], int colIndex) {
    int sum = 0;
    for (int i = 0; i < grid_size_rows; i++){
        sum += grid[i][colIndex];
    }
    
    return sum;

}

//int, int, int arr[][] -> int
//Calculates the sum of the top-left-to-bottom-right diagonal
int TLBRDiagonalSum(int rowLen, int colLen, int board[rowLen][colLen]){
	int diagSum = 0;
	for (int i = 0; i < rowLen; i++){
		diagSum += board[i][i];
	}

	return diagSum;
}


//int, int, int arr[][] -> int
//Calculates the sum of the bottom-left-to-top-right diagonal
int BLTRDiagonalSum(int rowLen, int colLen, int board[rowLen][colLen]){
	int diagSum = 0;
	int sth = (colLen - 1);
	for (int i = 0; i < rowLen; i++){
		diagSum += board[sth][i];
		sth--;
	}

	return diagSum;
}

int safe(int board[ROW][COL], int rowIndex, int colIndex){
	return (
		(board[rowIndex][colIndex] != 1) && (board[rowIndex][colIndex] != -1) &&
		(((rowIndex > -1) && (rowIndex < ROW)) && ((colIndex > -1) && (colIndex < COL)))
		);
}

void playMove(int board[ROW][COL], int i, int j, int move){
	if (safe(board, i, j) != 0){
		board[i][j] = move;
	}
}


int winner(int board[ROW][COL]){
	int col_sum = 0;
	int row_sum = 0;
	int TLBR_sum = TLBRDiagonalSum(ROW, COL, board);
	int BLTR_sum = BLTRDiagonalSum(ROW, COL, board);

	for (int i = 0; i < 3; i++){
		col_sum = colSum(ROW, COL, board, i);
		row_sum = rowSum(ROW, COL, board, i);

		if (col_sum == 3 || row_sum == 3 || TLBR_sum == 3 || BLTR_sum == 3){
			return 1;
		} else if (col_sum == -3 || row_sum == -3 || TLBR_sum == -3 || BLTR_sum == -3){
			return -1;
		}
	}

	return 0;

}


int ticTacToe(int board[ROW][COL]){
	int turn = 1;
	int player;
	int row;
	int col;
	int move = 1;
	int playerOneMove;
	int playerTwoMove;

	while (turn < 9 && (winner(board) == 0)){
		if (turn % 2 == 0){
			player = 2;
		} else{
			player = 1;
		}

		if (turn == 1){
			printf("\n>> Player 1, please specify your move (either 1 or -1 only): ");
			scanf("%d", &move);

			while (move != -1 && move != 1){
				printf("\n>> THAT MOVE IS INVALID!\n");
				printf("\tSpecify your move again, Player 1 (either 1 or -1 only): ");
				scanf("%d", &move);
			}

			printf("\tWhere do you want to place it?\n");
			printf("\tPlease input two numbers: ");
			scanf("%d %d", &row, &col);
			playerOneMove = move;
			playerTwoMove = (- playerOneMove);

			if (safe(board, row, col) != 1){
				printf("\n>> INDEXES OUT OF BOUNDS!\n");
				printf("\tBut it is still your turn.\n");
				printf("\tPlayer 1, please input two numbers again: ");
				scanf("%d %d", &row, &col);
			}
		}

		if (turn == 2){
			printf("\n>> Player 2, you can only have %d as your move.\n", playerTwoMove);
			printf("\tWhere do you want to place it?\n");
			printf("\tPlease input 2 numbers: ");
			scanf("%d %d", &row, &col);

			while (safe(board, row, col) != 1){
				printf("\n>>THAT PLACE HAS AN ELEMENT OR IS OUT OF BOUNDS!\n");
				printf("\tBut it is still your turn Player 2. \n\tInput 2 numbers: ");
				scanf("%d %d", &row, &col);
			}
		}

		if (turn > 2){
			printf("\n>> It's your turn Player %d.\n", player);
			printf("\tAt what row index and column index do you want to put your move?\n");
			printf("\tPlease input two numbers: ");
			scanf("%d %d", &row, &col);

			while(safe(board, row, col) != 1){
				printf("\n>> THAT PLACE HAS AN ELEMENT OR IS OUT OF BOUNDS!\n");
				printf("\tIt's still your turn Player %d.\n", player);
				printf("\tAt what row index and column index do you want to put your move?\n");
				printf("\tPlease input two numbers: ");
				scanf("%d %d", &row, &col);
			}
		}
		
		if (player == 1){
			playMove(board, row, col, playerOneMove);
		} else{
			playMove(board, row, col, playerTwoMove);
		}

		turn++;
	}

	if (winner(board) == 0){
		return 0;
	}

	return player;
}

int isYes(char str[]){
	int result = 0;
	int yesValue = 'Y' + 'E' + 'S';
	for (int i = 0; str[i] != '\0'; i++){
		result += str[i];
	}

	return (result == yesValue);
}

// int isNo(char str[]){
// 	int result = 0;
// 	int noValue = 'N' + 'O';
// 	for (int i = 0; str[i] != '\0'; i++){
// 		result += str[i];
// 	}

// 	return (result == noValue);
// }

int main(){
	int board1[ROW][COL] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	printf("~~~    WELCOME TO THE GAME OF TIC TAC TOE    ~~~");
	if (ticTacToe(board1) != 0){
		printf("\n>> PLAYER %d WON!", ticTacToe(board1));
	} else{
		printf("\n>> IT'S A DRAW!");
	}

	char answer[3];
	int noQuit = 0;
	while ((isYes(answer) != 1) || (noQuit == 0)){
		printf("\nDo you wish to quit?\n");
		printf("\t Type 'YES' to quit: ");
		scanf("%s", answer);
		noQuit = 1;

		// if (isNo(answer)){
		// 	ticTacToe(board1);
		// 	if (ticTacToe(board1) != 0){
		// 		printf("\n>> PLAYER %d WON!", ticTacToe(board1));
		// 	} else{
		// 		printf("\n>> IT'S A DRAW!");
		// 	}
		// }
	}
	return 0;
}