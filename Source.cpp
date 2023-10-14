//Chad Huntebrinker
//Student ID number: 12567690

#include<iostream>
#include<ctime>

using namespace std;

int FindingDiceNum();
int WhoseTurn(int num);
int GameResults(char letter);


int main() {
	int humanNum = 0;
	int computerNum = 0;
	int humanWins = 0;
	int computerWins = 0;
	int i = 0;
	char goAgain = 'y';
	char playersTurn = 'B';
	char winner = 'h';

	srand(time(NULL));
	do {
		i = 0;
		playersTurn = WhoseTurn(i);
		do {																//i = 0 causes the function WhoseTurn to assign char
			if (playersTurn == 'B') {										//playersTurn = B which causes both the human player and  
				cout << "Rolling two dice for Human: " << endl;				//the computer player to roll their dice for the first
				humanNum = FindingDiceNum();								//time. The human player goes first.
				cout << endl;
				cout << humanNum << " is the number to beat!" << endl;
				cout << "Rolling two dice for Computer: " << endl;
				computerNum = FindingDiceNum();
				cout << endl;
				if (humanNum >= computerNum) {
					i = -8;									//i = -8 causes the function WhoseTurn to  
					playersTurn = WhoseTurn(i);				//assign the char playersTurn = N which allows 
				}											//the char winner = h which lets the human player win.
				else if (computerNum > humanNum) {
					i = 1;									//i = 1 causes the function WhoseTurn to assign the.
					playersTurn = WhoseTurn(i);				//char playersTurn = H which means it is the human's turn again.
				}											
			}
			else if (playersTurn == 'C') {
				cout << humanNum << " is the number to beat!" << endl;
				cout << "Rolling two dice for Computer: " << endl;
				computerNum = FindingDiceNum();
				if (humanNum >= computerNum) {
					i = -8;
					playersTurn = WhoseTurn(i);
				}
				else if (computerNum > humanNum) {
					i = 1;
					playersTurn = WhoseTurn(i);
				}
			}
			else if (playersTurn == 'H') {
				cout << computerNum << " is the number to beat!" << endl;
				cout << "Rolling two dice for Human: " << endl;
				humanNum = FindingDiceNum();
				if (computerNum >= humanNum) {
					i = -7;									//i = -7 causes the function WhoseTurn to
					playersTurn = WhoseTurn(i);				//assign the char playersTurn = n which allows
				}											//the char winner = c which lets the computer win.
				else if (humanNum > computerNum) {
					i = 2;									//i = 2 causes the function WhoseTurn to assign the 
					playersTurn = WhoseTurn(i);				//char playersTurn = C which means it is the computer's turn again.
				}
			}
		} while ((playersTurn == 'C') || (playersTurn == 'H'));			/* if it is the computer's turn or the human's turn, the program runs again. */
		winner = GameResults(playersTurn);								// winner = GameResults(playersTurn) takes the players turn and finds the winner.
																		// If playersTurn = N, then human wins. If playersTurn = n, then computer wins.
		if (winner == 'c') {
			cout << "Too bad! Unlucky roll for the human player." << endl;
			++computerWins;
			cout << "The current score is - Human: " << humanWins << ", Computer: " << computerWins << endl;
		}
		else if (winner == 'h') {
			cout << "Too bad! Unlucky roll for the computer player." << endl;
			++humanWins;
			cout << "The current score is - Human: " << humanWins << ", Computer: " << computerWins << endl;
		}
		cout << endl;
		cout << "Would you like to go again [Y/N]?";
		cin >> goAgain;
	} while ((goAgain == 'y') || (goAgain == 'Y'));						//do...while loop goes again if user enters Y or y.

	return 0;
}

int FindingDiceNum() {										//The function to calculate the random dice numbers.

	int num1;
	int num2;
	int maxNum;
	num1 = (rand() % 6) + 1;
	num2 = (rand() % 6) + 1;
	if (num1 >= num2) {
		maxNum = (num1 * 10) + num2;
	}
	else {
		maxNum = (num2 * 10) + num1;
	}
	cout << "Rolled " << num1 << " and " << num2 << ", making " << maxNum << "." << endl;
	cout << endl;
	return maxNum;
}

int WhoseTurn(int num) {									//The function to find whose turn it is.
	char playerTurn;

	switch (num) {
	case 0:
		playerTurn = 'B';									//If playerTurn = B, then both human and computer get
		break;												// to roll their dice. Human goes first (B stands for both).
	case 1:
		playerTurn = 'H';									//If playerTurn = H, then Human gets to roll.
		break;
	case 2:
		playerTurn = 'C';									//If playerTurn = C, then Computer gets to roll.
		break;
	case -8:
		playerTurn = 'N';									//If playerTurn = N, then eventually the human
		break;												//will win (N stands for No one).
	case -7:
		playerTurn = 'n';									//If playerTurn = n, then evnetually the computer
		break;												//will win (n stands for no one).
	}
	return playerTurn;
}

int GameResults(char letter) {
	char winner;
		if (letter == 'N') {								//If letter == N, then winner = h which will
			winner = 'h';									//assign the win to the human player.
		}
		else if (letter == 'n') {							//If letter == n, then the winner = c which will
			winner = 'c';									//assign the win to the computer player.
		}

	return winner;
}
		

