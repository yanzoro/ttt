#include <stdio.h>
#include <unistd.h>

// prints the board
void print_board(char board[3][3]);

// get the coordinates from input
int get_coordinates(int *row, int *col);

int main(void) {	
	char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

	for(int i = 0 ;;) {
		int row, col; // row and columns for coordinate
		char player = (i % 2 == 0) ? 'X' : 'O';

		printf("\e[1;1H\e[2J"); // clear screen
		print_board(board);

		// check if tie and end game
		if(i == 9) {
			printf("TIE\n");
			break;
		}

		printf("%c: ", player); // so they would know whos turn it is
		if(get_coordinates(&row, &col) == 1) {
			printf("error: invalid input\n");
			sleep(2);
			continue;
		}

		if(board[row][col] == 'O' || board[row][col] == 'X') {
			printf("error: place already taken!!\n");
			sleep(2);
			continue;
		}
		else board[row][col] = player;
		i++;
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
	char input[100];

	printf("enter where you want to place: ");

	if(fgets(input, sizeof(input), stdin) == NULL) { // check if input is bad
		return 1;
	}

	if(sscanf(input, "%d", &place) == NULL) { 
		return 1;
	}


	if(place > 9 || place < 0)
		return 1;

	*row = place / 3;
	*col = place % 3 - 1;

	return 0;
}
