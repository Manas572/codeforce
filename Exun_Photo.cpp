#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> tree;
    Fenwick(int n) : n(n), tree(n + 1, 0) {}

    void add(int i, int delta) {
        for (; i <= n; i += i & -i)
            tree[i] += delta;
    }

    int query(int i) const {
        int sum = 0;
        for (; i > 0; i -= i & -i)
            sum += tree[i];
        return sum;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    Fenwick bit(n);
    vector<int> c(n);
    bool already_sorted = true;

    for (int i = 0; i < n; ++i) {
        c[i] = bit.query(p[i] - 1);
        if (c[i] > 0) already_sorted = false;
        bit.add(p[i], 1);
    }

    if (k == 1) {
        cout << (already_sorted ? 0 : -1) << "\n";
        return;
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (c[i] + k - 2) / (k - 1);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}