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
    map<ll,ll> f;
    rep(i,0,n){
        f[vec[i]]++;
    }
    ll ansl=-1,ansr=-1;
    ll r=0;
    ll len=0;
    rep(i,0,n){
       chmax(r,i);
       while(r<n && f[vec[r]]==1){
        r++;
       }
       if(r-i>len){
        len=r-i;
        ansr=r-1;
        ansl=i;
       }
    }
    if(ansl==-1){
        cout<<0<<endl;
    }
    else{
        cout<<ansl+1<<" "<<ansr+1<<endl;
    }
}

int main() {
    fast_io;
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}