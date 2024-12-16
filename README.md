# Stone-Paper-Scissors Game

This project implements a **Stone-Paper-Scissors Game** in C++. It offers an engaging way to play the classic game against the computer, with features to track results and replay multiple rounds.

---

## Features

1. **Interactive Gameplay**:
   - Players choose between Stone, Paper, and Scissors.
   - The computer randomly selects its choice.
   - Displays the winner of each round and tracks results.

2. **Score Tracking**:
   - Maintains statistics on the number of rounds played, player wins, computer wins, and draws.
   - Highlights the final winner after all rounds are completed.

3. **Replay Option**:
   - Players can opt to play multiple games.

4. **Color-Coded Feedback**:
   - Changes screen colors based on the outcome of each round (e.g., Green for player win, Red for computer win, Yellow for draw).

5. **Helper Functions**:
   - Modular functions to handle input validation, random number generation, and winner determination.

---

## Code Overview

### Helper Functions

- **`PrintMessageOnScreen(string msg)`**: Displays a message to the screen.
- **`ReadPositiveNumber(string question)`**: Reads a positive integer input.
- **`ReadPositiveNumberBetweenFrom1ToN(string question, short maxChoice)`**: Reads a positive number within a range.
- **`RandomNumber(int from, int to)`**: Generates a random number between two values.
- **`ReadOnlyOneCharacterYORN(string question)`**: Reads a single character input ('Y' or 'N').

### Core Enums and Structures

- **Enums**:
  - `enStonePaperScissors`: Represents the choices (Stone, Paper, Scissors).
  - `enWhoWinner`: Represents the winner of a round (Player, Computer, Draw).

- **Structures**:
  - `stRound`: Stores details of a single round, including player choice, computer choice, and round winner.
  - `stGameResult`: Tracks game statistics like total rounds, player wins, computer wins, draws, and final winner.

### Core Functions

- **`PlayRounds(int roundsCount, stGameResult& gameResult)`**: Handles multiple rounds of gameplay, updating scores and displaying results.
- **`CheckRoundWinner(int playerChoice, int computerChoice, stRound& roundDetails, stGameResult& gameResult)`**: Determines the winner of a round.
- **`CheckFinalWinner(stGameResult& gameResult)`**: Determines the final winner based on scores.
- **`PrintGameOver(stGameResult& gameResult)`**: Displays the final game summary.
- **`StartGame()`**: Main function that initializes the game and allows replaying.

---

## Example Gameplay

### Sample Round:
```
Round [1] Begins:
Your Choice: [1] Stone, [2] Paper, [3] Scissors ? 1

__________ Round [1] ___________
Player Choice    : Stone
Computer Choice  : Scissors
Round Winner     : Player
---------------------------------
```

### Final Result:
```
========================================================
		----- +++ GAME OVER +++ -----
========================================================
==================== [ Game Result ] ===================
		Game Round          : 5
		Player Won Time(s)  : 3
		Computer Won Time(s): 1
		Draw Time(s)        : 1
		Final Winner        : Player
========================================================
```

---

## Future Enhancements

- Add additional game modes, such as "Best of 3" or "Timed Challenge."
- Implement a graphical user interface (GUI).
- Extend to multiplayer functionality.

---

# Math Quiz Game

This project is a **Math Quiz Game** implemented in C++. It provides users with a fun and interactive way to test their mathematical skills by answering questions of varying difficulty levels and operation types.

---

## Features

1. **Dynamic Question Generation**:
   - Generates questions based on selected difficulty levels: Easy, Medium, Hard, and Mixed.
   - Supports different mathematical operations: Addition, Subtraction, Multiplication, Division, and Mixed Operations.

2. **Interactive Gameplay**:
   - Prompts users to answer questions and validates their input.
   - Keeps track of correct and incorrect answers.

3. **Score and Feedback**:
   - Displays a detailed summary of the game after completion.
   - Indicates whether the player passed or failed based on their performance.

4. **Replay Option**:
   - Allows users to play multiple rounds.

5. **Helper Functions**:
   - Modular functions to handle tasks like input validation, random number generation, and result calculations.

---

## Code Overview

### Helper Functions

- **`PrintMessageOnScreen(string msg)`**: Displays a message to the screen.
- **`ReadOnlyOneCharacterYORN(string question)`**: Reads a single character ('Y' or 'N') input.
- **`ReadPositiveNumber(string msg)`**: Reads a positive integer input.
- **`ReadPositiveNumberInRange(string msg, short minRange, short maxRange)`**: Reads a positive number within a specified range.
- **`RandomNumber(int from, int to)`**: Generates a random number between two values.
- **`Swap(float& num1, float& num2)`**: Swaps two numbers if necessary.

### Core Enums and Structures

- **Enums**:
  - `enChoiceLevel`: Represents difficulty levels (Easy, Medium, Hard, Mixed).
  - `enChoiceOperationType`: Represents operation types (Addition, Subtraction, Multiplication, Division, Mixed Operations).

- **Structures**:
  - `stQuestion`: Represents a single quiz question with numbers, the correct answer, and operation type.
  - `stFinalResult`: Tracks the results of the game, including the number of questions, right and wrong answers, difficulty level, and operation type.

### Core Functions

- **`PlayGame()`**: The main game loop that generates questions, evaluates answers, and updates scores.
- **`GiveScoreForTheQuestion(float userAnswer, stQuestion question, stFinalResult& finalResult)`**: Determines if the user's answer is correct and updates the result.
- **`printShowFinalResult(stFinalResult finalResult)`**: Displays the final game result.
- **`StartGame()`**: Handles the game flow and allows replaying.

## Example Gameplay

### Sample Question:
```
Question [1/5]
10
5	+
--------------------
Your answer: 15
Right Answer
```

### Final Result:
```
==================================================================
		----- +++ Final Result Is (Pass) +++ -----
==================================================================
========================= [ Game Result ] ========================
		Number Of Questions        : 5
		Questions Level            : Easy
		Questions Type             : Addition
		Number Of Questions Right  : 4
		Number Of Questions Wrong  : 1
==================================================================
```

---

## Future Enhancements

- Add support for more operations like modulus and exponentiation.
- Implement a graphical user interface (GUI).
- Introduce a leaderboard to track high scores.

---

## Contributing

Contributions are welcome! Feel free to fork the repository, improve the code, and submit a pull request.
