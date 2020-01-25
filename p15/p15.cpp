#include <bits/stdc++.h>

using namespace std;

long long dp[21][21];

int main()
{
    dp[0][0] = 1ll;
    for(int i = 0; i < 21; ++i) {
        for(int j = 0; j < 21; ++j) {
            if( i - 1 >= 0 ) dp[i][j] = dp[i - 1][j];
            if( j - 1 >= 0 ) dp[i][j] += dp[i][j - 1];
        }
    }
    cout << dp[20][20] << endl;
    return 0;
}
