#include <bits/stdc++.h>

using namespace std;

unordered_map<long long, int> chain_len;

inline int go(long long v) {
    if(chain_len[v]) return chain_len[v];
    if(v % 2 == 0) return chain_len[v] = go((v/2)) + 1;
    return chain_len[v] = go((v * 3 + 1)) + 1;
}

int main()
{
    chain_len[1] = 1;
    int longest = 1;
    for(int i = 2; i <= 1e6; ++i) {
        int res = go(i);
        if(res > chain_len[longest]) longest = i;
    }
    cout << longest << endl;
    return 0;
}
