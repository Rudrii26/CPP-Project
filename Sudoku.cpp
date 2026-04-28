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