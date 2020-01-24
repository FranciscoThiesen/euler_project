#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int ans = 2, total_elems = 2;
    vector<int> fib = {1, 2};
    
    constexpr int upper_limit = 4e6;

    while(fib.back() < upper_limit)
    {
        int nxt = fib[total_elems - 1] + fib[total_elems - 2];
        if(nxt > upper_limit) break; 
        if(nxt % 2 == 0) ans += nxt;
        fib.push_back(nxt);
        total_elems++;
    }
    
    cout << ans << endl;
    return 0;
}
