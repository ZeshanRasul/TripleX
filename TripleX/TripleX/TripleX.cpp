#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
	std::cout << "You are a secret agent breaking into a level " << Difficulty << " secure server room\n";
	std::cout << "You need to enter the correct codes to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
	PrintIntroduction(Difficulty);

	const int CodeA = rand() % Difficulty + Difficulty;
	const int CodeB = rand() % Difficulty + Difficulty;
	const int CodeC = rand() % Difficulty + Difficulty;

	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;

	std::cout << "> The code has three numbers\n";
	std::cout << "> The sum of the numbers is: " << CodeSum;
	std::cout << "\n> The product of the numbers is: " << CodeProduct << std::endl << std::endl;

	int GuessA, GuessB, GuessC;
	std::cin >> GuessA >> GuessB >> GuessC;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		std::cout << "\nYou guessed correctly\n";
		std::cout << "You can now go through to the next room!\n\n";
		return true;
	}
	else
	{
		std::cout << "\nYou guessed incorrectly\n";
		std::cout << "You'll have to start this room again!\n\n";
		return false;
	}
}

int main()
{
	srand(time(NULL));

	int LevelDifficulty = 1;
	int const MaxDifficulty = 5;
	
	while (LevelDifficulty <= MaxDifficulty)
	{
		bool bLevelComplete = PlayGame(LevelDifficulty);
		std::cin.clear();
		std::cin.ignore();

		if (bLevelComplete)
		{
			++LevelDifficulty;
		}
	}

	std::cout << "You won the game!\n";

	return 0;
}