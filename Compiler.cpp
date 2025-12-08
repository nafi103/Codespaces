#include <bits/stdc++.h>

using namespace std;

/****************************************************************/

#define int long long
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define endl "\n"
const int mod = 998244353;
const int inf = 1e18 + 10;

#ifndef ONLINE_JUDGE
#include "debug.h"
#define debug(x)                                        \
    cerr << "Line " << __LINE__ << ": " << #x << " = "; \
    _print(x);                                          \
    cerr << endl;
#else
#define debug(...)
#endif

/****************************************************************/

const int MAXN = 200;
vector<int> adj[MAXN];
char val[MAXN];
int pos[MAXN], nodeIdx = 0;

int newNode(char c)
{
    nodeIdx++;
    val[nodeIdx] = c;
    pos[nodeIdx] = 0;
    adj[nodeIdx].clear();
    return nodeIdx;
}

bool isOp(char c) { 
    return isalnum(c) || c == '#'; 
}

int prec(char c)
{
    if (c == '*')
    {
        return 3;
    }
    else if (c == '.')
    {
        return 2;
    }
    else if (c == '|')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void printInorder(int u)
{
    if (adj[u].size() > 0)
        printInorder(adj[u][0]);
    cout << val[u];
    if (pos[u])
        cout << "(pos:" << pos[u] << ")";
    cout << " ";
    if (adj[u].size() > 1)
        printInorder(adj[u][1]);
}

int32_t main()
{
    string raw, s = "";
    cout << "Enter Regular Expression: ";
    cin >> raw;

    string aug = "(" + raw + ")#";
    for (int i = 0; i < aug.size(); i++)
    {
        s += aug[i];
        if (i + 1 < aug.size())
        {
            char l = aug[i], r = aug[i + 1];
            if ((isOp(l) || l == '*' || l == ')') && (isOp(r) || r == '('))
                s += '.';
        }
    }

    string post = "";
    stack<char> ops;
    for (char c : s)
    {
        if (isOp(c))
            post += c;
        else if (c == '(')
            ops.push(c);
        else if (c == ')')
        {
            while (ops.top() != '(')
            {
                post += ops.top();
                ops.pop();
            }
            ops.pop();
        }
        else
        {
            while (!ops.empty() && prec(ops.top()) >= prec(c))
            {
                post += ops.top();
                ops.pop();
            }
            ops.push(c);
        }
    }
    while (!ops.empty())
    {
        post += ops.top();
        ops.pop();
    }

    stack<int> st;
    int leafCnt = 0;
    for (char c : post)
    {
        int u = newNode(c);
        if (isOp(c))
            pos[u] = ++leafCnt;
        else if (c == '*')
        {
            adj[u].push_back(st.top());
            st.pop();
        }
        else
        {
            int r = st.top();
            st.pop();
            int l = st.top();
            st.pop();
            adj[u].push_back(l);
            adj[u].push_back(r);
        }
        st.push(u);
    }

    cout << "Formatted: " << s << "\nTree (Inorder): ";
    if (!st.empty())
        printInorder(st.top());
    cout << endl;
    return 0;
}
