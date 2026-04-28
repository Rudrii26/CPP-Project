#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 9;

// Display Sudoku board
void displayBoard(int board[N][N]) {

    cout << endl;

    for(int i=0;i<N;i++) {

        if(i%3==0 && i!=0)
            cout<<"---------------------"<<endl;

        for(int j=0;j<N;j++) {

            if(j%3==0 && j!=0)
                cout<<"| ";

            cout<<board[i][j]<<" ";
        }

        cout<<endl;
    }
}

// Check row
bool checkRow(int board[N][N], int row) {

    bool used[10] = {false};

    for(int col=0; col<N; col++) {

        int num = board[row][col];

        if(num<1 || num>9 || used[num])
            return false;

        used[num] = true;
    }

    return true;
}

// Check column
bool checkCol(int board[N][N], int col) {

    bool used[10] = {false};

    for(int row=0; row<N; row++) {

        int num = board[row][col];

        if(num<1 || num>9 || used[num])
            return false;

        used[num] = true;
    }

    return true;
}

// Check 3x3 box
bool checkBox(int board[N][N], int startRow, int startCol) {

    bool used[10] = {false};

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++) {

            int num = board[i+startRow][j+startCol];

            if(num<1 || num>9 || used[num])
                return false;

            used[num] = true;
        }

    return true;
}

// Validate Sudoku solution
bool isValidSudoku(int board[N][N]) {

    for(int i=0;i<9;i++) {

        if(!checkRow(board,i) || !checkCol(board,i))
            return false;
    }

    for(int i=0;i<9;i+=3)
        for(int j=0;j<9;j+=3)

            if(!checkBox(board,i,j))
                return false;

    return true;
}

// Remove random numbers
void removeNumbers(int board[N][N], int count) {

    while(count>0) {

        int row = rand()%9;
        int col = rand()%9;

        if(board[row][col]!=0) {

            board[row][col]=0;
            count--;
        }
    }
}

int main() {

    srand(time(0));

    int puzzle[N][N] = {
    {5,3,4,6,7,8,9,1,2},
    {6,7,2,1,9,5,3,4,8},
    {1,9,8,3,4,2,5,6,7},
    {8,5,9,7,6,1,4,2,3},
    {4,2,6,8,5,3,7,9,1},
    {7,1,3,9,2,4,8,5,6},
    {9,6,1,5,3,7,2,8,4},
    {2,8,7,4,1,9,6,3,5},
    {3,4,5,2,8,6,1,7,9}
    };

    // create puzzle
    removeNumbers(puzzle,40);

    cout<<"Generated Sudoku Puzzle:"<<endl;
    displayBoard(puzzle);

    cout<<endl<<"Solve the puzzle and enter your completed Sudoku:<<endl";

    int userBoard[N][N];

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>userBoard[i][j];

    if(isValidSudoku(userBoard))
        cout<<endl<<"Correct Solution!";
    else
        cout<<endl<<"Incorrect Solution.";

    return 0;
}