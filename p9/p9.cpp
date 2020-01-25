// START OF TEMPLATE CODE
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE( cout << #x" = " << x << endl)
#define PRINT(x) TRACE(printf(x))
#define WATCHR(a, b) TRACE( for(auto c = a; c != b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end()); } )
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(v) (int) (v).size()
#define rep(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define funoredered_map __fast_unordered_map

template<class Key, class Value, class Hash = std::hash<Key>>
using funordered_map = __gnu_pbds::gp_hash_table<Key, Value, Hash>;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdb = pair< double, double >;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vvi = vector<vi>;

constexpr int inf = 0x3f3f3f3f;
constexpr double eps = 1e-8;
constexpr ll MOD = 1000000007LL;

template <typename T>
using ordered_set = 
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

inline ll powmod( ll a, ll b, ll mod = MOD) {
    ll res = 1; a %= mod; assert(b >= 0);
    for(;b;b>>=1) {
        if(b&1) res = (res * a) % mod;
        a = (a * a) % mod;
    }
    return res;
}

void buff() { ios::sync_with_stdio(false); cin.tie(nullptr); }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// END OF TEMPLATE CODE

int main()
{
    buff(); 
    for(int i = 1; i < 1000; ++i) {
        for(int j = i; i + j < 1000; ++j) {
            int k = 1000 - i - j;
            if( i * i + j * j == k * k ) {
                cout << 1ll * i * j * k << endl;
                return 0;
            }
        }
    }
    return 0;
}

