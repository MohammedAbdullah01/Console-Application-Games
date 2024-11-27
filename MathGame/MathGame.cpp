#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


#pragma region Helper Function
void PrintMessageOnScreen(string msg)
{
	cout << msg << endl;
}

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

int ReadPositiveNumber(string msg)
{
	int number;

	do
	{
		cout << msg;
		cin >> number;
	} while (number < 0);

	return number;
}

short ReadPositiveNumberInRange(string msg , short minRange , short maxRang)
{
	short howManyQuestion;

	do
	{
		PrintMessageOnScreen(msg);
		cin >> howManyQuestion;

	} while (howManyQuestion < minRange || howManyQuestion > maxRang);

	return howManyQuestion;
}

int RandomNumber(int from, int to)
{
	return (rand() % (to - from + 1) + from);
}

void Swap(float& num1 , float& num2)
{
	if (num2 > num1)
	{
		float temp = num1;
		num1 = num2;
		num2 = temp;
	}
}
#pragma endregion

enum enChoiceLevel
{
	Easy = 1, Med, Hard, Mix
};

enum enChoiceOperationType
{
	Add = 1, Sub, Mul, Div, MixedOperations
};

struct stQuestion
{
	float number1 = 0.0f, number2 = 0.0f, RightAnswer = 0.0f;
	enChoiceOperationType opType = enChoiceOperationType::Add;
};

struct  stFinalResult
{
	int	 numberOfQuestion = 0;
	short numberOfRight = 0, numberOfWrong = 0;
	enChoiceLevel level = enChoiceLevel::Easy;
	enChoiceOperationType opType = enChoiceOperationType::Add;
};

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

float GetRandomNumberDependingTheLevel(enChoiceLevel level)
{
	switch (level)
	{
	case enChoiceLevel::Easy:	return (float)RandomNumber(1, 20);
	case enChoiceLevel::Med:	return (float)RandomNumber(20, 100);
	case enChoiceLevel::Hard:	return (float)RandomNumber(100, 1000);
	case enChoiceLevel::Mix:	return (float)RandomNumber(1, 1000);
	default: return 0;
	}
}

bool CheckUserAnswerAndRightAnswer(float useranswer, stQuestion question)
{
	return (useranswer == question.RightAnswer);
}

void GiveScoreForTheQuestion(float useranswer, stQuestion question, stFinalResult& finalResult)
{
	if (CheckUserAnswerAndRightAnswer(useranswer, question))
	{
		PrintMessageOnScreen("Right Answer\n");
		system("color 2F"); //turn screen to Green
		finalResult.numberOfRight++;
		return;
	}
	else
	{
		PrintMessageOnScreen("Wrong Answer");
		cout << "The Right Answer Is = " << question.RightAnswer << "\n\n";
		system("color 4F"); //turn screen to Red
		cout << "\a";
		finalResult.numberOfWrong++;
	}
}

string getChoiceLevelName(enChoiceLevel levelName)
{
	switch (levelName)
	{
	case Easy:	return "Easy";
	case Med:	return "Medium";
	case Hard:	return "Hard";
	case Mix:	return "Mixed";
	default:	return "Unknown";
	}
}

string getChoiceOperationTypeName(enChoiceOperationType opType)
{
	switch (opType)
	{
	case Add:	return "Addition";
	case Div:	return "Division";
	case Sub:	return "Subtraction";
	case Mul:	return "Multiplication";
	case MixedOperations: return "Mixed Operations";
	default: return "Unknown";
	}
}

string getChoiceOperationCharacter(enChoiceOperationType opType)
{
	switch (opType)
	{
	case Add:	return "+";
	case Div:	return "/";
	case Sub:	return "-";
	case Mul:	return "*";
	default:	return "?";
	}
}

void CalculateTwoNumber(stQuestion& question)
{
	switch (question.opType)
	{
	case Add:	question.RightAnswer = question.number1 + question.number2;	break;
	case Sub:	question.RightAnswer = question.number1 - question.number2;	break;
	case Mul:	question.RightAnswer = question.number1 * question.number2;	break;
	case Div:	question.RightAnswer = question.number1 / question.number2;	break;
	default:	question.RightAnswer = 0; break;
	}
}

string CheckFinalResultPassOrFailed(stFinalResult finalResult)
{
	return (finalResult.numberOfRight >= finalResult.numberOfWrong) ? "Pass" : "I Failed";
}

void printShowDetailsTheQuestion(stQuestion question)
{
	cout << question.number1 << endl;
	cout << question.number2 << "\t" + getChoiceOperationCharacter(question.opType) << endl;
	PrintMessageOnScreen("--------------------\n");
}

void printShowFinalResult(stFinalResult finalResult)
{
	PrintMessageOnScreen("\n\n\t\t\t==================================================================");
	PrintMessageOnScreen("\t\t\t\t\t----- +++ Final Result Is (" + (CheckFinalResultPassOrFailed(finalResult)) + ") +++ -----");
	PrintMessageOnScreen("\t\t\t==================================================================\n");
	PrintMessageOnScreen("\t\t\t========================= [ Game Result ] ========================\n");
	cout << "\t\t\tNumber Of Question		: " << finalResult.numberOfQuestion << endl;
	cout << "\t\t\tQuestions Level			: " << getChoiceLevelName(finalResult.level)  << endl;
	cout << "\t\t\tQuestions Type			: " <<  getChoiceOperationTypeName(finalResult.opType) << endl;
	cout << "\t\t\tNumber Of Question Right	: " << finalResult.numberOfRight << endl;
	cout << "\t\t\tNumber Of Question Wrong	: " << finalResult.numberOfWrong << endl;
	PrintMessageOnScreen("\t\t\t==================================================================\n");
}

stFinalResult PlayGame()
{
	stFinalResult finalResult;

	finalResult.numberOfQuestion = ReadPositiveNumberInRange("How Many Question Do You Want Answer ? From (1) To (10)", 1, 10);
	finalResult.level = (enChoiceLevel)ReadPositiveNumberInRange("Enter Questions Level [1]Easy, [2]Med, [3]Hard, [4]Mix ? Choice From [1] To [4]", 1, 4);
	finalResult.opType = (enChoiceOperationType)ReadPositiveNumberInRange("Enter Questions Type [1]Add, [2]Sub, [3]Mul, [4]Div, [5]Mix ? Choice From [1] To [5]", 1, 5);

	
	for (int i = 1; i <= finalResult.numberOfQuestion; i++)
	{
		stQuestion question;

		question.opType = (finalResult.opType == MixedOperations)
			? (enChoiceOperationType)(RandomNumber(1, 4))
			: finalResult.opType;

		question.number1 = GetRandomNumberDependingTheLevel(finalResult.level);
		question.number2 = GetRandomNumberDependingTheLevel(finalResult.level);

		Swap(question.number1, question.number2);
		CalculateTwoNumber(question);
		
		cout << "Question [" << i << "/" << finalResult.numberOfQuestion << "]" << endl;
		printShowDetailsTheQuestion(question);

		float userAnswer = (float)ReadPositiveNumber("Your answer: ");
		GiveScoreForTheQuestion(userAnswer, question , finalResult);
	}

	return finalResult;
}

void StartGame()
{
	char playAgain;
	do
	{
		ResetScreen();
		stFinalResult FinalResult = PlayGame();
		printShowFinalResult(FinalResult);
		playAgain = ReadOnlyOneCharacterYORN("Do You Want To Play Again ? Y/N ? ");
	} while (playAgain == 'Y' || playAgain == 'y');
}


int main()
{
	srand((unsigned)time(NULL));
	StartGame();
}