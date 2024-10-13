#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;

template<typename T>
T chmax(T a, T b) {
    return a > b ? a : b;
}

template<typename T>
T chmin(T a, T b) {
    return a > b ? b : a;
}

const int N = (int)1e5 + 1, M = N * 2;

void solve(){
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n + 1), b(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++){
        a[i] -= i;
        b[i] = a[i];
    }

    vector<ll> f(n + 1);
    for(int i = 1; i <= n; i++){
        f[i] = f[i - 1] + b[i];
    }

    int l = 1, r = 1;
    ll sum = 0, qwq = 0;

    vector<int> window;

    auto calc = [&](ll median, int dr) -> int{
        int l = 1, r = dr + 1;
        while(l < r){
            int mid = l + r >> 1;
            if(b[mid] >= median) r = mid;
            else l = mid + 1;
        }

        //cout << "here " << median << " " << l << " " << dr << endl;
        if(a[l] > median) l--;
        cout << "here " << median << " " << l << endl;
        return median * l - f[l] + (f[dr] - f[l]) - median * (dr - l);
    };

    while(r <= n){
        auto it = lower_bound(window.begin(), window.end(), a[r]);
        window.insert(it, a[r]);
        sum += a[r];

        ll median = 0;
        if(window.size() % 2){
            median = window[window.size() / 2];
        } else {
            median = window[window.size() / 2 - 1];
        }

        //cout << r << " " << median << " " << sum << " " << median * (r - l + 1) - sum << endl;
        //cout << median << " " << calc(median, r) << endl;
        while(l < r && calc(median, r) > k){
            auto it = lower_bound(window.begin(), window.end(), a[l]);
            window.erase(it);
            sum -= a[l];
            ++l;
        }

//        cout << l << " " << r << endl;
        qwq = chmax(qwq, r - l + 1ll);
        r++;
    }
    cout << qwq << endl;
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}