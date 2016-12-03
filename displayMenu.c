#pragma once

#include <stdio.h>
#include "player.h"

void displayTitle() {
	system("cls");
	printf("\n\n\n\n\n\t\t\t\t**********************************************");
	printf("\n\t\t\t\t*\t\tWelcome to Bingo!\t     *");
	printf("\n\t\t\t\t**********************************************");
}

void displayStartMenu() {
	displayTitle();
	printf("\n\n\t\t\t\t\t1 - Start a new game of Bingo?");
	printf("\n\t\t\t\t\t2 - Load an old Game?");
	printf("\n\t\t\t\t\t3 - Exit?");
	printf("\n\n\t\t\t\t\tYour choice: ");
}


void displayMainOptions() {
	displayTitle();

	printf("\n\n\t\t\t\t\tWhat's your next move?");
	printf("\n\n\t\t\t\t\t1 - Draw a number");
	printf("\n\t\t\t\t\t2 - Save Game");
	printf("\n\t\t\t\t\t3 - Show Game Status");
	printf("\n\t\t\t\t\t4 - Exit Game Without Saving");
	printf("\n\n\t\t\t\t\tYour choice: ");

}



void displayExitOptions() {
	displayTitle();

	printf("\n\n\t\t\t\t\tLeave Bingo?");
	printf("\n\n\t\t\t\t\t1 - Start a new Game");
	printf("\n\t\t\t\t\t2 - Load Game");
	printf("\n\t\t\t\t\t3 - Exit Game Without Saving");
	printf("\n\n\t\t\t\t\tYour choice: ");

}

void displayGoodbye() {
	displayTitle();
	printf("\n\n\t\t\t\t\tGoodbye - See you next time!");
}

//convenience function to display a players status
void displayPlayer(Player player) {
	printf("\n\t\t\t\tPlayers name: %s", player.name);

	//display players card
	printf("\n\t\t\t\tPlayers card");
	printf("\n\t\t\t\t-----------------------------");

	for (int row = 0; row < ROW; row++) {
		printf("\n\t\t\t\t|");

		for (int col = 0; col < COL_LONG; col++) {
			if (player.displayCard[row][col] != -1) {
				printf("%2d ", player.displayCard[row][col]);
			}
			else {
				printf("   ");
			}
		}
		printf("|");
	}
	printf("\n\t\t\t\t-----------------------------");
}



//display remaining numbers for all winning options
void displayRemaining(Player player) {

	//remaining for four corners
	int fourCourners = 4;
	if (player.shortCard[0][0] == 0) {
		fourCourners--;
	}
	if (player.shortCard[0][4] == 0) {
		fourCourners--;
	}
	if (player.shortCard[2][0] == 0) {
		fourCourners--;
	}
	if (player.shortCard[2][4] == 0) {
		fourCourners--;
	}


	//remaining for rows
	int leastNumbers[3];

	for (int i = 0; i < 3; i++) {
		leastNumbers[i] = player.remaining[i];
	}

	for (int i = 2; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (leastNumbers[j] > leastNumbers[j + 1]) {
				int temp = leastNumbers[j];
				leastNumbers[j] = leastNumbers[j + 1];
				leastNumbers[j + 1] = temp;
			}
		}
	}

	printf("\n\n\t\t\t\tNumbers needed to complete four courners: %2d", fourCourners);
	printf("\n\t\t\t\tNumbers needed to complete a row: %2d", leastNumbers[0]);
	printf("\n\t\t\t\tNumbers needed to complete two rows: %2d", leastNumbers[0] + leastNumbers[1]);
	printf("\n\t\t\t\tNumbers needed to complete Full House: %2d", leastNumbers[0] + leastNumbers[1] + leastNumbers[2]);

}
