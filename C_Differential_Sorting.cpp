#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define print(x) cout << x << '\n'
#define ll long long
#define tc ll t; cin >> t; while(t--)
#define vin(v, n) for (ll i = 0; i < n; ++i) cin >> v[i]
#define vout(v) for (auto &x : v) cout << x << ' '; cout << '\n'
#define llmax LLONG_MAX
#define llmin LLONG_MIN
#define pb push_back
#define all(x) x.begin(), x.end()
#define sortv(v) sort(v.begin(), v.end())
#define rep(i, a, l) for (ll i = a; i < l; ++i)
#define rev(i, a, l) for (ll i = a; i >= l; --i)
#define chmin(a, l) (a = std::min(a, l))
#define chmax(a, l) (a = std::max(a, l))
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define vmin(v) (*min_element(v.begin(), v.end()))
#define vmax(v) (*max_element(v.begin(), v.end()))
#define INF 1e18
#define vinit(type, name, size) vector<type> name(size)
#define MOD 1000000007
#define MAXN 100005
#define ld long double

using namespace std;

typedef vector<ll> vll;

// -------- read() helper --------
template<typename... Args>
void read(Args&... args) {
    (cin >> ... >> args);
}

// -------- Custom gcd + lcm --------
ll gcdll(ll a, ll b) {
    return (b == 0 ? a : gcdll(b, a % b));
}

ll lcm(ll a, ll b) {
    return a / gcdll(a, b) * b;
}

// -------- Sieve of Eratosthenes --------
vector<bool> isPrime;
vector<int> primes;

void sieve(int n = 2000000) {
    isPrime.assign(n+1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    for (int i = 2; i <= n; i++)
        if (isPrime[i]) primes.push_back(i);
}

// -------- DFS Template --------
vector<vector<int>> adj;
vector<int> vis;

void dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
}

// -------- Generic rec(u, parent) helper --------
void rec(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        rec(v, u);
    }
}

// -------- Solve --------
void solve() {
    ll n;
    read(n);
    vll vec(n);
    vin(vec,n);
    ll p=vec[0];
    ll c=0;
    rep(i,1,n){
        if(p>vec[i]){
            c++;
        }
        p=vec[i];
    }
    if(c==0){
        print(0);
        return;
    }
    if(vec[n-2]<vec[n-1] && vec[n-2]>=(vec[n-2]-vec[n-1])){
        print(n-2);
        rep(i,1,n-1){
            cout<<i<<" "<<n-1<<" "<<n<<endl;
        }
    }else if(vec[n-1]==vec[n-2] && vec[n-1]>=0){
        print(n-2);
        rep(i,1,n-1){
            cout<<i<<" "<<n-1<<" "<<n<<endl;
        }
    }else{
        print(-1);
    }
}

int main() {
    fast_io;
    tc
        solve();
    return 0;
}