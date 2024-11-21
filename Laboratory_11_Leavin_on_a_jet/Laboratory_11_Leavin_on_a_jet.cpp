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
void displaySeatColumn(char seats[][COLUMNS], int column);
void displaySeatingChart(char seats[][COLUMNS]);
bool reserveSeat(char seats[][COLUMNS], int row, int seat);



