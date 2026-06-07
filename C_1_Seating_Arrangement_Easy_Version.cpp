#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define prt(l) cout << l << '\n'
#define ll long long
#define tc ll t; cin >> t; while(t--)
#define vin(v, x) for (ll i = 0; i < x; ++i) cin >> v[i]
#define vout(v) for (auto &l : v) cout << l << ' '; cout << '\n'
#define pb push_back
#define all(l) l.begin(), l.end()
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
ll countDivisors(ll x) {
    ll ans = 1;
    for (ll i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            ll cnt = 0;
            while (x % i == 0) {
                x /= i;
                cnt++;
            }
            ans *= (cnt + 1);
        }
    }
    if (x > 1) ans *= 2;
    return ans;
}

// -------- Combinatorics --------
vll fact, invfact;

void init_combinatorics(int x = MAXN) {
    fact.assign(x + 1, 1);
    for (int i = 1; i <= x; ++i)
        fact[i] = fact[i - 1] * i % MOD;

    invfact.assign(x + 1, 1);
    invfact[x] = modinv(fact[x]);
    for (int i = x; i >= 1; --i)
        invfact[i - 1] = invfact[i] * i % MOD;
}

ll nCr(int x, int r) {
    if (r < 0 || r > x) return 0;
    return fact[x] * invfact[r] % MOD * invfact[x - r] % MOD;
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
    ll n, x, l; 
    cin >> n >> x >> l;
    string s;
    cin >> s;
    ll emp = x;
    ll val1 = 0;
    ll val2 = 0; 
    ll ans = 0;
    for (char c : s) {
        if (c == 'I') {
            if (emp > 0) {
                emp--;
                val1 += (l - 1);
                ans++;
            }
        } else if (c == 'E') {
            if (val1 > 0) {
                val1--;
                ans++;
            } else if (val2 > 0 && emp > 0) {
                val2--;
                emp--;
                val1 += l; 
                val1--;
                ans++;
            }
        } else if (c == 'A') {
            if (val1 > 0) {
                val1--;
                ans++;
                if (emp > 0) {
                    val2++;
                }
            } else if (emp > 0) {
                emp--;
                val1 += (l - 1);
                ans++;
            }
        }
    }
    
    prt(ans);
}

int main() {
    fast_io;
    tc solve();
    return 0;
}