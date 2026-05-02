#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define prt(x) cout << x << '\n'
#define ll long long
#define tc ll t; cin >> t; while(t--)
#define vin(v, n) for (ll i = 0; i < n; ++i) cin >> v[i]
#define vout(v) for (auto &x : v) cout << x << ' '; cout << '\n'
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
#define MOD 1000000007
#define MAXN 1000000

using namespace std;

typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

// -------- Custom gcd + lcm --------
ll gcdll(ll a, ll b) {
    a = llabs(a);
    b = llabs(b);
    while (b != 0) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
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
ll modinv(ll a, ll m = MOD) {
    return modpow(a, m - 2, m);
}

// -------- Number of Divisors --------
ll countDivisors(ll n) {
    ll ans = 1;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            ll cnt = 0;
            while (n % i == 0) {
                n /= i;
                cnt++;
            }
            ans *= (cnt + 1);
        }
    }
    if (n > 1) ans *= 2;
    return ans;
}

// -------- Combinatorics --------
vll fact, invfact;

void init_combinatorics(int n = MAXN) {
    fact.assign(n + 1, 1);
    for (int i = 1; i <= n; ++i)
        fact[i] = fact[i - 1] * i % MOD;

    invfact.assign(n + 1, 1);
    invfact[n] = modinv(fact[n]);
    for (int i = n; i >= 1; --i)
        invfact[i - 1] = invfact[i] * i % MOD;
}

ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}

// -------- Prime Factor Sieve --------
vector<vector<int>> pf;

void init_prime_factors(int N = 200000) {
    pf.assign(N + 1, {});
    for (int i = 2; i <= N; i++) {
        if (pf[i].empty()) {
            for (int j = i; j <= N; j += i)
                pf[j].push_back(i);
        }
    }
}


ll fun1(vector<bool>& vis, ll n) {
    for (ll i = 0; i < n; i++) {
        if (!vis[i]) return i;
    }
    return n;
}

ll fun2(vector<ll>& a, ll l, ll r, ll n) {
    vector<bool> vis(n, false);
    vis[0] = true;

    while (l >= 0 && r < 2 * n && a[l] == a[r]) {
        if (a[l] < n) vis[a[l]] = true;
        l--; 
        r++;
    }

    return fun1(vis, n);
}

void solve() {
    ll n;
    cin >> n;
    vll a(2*n,0);
    vin(a,2*n);
    ll val1 = -1, val2 = -1;
    rep (i,0,2*n) {
        if (a[i] == 0) {
            if (val1 == -1) val1 = i;
            else val2 = i;
        }
    }
    ll ans = 0;
    chmax(ans, fun2(a, val1 - 1, val1 + 1, n));
    chmax(ans, fun2(a, val2 - 1, val2 + 1, n));
    bool ok = true;
    ll l = val1 + 1, r = val2 - 1;
    vector<bool> vis(n, false);
    vis[0] = true;
    while (l <= r) {
        if (a[l] != a[r]) {
            ok = false;
            break;
        }
        if (a[l] < n) vis[a[l]] = true;
        l++;
        r--;
    }

    if (ok) {
        while (val1 - 1 >= 0 && (val2 + 1 < (2 * n)) && (a[val1 - 1] == a[val2 + 1])) {
            val1--; val2++;
            if (a[val1] < n) vis[a[val1]] = true;
        }
        chmax(ans, fun1(vis, n));
    }

    prt(ans);
}

int main() {
    fast_io;
    tc solve();
    return 0;
}