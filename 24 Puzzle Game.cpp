// 1. This is a classic 24 puzzle game. At te starting of the game two board will be displayed the randomly generated
// board (which the user has to organize in accending order) and the goal state board (which the user has to achive
// inorder to win).
// 2.  In this game the user will enter there move by enterting U, D, L, R
// 3. Talking about the code the first function void init() is used to randomly generate the board with numbers and
// print the numbers along with a blank space.  
// 4. The second function void goal() is used to generate the board which is in acending order containing numbers
// from 1 - 24 and a blank space at the 25th place
// 5. The third function bool Is_Solvable() is used to check whether the randomly generated board is solvable or not
// The function does this by checking the number of inversions. If the number of inversions are even then it is
// solavle else it is not. Further inside the function a boolean variable is_reachable is used. If the number of
// inversions a even it will return true else it will return false. At the end the function will return is_reachable
// In the case of false the game will randomly generate 2 indexes and randomly assign them value between 1 and 24.
// 6. Then in the the fourth fucntion bool is_goal() the fucntion checks if the randomly generated board is 
// equal to the goal state board if yes it is it will return true else it will return false.
// 7. the fifth function is is used to check whether the moves are legal or not. if the empty bix is at the right end 
// of the grid it will have two options up or left. if the user give the choice right it will prompt the user that 
// its not legal or invalid move.
// 8.  the sixth function makes_moves which is used to move the the box up, right, down, left so that if user enter
//  the choice it returns it correctly.
// 9. the fifth function is used to print the path. It prints out the sequence of moves taken from the initial state 
// to reach the goal state of the puzzle.
// 10. Lastly in the main all of the functions are called and a while loop is used. inside the loop the program
// will get user's move and update the board then it checks if the randomly generated board (after updating
// user's move) beacomes equal to the goal sate board. If it becomes the program will terminte after displaying 
// the victory mesaage else loop will continue to run. 




#include<iostream>
#include <cstdlib>
#include <ctime>
#include<iomanip>
#include <fstream> // Include the file stream library for file handling
#include<cmath>
using namespace std;

#define ANSI_COLOUR_YELLOW  "\x1b[33m"
#define ANSI_COLOUR_GREEN   "\x1b[32m"
#define ANSI_COLOUR_RED     "\x1b[31m"
#define ANSI_COLOUR_ORANGE  "\x1b[38;5;208m" // Using 8-bit color for orange
#define ANSI_COLOUR_MAGENTA "\x1b[35m"
#define ANSI_COLOUR_CYAN "\x1b[36m"
#define ANSI_COLOUR_RESET   "\x1b[0m" // Reset color to default

int board[5][5]; // 2D Array to make 5 * 5 game board
int Game_board[5][5]; // Final answer or goal board

const int board_size = 5; // board size 5 by 5
const int max_moves = 100; // max moves user can for the targeted state 

void starting_Interferance()
{
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    cout << setw(57) << ANSI_COLOUR_ORANGE << " -------------------------" << endl;
    cout << setw(75) << "|      1: START            |  " << endl;
    cout << setw(75) << "|      2:INSTRUCTION       |  " << endl;
    cout << setw(75) << "|      3: CREDIT           |  " << endl;
    cout << setw(75) << "|      4: EXIT             |  " << endl;
    cout << setw(75) << "|    ENTER YOUR CHOICE     |  " << endl;
    cout << setw(72) << " -------------------------" << ANSI_COLOUR_ORANGE << endl;
}
void INSTRUCTION()
{
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    cout << setw(100) << " ----------------------------------------------------------------------" << endl;
    cout << setw(102) << "|     Swap the blank spaces with the numbers until all the numbers     | " << endl;
    cout << setw(102) << "|               are placed in the ascending order.                     | " << endl;
    cout << setw(100) << " ----------------------------------------------------------------------" << endl;
}
void CREDIT()
{
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    cout << setw(72) << " ------------------" << endl;
    cout << setw(73) << "|    MADE BY:       |" << endl;
    cout << setw(73) << "|  SEEMA HAIDER     |" << endl;
    cout << setw(73) << "|  NIMRAH SHAHID    |" << endl;
    cout << setw(72) << " ------------------" << endl;

}
void EXIT()
{
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    cout << setw(72) << "------------------------" << endl;
    cout << setw(73) << "|   Exiting the game :)  |" << endl;
    cout << setw(72) << "------------------------" << endl;
}
void menue()
{
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    char key;
    cout << setw(45) << ANSI_COLOUR_YELLOW << "  ------------------------------------------ " << endl;
    cout << setw(85) << "|  WELCOME TO CLASSIC 24 PUZZLE GAME       |" << endl;
    cout << setw(86) << "|             ENJOY!                       | " << endl;
    cout << setw(86) << "|       ENTER ANY KEY TO CONTINUE          | " << endl;
    cout << setw(85) << "   -----------------------------------------  " << ANSI_COLOUR_YELLOW << endl;
    cin >> key;
    system("cls");
}
void init()
{
    cout << endl;
    cout << endl;
    cout << endl;

    srand(time(0));
    int values[24]; // 1D Array to store numbers from 1 to 24

    // Fill the numbers array with values from 1 to 24
    for (int i = 0; i < 24; i++)
    {
        values[i] = i + 1;
    }

    // Shuffle the numbers array by swapping elements randomly
    for (int i = 0; i < 24; i++)
    {
        // Generate a random index within the range of the array
        int j = rand() % 24;
        // Swap the current number with the randomly selected number
        int temp = values[i];
        values[i] = values[j];
        values[j] = temp;
    }

    // Initialize a count variable to keep track of the current number being assigned
    int count = 0;

    // Assign the shuffled numbers to the board
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            // If it is the last element in the board, assign 0
            if (i == 4 && j == 4)
            {
                board[i][j] = 0;
            }
            // Otherwise, assign the next shuffled number to the current element
            else
            {
                board[i][j] = values[count++];
            }
        }
    }

    cout << ANSI_COLOUR_CYAN << "Your game board: " << endl;
    cout << endl;

    cout << ANSI_COLOUR_CYAN << "-+-+-+-+-+-+-+-+-+-+-" << endl;

    // Print the initialized board
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (board[i][j] == 0)
            {
                cout << ANSI_COLOUR_CYAN << "  "; // Print a blank space
            }
            else
            {
                cout << ANSI_COLOUR_CYAN << board[i][j] << " "; // Print the number
            }
            if (j < 5 - 1)
                cout << ANSI_COLOUR_CYAN << "| "; // Separate indices
        }
        cout << endl;
        if (i < 5 - 1)
        {
            cout << ANSI_COLOUR_CYAN << "-+-+-+-+-+-+-+-+-+-+-" << endl; // Separate rows vertically
        }
    }
    cout << ANSI_COLOUR_CYAN << "-+-+-+-+-+-+-+-+-+-+-" << endl;
}

void goal()
{

    // Assigning values to game board
    int count = 1;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (count <= 24)
            {
                Game_board[i][j] = count;
                count++;
            }
            else
            {
                Game_board[i][j] = 0;
            }
        }
    }

    cout << ANSI_COLOUR_GREEN << "The goal state you have to reach: " << endl;
    cout << endl;

    cout << ANSI_COLOUR_GREEN << "-+-+-+-+-+-+-+-+-+-+-" << endl;

    // Print the initialized board
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (Game_board[i][j] == 0)
            {
                cout << ANSI_COLOUR_GREEN << "  "; // Print a blank space
            }
            else
            {
                cout << ANSI_COLOUR_GREEN << Game_board[i][j]; // Print the number
            }
            if (j < 5 - 1)
                cout << ANSI_COLOUR_GREEN << " | "; // Separate indices
        }
        cout << endl;
        if (i < 5 - 1)
        {
            cout << ANSI_COLOUR_GREEN << "-+-+-+-+-+-+-+-+-+-+-" << endl; // Separate rows vertically
        }
    }
    cout << ANSI_COLOUR_GREEN << "-+-+-+-+-+-+-+-+-+-+-" << endl;
}

bool Is_Solvable()
{
    // Perform an even parity check on the goal state
    int inversions = 0; // Initialize the count of inversions
    int goalNumbers[25]; // Increase the size to 25 to accommodate all elements of the 5x5 board

    // Flatten the 2D array into a 1D array
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            goalNumbers[i * 5 + j] = board[i][j]; // Store each element in the flattened array
        }
    }

    // Count the number of inversions
    for (int i = 0; i < 25; i++) // Change the limit to 25
    {
        for (int j = i + 1; j < 25; j++) // Change the limit to 25
        {
            if (goalNumbers[i] > goalNumbers[j]) // Check if there is an inversion
            {
                inversions++; // Increment the count of inversions
            }
        }
    }

    // If the number of inversions is odd, the goal state is not reachable
    // If it's odd, swap two numbers to make it reachable
    if (inversions % 2 != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool is_goal()
{
    if (board == Game_board) // If the randomly generated board is equal to the goal state board
    {
        return true;
    }
    else
    {
        return false;
    }
}

// function to check whether the move is legal or not
void legal_moves(int* board_ptr, int board_size)
{
    int empty_row = -1, empty_col = -1;

    // Find the position of the empty cell (0)
    for (int i = 0; i < board_size; ++i) {
        for (int j = 0; j < board_size; ++j) {
            if (*(board_ptr + i * board_size + j) == 0) {
                empty_row = i;
                empty_col = j;
                break;
            }
        }
        if (empty_row != -1)
            break;
    }

    // Print the legal moves based on the position of the empty cell
    cout << "Legal moves: ";
    if (empty_row > 0)
        cout << "U ";
    if (empty_row < board_size - 1)
        cout << "D ";
    if (empty_col > 0)
        cout << "L ";
    if (empty_col < board_size - 1)
        cout << "R ";
    cout << endl;
}


// Function to take input from the user for their move
char get_user_move()
{
    cout << "Enter your move (U/D/L/R): ";
    char move;
    cin >> move;
    return move;
}
bool make_moves(char move, int* board_ptr, char* moves, int& no_of_moves)
{
    int empty_row = -1, empty_col = -1;

    // find the position of empty cell

    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
        {
            if (*(board_ptr + i * board_size + j) == 0)
            {
                empty_row = i;
                empty_col = j;
                break;
            }
        }
        if (empty_row != -1)
            break;

    }
    switch (move)
    {
    case 'U':
        if (empty_row > 0)
        {
            swap(*(board_ptr + empty_row * board_size + empty_col), *(board_ptr + (empty_row - 1) * board_size + empty_col));
            return true;
        }
        else
        {
            cout << "Invalid move. Cannot move up." << endl;
            return false;
        }
    case 'D': // Move empty cell down
        if (empty_row < board_size - 1)
        {
            swap(*(board_ptr + empty_row * board_size + empty_col), *(board_ptr + (empty_row + 1) * board_size + empty_col));
            return true;
        }
        else
        {
            cout << "Invalid move. Cannot move down." << endl;
            return false;
        }
    case 'L': // Move empty cell left
        if (empty_col > 0)
        {
            swap(*(board_ptr + empty_row * board_size + empty_col), *(board_ptr + empty_row * board_size + (empty_col - 1)));
            return true;
        }
        else
        {
            cout << "Invalid move. Cannot move left." << endl;
            return false;
        }
    case 'R': // Move empty cell right
        if (empty_col < board_size - 1)
        {
            swap(*(board_ptr + empty_row * board_size + empty_col), *(board_ptr + empty_row * board_size + (empty_col + 1)));
            return true;
        }
        else
        {
            cout << "Invalid move. Cannot move right." << endl;
            return false;
        }
    default:
        cout << "Invalid move. Please enter 'U', 'D', 'L', or 'R'." << endl;
        return false;
    }
}
// Function to print the path 
void print_path(const char* moves, int num_moves)
{
    cout << "Moves taken from initial state to reach goal state: ";
    for (int i = 0; i < num_moves; i++)
    {
        cout << moves[i] << " ";
    }
    cout << endl;
}
void update_board(char move)
{
    // Update the board based on the user's move
    int empty_row = -1, empty_col = -1;

    // Find the position of the empty cell (0)
    for (int i = 0; i < board_size; ++i)
    {
        for (int j = 0; j < board_size; ++j)
        {
            if (board[i][j] == 0)
            {
                empty_row = i;
                empty_col = j;
                break;
            }
        }
        if (empty_row != -1)
            break;
    }

    // Update the board based on the user's move
    switch (move)
    {
    case 'U': // Move empty cell up
        if (empty_row > 0)
        {
            swap(board[empty_row][empty_col], board[empty_row - 1][empty_col]);
        }
        else
        {
            cout << "Invalid move. Cannot move up." << endl;
        }
        break;
    case 'D': // Move empty cell down
        if (empty_row < board_size - 1)
        {
            swap(board[empty_row][empty_col], board[empty_row + 1][empty_col]);
        }
        else
        {
            cout << "Invalid move. Cannot move down." << endl;
        }
        break;
    case 'L': // Move empty cell left
        if (empty_col > 0)
        {
            swap(board[empty_row][empty_col], board[empty_row][empty_col - 1]);
        }
        else
        {
            cout << "Invalid move. Cannot move left." << endl;
        }
        break;
    case 'R': // Move empty cell right
        if (empty_col < board_size - 1)
        {
            swap(board[empty_row][empty_col], board[empty_row][empty_col + 1]);
        }
        else
        {
            cout << "Invalid move. Cannot move right." << endl;
        }
        break;
    default:
        cout << "Invalid move. Please enter 'U', 'D', 'L', or 'R'." << endl;
        break;
    }

    // Print the updated board
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (board[i][j] == 0)
            {
                cout << "  "; // Print a blank space
            }
            else
            {
                cout << board[i][j] << " "; // Print the number
            }
            if (j < 5 - 1)
                cout << "| "; // Separate indices
        }
        cout << endl;
        if (i < 5 - 1)
        {
            cout << "-+-+-+-+-+-+-+-+-+-+-" << endl; // Separate rows vertically
        }
    }
}

// Function to store the moves made by the player in a file
void store_moves(const char* moves, int num_moves) // FILE HANDLING
{
    ofstream outputFile;

    outputFile.open("moves.txt"); // Open a file named "moves.txt" for writing

    // Check if the file was opened successfully
    if (outputFile.is_open())
    {
        // Write each move to the file
        for (int i = 0; i < num_moves; i++)
        {
            outputFile << moves[i] << " ";
        }

        // Close the file after writing
        outputFile.close();
        cout << "Moves have been successfully stored in 'moves.txt'." << endl;
    }
    else
    {
        cout << "Unable to open file 'moves.txt'." << endl;
    }
}
int main()
{

    int no_of_moves = 0;

    int selection;
    starting_Interferance();
    cin >> selection;
    system("cls");

    switch (selection)
    {
    case 1:
        menue();
        goal();
        init();
        Is_Solvable();

        if (Is_Solvable() == false)
        {
            cout << "Game is not solvable" << endl;
            break;
        }

        char moves[max_moves]; // Array to store moves

        while (true)
        {
            // Get user's move
            char move = get_user_move();
            cout << endl;

            // Check if the move is legal
            if (make_moves(move, &board[0][0], moves, no_of_moves))
            {
                // Print the updated board
                for (int i = 0; i < 5; i++)
                {
                    for (int j = 0; j < 5; j++)
                    {
                        if (board[i][j] == 0)
                        {
                            cout << "  "; // Print a blank space
                        }
                        else
                        {
                            cout << board[i][j] << " "; // Print the number
                        }
                        if (j < 5 - 1)
                            cout << "| "; // Separate indices
                    }
                    cout << endl;
                    if (i < 5 - 1)
                    {
                        cout << "-+-+-+-+-+-+-+-+-+-+-" << endl; // Separate rows vertically
                    }
                }
                // check whether move is legal or not 
                legal_moves(&board[0][0], board_size);

                // Store the move
                moves[no_of_moves++] = move;

                // Print path
                print_path(moves, no_of_moves);
                cout << endl;

                // Store the moves in a file
                store_moves(moves, no_of_moves);

                // Check if the puzzle is solved
                if (is_goal())
                {
                    print_path(moves, no_of_moves);

                    cout << setw(85) << "  -------------------------------------------- " << endl;
                    cout << setw(85) << " |   Congratulations! You solved the puzzle.   |" << endl;
                    cout << setw(85) << "  -------------------------------------------- " << endl;

                    break;
                }
            }
        }
        break;

    case 2:
        INSTRUCTION();
        break;

    case 3:
        CREDIT();
        break;
    case 4:
        EXIT();
        break;

    default:
        cout << "Wrong Input" << endl;
    }

    system("pause");
    return 0;
}