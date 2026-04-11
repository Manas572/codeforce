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
template<typename... Args>
void read(Args&... args) {
    (cin >> ... >> args);
}


void solve() {
    ll n,q;
    read(n,q);
    vll N(n);
    vin(N,n);
    ll s=accumulate(all(N),0ll);
    bool two=false;
    ll v2=0;
    map<ll,ll>mp;
    rep(i,0,q){
        ll x;
        cin>>x;
        if(x==1){
            ll idx,val;
            cin>>idx>>val;
            if(two && !mp.count(idx-1)){
                N[idx-1]=v2;
            }
            s-=N[idx-1];
            s+=val;
            N[idx-1]=val;
            mp[idx-1]=1;
        }else{
            two=true;
            ll val;
            cin>>val;
            v2=val;
            s=n*val;
            mp.clear();
        }
        print(s);
    }
}

int main() {
    fast_io;
     solve();
    return 0;
}