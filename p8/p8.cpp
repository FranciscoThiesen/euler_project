#include <bits/stdc++.h>

using namespace std;

long long mat[1000];

int main()
{
    ifstream in("big_num.txt");
    
    string x;
    for(int i = 0; i < 20; ++i) {
        string s;
        in >> s;
        x += s;
    }
    
    for(int i = 0; i < 1000; ++i) mat[i] = (x[i] - '0');

    long long best = 0; 
    for(int i = 0; i < 1000; ++i)
    {
        if( i + 12 >= 1000 ) continue;
        long long ans = mat[i];
        for(int j = 1; j < 13; ++j) ans = (ans * mat[i + j]);
        best = max(best, ans);
    }
    cout << best << '\n';
    return 0;
}
