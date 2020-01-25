#include <bits/stdc++.h>

using namespace std;

long long lcm(long long a, long long b) {
    return a / __gcd(a,b) * b;
}

int main()
{
    long long res = 1;
    for(long long i = 2; i <= 20; ++i) res = lcm(res, i);
    cout << res << endl;
    return 0;
}
