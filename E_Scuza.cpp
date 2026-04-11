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
    ll n,q;
    cin>>n>>q;
    vll N(n),Q(q);
    vin(N,n);
    vin(Q,q);
    ll m1=llmin;
    ll m2=llmax;
    map<ll,ll>mp;
    ll s=0;
    rep(i,0,n){
        chmax(m1,N[i]);
        chmin(m2,N[i]);
        s+=N[i];
        mp[m1]=s;
    }
    rep(i,0,q){
        if(Q[i]<m2){
            cout<<"0"<<" ";
            continue;
        }
        if(Q[i]>m1){
            cout<<s<<" ";
            continue;
        }
        if (mp.count(Q[i])) {
    cout << mp[Q[i]] << " ";
} else {
    auto it = mp.upper_bound(Q[i]);

if (it == mp.begin()) {
    cout << 0 << " ";
} else {
    it--;
    cout << it->second << " ";
}

}

    }
    cout<<endl;
}

int main() {
    fast_io;
    tc
     solve();
    return 0;
}