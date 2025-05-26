#include <iostream> 
#include <iomanip> 
#include <vector> 
#include <algorithm> 
using namespace std; 
 
const int N = 8; 
 
// Possible knight moves 
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2}; 
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1}; 
 
// Check if move is within bounds and unvisited 
bool isSafe(int x, int y, vector<vector<int>>& board) { 
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1); 
} 
 
// Count onward moves from position (x, y) 
int countOnwardMoves(int x, int y, vector<vector<int>>& board) { 
    int count = 0; 
    for (int i = 0; i < 8; i++) { 
        int nx = x + dx[i], ny = y + dy[i]; 
        if (isSafe(nx, ny, board)) count++; 
    } 
    return count; 
} 
 
// Warnsdorff's Knight Tour function 
bool knightTour(int x, int y, int movei, vector<vector<int>>& 
board) { 
    if (movei == N * N) return true; 
 
    vector<pair<int, pair<int, int>>> nextMoves; 
 
    for (int i = 0; i < 8; i++) { 
        int nx = x + dx[i], ny = y + dy[i]; 
        if (isSafe(nx, ny, board)) { 
            int c = countOnwardMoves(nx, ny, board); 
            nextMoves.push_back({c, {nx, ny}}); 
        } 
    } 
 
    // Sort next moves by least onward moves (Warnsdorff's rule) 
 
    sort(nextMoves.begin(), nextMoves.end()); 
 
    for (auto move : nextMoves) { 
        int nx = move.second.first; 
        int ny = move.second.second; 
        board[nx][ny] = movei; 
        if (knightTour(nx, ny, movei + 1, board)) return true; 
        board[nx][ny] = -1; // Backtrack 
    } 
 
    return false; 
} 
 
// Display the board 
void printBoard(const vector<vector<int>>& board) { 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) { 
            cout << setw(2) << board[i][j] << " "; 
        } 
        cout << endl; 
    } 
} 
 
int main() { 
    vector<vector<int>> board(N, vector<int>(N, -1)); 
 
    int startX, startY; 
    cout << "Enter starting X (0-7): "; 
    cin >> startX; 
    cout << "Enter starting Y (0-7): "; 
    cin >> startY; 
 
    board[startX][startY] = 0; 
 
    if (knightTour(startX, startY, 1, board)) { 
        cout << "\nKnight's Tour using Warnsdorff's Rule:\n"; 
        printBoard(board); 
    } else { 
        cout << "No solution found.\n"; 
    } 
 
    return 0; 
} 
