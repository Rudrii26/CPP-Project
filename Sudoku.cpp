// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// using namespace std;

// const int N = 9;

// // Display Sudoku board
// void displayBoard(int board[N][N]) {

//     cout << endl;

//     for(int i=0;i<N;i++) {

//         if(i%3==0 && i!=0)
//             cout<<"---------------------"<<endl;

//         for(int j=0;j<N;j++) {

//             if(j%3==0 && j!=0)
//                 cout<<"| ";

//             cout<<board[i][j]<<" ";
//         }

//         cout<<endl;
//     }
// }

// // Check row
// bool checkRow(int board[N][N], int row) {

//     bool used[10] = {false};

//     for(int col=0; col<N; col++) {

//         int num = board[row][col];

//         if(num<1 || num>9 || used[num])
//             return false;

//         used[num] = true;
//     }

//     return true;
// }

// // Check column
// bool checkCol(int board[N][N], int col) {

//     bool used[10] = {false};

//     for(int row=0; row<N; row++) {

//         int num = board[row][col];

//         if(num<1 || num>9 || used[num])
//             return false;

//         used[num] = true;
//     }

//     return true;
// }

// // Check 3x3 box
// bool checkBox(int board[N][N], int startRow, int startCol) {

//     bool used[10] = {false};

//     for(int i=0;i<3;i++)
//         for(int j=0;j<3;j++) {

//             int num = board[i+startRow][j+startCol];

//             if(num<1 || num>9 || used[num])
//                 return false;

//             used[num] = true;
//         }

//     return true;
// }

// // Validate Sudoku solution
// bool isValidSudoku(int board[N][N]) {

//     for(int i=0;i<9;i++) {

//         if(!checkRow(board,i) || !checkCol(board,i))
//             return false;
//     }

//     for(int i=0;i<9;i+=3)
//         for(int j=0;j<9;j+=3)

//             if(!checkBox(board,i,j))
//                 return false;

//     return true;
// }

// // Remove random numbers
// void removeNumbers(int board[N][N], int count) {

//     while(count>0) {

//         int row = rand()%9;
//         int col = rand()%9;

//         if(board[row][col]!=0) {

//             board[row][col]=0;
//             count--;
//         }
//     }
// }

// int main() {

//     srand(time(0));

//     int puzzle[N][N] = {
//     {5,3,4,6,7,8,9,1,2},
//     {6,7,2,1,9,5,3,4,8},
//     {1,9,8,3,4,2,5,6,7},
//     {8,5,9,7,6,1,4,2,3},
//     {4,2,6,8,5,3,7,9,1},
//     {7,1,3,9,2,4,8,5,6},
//     {9,6,1,5,3,7,2,8,4},
//     {2,8,7,4,1,9,6,3,5},
//     {3,4,5,2,8,6,1,7,9}
//     };

//     // create puzzle
//     removeNumbers(puzzle,40);

//     cout<<"Generated Sudoku Puzzle:"<<endl;
//     displayBoard(puzzle);

//     cout<<endl<<"Solve the puzzle and enter your completed Sudoku:"<<endl;

//     int userBoard[N][N];

//     for(int i=0;i<N;i++)
//         for(int j=0;j<N;j++)
//             cin>>userBoard[i][j];

//     if(isValidSudoku(userBoard))
//         cout<<endl<<"Correct Solution!";
//     else
//         cout<<endl<<"Incorrect Solution.";

//     return 0;
// }






// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// using namespace std;

// const int N = 9;

// // Display board
// void displayBoard(int board[N][N]) {
//     cout << "\n+-------+-------+-------+\n";
//     for(int i=0;i<9;i++) {
//         cout << "| ";
//         for(int j=0;j<9;j++) {
//             if(board[i][j] == 0)
//                 cout << ". ";
//             else
//                 cout << board[i][j] << " ";

//             if((j+1)%3==0)
//                 cout << "| ";
//         }
//         cout << endl;
//         if((i+1)%3==0)
//             cout << "+-------+-------+-------+\n";
//     }
// }

// // Check validity
// bool isSafe(int board[N][N], int row, int col, int num) {

//     for(int j=0;j<9;j++)
//         if(board[row][j] == num)
//             return false;

//     for(int i=0;i<9;i++)
//         if(board[i][col] == num)
//             return false;

//     int sr = row - row%3;
//     int sc = col - col%3;

//     for(int i=0;i<3;i++)
//         for(int j=0;j<3;j++)
//             if(board[sr+i][sc+j] == num)
//                 return false;

//     return true;
// }

// // Check complete
// bool isComplete(int board[N][N]) {
//     for(int i=0;i<9;i++)
//         for(int j=0;j<9;j++)
//             if(board[i][j] == 0)
//                 return false;
//     return true;
// }

// // Remove numbers
// void removeNumbers(int board[N][N], int count) {
//     while(count>0) {
//         int r = rand()%9;
//         int c = rand()%9;

//         if(board[r][c] != 0) {
//             board[r][c] = 0;
//             count--;
//         }
//     }
// }

// int main() {

//     srand(time(0));

//     int board[N][N] = {
//     {5,3,4,6,7,8,9,1,2},
//     {6,7,2,1,9,5,3,4,8},
//     {1,9,8,3,4,2,5,6,7},
//     {8,5,9,7,6,1,4,2,3},
//     {4,2,6,8,5,3,7,9,1},
//     {7,1,3,9,2,4,8,5,6},
//     {9,6,1,5,3,7,2,8,4},
//     {2,8,7,4,1,9,6,3,5},
//     {3,4,5,2,8,6,1,7,9}
//     };

//     removeNumbers(board, 40);

//     cout << "Sudoku Game\n";

//     while(true) {

//         displayBoard(board);

//         if(isComplete(board)) {
//             cout << "\nCompleted!";
//             break;
//         }

//         int row, col, num;

//         cout << "\nEnter row and column of empty cell (1-9 1-9): ";
//         cin >> row >> col;

//         row--; col--;

//         if(board[row][col] != 0) {
//             cout << "Already filled!\n";
//             continue;
//         }

//         cout << "Enter number: ";
//         cin >> num;

//         if(isSafe(board,row,col,num)) {
//             board[row][col] = num;
//             cout << "Correct!\n";
//         } else {
//             cout << "Wrong!\n";
//         }
//     }

//     return 0;
// }


#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

const int SIZE = 9;

int board[SIZE][SIZE] = {
    {5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {0,9,8,0,0,0,0,6,0},
    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,0,0,1},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,7,9}
};

int original[SIZE][SIZE];

bool isSafe(int row, int col, int num) {
    for(int i=0;i<9;i++) {
        if(board[row][i]==num || board[i][col]==num)
            return false;
    }

    int sr = row - row%3;
    int sc = col - col%3;

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[sr+i][sc+j]==num)
                return false;

    return true;
}

int main() {

    // copy original board
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            original[i][j] = board[i][j];

    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(540,540)), "Sudoku");

    sf::Font font;
    if(!font.openFromFile("arial.ttf")) {
        cout<<"Font not found!\n";
        return -1;
    }

    int selectedRow = -1, selectedCol = -1;

    while(window.isOpen()) {

        while(auto event = window.pollEvent()) {

            // Close window
            if(event->is<sf::Event::Closed>())
                window.close();

            // Mouse click
            if(auto mouse = event->getIf<sf::Event::MouseButtonPressed>()) {

                int x = mouse->position.x / 60;
                int y = mouse->position.y / 60;

                if(x >= 0 && x < 9 && y >= 0 && y < 9) {
                    selectedCol = x;
                    selectedRow = y;
                }
            }

            // Keyboard input
            if(auto text = event->getIf<sf::Event::TextEntered>()) {

                if(selectedRow != -1 && selectedCol != -1 &&
                   original[selectedRow][selectedCol] == 0) {

                    int num = text->unicode - '0';

                    if(num >=1 && num <=9) {

                        if(isSafe(selectedRow, selectedCol, num)) {
                            board[selectedRow][selectedCol] = num;
                        } else {
                            cout<<"Wrong move!\n";
                        }
                    }
                }
            }
        }

        window.clear(sf::Color::White);

        // Highlight selected cell
        if(selectedRow != -1 && selectedCol != -1) {
            sf::RectangleShape highlight(sf::Vector2f(60.f,60.f));
            highlight.setPosition(sf::Vector2f(selectedCol*60.f, selectedRow*60.f));
            highlight.setFillColor(sf::Color(200,200,255,100));
            window.draw(highlight);
        }

        // Draw grid
        for(int i=0;i<=9;i++) {

            sf::RectangleShape line;

            // vertical
            line.setSize(sf::Vector2f((i%3==0)?4.f:1.f, 540.f));
            line.setPosition(sf::Vector2f(i*60.f,0.f));
            line.setFillColor(sf::Color::Black);
            window.draw(line);

            // horizontal
            line.setSize(sf::Vector2f(540.f,(i%3==0)?4.f:1.f));
            line.setPosition(sf::Vector2f(0.f,i*60.f));
            window.draw(line);
        }

        // Draw numbers
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {

                if(board[i][j] != 0) {

                    sf::Text text(font, to_string(board[i][j]), 30);

                    if(original[i][j] != 0)
                        text.setFillColor(sf::Color::Black);
                    else
                        text.setFillColor(sf::Color::Blue);

                    text.setPosition(sf::Vector2f(j*60.f+20.f, i*60.f+10.f));

                    window.draw(text);
                }
            }
        }

        window.display();
    }

    return 0;
}