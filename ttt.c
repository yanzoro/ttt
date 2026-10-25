#include <stdio.h>

// prints the board
void print_board(char board[3][3]);

// get the coordinates from input
int get_coordinates(int *row, int *col);

int main(void) {	
	char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

	for(;;) {
		int row, col; // row and columns for coordinate

		printf("\e[1;1H\e[2J"); // clear screen
		print_board(board);

		get_coordinates(&row, &col);
	}

	return 0;
}

void print_board(char board[3][3]) {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++)
			printf("%c    ", board[i][j]);
		printf("\n\n");
	}
}

int get_coordinates(int *row, int *col) {
	int place;

	printf("enter where you want to place: ");
	scanf("%d", &place);

	if(place > 9 || place < 0)
		return 1;

	*row = place / 3 - 1;
	*col = place % 3;

	return 0;
}
