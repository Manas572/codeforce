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
#define rep(i, x, l) for (ll i = x; i < l; ++i)
#define rev(i, x, l) for (ll i = x; i >= l; --i)
#define chmin(x, l) (x = std::min(x, l))
#define chmax(x, l) (x = std::max(x, l))
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define vmin(v) (*min_element(v.begin(), v.end()))
#define vmax(v) (*max_element(v.begin(), v.end()))
#define INF 1e18
#define vinit(type, name, size) vector<type> name(size)
#define MOD 1000000007
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
ll gcdll(ll x, ll y) {
    return (y == 0 ? x : gcdll(y, x % y));
}

ll lcm(ll x, ll y) {
    return x / gcdll(x, y) * y;
}

// -------- Binary Exponentiation --------
ll modpow(ll x, ll e, ll m = MOD) {
    x %= m;
    ll res = 1;
    while (e > 0) {
        if (e & 1) res = (res * x) % m;
        x = (x * x) % m;
        e >>= 1;
    }
    return res;
}

// -------- Fermat Little Theorem (mod inverse) --------
// m must be prime, x and m coprime
ll modinv(ll x, ll m = MOD) {
    return modpow(x, m - 2, m);
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

ll nCr(int n, int r) {
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

// -------- Solve --------
void solve() {
    ll x,y,z;
    cin>>x>>y>>z;
   ll a=x|z;
   ll b=y|x;
   ll c=y|z;
      if((a&b) == x && (b&c)==y && (a&c) == z){
           YES;
          }
          else{
            NO;
          }
}

int main() {
    fast_io;
    tc
        solve();
    return 0;
}