#include <cstdint>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

namespace boardutils {
    void printBoard(const std::vector<char>& board) {
        std::cout << "\n{\n";
        for (int i = 1; i < 10; i++) {
            std::cout << board[i - 1] << ' ';

            if ((i ) % 3 == 0)
                std::cout << "\n";
        }

        std::cout << "}\n";
    }

    char getPlayer(uint8_t idx) {
        return (idx % 2 == 0) ? 'A' : 'B';
    }


    char get(uint8_t idx) {
        return boardutils::getPlayer(idx) == 'A' ? 'X' : '0';
    }

    void pushAtBoard( std::vector<char>& board,short idx,short input) {
        board.at(input - 1) = boardutils::get(idx);
    }

    bool checkForWin(std::vector<char>& board,char p) {
        return ((board[0] == p && board[1] == p && board[2] == p) ||
        (board[3] == p && board[4] == p && board[5] == p) ||
         (board[6] == p && board[7] == p && board[8] == p) ||
        (board[0] == p && board[3] == p && board[6] == p)  ||
         (board[1] == p && board[4] == p && board[7] == p) ||
          (board[2] == p && board[5] == p && board[8] == p) ||
        (board[0] == p && board[4] == p && board[8] == p)||
        (board[2] == p && board[4] == p && board[6] == p) );
    }

}


int main() {
    std::vector<char> board;
    board.resize(9,'-');

    bool win = false;

    for (uint8_t i = 0 ; i < 9 && !win;) {

        if ( i >= 10)
            continue;

        short input;
        std::cout << std::endl;
        std::cout << boardutils::getPlayer(i) << " выберите ячейку: ";
        std::cin >> input;

        if (board[input - 1] != '-') {
            std::cout << "клетка занята\n";
            continue;
        }

        boardutils::pushAtBoard(board,i,input);
        boardutils::printBoard(board);

        win = boardutils::checkForWin(board,boardutils::get(i));

        if (win)
            std::cout << "игрок " << boardutils::getPlayer(i) << " выиграл!" << std::endl;
        i++;
    }

}