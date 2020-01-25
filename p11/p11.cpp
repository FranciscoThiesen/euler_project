#include <bits/stdc++.h>

using namespace std;

int mat[20][20];
pair<int, int> dirs[8] = { {0, 1}, {1, 0}, {1, 1}, {-1, -1}, {-1, 0}, {0, -1}, {1, -1}, {-1, 1} };


inline bool valid(int a, int b) { return ( a >= 0 && a < 20 && b >= 0 && b < 20); }


int main()
{
    ifstream in("mat.txt");
    for(int i = 0; i < 20; ++i) {
        for(int j = 0; j < 20; ++j) {
            in >> mat[i][j];
        }
    }

    int best = 0; 
    for(int i = 0; i < 20; ++i) {
        for(int j = 0; j < 20; ++j) {
            for(int d = 0; d < 8; ++d) {
                if( valid(i + 3 * dirs[d].first, j + 3 * dirs[d].second) ) {
                    int res = mat[i][j];
                    for(int k = 1; k <= 3; ++k) res *= mat[i + k * dirs[d].first][j + k * dirs[d].second];
                    best = max(best, res);
                }
            }
        }
    }
    cout << best << endl;
    return 0;
}
