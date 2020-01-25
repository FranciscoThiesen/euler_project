#include <bits/stdc++.h>

using namespace std;

constexpr int lim = 1e7;
deque<bool> is_prime(lim, true);

int main()
{
    is_prime[0] = is_prime[1] = false;
    int prime_count = 0;
    for(long long i = 2; i < lim; ++i) {
        if( is_prime[i] ) {
            prime_count++;
            if( prime_count == 10001) cout << i << endl;
            for(long long j = i * i; j < lim; j += i) is_prime[j] = false;
        }
    }
    return 0;
}
