#include <bits/stdc++.h>

using namespace std;

int get_len(int num) {
    string s = to_string(num);
    string c = s;
    reverse(c.begin(), c.end());
    if(s == c) return (int) s.size();
    return -1;
}

int main()
{
    int best = -1;
    int resp = -1;
    for(int i = 100; i < 1000; ++i) {
        for(int j = 100; j < 1000; ++j) {
            int go = i * j;
            if(get_len(go) > best) {
                best = get_len(go);
                resp = go;
            }
            if(get_len(go) == best) resp = max(resp, go);
        }
    }
    cout << resp << endl;
    return 0;
}
