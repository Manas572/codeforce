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

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;

    vll vec(n+1, llmax);

    for (ll k = 1; k <= n; ++k) {
        for (ll j = k; j <= n; j += k) {

            if (s[j-1] == '1') break;     

            if (vec[j] == llmax) {        
                vec[j] = k;
            }
        }
    }

    ll ans = 0;

    for (ll i = 1; i <= n; i++) {
        if (s[i-1] == '0') ans += vec[i];
    }

    print(ans);
}

int main() {
    fast_io;
    tc solve();
    return 0;
}
