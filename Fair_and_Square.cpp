#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

/****************************************************************/

#define int long long
#define pi acos(-1.0)
const int mod = 998244353;
#define inf 1e18+10
#define sz(x) (int)(x).size()
#define LSOne(x) ((x)&(-x))
#define all(x) x.begin(), x.end()
#define readv(v)      \
    for (auto &x : v) \
    cin >> x
#define endl "\n"
#define fastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
template <class T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update >;

#ifndef ONLINE_JUDGE
#include "debug.h"
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
#define debug(...)
#endif

/****************************************************************/


void solve()
{
    int n,m,cnt = 0, g = 0;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>grid[i][j];
            if(grid[i][j]=='.'){
                g = gcd(g,cnt);
                cnt = 0;
            }
            else
                cnt++;
        }
        g = gcd(g,cnt);
        cnt = 0;
    }
    for(int j = 0; j<m; j++){
        for(int i = 0; i<n; i++){
            if(grid[i][j]=='.'){
                g = gcd(g,cnt);
                cnt = 0;
            }
            else
                cnt++;
        }
        g = gcd(g,cnt);
        cnt = 0;
    }
    cout<<g<<endl;
}

int32_t main()
{
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    fastIO;
    cout.precision(10);
    cout.setf(ios::fixed);
    int t = 1;
    for(int z = 1; z<=t; z++){
        // cout<<"Case "<<z<<": ";
        solve();
    }
}