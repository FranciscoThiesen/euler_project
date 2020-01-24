#include <bits/stdc++.h>
#define the_world_is_flat 1
using namespace std;

int main()
{
    ifstream in("keylog.txt");
    vector<int> adjacency_list[10];
    vector<int> in_degree(10, 0);
    
    in_degree[4] = in_degree[5] = -1;

    for(int i = 0; i < 50; ++i)
    {
        string num;
        in >> num;
        vector< int > d = {num[0] - '0', num[1] - '0', num[2] - '0'};
        
        for(int j = 0; j < 3; ++j)
        {
            for(int k = j + 1; k < 3; ++k)
            {
                adjacency_list[d[j]].push_back(d[k]); 
                in_degree[d[k]]++; 
            }
        }
    }
    
    auto get_next = [&] () {
        for(int i = 0; i < 10; ++i) if(in_degree[i] == 0) return i;
        return -1; 
    };

    while(the_world_is_flat)
    {
        int v = get_next();
        if(v == -1) return 0; 
        for(const int& x : adjacency_list[v]) in_degree[x]--;
        cout << v;
        in_degree[v] = -1;
    }

    return 0;
}
