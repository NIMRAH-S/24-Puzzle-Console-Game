# 🧩 24-Puzzle Console Game – C++ Project

This is a **console-based 24 Puzzle game** implemented in **C++**, designed to challenge your logic and problem-solving skills. It's a classic sliding puzzle where you rearrange numbers in ascending order by moving the blank tile.

---

## 🎮 Game Features

- 📦 5x5 Board (numbers 1–24 and a blank tile)  
- 🧠 Random board generation with solvability check  
- 🎯 Goal State Preview before the game starts  
- 🎮 Move with keys: `U`, `D`, `L`, `R` (Up, Down, Left, Right)  
- ✅ Valid move checking  
- 💾 Move tracking and storage in a file (`moves.txt`)  
- 🎨 Colored terminal interface using ANSI escape codes  
- 🖥️ Purely terminal-based — no external libraries required  

---

## 🚀 How to Run

### 1. Clone the Repository
```bash
git clone https://github.com/NIMRAH-S/24-Puzzle-Console-Game.git
cd 24-Puzzle-Console-Game

### 2. Compile the Game
g++ "24 Puzzle Game.cpp" -o puzzle

⚠️ On Windows, make sure you're using a compiler that supports <conio.h> and <windows.h>, such as MinGW or Code::Blocks.

### 3. Run the Game
./puzzle

📝 Game Instructions
A randomly shuffled board will be generated
A goal state (ordered from 1 to 24) will be displayed
Use the following keys to move the blank tile:
 U → Move blank Up
 D → Move blank Down
 L → Move blank Left
 R → Move blank Right
After each move, the game checks if you've reached the goal state
All your moves are saved in moves.txt

👨‍💻 Contributors
Nimrah Shahid
Seema Haider
