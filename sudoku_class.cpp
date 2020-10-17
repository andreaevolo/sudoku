#include "sudoku_class.h"
#include <iostream>

// private methods

void Sudoku::fillSudokuTable() {
        for(int i = 0; i < 9;i++) {
            for(int j = 0; j < 9;j++) {
                sudoku_table_[i][j] = 0;
            }
        } 
}

bool Sudoku::init() {
    return game_running_;
}
void Sudoku::end() {
    game_running_ = false;
}

void Sudoku::printTable() {
    for(int i = 0; i < 9;i++) {
        
        for(int j = 0; j < 9;j++) {
             if((j+1) == 9) {
               // std::cout<<sudoku_table_[i][j]<<"|";
               std::cout<<"["<<i<<","<<j<<"]"<<"\n";
            } else {
              std::cout<<"["<<i<<","<<j<<"] ";
            } 
        }
     
    }
};

bool Sudoku::checkColumn(short int y, short int input_value) {
    bool isValid = true;
    for(int i = 0; i < 9;i++) {
        if(sudoku_table_[i][y] == input_value) isValid = false;
    }
    return isValid;
}

bool Sudoku::checkRow(short int x, short int input_value) {
    bool isValid = true;
    for(int i = 0; i < 9;i++) {
        if(sudoku_table_[x][i] == input_value) isValid = false;
    }
    return isValid;
}

 bool Sudoku::checkGrid(short int x, short int y) {

 };

void Sudoku::askUserInput() {
   
   short int val = inputCellValue();
   Coordinates user_coordinates = inputCoordinates();
    
}

 short int Sudoku::inputCellValue() {
    std::cout<<"Enter a number from 1 to 9"<<std::endl;
    short int value;
    std::cin>>value;
    bool invalid_value = true;
    while(invalid_value) {
      try {
        if(value < 1 || value > 9) throw "In sudoku you can only use numbers from 1 to 9, please insert a correct number.";
        invalid_value = false;
    } catch(const char * err) {
        std::cout<<err<<"\n";
        std::cin>>value;
    }
    }
    return value;
 };

 Coordinates Sudoku::inputCoordinates() {
    std::cout<<"Enter X (row) and Y (Column) coordinates where you would like to place your number "<<std::endl;
    short int row,column;
    std::cin>>row>>column;
    bool invalidCordinates = true;
    while(invalidCordinates) {
       try {
        if(row < 1 || row > 9) throw -1;
        if(row < 1 || column > 9) throw -2;
        invalidCordinates = false;
    } catch(int error_code) {
        if(error_code == -1) 
        {
            std::cerr<<"The row number you entered doesn't exist. Please enter a valid number."<<"\n";
        }
        else 
        {
            std::cerr<<"The Column number you entered doesn't exist. Please enter a valid number."<<"\n";
        }
        std::cin>>row>>column;
    }
    }
    Coordinates sudoku_coordinates;
    sudoku_coordinates.x_ = row;
    sudoku_coordinates.y_ = column;
    return sudoku_coordinates;
 }