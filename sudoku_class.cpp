#include "sudoku_class.h"
#include <iostream>

// private methods

void Sudoku::fillSudokuTable()
{

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            sudoku_table_[i][j] = 0;
        }
    }
    timer_.startTimer();
}

void Sudoku::addHintsToTable()
{
    while (hints_ >= 0)
    {
        // generate random numbers in range 1 - 9
        short int random_value = (rand() % 9) + 1;
        short int i = (rand() % 9) + 1;
        short int j = (rand() % 9) + 1;
        if (random_value < 1 || random_value > 9)
            std::cout << "Generated number it's not in the range (1, 9)"
                      << "\n";
        if (checkColumn(j, random_value) && checkRow(i, random_value))
        {
            /* 
            check if the number can be inserted in the grid,
            and check if the spot is not already filled.
            otherwise keep looping untile the are no more hints.
            */
            if (checkGrid(i, j, random_value) && (sudoku_table_[i][j] == 0))
            {
                sudoku_table_[i][j] = random_value;
                hints_--;
            };
        }
    }
}

void Sudoku::setLevel()
{
    short int lvl = 1;
    std::cout << "Choose the difficulty of your sudoku" << std::endl;
    std::cout << "Enter number 1 to choose EASY ( 32 Hints ) " << std::endl;
    std::cout << "Enter number 2 to choose MEDIUM ( 24 Hints ) " << std::endl;
    std::cout << "Enter number 3 to choose HARD ( 17 Hints ) " << std::endl;

    std::cin >> lvl;
    switch (lvl)
    {
    case 1:
        hints_ = 32;
        break;
    case 2:
        hints_ = 24;
        break;
    case 3:
        hints_ = 17;
        break;
    default:
        break;
    }
}
bool Sudoku::init()
{
    if (player_moves_count_ == 0)
    {
        setLevel();
        addHintsToTable();
        printTable();
    }
    askUserInput();
    return game_running_;
}
void Sudoku::end()
{
    game_running_ = false;
    timer_.stopTimer();
    std::cout << "You have completed your game in: ";
    timer_.printTimeElapsed();
    std::cout << "Total number of mooves needed for you to complete the sudoku: " << numbers_added_ << std::endl;
}

void Sudoku::printTable()
{

    for (int i = 0; i < 9; i++)
    {
        std::cout << "-------------------------------------"
                  << "\n";
        for (int j = 0; j < 9; j++)
        {

            if (j == 0)
            {
                // std::cout<<sudoku_table_[i][j]<<"|";
                std::cout << "| " << sudoku_table_[i][j] << " | ";
            }
            else if ((j + 1) == 9)
            {
                std::cout << sudoku_table_[i][j] << " |"
                          << "\n";
            }
            else
            {
                std::cout << sudoku_table_[i][j] << " | ";
            }
        }
        if (i == 8)
            std::cout << "\n";
    }
};

bool Sudoku::checkColumn(short int y, short int input_value)
{
    bool is_valid = true;
    for (int i = 0; i < 9; i++)
    {
        if (sudoku_table_[i][y] == input_value)
        {
            is_valid = false;
            std::cout << input_value << " is already present in this column" << std::endl;
        };
    }
    return is_valid;
}

bool Sudoku::checkRow(short int x, short int input_value)
{
    bool is_valid = true;
    for (int i = 0; i < 9; i++)
    {
        if (sudoku_table_[x][i] == input_value)
        {
            is_valid = false;
            std::cout << input_value << " is already present in this row" << std::endl;
            break;
        };
    }
    return is_valid;
}

bool Sudoku::checkGrid(short int x, short int y, short int input_value)
{
    short int grid_number = 0;

    // find where the numbers given by user input is located on the grid
    if (y >= 0 && y <= 2)
        if (y >= 0 && y <= 2)
        {
            if (x >= 0 && x <= 2)
            {
                grid_number = 1;
            }
            else if (x >= 3 && x <= 5)
            {
                grid_number = 4;
            }
            else
            {
                grid_number = 7;
            }
        }
        else if (y >= 3 && y <= 5)
            if (x >= 0 && x <= 2)
            {
                grid_number = 2;
            }
            else if (x >= 3 && x <= 5)
            {
                grid_number = 5;
            }
            else
            {
                grid_number = 8;
            }

        else if (y >= 6 && y <= 8)
        {
            if (x >= 0 && x <= 2)
            {
                grid_number = 3;
            }
            else if (x >= 3 && x <= 5)
            {
                grid_number = 6;
            }
            else
            {
                grid_number = 9;
            }
        }
    /*
        start looping through the grid elements and
        checks if the number given by the user is unique.
    */
    bool unique_value = true;
    switch (grid_number)
    {
    case 1:
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (sudoku_table_[i][j] == input_value)
                    unique_value = false;
            }
        }
        break;
    case 2:
        for (int i = 0; i < 3; i++)
        {
            for (int j = 3; j < 5; j++)
            {
                if (sudoku_table_[i][j] == input_value)
                    unique_value = false;
            }
        }
    case 3:
        for (int i = 0; i < 3; i++)
        {
            for (int j = 6; j < 9; j++)
            {
                if (sudoku_table_[i][j] == input_value)
                    unique_value = false;
            }
        }
    case 4:
        for (int i = 3; i < 6; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (sudoku_table_[i][j] == input_value)
                    unique_value = false;
            }
        }
    case 5:
        for (int i = 3; i < 6; i++)
        {
            for (int j = 3; j < 6; j++)
            {
                if (sudoku_table_[i][j] == input_value)
                    unique_value = false;
            }
        }
    case 6:
        for (int i = 3; i < 6; i++)
        {
            for (int j = 6; j < 9; j++)
            {
                if (sudoku_table_[i][j] == input_value)
                    unique_value = false;
            }
        }
    case 7:
        for (int i = 6; i < 9; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (sudoku_table_[i][j] == input_value)
                    unique_value = false;
            }
        }
    case 8:
        for (int i = 6; i < 9; i++)
        {
            for (int j = 3; j < 6; j++)
            {
                if (sudoku_table_[i][j] == input_value)
                    unique_value = false;
            }
        }
    case 9:
        for (int i = 6; i < 9; i++)
        {
            for (int j = 6; j < 9; j++)
            {
                if (sudoku_table_[i][j] == input_value)
                    unique_value = false;
            }
        }
    default:
        break;
    }
    if (!unique_value)
        std::cout << input_value << " is already present in this 3x3 block" << std::endl;
    return unique_value;
};

void Sudoku::askUserInput()
{
    short int val = inputCellValue();
    // if there aren't any empty cell left end the game
    if (numbers_added_ == 81 || val == -1)
        return end();
    Coordinates user_coordinates = inputCoordinates();
    short int row = user_coordinates.x_;
    short int column = user_coordinates.y_;
    bool c = checkColumn(column, val);
    bool r = checkRow(row, val);
    bool g = false;
    if (c && r)
    {
        g = checkGrid(row, column, val);
    }
    if (c && r && g)
    {
        sudoku_table_[row][column] = val;
        numbers_added_++;
    }
    player_moves_count_++;
    //printTable();
}

short int Sudoku::inputCellValue()
{
    std::cout << "Enter a number from 1 to 9" << std::endl;
    short int value;
    std::cin >> value;
    if (value == -1)
        return -1;
    bool invalid_value = true;
    while (invalid_value)
    {
        try
        {
            if (value < 1 || value > 9)
                throw "In sudoku you can only use numbers from 1 to 9, please insert a correct number.";
            invalid_value = false;
        }
        catch (const char *err)
        {
            std::cout << err << "\n";
            std::cin >> value;
        }
    }
    return value;
};

Coordinates Sudoku::inputCoordinates()
{
    std::cout << "Enter X (row) and Y (Column) coordinates where you would like to place your number " << std::endl;
    short int row, column;
    std::cin >> row >> column;
    bool invalidCordinates = true;
    while (invalidCordinates)
    {
        try
        {
            if (row < 1 || row > 9)
                throw -1;
            if (row < 1 || column > 9)
                throw -2;
            invalidCordinates = false;
        }
        catch (int error_code)
        {
            if (error_code == -1)
            {
                std::cerr << "The row number you entered doesn't exist. Please enter a valid number."
                          << "\n";
            }
            else
            {
                std::cerr << "The Column number you entered doesn't exist. Please enter a valid number."
                          << "\n";
            }
            std::cin >> row >> column;
        }
    }
    Coordinates sudoku_coordinates;
    // substruct one so the user can enter values from to 1 to 9 in rows and columns
    sudoku_coordinates.x_ = row - 1;
    sudoku_coordinates.y_ = column - 1;
    return sudoku_coordinates;
}