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
    cin>>n;
    vll vec(n);
    vin(vec,n);
    bool even=false,odd=false;
    rep(i,0,n){
        if(vec[i]&1){
            odd=true;
        }else{
            even=true;
        }
    }
    if(even && odd){
        print(2);
    }
    else{
    rep(i,1,60){
        ll v=1ll<<i;
        unordered_set<ll> uset;
        for(auto x:vec){
            uset.insert(x%v);
        }
        if(uset.size()==2){
            print(v);
            return;
        }
    }
}
}

int main() {
    fast_io;
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}