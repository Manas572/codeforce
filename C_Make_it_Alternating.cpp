#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define prt(x) cout << x << '\n'
#define ll long long
#define tc ll t; cin >> t; while(t--)
#define vin(v, n) for (ll i = 0; i < n; ++i) cin >> v[i]
#define vout(v) for (auto &x : v) cout << x << ' '; cout << '\n'
#define llmax LLONG_MAX
#define llmin LLONG_MIN
#define pb push_back
#define all(x) x.begin(), x.end()
#define stv(v) sort(v.begin(), v.end())
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
#define MOD 998244353
#define MAXN 1000000
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

// -------- Binary Exponentiation --------
ll modpow(ll a, ll e, ll m = MOD) {
    a %= m;
    ll res = 1;
    while (e > 0) {
        if (e & 1) res = (res * a) % m;
        a = (a * a) % m;
        e >>= 1;
    }
    return res;
}

// -------- Fermat Little Theorem (mod inverse) --------
// m must be prime, a and m coprime
ll modinv(ll a, ll m = MOD) {
    return modpow(a, m - 2, m);
}

// -------- Combinatorics: factorials & inverse factorials --------
vll fact, invfact;

void init_combinatorics(int n = MAXN) {
    fact.assign(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    invfact.assign(n + 1, 1);
    invfact[n] = modinv(fact[n]);
    for (int i = n; i >= 1; --i) {
        invfact[i - 1] = invfact[i] * i % MOD;
    }
}

ll nCr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
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
    string s;
    cin>>s;
    auto l=s[0];
    ll k=1;
    vll vec;
    rep(i,1,s.size()){
        if(l!=s[i]){
            if(k>1){
                vec.pb(k);
            }
            k=1;
        }else{
            k++;
        }
        l=s[i];
    }
    if(k>1){
        vec.pb(k);
    }
    if(vec.size()==0){
        cout<<0<<" "<<1<<endl;
        return;
    }
    ll ans1=0;
    ll ans2=1;
    ll m=llmin;
    rep(i,0,vec.size()){
        ans1+=(vec[i]-1);
        chmax(m,vec[i]);
    }
    init_combinatorics(max(m,ans1));
    rep(i,0,vec.size()){
     ans2=(ans2*vec[i])%MOD;
    }
    ans2=(ans2*fact[ans1])%MOD;
    cout<<ans1<<" "<<ans2<<endl;
}

int main() {
    fast_io;
    tc
        solve();
    return 0;
}