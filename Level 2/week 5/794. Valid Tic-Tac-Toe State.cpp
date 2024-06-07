
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int countX = 0, countO = 0;
        for (const string& row : board) {
            for (char c : row) {
                if (c == 'X') countX++;
                else if (c == 'O') countO++;
            }
        }
        if (countX != countO && countX != countO + 1) return false; // Invalid count of 'X' and 'O'
        if (win(board, 'X') && countX != countO + 1) return false; // 'X' wins but 'O' has more turns
        if (win(board, 'O') && countX != countO) return false; // 'O' wins but 'X' has more turns
        return true;
    }
    
    bool win(const vector<string>& board, char player) {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true; // Check rows
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true; // Check columns
        }
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true; // Check diagonal
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true; // Check reverse diagonal
        return false;
    }
};