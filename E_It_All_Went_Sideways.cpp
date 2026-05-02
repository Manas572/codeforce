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
#define rep(i, vec, l) for (ll i = vec; i < l; ++i)
#define rev(i, vec, l) for (ll i = vec; i >= l; --i)
#define chmin(vec, l) (vec = std::min(vec, l))
#define chmax(vec, l) (vec = std::max(vec, l))
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
ll gcdll(ll vec, ll b) {
    vec = llabs(vec);
    b = llabs(b);
    while (b != 0) {
        ll r = vec % b;
        vec = b;
        b = r;
    }
    return vec;
}

ll lcm(ll vec, ll b) {
    return vec / gcdll(vec, b) * b;
}

// -------- Binary Exponentiation --------
ll modpow(ll vec, ll e, ll m = MOD) {
    vec %= m;
    ll res = 1;
    while (e > 0) {
        if (e & 1) res = (res * vec) % m;
        vec = (vec * vec) % m;
        e >>= 1;
    }
    return res;
}

// -------- Fermat Little Theorem (mod inverse) --------
ll modinv(ll vec, ll m = MOD) {
    return modpow(vec, m - 2, m);
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

// -------- Solve --------
void solve() {
    ll n;
    cin >> n;
    vll vec(n);
    vin(vec, n);
    ll ts = accumulate(all(vec), 0LL);
    vll suf(n);
    suf[n - 1] = vec[n - 1];
    rev (i,n-2,0) {
        suf[i] = min(vec[i], suf[i + 1]);
    }
    ll ss = accumulate(all(suf), 0LL);
    ll ans = ts - ss;
    stack<ll> st;
    ll ans2 = ans;
    rep (i,0,n) {
        while (!st.empty() && vec[st.top()] >= vec[i]) {
            st.pop();
        }
        ll p = (st.empty()) ? -1 : st.top();
        if (vec[i] == suf[i]) {
            ll gain = i - p - 1;
            chmax(ans2, ans+gain);
        }
        st.push(i);
    }

    prt(ans2);
}

int main() {
    fast_io;
    tc solve();
    return 0;
}


