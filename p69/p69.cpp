#include <bits/stdc++.h>

using namespace std;


constexpr int ms = 1e6 + 13;
deque<bool> is_prime(ms, true);


void sieve(int limit) {
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i * i <= limit; ++i) {
        if(is_prime[i]) {
            for(int j = i * i; j < ms; j += i) is_prime[j] = false;
        } 
    }
}

vector<int> phi;
void calc_phi(int n) {
    phi.resize(n + 1);
    iota(phi.begin(), phi.end(), 0);
    for(int i = 1; i <= n; ++i) {
        if( is_prime[i] == true ) {
            for(int j = i; j <= n; j += i) phi[j] -= (phi[j] / i);
        }
    }
}

int main()
{
    sieve(ms);
    calc_phi(ms);
    int best = 1;
    double ans = 1.0;
    for(int i = 2; i <= 1e6; ++i) {
        double cur = 1.0 * i / phi[i];
        if(cur > ans) {
            ans = cur;
            best = i;
        }
    }
    cout << best << '\n';
    return 0;
}
