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
#define pb push_back
#define ff first
#define ss second
#define sz(x) (int)(x).size()
#define LSOne(x) ((x)&(-x))
#define all(x) x.begin(), x.end()
#define readv(v)      \
    for (auto &x : v) \
    cin >> x
#define writev(v)     \
    for (auto &x : v) \
    cout << x << " "; \
    cout<<endl
#define endl "\n"
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define remove_punctuation(text) regex_replace(text, regex(R"([^\w\s])"), "")
#define fastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
template <class T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update >;

#ifndef ONLINE_JUDGE
#include "debug.h"
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
#define debug(...)
#endif

/****************************************************************/

struct DSU{
    vector<int>parent, _size;
    int n,cost;

    DSU(int _n){
        n = _n;
        parent.resize(n);
        iota(all(parent),0);
        _size.assign(n,1); 
        cost = 0;
    }
 
    int find(int i){ 
        if(parent[i]==i) return i; 
        return parent[i] = find(parent[i]); 
    } 
    
    int size(int a){ 
        a = find(a); 
        return _size[a]; 
    }
    
    void Union(int a, int b, int _cost){ 
        a = find(a); 
        b = find(b); 
        if(a==b) return; 
        cost+=_cost;
        if(_size[a]<_size[b]) swap(a,b);
        parent[b] = a; 
        _size[a]+=_size[b]; 
    }

    bool connected(){
        int cnt = 0;
        for(int i = 0;i<n; i++){
            if(parent[i]==i)
                cnt++;
        }
        return cnt<2;
    }
};

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<array<int,3>> edges(m);
    for(auto &[u,v,w]: edges){
        cin>>u>>v>>w;
        u--,v--;
    }
    sort(all(edges),[&](array<int,3>&a, array<int,3>&b){
        if(a[2]!=b[2])
            return a[2]<b[2];
        return a<b;
    });
    DSU d(n);
    for(auto &[u,v,w]: edges){
        d.Union(u,v,w);
    }
    if(d.connected()){
        cout<<d.cost<<endl;
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }
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