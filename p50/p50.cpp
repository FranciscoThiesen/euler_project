#include <bits/stdc++.h>
#define TRACE(x) x
using namespace std;

constexpr int ms = 1000 * 1000 + 10;

unordered_map<long long, int> hashTable; // -> Vamo guardar o numero e o tamanho da maior soma de primos consecutivos que = X

deque<bool> isPrime(ms, true);
vector<int> primes;

void crivo() {
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i < ms; ++i) {
        if( isPrime[i] == true ) {
            primes.push_back(i);
            for(long long j = 1LL * i * i; j < ms; j += i) {
                isPrime[j] = 0;
            }
        }
    }
}

bool checkPrime(int n) {
    return isPrime[n];
}

int main()
{
    crivo();
    
    int len = (int) primes.size();
    
    vector<int> somaAcumulada(len + 1, 0LL);
    for(int i = 0; i < len; ++i) somaAcumulada[i + 1] = somaAcumulada[i] + primes[i];
    
    for(int st = 1; st <= len; ++st) {
        for(int nd = st + 1; nd <= len; ++nd) {
            int valor = somaAcumulada[nd] - somaAcumulada[st - 1];
            if( valor < 1000000 && checkPrime(valor) ) {
                int totalDePrimos = nd - st + 1;
                hashTable[valor] = max( hashTable[valor], totalDePrimos);
            }
            else if( valor > 1000000 ) break;
        }
    }
    int maiorSequencia = 0;
    long long melhorPrimo = -1;
    
    for(const auto& par : hashTable) {
        if( par.second > maiorSequencia) {
            melhorPrimo = par.first;
            maiorSequencia = par.second;
        }
    } 
    cout << melhorPrimo << endl; 
    return 0;
}
