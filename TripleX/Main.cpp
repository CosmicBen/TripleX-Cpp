#include <iostream>
#include <ctime>

void PrintInstructions(int LevelDifficulty) {
	// Print welcome messages to the terminal
	std::cout << "You are a secret agent breaking into a level " << LevelDifficulty << " secure server room..." << std::endl;
	std::cout << "You need to enter the correct codes to continue..." << std::endl;
	std::cout << std::endl;
}

bool PlayGame(int LevelDifficulty) {
	PrintInstructions(LevelDifficulty);

	// Declare 3 number code
	const int CodeA = 1 + (rand() % (1 + LevelDifficulty));
	const int CodeB = 1 + (rand() % (1 + LevelDifficulty));
	const int CodeC = 1 + (rand() % (1 + LevelDifficulty));

	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;

	// Print sum and product to the terminal
	std::cout << "+ There are 3 numbers in the code" << std::endl;
	std::cout << "+ The codes add-up to: " << CodeSum << std::endl;
	std::cout << "+ The codes multiply to give: " << CodeProduct << std::endl;

	std::cout << std::endl;
	int GuessA, GuessB, GuessC;
	std::cin >> GuessA >> GuessB >> GuessC;
	std::cin.clear();
	std::cin.ignore();
	std::cout << std::endl;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	// Check if the players guess is correct
	if (CodeSum == GuessSum && CodeProduct == GuessProduct) {
		std::cout << "*** Well done agent! You have extracted a file! Keep going! ***" << std::endl << std::endl;
		return true;
	}
	else {
		std::cout << "*** You entered the wrong code! Careful agent! Try again! ***" << std::endl << std::endl;
		return false;
	}
}

int main() {
	srand(time(NULL));

	int LevelDifficulty = 1;
	const int MaxDifficulty = 5;

	while (LevelDifficulty <= MaxDifficulty) {
		bool bLevelComplete = PlayGame(LevelDifficulty);

		if (bLevelComplete) {
			LevelDifficulty++;
		}
	}

	std::cout << "*** Great work agent! You got all the files! Now get out of there! ***" << std::endl;

	return 0;
}