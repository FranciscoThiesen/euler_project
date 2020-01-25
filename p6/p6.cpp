#include <bits/stdc++.h>

using namespace std;

long long arithmetic_progression(int a, int b, int n) {
    long long resp = (a + b) * n;
    return resp / 2;
}

long long sum_squares(int a, int b) {
    long long resp = 0;
    for(long long i = a; i <= b; ++i) resp += (i * i);
    return resp;
}

int main()
{
    auto a = arithmetic_progression(1, 100, 100);
    a *= a;
    auto b = sum_squares(1, 100);
    cout << llabs(a - b) << endl;
    return 0;
}
