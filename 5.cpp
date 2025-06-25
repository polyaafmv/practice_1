#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<int>> matrix(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> matrix[i][j];
        }
    }

    int min_row = INT_MAX, min_col = INT_MAX;
    int max_row = INT_MIN, max_col = INT_MIN;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (matrix[i][j] == 1) {
                if (i < min_row) min_row = i;
                if (j < min_col) min_col = j;
                if (i > max_row) max_row = i;
                if (j > max_col) max_col = j;
            }
        }
    }

    cout << min_row << " " << min_col << " " << max_row << " " << max_col << endl;

    return 0;
}