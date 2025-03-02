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

const int N = (int)1e5 + 1;

// Function to find LIS using binary search
int findLIS(int* seq, int n) {
    if (n == 0) return 0;
    
    vector<int> dp;  // dp[i] = smallest value at which an increasing subsequence of length i+1 ends
    
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), seq[i]);
        if (it == dp.end())
            dp.push_back(seq[i]);
        else
            *it = seq[i];
    }
    
    return dp.size();
}

void solve(){
    int n;
    cin >> n;

    string a[5][n];
    int a_size[5] = {0};
    int mp[128] = {0};  // Direct array mapping for characters
    string b[n];
    int b_size = 0;

    mp['S'] = 0;
    mp['W'] = 1;
    mp['E'] = 2;
    mp['R'] = 3;
    mp['C'] = 4;

    auto cmp = [&](string a, string b) -> bool {
        int _a = stoi(a.substr(1));
        int _b = stoi(b.substr(1));
        return _a < _b;
    };

    for (int i = 0; i < n; i++) {
        string S;
        cin >> S;
        char c = S[0];
        a[mp[c]][a_size[mp[c]]++] = S;
        b[b_size++] = S;
    }

    for (int i = 0; i < 5; i++) {
        sort(a[i], a[i] + a_size[i], cmp);
    }

    // Use unordered_map for faster lookups
    unordered_map<string, int> rec;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < a_size[i]; j++) {
            rec[a[i][j]] = j + 1;
        }
    }

    int perm[4] = {0, 1, 2, 3};
    int qwq = 1e9;

    do {
        int seq[N], seq_size = 0;
        int len[5] = {0};
        int dt[128] = {0};  // Direct array mapping
        dt['C'] = 4;

        for (char k : {'S', 'W', 'E', 'R'}) {
            for (int i = 0; i < 4; i++) {
                if (perm[i] == mp[k]) {
                    dt[k] = i;
                }
            }
        }
        
        for (int i = 1; i < 5; i++) {
            len[i] = len[i - 1] + a_size[perm[i - 1]];
        }

        for (int i = 0; i < n; i++) {
            seq[seq_size++] = rec[b[i]] + len[dt[b[i][0]]];
        }

        // Use binary search algorithm to find LIS
        int lis_length = findLIS(seq, seq_size);
        qwq = chmin(qwq, n - lis_length);
    } while (next_permutation(perm, perm + 4));

    cout << qwq << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //  cin >> t;

    while(t--){
        solve();
    }

    return 0;
}