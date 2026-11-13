#include <iostream>
using namespace std;

int main() {
    // 1. Original 4x5 Sparse Matrix (mostly zeros)
    const int ROWS = 4;
    const int COLS = 5;
    int sparseMatrix[ROWS][COLS] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    // 2. Count total non-zero elements
    int nonZeroCount = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (sparseMatrix[i][j] != 0) {
                nonZeroCount++;
            }
        }
    }

    // 3. Create 3-tuple array: (nonZeroCount + 1) rows x 3 columns
    int triplet[20][3];

    // Row 0 stores matrix summary metadata
    triplet[0][0] = ROWS;
    triplet[0][1] = COLS;
    triplet[0][2] = nonZeroCount;

    // 4. Fill remaining rows with [Row, Col, Value] of non-zero items
    int k = 1;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (sparseMatrix[i][j] != 0) {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = sparseMatrix[i][j];
                k++;
            }
        }
    }

    // 5. Display the 3-tuple array
    cout << "Sparse Matrix 3-Tuple Representation (0-indexed):\n";
    cout << "Row\tCol\tValue\n";
    cout << "---------------------\n";
    for (int i = 0; i <= nonZeroCount; i++) {
        cout << triplet[i][0] << "\t"
             << triplet[i][1] << "\t"
             << triplet[i][2] << "\n";
    }

    return 0;
}