#include <bits/stdc++.h>

using namespace std;

inline bool good(int n) { return (n % 2 != 0 && n % 5 != 0); }

long long calc_order(int b)
{
    int cur = 10;
    int len = 1;
    while( cur != 1 ) cur = ( cur * 10 ) % b, ++len;
    return len;
}

int main()
{
    ios::sync_with_stdio( false ); cin.tie(nullptr);
    int longest = -1;
    int best = -1;
    for(int i = 3; i < 1001; ++i)
    {
        if( !good(i) ) continue;
        int resp = calc_order(i);
        if( resp > longest ) {
            longest = resp;
            best = i;
        }
    }
    cout << best << '\n';
    return 0;
}
