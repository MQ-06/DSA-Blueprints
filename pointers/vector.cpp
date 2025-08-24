#include <iostream>
#include <vector>
using namespace std;

int main() {
    int depth = 2; // Depth (number of 2D layers)
    int rows = 3; // Number of rows in each layer
    int cols = 4; // Number of columns in each row
    vector<vector<vector<int>>> tensor(depth, vector<vector<int>>(rows, vector<int>(cols))); // Creates a 3D vector

    // Assign values
     int count = 1;
    for (int i = 0; i < tensor.size(); ++i) { // tensor.size() gives depth
        for (int j = 0; j < tensor[i].size(); ++j) { // tensor[i].size() gives number of rows
            for (int k = 0; k < tensor[i][j].size(); ++k) { // tensor[i][j].size() gives number of columns
                tensor[i][j][k] = count++; // Assigning values 1 to 24
            }
        }
    }

    // Output values
    for (const auto& matrix : tensor) {
        for (const auto& row : matrix) {
            for (const auto& val : row) {
                cout << val << " "; // Outputs: 1 to 24
            }
            cout << endl;
        }
        cout << endl; // Separate each layer
    }

    return 0;
}
