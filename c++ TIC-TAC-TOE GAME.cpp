#include <iostream>
#include <vector>

const int SIZE = 3; 
void display_board(const std::vector<std::vector<char>>& board) {
    std::cout << "\nCurrent Board:\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
}
bool check_win(const std::vector<std::vector<char>>& board, char player) {
    
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}
bool check_draw(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false; 
            }
        }
    }
    return true; 
}
void play_game() {
    std::vector<std::vector<char>> board(SIZE, std::vector<char>(SIZE, ' '));
    char current_player = 'X';
    bool game_over = false;

    while (!game_over) {
        display_board(board);
        int row, col;

        
        std::cout << "Player " << current_player << ", enter your move (row and column): ";
        std::cin >> row >> col;

        
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
            std::cout << "Invalid move. Try again.\n";
            continue;
        }
		board[row][col] = current_player;

        
        if (check_win(board, current_player)) {
            display_board(board);
            std::cout << "Player " << current_player << " wins!\n";
            game_over = true;
        } else if (check_draw(board)) {
            display_board(board);
            std::cout << "It's a draw!\n";
            game_over = true;
        } else {
            
            current_player = (current_player == 'X') ? 'O' : 'X';
        }
    }
}
int main() {
    char play_again;

    do {
        play_game();
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> play_again;
    } while (play_again == 'y' || play_again == 'Y');

    std::cout << "Thank you for playing!\n";
    return 0;
}

