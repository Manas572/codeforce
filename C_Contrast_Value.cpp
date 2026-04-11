#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define print(x) cout << x << '\n'
#define ll long long
#define vin(v, n) for (ll i = 0; i < n; ++i) cin >> v[i]
#define vout(v) for (auto &x : v) cout << x << ' '; cout << '\n'
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
    vll vec(n);
    vin(vec, n);

    bool ok = true;
    rep(i, 1, n) if (vec[i] != vec[0]) ok = false;
    if (ok) {
        print(1);
        return;
    }

    ll p = 1;         
    ll dir = 0;        
    ll last = vec[0];

    rep(i, 1, n) {
        if (vec[i] == last) continue;  

        ll ndir = (vec[i] > last ? 1 : 2);

        if (dir == 0) {
            dir = ndir;
            p++;
        } 
        else if (dir != ndir) {  
            p++;
            dir = ndir;
        }

        last = vec[i];
    }

    print(p);
}

int main() {
    fast_io;
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
