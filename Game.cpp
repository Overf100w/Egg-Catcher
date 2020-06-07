#include <iostream>
#include "windows.h"
#include <conio.h>
#include <random>
#include <ctime>

void drow(int x, int egg_x, int egg_y, int score); // drow map
void tap(int &x, bool &game); // tap check

int main() {
	srand(time(0));

	bool game = true; // game 
	int egg_time;     // egg drop delay
	int score;
	int x;            // bag position
	
	int egg_x = rand() % 40, egg_y = 0;

	while (true) {      // LOOOOOP
		score = 0;
		egg_time = 0;
		x = 18;
		game = true;

		system("cls");
	// menu-------

	std::cout << "  _____    ____    ____      ____      _      _____    ____   _   _   _____   ____  " << std::endl << " | ____|  / ___|  / ___|    / ___|    / \\    |_   _|  / ___| | | | | | ____| |  _ \\ " << std::endl << " |  _|   | |  _  | |  _    | |       / _ \\     | |   | |     | |_| | |  _|   | |_) |" << std::endl << " | |___  | |_| | | |_| |   | |___   / ___ \\    | |   | |___  |  _  | | |___  |  _ < " << std::endl << " |_____|  \\____|  \\____|    \\____| /_/   \\_\\   |_|    \\____| |_| |_| |_____| |_| \\_\\" << std::endl;
	std::cout << "\n\t\t\t\tARE U READY!?!?!?!\t!!!TURN TO ENGLISH KEY!!!" << std::endl;
	
	system("pause"); // tap to play

	// menu-------

	for (int i = 3; i > -1; i--) { // count down---
		system("cls");

		switch (i) {
		case 0: 
			std::cout << "                  _ \n   __ _    ___   | |\n  / _` |  / _ \\  | |\n | (_| | | (_) | |_|\n  \\__, |  \\___/  (_)\n  |___/             " << std::endl;
			Beep(2000, 400);
			break;
		case 1: 
			std::cout << " _ \n/ |\n| |\n| |\n|_|" << std::endl;
			Beep(480, 200);
			break;
		case 2:
			std::cout << " ____  \n|___ \ \n  __) |\n / __/ \n|_____|" << std::endl;
			Beep(480, 200);
			break;
		case 3: 
			std::cout << " _____ \n|___ / \n  |_ \ \n ___) |\n|____/ \n" << std::endl;
			Beep(480, 200);
		}
		Sleep(1000);
		system("cls");
	}// count down---


	while (game) { //main loop
		drow(x, egg_x, egg_y, score);

		if (egg_time % 4 == 0) { // egg spped reduction x4
			egg_y++;
			egg_time++;
		}
		else egg_time++;
		
		if (egg_y == 15) { // egg position check
			if ((egg_x > x - 1) && (egg_x < x + 4)) { // if egg has caught
				score++;
				egg_y = 0;
				egg_x = rand() % 40;
				Beep(100, 100);
			}
			else game = false;	// if it has nt caught
		}

		tap(x, game);
		Sleep(20);
	}

	std::cout << "             GAME OVER, " << "score - " << score << std::endl; // in case lose
	Beep(500, 300); // tragic tune
	Beep(300, 300); // tragic tune
	Beep(100, 500); // tragic tune

	system("pause");
	}

	return 0;
}

void drow(int x, int egg_x, int egg_y,int score) {
	system("cls");

	for (int i = 0; i < egg_y; i++) std::cout << std::endl; // drow the egg
	for (int i = 0; i < egg_x; i++) std::cout << ' ';
	std::cout << '#';

	for (int i = 0; i < 15 - egg_y; i++) std::cout << std::endl; // drow the bag	
	for (int i = 0; i < x; i++) std::cout << ".";
	std::cout << "-__-";
	for (int i = 0; i < 36 - x; i++) std::cout << ".";
	std::cout << std::endl << score << std::endl;
}

void tap(int &x, bool &game) {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a': // move left
		case 'A': //move left (CAPS)
			if (x > 0) x--;
			break;

		case 'd': //move right
		case 'D': //move right (CAPS)
			if (x < 36) x++;
			break;

		case 'x': // end the game
		case 'X': game = false; //end the game
		}
	}
}