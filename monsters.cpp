#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define repb(i, a, b) for (int i = a; i >= b; i--)
#define endl '\n'
#define print(x) cout << x << endl
#define printInline(x) cout << x << " "

#define ll long long
#define lli long long int
// #define int long long
#define ll long long
#define pb push_back
#define fi(x, a, b) for (int x = (int)(a); (x) <= (int)(b); ++(x))
#define fd(x, a, b) for (int x = (int)(a); (x) >= (int)(b); --(x))
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vpi vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>

#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define popb pop_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define invec(n, vec)           \
    for (int i = 0; i < n; i++) \
    cin >> vec[i]
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

const int inf = 1e9;
const int MOD = 1e9 + 7;
#define MOD1 998244353

class DisjointSet
{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

ll MODi(ll a, ll b)
{
    a %= MOD1;
    b %= MOD1;
    return (1LL * a * b) % MOD1;
}

ll bnr(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = MODi(res, a);
        }
        a = MODi(a, a);
        b >>= 1;
    }
    return res;
}

bool prime(int n)
{
    bool prime = 1;
    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0)
        {
            prime = 0;
            break;
        }
    }
    if (prime)
        return 1;
    else
        return 0;
}

bool sieve(int n)
{
    vector<bool> sieve(n + 1, 1);
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i * i <= n; ++i)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                sieve[j] = 0;
            }
        }
    }
    return (sieve[n]) ? 1 : 0;
}

int gcd(int a, int b)
{
    // if(b==0){
    //     return
    // }

    // return (b, gcd(a%b));
    return __gcd(a, b);

    // if gcd of two numbers is 1.. then those numbers are called co-prime numbers.
    // means these two numbers dont have common divisors
}

int lcm(int a, int b)
{
    return ((a * b) / gcd(a, b));
}

int power(int x, int y, int p = MOD)
{
    unsigned long long res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
        {
            res = (res * x) % p;
        }
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int modInverse(int n, int p = MOD)
{ // fermats little theorem  ... n^(-1)
    return power(n, p - 2, p);
}

int nCr(int n, int r, int p = MOD)
{
    if (n < r)
    {
        return 0;
    }
    if (r == 0)
    {
        return 1;
    }
    vector<int> fac(n + 1, 0);
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fac[i] = (fac[i - 1] * i) % p;
    }
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

// Sorting
bool sorta(const pair<ll, ll> &a, const pair<ll, ll> &b) { return (a.second < b.second); } // sort in ascending according to 2nd value of pair
bool sortd(const pair<ll, ll> &a, const pair<ll, ll> &b) { return (a.second > b.second); } // sort is descending according to 2nd value of pair

// Bits
string decToBinary(ll n)
{
    string s = "";
    ll i = 0;
    while (n > 0)
    {
        s = to_string(n % 2) + s;
        n = n / 2;
        i++;
    }
    return s;
}

ll binaryToDecimal(string n)
{
    string num = n;
    ll dec_value = 0;
    int base = 1;
    int len = num.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}

// Check
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}

bool isPerfectSquare(ll x)
{
    if (x >= 0)
    {
        ll sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}

ll mod_mul(ll a, ll b, ll mod)
{
    return ((a % mod) * (b % mod)) % mod;
}

// Function to perform modular addition (a + b) % MOD
ll mod_add(ll a, ll b, ll mod)
{
    return (a % mod + b % mod + mod) % mod;
}

// Function to perform modular subtraction (a - b) % MOD
ll mod_sub(ll a, ll b, ll mod)
{
    return ((a % mod - b % mod) + mod) % mod;
}

bool inrange(int x, int y, int n, int m){
    return (x >= 0 && x < n && y >= 0 && y < m);
}
ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, 1, 0, -1};
char pro(pair<ll, ll> a, pair<ll, ll> b)
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

    vector<vector<ll>> dist(n, vector<ll>(m, LLONG_MAX));
    vector<vector<ll>> vis(n, vector<ll>(m, 0));
    queue<pair<ll, ll>> q;

    vector<string> vec(n);
    for(auto &it : vec){
        cin >> it;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vec[i][j] == 'M'){
                q.push({i, j});
                vis[i][j] = 1;
                dist[i][j] = 0;
            }
        }
    }
    while(q.size() > 0){
        pair<ll,ll> p = q.front();
        q.pop();

        int x = p.first;
        int y = p.second;

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(inrange(nx, ny, n, m) && vec[nx][ny] != '#' && !vis[nx][ny]){
                q.push({nx, ny});
                vis[nx][ny] = 1;
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }

    vector<vector<ll>> dista(n, vector<ll>(m, LLONG_MAX));
    vector<vector<ll>> visa(n, vector<ll>(m, 0));
    queue<pair<ll, ll>> qa;
    vector<vector<pair<ll,ll>>> par(n, vector<pair<ll,ll>> (m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vec[i][j] == 'A'){
                qa.push({i, j});
                visa[i][j] = 1;
                dista[i][j] = 0;
                par[i][j] = {i,j};
            }
        }
    }
    while(qa.size() > 0){
        pair<ll,ll> p = qa.front();
        qa.pop();

        int x = p.first;
        int y = p.second;

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(inrange(nx, ny, n, m) && vec[nx][ny] != '#' && !visa[nx][ny]){
                qa.push({nx, ny});
                visa[nx][ny] = 1;
                dista[nx][ny] = dista[x][y] + 1;
                par[nx][ny] = {x,y};
            }
        }
    }

    vector<pair<ll, ll>> res;
    bool f = true;
    for (int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m ; j++){
            if(((i == 0) || (j == 0)) || ((i == n - 1) || (j == m - 1))){
                if(dista[i][j] < dist[i][j]){
                    pair<ll,ll> z = {i,j};
                    while(par[z.first][z.second] != z){
                        res.push_back(z);
                        z = par[z.first][z.second];
                    }
                    res.push_back(z);
                    f = false;
                    break;
                }
            }
        }
        if(!f) break;
    }
    if(!f){
        cout << "YES\n";
        ll x = res.size();
        cout << x - 1 << endl;
        reverse(res.begin(), res.end());
        for(int i = 0; i < x - 1; i++){
            char ch = pro(res[i], res[i+1]);
            cout << ch;
        }
    }else{
        cout << "NO\n";
    }

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