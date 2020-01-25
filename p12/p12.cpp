#include <bits/stdc++.h>

using namespace std;

int count_div(int x)
{
    vector<int> prime_powers;
    int cur = x;
    for(int i = 2; i * i <= x && cur > 1; ++i) {
        if( cur % i == 0 ) {
            int power = 1;
            while( cur % i == 0 ) {
                cur /= i;
                power++; 
            }
            prime_powers.push_back(power);
        }
    }
    if(cur > 1) prime_powers.push_back(2);
    int ans = accumulate(prime_powers.begin(), prime_powers.end(), 1, [&] (int a, int b) { return a * b; } );
    return ans;
}

int main()
{
    int add = 2;
    int cur = 1;
    while(count_div(cur) <= 500) {
        cur += add;
        ++add;
    }
    cout << cur << endl;
    return 0;
}
