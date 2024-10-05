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
    vector<string> v(n);
    vector<vector<ll>> vis(n, vector<ll>(m));
    for (auto &i : v)
    {
        cin >> i;
    }
    ll cnt = 0;
    queue<pair<ll, ll>> q;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (v[i][j] == '#' || vis[i][j] == 1)
                continue;
            q.push({i, j});
            vis[i][j] = 1;
            cnt++;
            while (q.size() > 0)
            {
                ll x = q.front().first;
                ll y = q.front().second;
                q.pop();
                for (ll j = 0; j < 4; j++)
                {
                    ll nx = x + dx[j];
                    ll ny = y + dy[j];
                    if ((inrange(nx, ny, n, m) && v[nx][ny] != '#') && vis[nx][ny] == 0)
                    {
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    cout << cnt;


}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    #endif

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    // solve();
    return 0;
}