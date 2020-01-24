#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

vector< pii > dirs = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

inline bool check_prime(const int n) 
{
    if(n <= 1) return false;
    if(n == 2 || n == 3) return true;
    for(int i = 2; i * i <= n; ++i)
    {
        if(n % i == 0) return false;
    }
    return true;
}

unordered_map<int, int> prime_per_square_size;

void gen_diag(int upper_limit)
{
    int tam = 2;
    int sqr_sz = 3;
    int cur = 1;
    while(cur < upper_limit)
    {
        for(int i = 0; i < 4; ++i)
        {
            cur += tam;
            if( check_prime(cur) )
            {
                prime_per_square_size[sqr_sz]++; 
            }
        }
        tam += 2;
        sqr_sz += 2;
    }
}

int main()
{
    constexpr int upper_lim = 2e9;
    gen_diag(upper_lim);
    
    int total_primes = 0;
    int total_numbers = 1;
    for(int sqr_sz = 3; sqr_sz <= 44719; sqr_sz += 2)
    {
        total_numbers += 4; 
        total_primes += prime_per_square_size[sqr_sz];
        if( total_primes * 10 < total_numbers )
        {
            cout << "Resposta = Espiral de lado = " << sqr_sz << endl;
            return 0;
        }
    }
    return 0;
}
