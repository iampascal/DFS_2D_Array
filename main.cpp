#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void printStack(stack<pair<int, int>>& stk) {
    // Create a copy of the stack
    stack<pair<int, int>> temp = stk;

    // Print each element of the stack
    while (!temp.empty()) {
        pair<int, int> current = temp.top();
        cout << " Currently in Stack: (" << current.first << "," << current.second << ") " << '\n';
        temp.pop();
    }
    cout << endl;
}


bool isValid(int row, int col, const vector<vector<int>>& grid) {
    int numRows = grid.size();
    if (numRows == 0) return false;
    int numCols = grid[0].size();
    return (row >= 0 && row < numRows && col >= 0 && col < numCols);
}

void updateConnectedElement(vector<vector<int>>& inputMatrix, int xPosition, int yPosition) {
    // Defines possible movements
    int xDirection[] = {1, -1, 0, 0};
    int yDirection[] = {0, 0, 1, -1};

    int rows = inputMatrix.size();
    int cols = inputMatrix[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false)); // Visited array

    stack<pair<int,int>> neighbourStack;
    neighbourStack.push({xPosition, yPosition});

    while (!neighbourStack.empty()) {
        pair<int, int> current = neighbourStack.top();
        neighbourStack.pop();

        int row = current.first;
        int col = current.second;

        visited[row][col] = true;
        cout << "(" << row << "," << col << ") ";

        for (int i = 0; i < 4; ++i) {
            int newRow = row + xDirection[i];
            int newCol = col + yDirection[i];

            if (isValid(newRow, newCol, inputMatrix) && !visited[newRow][newCol]) {
                neighbourStack.push({newRow, newCol});
            }
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
    };

    updateConnectedElement(matrix, 0, 0);

    // Print the matrix
    for (const auto &row: matrix) {
        for (const auto &element: row) {
            cout << element << " ";
        }
        cout << '\n';
    }

    return 0;
}
