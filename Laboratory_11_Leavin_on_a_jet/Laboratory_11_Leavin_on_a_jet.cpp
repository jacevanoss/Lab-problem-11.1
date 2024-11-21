/* Date: Nov 14, 2024
* Name: Jace Van Oss
* File: Laboratory_11_Leavin_on_a_jet.cpp
* 
* Description: program that tracks seats on a jet if they are full or not
*/

#include <iostream>
#include <string>
#include <cctype>

const int ROWS = 4;
const int COLUMNS = 13;
const char ERROR = 'X';

using namespace std;

int findRowIndex(int thisRow);
int findSeatIndex(char thisSeat);
void displaySeatColumn(char seats[][COLUMNS], int column);
void displaySeatingChart(char seats[][COLUMNS]);
bool reserveSeat(char seats[][COLUMNS], int row, int seat);

int main() {

	char seats[ROWS][COLUMNS] = {
		{'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', ' '},
		{'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', ' '},
		{'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'},
		{'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'}
	};
	char rowLetter;
	int seatNumber;
	bool isValid;

	displaySeatingChart(seats);

	while (true) {
		cout << "Enter seat number to reserve a seat or q to quit: ";
		string input;
		cin >> input;
		if (input == "Q" || input == "q") {
			break;
		}
		if (input.length() != 2 && input.length() != 3) {
			cout << "Error - invalid input, enter a valid seat number" << endl;
			continue;
		}
		seatNumber = stoi(input.substr(0, input.length() - 1));
		rowLetter = toupper(input[input.length() - 1]);
		int rowIndex = findSeatIndex(rowLetter);
		if (rowIndex == ERROR) {
			cout << "Error - invalid seat, choose a valid seat" << endl;
			continue;
		}
		if ((rowLetter == 'C' || rowLetter == 'D') && seatNumber == 13) {
			cout << "Seat " << input << " is invalid" << endl;
			continue;
		}
		int seatIndex = findRowIndex(seatNumber);
		if (seatIndex == ERROR) {
			cout << "Error - invalid seat number for this row, please enter a valid seat number" << endl;
			continue;
		}
		isValid = reserveSeat(seats, rowIndex, seatIndex);
		if (isValid) {
			cout << "Seat " << input << " reserved" << endl;
		}
		else {
			cout << "Seat " << input << " is already reserved" << endl;
		}
		displaySeatingChart(seats);
	}

	return 0;
}

int findRowIndex(int thisRow) {
	if (thisRow >= 1 && thisRow <= COLUMNS) {
		return thisRow - 1;
	}
	return ERROR;
}
int findSeatIndex(char thisSeat) {
	if (thisSeat == 'D') return 0;
	if (thisSeat == 'C') return 1;
	if (thisSeat == 'B') return 2;
	if (thisSeat == 'A') return 3;
	return ERROR;
}
void displaySeatColumn(char seats[][COLUMNS], int column) {
	if (column < 1 || column > COLUMNS) {
		cout << "Error - invalid colun number, please enter a valid column" << endl;
		return;
	}
	cout << "Column " << column << ": ";
	for (int i = 0; i < ROWS; i++) {
		cout << seats[i][column - 1] << " ";
	}
	cout << endl;
}
void displaySeatingChart(char seats[][COLUMNS]) {
	for (int i = 0; i < COLUMNS; i++) {
		cout << seats[0][i] << " ";
	}
	cout << endl;
	for (int i = 0; i < COLUMNS; i++) {
		cout << seats[1][i] << " ";
	}
	cout << endl;
	cout << endl;
	cout << "                  1 1 1 1" << endl;
	cout << "1 2 3 4 5 6 7 8 9 0 1 2 3" << endl;
	cout << endl;
	for (int i = 0; i < COLUMNS; i++) {
		cout << seats[2][i] << " ";
	}
	cout << endl;
	for (int i = 0; i < COLUMNS; i++) {
		cout << seats[3][i] << " ";
	}
	cout << endl;
}
bool reserveSeat(char seats[][COLUMNS], int row, int seat) {
	if (seats[row][seat] == 'X') {
		return false;
	}
	else {
		seats[row][seat] = 'X';
		return true;
	}
}



