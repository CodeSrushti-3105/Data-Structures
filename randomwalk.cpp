#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX = 10; // Maximum size for demonstration

struct Position {
    int x, y;
};

// Function to check if all tiles have been visited
bool allVisited(bool visited[MAX][MAX], int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!visited[i][j])
                return false;
    return true;
}

int main() {
    int n = 5, m = 5; // Room size (change as needed)
    bool visited[MAX][MAX] = {false};

    Position cockroach = {n / 2, m / 2}; // Start in the middle
    visited[cockroach.x][cockroach.y] = true;
    
    int moves = 0;
    srand(time(0));

    while (!allVisited(visited, n, m)) {
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}; // Possible moves (vertical, horizontal, diagonal)
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        int moveIndex = rand() % 8;
        int newX = cockroach.x + dx[moveIndex];
        int newY = cockroach.y + dy[moveIndex];

        if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
            cockroach.x = newX;
            cockroach.y = newY;
            visited[newX][newY] = true;
            moves++;
        }
    }

    cout << "The drunken cockroach touched all tiles in " << moves << " moves.\n";
    return 0;
}
