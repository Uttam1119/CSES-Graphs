#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define fr(i, n) for (ll i = 0; i < n; i++)
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

bool inrange(int x, int y, int n, int m){
    return (x >= 0 && x < n && y >= 0 && y < m);
}
ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, 1, 0, -1};
char pos(pair<ll, ll> a, pair<ll, ll> b)
{
    if ((a.second + 1) == (b.second))
    {
        return 'R';
    }
    else if ((a.second - 1) == (b.second))
    {
        return 'L';
    }
    else if ((a.first - 1) == (b.first))
    {
        return 'U';
    }
    else
        return 'D';
}
void solve(){
     ll n, m;
        cin >> n >> m;
        vector<vector<pair<ll, ll>>> adj(n + 1);
        vector<ll> dist(n + 1, LLONG_MAX);
        dist[1] = 0;
        while (m--)
        {
            ll u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
        }
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        pq.push({0, 1});
        while (pq.size())
        {
            ll distance = pq.top().first;
            ll node = pq.top().second;
            pq.pop();
            if (distance > dist[node])
                continue;
            for (auto &child : adj[node])
            {
                if (dist[child.first] > distance + (child.second))
                {
                    dist[child.first] = distance + (child.second);
                    pq.push({distance + (child.second), child.first});
                }
            }
        }
        for (ll i = 1; i <= n; i++)
            cout << dist[i] << " ";
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