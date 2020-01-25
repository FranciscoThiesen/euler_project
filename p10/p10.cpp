#include <bits/stdc++.h>

using namespace std;

constexpr int ms = 2e6 + 1;
deque<bool> is_prime(ms, true);

int main()
{
    is_prime[0] = is_prime[1] = false;
    long long ans = 0; 
    for(long long i = 2; i < ms; ++i) {
        if(is_prime[i]) {
            ans += i;
            for(long long j = i * i; j < ms; j += i) is_prime[j] = false;
        }
    }
    cout << ans << endl;
    return 0;
}
