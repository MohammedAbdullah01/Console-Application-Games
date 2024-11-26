#include <iostream>
using namespace std;

#pragma region Helper function
void PrintMessageOnScreen(string msg)
{
	cout << msg << endl;
}

int ReadPositiveNumber(string question)
{
	int number;

	do
	{
		PrintMessageOnScreen(question);
		cin >> number;
	} while (number <= 0);
	return number;
}

int ReadPositiveNumberBetweenFrom1ToN(string question, short maxChoice)
{
	int number;

	do
	{
		cout << question;
		cin >> number;
	} while (number <= 0 || number > maxChoice);
	return number;
}

int RandomNumber(int from, int to)
{
	return rand() % (to - from + 1) + from;
}
#pragma endregion


enum  enStonePaperScissors
{
	Stone = 1, Paper, Scissors 
};

enum enWhoWinner
{
	Player, Computer, Draw
};

char ReadOnlyOneCharacterYORN(string question)
{
	char character;
	do
	{
		PrintMessageOnScreen(question);
		cin >> character;
	} while (character != 'Y' &&
			character != 'N' &&
			character != 'n' &&
			character != 'y');
	return character;
}

string whoWinner(enWhoWinner winner)
{
	switch (winner)
	{
	case Player:
		return "Player";
	case Computer:
		return "Computer";
	case Draw:
		return "Draw";
	default:
		return "Unknown";
	}
}

string GetChoice(enStonePaperScissors choice)
{
	switch (choice)
	{
	case enStonePaperScissors::Stone:
		return "Stone";
	case enStonePaperScissors::Paper:
		return "Paper";
	case enStonePaperScissors::Scissors:
		return "Scissors";
	default:
		return "Unknown";
	}
}

struct stRound
{
	string PlayerChoice, ComputerChoice, RoundWinner ;
};

struct stGameResult
{
	int gameRound = 0, playerWonTimes = 0, computerWonTimes = 0, drawTimes = 0;
	string finalWinner;
};

void CheckRoundWinner(int playerChoice, int computerChoice , stRound& roundDetails , stGameResult& gameResult)
{
	if (playerChoice == computerChoice)
	{
		roundDetails.RoundWinner = whoWinner(enWhoWinner::Draw);
		gameResult.drawTimes++;
		system("color 6F"); //turn screen to Yellow
	}

	else if (
		(playerChoice == enStonePaperScissors::Stone &&
			computerChoice == enStonePaperScissors::Scissors) ||
		(playerChoice == enStonePaperScissors::Scissors &&
			computerChoice == enStonePaperScissors::Paper) || 
		(playerChoice == enStonePaperScissors::Paper &&
			computerChoice == enStonePaperScissors::Stone))
	{
		roundDetails.RoundWinner = whoWinner(enWhoWinner::Player);
		gameResult.playerWonTimes++;
		system("color 2F"); //turn screen to Green
	}
	else
	{
		roundDetails.RoundWinner = whoWinner(enWhoWinner::Computer);
		gameResult.computerWonTimes++;
		system("color 4F"); //turn screen to Red
		cout << "\a";
	}
}

void PlayRounds(int roundsCount , stGameResult& gameResult)
{
	for (int i = 1; i <= roundsCount; i++)
	{
		cout << "\nRound [" << i << "] Begins:" << endl;
		int playerChoice =
			ReadPositiveNumberBetweenFrom1ToN("Your Choise: [1]Stone , [2]Paper , [3]Scissors ?" , 3);

		 int computerChoice = RandomNumber(enStonePaperScissors::Stone , enStonePaperScissors::Scissors);

		 stRound roundDetails;
		CheckRoundWinner(playerChoice, computerChoice , roundDetails , gameResult);

		roundDetails.PlayerChoice = GetChoice((enStonePaperScissors)playerChoice);
		roundDetails.ComputerChoice = GetChoice((enStonePaperScissors)computerChoice);

		cout<< "\n__________ Round [" << i << "] ___________\n" << endl ;
		cout << "Player Choise : " << roundDetails.PlayerChoice << endl;
		cout << "Computer Choise : " << roundDetails.ComputerChoice << endl;
		cout << "Round Winner : " << roundDetails.RoundWinner << endl;
		PrintMessageOnScreen("---------------------------------\n");

	}
	gameResult.gameRound = roundsCount;
}

void CheckFinalWinner(stGameResult& gameResult)
{
	if (gameResult.playerWonTimes > gameResult.computerWonTimes)
		gameResult.finalWinner = whoWinner(enWhoWinner::Player);

	else if(gameResult.computerWonTimes > gameResult.playerWonTimes)
		gameResult.finalWinner = whoWinner(enWhoWinner::Computer);

	else
		gameResult.finalWinner = whoWinner(enWhoWinner::Draw);
}

void PrintGameOver(stGameResult& gameResult)
{
	PrintMessageOnScreen("\n\n\t\t\t========================================================");
	PrintMessageOnScreen("\t\t\t\t\t----- +++ GAME OVER +++ -----");
	PrintMessageOnScreen("\t\t\t========================================================\n");
	PrintMessageOnScreen("\t\t\t==================== [ Game Result ] ===================\n");
	cout << "\t\t\tGame Round		: " << gameResult.gameRound << endl;
	cout << "\t\t\tPlayer Won Time(s)	: " << gameResult.playerWonTimes << endl;
	cout << "\t\t\tComputer Won Time(s)	: " << gameResult.computerWonTimes << endl;
	cout << "\t\t\tDraw Time(s)		: " << gameResult.drawTimes << endl;
	cout << "\t\t\tFinal Winner		: " << gameResult.finalWinner << endl;
	PrintMessageOnScreen("\t\t\t========================================================\n");



}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void StartGame()
{
	char playAgain = 'Y';
	do
	{
		stGameResult gameResult;

		ResetScreen();

		int roundsCount = ReadPositiveNumber("How Many Round 1 To 10 ?");

		PlayRounds(roundsCount, gameResult);

		CheckFinalWinner(gameResult);

		PrintGameOver(gameResult);

		playAgain = ReadOnlyOneCharacterYORN("Do You Want To Play Again ? Y/N ? ");
	} while (playAgain == 'Y' || playAgain == 'y');
	
}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();
}