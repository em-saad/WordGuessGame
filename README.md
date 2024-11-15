# Word Search Puzzle Game

A console-based Word Search Puzzle Game implemented in C++. Challenge yourself to find hidden words in a dynamic grid!

## Table of Contents

- [Features](#features)
- [Project Structure](#project-structure)
- [Requirements](#requirements)
- [Installation](#installation)
- [Building the Game](#building-the-game)
- [Running the Game](#running-the-game)
- [Gameplay Instructions](#gameplay-instructions)
- [Controls](#controls)
- [High Scores](#high-scores)
- [Color Legend](#color-legend)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgments](#acknowledgments)

## Features

- **Multiple Difficulty Levels**
  - **Easy:** 10x10 grid with 3 words to guess.
  - **Medium:** 15x15 grid with 5 words to guess.
  - **Hard:** 20x20 grid with 7 words to guess.
  
- **Dynamic Word Placement**
  - Words can be placed **horizontally**, **vertically**, or **diagonally**.
  
- **Colorful Console Interface**
  - Enhanced visual experience with colored text for better readability.
  
- **Score Tracking and High Scores**
  - Earn points for each correct word.
  - Maintain and display top scores.
  
- **Robust Gameplay Mechanics**
  - Shuffle words to ensure random placement.
  - Limit on incorrect guesses to increase challenge.
  
- **User-Friendly Instructions and Menu Navigation**
  - Intuitive menu system for easy navigation through game options.

## Project Structure

```
src/
├── 

main.cpp

             - Entry point
├── Game.h/cpp           - Main game controller
├── 

Mode.h

               - Base class for game modes
├── EasyMode.h/cpp       - Easy mode implementation
├── Grid.h/cpp           - Grid management
├── Player.h/cpp         - Player state management
├── 

Word.h

               - Word entity
├── WordValidator.h/cpp  - Word validation logic
├── ScoreTracker.h/cpp   - High score management
├── Utility.h/cpp        - Utility functions and definitions
├── 

easy_words.txt

       - Word database for easy mode
├── 

easy_highscores.txt

  - High score records
└── 

README.md

            - Project documentation
```

## Requirements

- **Operating System:** Windows
- **Compiler:** C++11 compatible compiler (e.g., GCC, MSVC)
- **IDE:** Visual Studio Code (recommended)
- **Additional:** C++ standard library, Windows-specific libraries for console manipulation

## Installation

1. **Clone the Repository**

   ```bash
   git clone https://github.com/em-saad/word-search-puzzle-game.git
   ```

2. **Navigate to the Source Directory**

   ```bash
   cd word-search-puzzle-game/src
   ```

3. **Ensure All Required Files Are Present**

   - `easy_words.txt` should contain the list of words for easy mode.
   - `easy_highscores.txt` will be created automatically to store high scores.

## Building the Game

1. **Open the Source Directory in Visual Studio Code**

   ```bash
   code .
   ```

2. **Compile the Source Files**

   Use the following command in the terminal to compile all source files:

   ```bash
   g++ -std=c++11 -o WordSearchGame main.cpp Game.cpp EasyMode.cpp Grid.cpp Word.cpp WordValidator.cpp ScoreTracker.cpp Player.cpp Utility.cpp
   ```

   - **Note:** Ensure that your compiler is correctly set up and added to your system's PATH.

## Running the Game

After successful compilation, run the game using the following command:

```bash
WordSearchGame.exe
```

## Gameplay Instructions

1. **Select Game Mode**
   - Choose **Easy**, **Medium**, or **Hard** mode to start.

2. **Enter Your Name**
   - Personalize your gaming experience by entering your name.

3. **Find Words in the Grid**
   - Words can be placed **horizontally**, **vertically**, or **diagonally**.
   - **Word Lengths:** 
     - Easy Mode: 2-4 letters
     - Medium/Hard Modes: Varies based on level
   - **Chances:**
     - You have a limited number of incorrect guesses to complete all levels.

4. **Make Guesses**
   - Type the word you believe is hidden in the grid and press Enter.
   - Correct guesses will reveal the word in the grid and earn you points.
   - Incorrect guesses will decrease your remaining chances.

5. **Complete Levels**
   - Successfully guess all words in the level to advance.
   - If you run out of chances, the game ends.

## Controls

- **Menu Navigation:**
  - Enter numbers (e.g., 1-5) to navigate through menus.
  
- **Making Guesses:**
  - Type the guessed word and press **Enter** to submit.
  
- **Pausing:**
  - Press any key to continue at prompts or after certain actions.

## High Scores

- **Viewing High Scores:**
  - After completing a level or exiting the game, high scores are displayed.
  
- **Saving High Scores:**
  - Your score is saved automatically if it qualifies as a high score.
  
- **High Score File:**
  - 

easy_highscores.txt

 stores the top 5 high scores.

## Color Legend

Enhance your gameplay experience with the following color-coded elements:

- 🟦 **Cyan:** Borders and frames
- 🟨 **Yellow:** Coordinates and statistics
- ⬜ **White:** Regular letters
- 🟩 **Green:** Found words
- 🔴 **Red:** Error messages

## Contributing

Contributions are welcome! To contribute:

1. **Fork the Repository**

2. **Create a New Branch**

   ```bash
   git checkout -b feature/YourFeatureName
   ```

3. **Commit Your Changes**

   ```bash
   git commit -m "Add some feature"
   ```

4. **Push to the Branch**

   ```bash
   git push origin feature/YourFeatureName
   ```

5. **Open a Pull Request**

## Acknowledgments

- Developed by [Muhammad Saad].
- Inspired by classic word search puzzles.

---

Enjoy playing the Word Search Puzzle Game! Feel free to reach out with any questions or feedback.
