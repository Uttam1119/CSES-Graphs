/*
Connected components nikaalne k liye for loop k thru har node me iterate krna hai.
and har unvisited node k liye new queue initialize hoga
but visited array sb k liye ek hi hoga.. means only one visited array for the whole question
*/

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define repb(i, a, b) for (int i = a; i >= b; i--)
#define endl '\n'
#define print(x) cout << x << endl
#define printInline(x) cout << x << " "

#define ll long long
#define lli long long int

bool inrange(int x, int y, int n, int m){
    return (x >= 0 && x < n && y >= 0 && y < m);
}
ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, 1, 0, -1};
void solve(){
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> v(n);
        while (m--)
        {
            ll x, y;
            cin >> x >> y;
            x--;
            y--;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        vector<ll> vis(n, 0);
        queue<ll> q;
        q.push(0);
        vis[0] = 1;
        vector<ll> prev(n, -1);
        while (q.size())
        {
            ll curr = q.front();
            q.pop();
            for (auto child : v[curr])
            {
                if (vis[child] == 1)
                    continue;
                q.push(child);
                vis[child] = 1;
                prev[child] = curr;
            }
        }
        if (vis[n - 1] == 0)
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
        vector<ll> res;
        ll cur = n - 1;
        // res.push_back();
        while (cur != 0)
        {
            res.push_back(cur);
            cur = prev[cur];
        }
        res.push_back(cur);
        reverse(res.begin(), res.end());
        cout << res.size() << "\n";
        for (auto i : res)
            cout << i + 1 << " ";
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    #endif

    int T = 1;
    // cin >> T;
    // while (T--)
    // {
    //     solve();
    // }
    solve();
    return 0;
}