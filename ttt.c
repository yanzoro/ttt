#include <stdio.h>

// prints the board
void print_board(char board[3][3]);

int main(void) {	
	char board[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

	printf("\e[1;1H\e[2J"); // clear screen
	print_board(board);
}

void print_board(char board[3][3]) {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++)
			printf("%c    ", board[i][j]);
		printf("\n\n");
	}
}
