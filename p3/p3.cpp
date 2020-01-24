#include <bits/stdc++.h>

using namespace std;


long long factorize(long long n)
{
    long long resp = -1;
    long long limit = n;
    for(long long f = 2; f * f <= limit; ++f)
    {
        while(n % f == 0) {
            resp = max(resp, f);
            n /= f;
        }
    }
    if(n > 1) resp = max(resp, n);
    return resp;
}


int main()
{
    cout << factorize(600851475143) << endl;

}
