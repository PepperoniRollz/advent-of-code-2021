#include <iostream>
#include <fstream>
#include <vector>

int winningBoard(std::vector<int> board) {
	for (int i =0; i < board.size(); i++) {
		//rows
		if (i % 25 == 0) {
			if (board[i] == -1 && board[i+1] == -1 && board[i+2] == -1 && board[i+3] == -1 && board[i+4] == -1)
				return i / 25;
			}
		else if (i % 25 == 5) {
			if (board[i] == -1 && board[i+1] == -1 && board[i+2] == -1 && board[i+3] == -1 && board[i+4] == -1)
				return i / 25;
			}
		else if (i % 25 == 10) {
			if (board[i] == -1 && board[i+1] == -1 && board[i+2] == -1 && board[i+3] == -1 && board[i+4] == -1)
				return i / 25;
			}
		else if (i % 25 == 15) {
			if (board[i] == -1 && board[i+1] == -1 && board[i+2] == -1 && board[i+3] == -1 && board[i+4] == -1)
				return i / 25;
			}
		else if (i % 25 == 19) {
			if (board[i] == -1 && board[i+1] == -1 && board[i+2] == -1 && board[i+3] == -1 && board[i+4] == -1)
				return i / 25;
			}
			
		//columns
		else if (i % 25 == 0) {
			if (board[i] == -1 && board[i+5] == -1 && board[i+10] == -1 && board[i+15] == -1 && board[i+20] == -1)
				return i / 25;
			}
		else if (i % 25 == 1) {
			if (board[i] == -1 && board[i+5] == -1 && board[i+10] == -1 && board[i+15] == -1 && board[i+20] == -1)
				return i / 25;
			}
		else if (i % 25 == 2) {
			if (board[i] == -1 && board[i+5] == -1 && board[i+10] == -1 && board[i+15] == -1 && board[i+20] == -1)
				return i / 25;
			}
		else if (i % 25 == 3) {
			if (board[i] == -1 && board[i+5] == -1 && board[i+10] == -1 && board[i+15] == -1 && board[i+20] == -1)
				return i / 25;
			}
		else if (i % 25 == 4) {
			if (board[i] == -1 && board[i+5] == -1 && board[i+10] == -1 && board[i+15] == -1 && board[i+20] == -1)
				return i / 25;
			}
			
			}
	return -1;

}

void markBoard(std::vector<int> &board, int number) {
	for (int i = 0; i < board.size(); i++)
		if (board[i] == number)
			board[i] = -1;
}

int getBoardScore(std::vector<int> board, int boardNum) {
	int sum = 0;
	for (int i = boardNum * 25; i < (boardNum * 25) + 25; i++) {
		if (board[i] != -1)
			sum += board[i];
	}
	return sum;
}

int main() {
    std::ifstream file;
    int col1, col2, col3, col4, col5;
	int winningBoardNum;
	std::vector<int> boards;
	std::vector<int> bingoNumbers = {63,23,2,65,55,94,38,20,22,39,5,98,9,60,80,45,99,68,12,3,6,34,64,10,70,69,95,96,83,81,32,30,42,73,52,48,92,28,37,35,54,7,50,21,74,36,91,97,13,71,86,53,46,58,76,77,14,88,78,1,33,51,89,26,27,31,82,44,61,62,75,66,11,93,49,43,85,0,87,40,24,29,15,59,16,67,19,72,57,41,8,79,56,4,18,17,84,90,47,25};
    
    file.open("day-4-input.txt");
    while ( file >> col1 >>  col2 >> col3 >> col4 >> col5) {
        boards.push_back(col1);
		boards.push_back(col2);
		boards.push_back(col3);
		boards.push_back(col4);
		boards.push_back(col5);
        }
		
		for (int i = 0; i < bingoNumbers.size(); i++) {
			markBoard(boards, bingoNumbers[i]);
			winningBoardNum = winningBoard(boards);

			if (winningBoardNum >= 0 ) {
				std::cout << "first winning board number: "  << winningBoardNum << std::endl 
				<<"winning bingo number: " << bingoNumbers[i] << std::endl 
				<<"board score: " << getBoardScore(boards, winningBoardNum) << std::endl
				<<"boardScore * winningBingoNumber = " << getBoardScore(boards, winningBoardNum) * bingoNumbers[i]; //answer is 64 * 991 = 63424
				break;
			}
		}
}