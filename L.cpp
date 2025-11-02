#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

/****************************************************************/

#define int long long
#define pi acos(-1.0)
const int mod = 998244353;
#define inf 1e18 + 10
#define sz(x) (int)(x).size()
#define LSOne(x) ((x) & (-x))
#define all(x) x.begin(), x.end()
#define readv(v)      \
    for (auto &x : v) \
    cin >> x
#define endl "\n"
#define fastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
template <class T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#ifndef ONLINE_JUDGE
#include "debug.h"
#define debug(x)         \
    cerr << #x << " = "; \
    _print(x);           \
    cerr << endl;
#else
#define debug(...)
#endif

/****************************************************************/

// Precalculate parents first in main

int expo(int a, int b, int m) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}
int mminvprime(int a, int b) {return expo(a, b - 2, b);}

const int N = 1e5 + 10;
vector<vector<int>> divisors(N);
vector<vector<int>> t, parents;
vector<int> level;
int mx;
int p = 31;
vector<int> hashes;
string str;

void dfs(int node, int parent, int cLevel, int hash)
{
    hashes[node] = hash;
    level[node] = cLevel;
    parents[0][node] = parent;
    for (auto &x : t[node])
    {
        int new_hash = hash + (((str[x - 2] - 'a') + 1) * expo(p, cLevel + 1, mod)) % mod;
        new_hash %= mod;
        dfs(x, node, cLevel + 1, new_hash);
    }
}

int kthParent(int a, int k)
{
    for (int i = 0; i < mx; i++)
    {
        if (a == -1)
            return a;
        if (k & (1 << i))
            a = parents[i][a];
    }
    return a;
}


void solve()
{
    int n, ans = 1;
    cin >> n;
    mx = log2(n) + 2;
    level.resize(n+1);
    parents.resize(mx, vector<int>(n + 1));
    hashes.resize(n + 1);
    t.resize(n + 1);
    for (int i = 2; i <= n; i++){
        int p;
        cin >> p;
        t[p].push_back(i);
    }
    cin >> str;
    dfs(1, -1, 0, 0);
    for (int i = 1; i < mx; i++){
        for (int j = 1; j <= n; j++){
            int prev_par = parents[i - 1][j];
            if(prev_par!=-1)
                parents[i][j] = parents[i - 1][prev_par];
        }
    }
    for (int i = 2; i <= n; i++){
        int d = level[i];
        if(d==1)
            continue;
        for(auto &div: divisors[d]){
            int pre_hash = hashes[kthParent(i, d - div)];
            int r = expo(p, div, mod), tn = d/div;
            int rn = expo(r, tn, mod);
            int nom = 1 - rn + mod;
            int denom = 1 - r + mod;
            denom = mminvprime(denom, mod);
            int new_hash = ((pre_hash * nom) % mod * denom) % mod;
            if(new_hash==hashes[i]){
                ans = max(ans, div);
                break;
            }
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    fastIO;
    cout.precision(10);
    cout.setf(ios::fixed);
    for (int i = 1; i < N; i++){
        reverse(all(divisors[i]));
        for (int j = i + i; j < N; j+=i)
            divisors[j].push_back(i);
    }
    int t = 1;
    for (int z = 1; z <= t; z++)
    {
        // cout<<"Case "<<z<<": ";
        solve();
    }
}