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

const int N = 2e5+10;
vector<vector<int>>divisors(N);

void solve()
{
    int n,ans = 0;
    cin>>n;
    vector<int>cnt(n+1,0), skip;
    vector<bool>check(n+1,false);
    for(int i = 1; i<=n; i++){
        int num;
        cin>>num;
        vector<int>check_next;
        for(auto &x: divisors[num]){
            cnt[x]++;
            if(cnt[x]==i){
                if(!check[x]){
                    check_next.push_back(x);
                    check[x] = true;
                }
            }else{
                ans = max(ans,cnt[x]);
            }
        }
        for(auto &x: skip){
            if(cnt[x]==i){
                check_next.push_back(x);
            }else{
                check[x] = false;
                ans = max(ans, cnt[x]);
            }
        }
        skip = check_next;
        cout<<ans<<" ";
    }
    cout<<endl;
}

int32_t main()
{
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    fastIO;
    cout.precision(10);
    cout.setf(ios::fixed);
    for(int i = 2; i<N; i++){
        for(int j = i; j<N; j+=i){
            divisors[j].push_back(i);
        }
    }
    int t = 1;
    cin >> t;
    for(int z = 1; z<=t; z++){
        // cout<<"Case "<<z<<": ";
        solve();
    }
}