#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

/****************************************************************/

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
    int n,m;
    cin>>n>>m;
    map<int,pair<int,int>>pos;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            int x;
            cin>>x;
            pos[x] = {i,j};
        }
    }
    int mex;
    set<pair<int,int>>s;
    s.insert({0,0});
    s.insert({n+1,m+1});
    for(mex = 0; mex<n*m ; mex++){
        auto [r,c] = pos[mex];
        // debug(r) debug(c)
        auto it = s.upper_bound({r,c});
        auto pre = prev(it);
        // debug(mex) debug(*pre) debug(*it)
        auto [lr,lc] = *pre;
        auto [rr,rc] = *it;
        if(r>=lr and r<=rr and c>=lc and c<=rc){
            s.insert({r,c});
            continue;
        }else{
            break;
        }
    }
    cout<<mex<<endl;
}

int32_t main()
{
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    fastIO;
    cout.precision(10);
    cout.setf(ios::fixed);
    int t = 1;
    cin >> t;
    for(int z = 1; z<=t; z++){
        // cout<<"Case "<<z<<": ";
        solve();
    }
}