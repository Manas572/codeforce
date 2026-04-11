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
    string n;
    cin >> n;

    ll s = 0, c2 = 0, c3 = 0;

    for (auto &ch : n) {
        ll d = ch - '0';
        s += d;
        if (d == 2) c2++;
        if (d == 3) c3++;
    }

    vector<int> dp(9, 0), newdp(9, 0);
    dp[s % 9] = 1;

    rep(i, 0, c2) {
        fill(all(newdp), 0);
        rep(r, 0, 9) {
            if (dp[r]) {
                newdp[r] = 1;
                newdp[(r + 2) % 9] = 1;
            }
        }
        dp = newdp;
    }

    rep(i, 0, c3) {
        fill(all(newdp), 0);
        rep(r, 0, 9) {
            if (dp[r]) {
                newdp[r] = 1;
                newdp[(r + 6) % 9] = 1;
            }
        }
        dp = newdp;
    }

    if (dp[0]) YES;
    else NO;
}

int main() {
    fast_io;
    tc solve();
    return 0;
}
