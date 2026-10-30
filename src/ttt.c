#include <stdio.h>
#include <unistd.h>

// prints the board
void print_board(char board[3][3]);

// get the coordinates from input
int get_coordinates(int *row, int *col);

// check if someone won or not and return the winners symbol
char check_win(char board[3][3]);

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

		// check if someone won
		char winner = check_win(board);
		if(winner != 0) {
			printf("%c WON\n", winner);
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

char check_win(char board[3][3]) {	
	// look away kids..
	
	// X
	if(
		// horozontal
		(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') ||
		(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') ||
		(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') ||
		
		// vertical
		(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') ||
		(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') ||
		(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') ||

		// diagonal
		(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') ||
		(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
	) return 'X';

	// O
	else if(
		// horozontal
		(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') ||
		(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') ||
		(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') ||
		
		// vertical
		(board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') ||
		(board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') ||
		(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') ||

		// diagonal
		(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') ||
		(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
	) return 'O';

	return 0; // return 0 if nobody won yet
}
