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
#define tc ll t; cin >> t; while(t--)
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
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> vec(n);
    rep(i,0,n){
        rep(j,0,m){
            ll x;
            cin>>x;
            vec[i].push_back(x);
        }
    }
    ll ans=0;
    rep(i,0,n-1){
        rep(j,i+1,n){
            rep(k,0,m){
                ans+=abs(vec[i][k]-vec[j][k]);
            }
        }
    }
    print(ans);
}

int main() {
    fast_io;
    tc
    solve();
    return 0;
}