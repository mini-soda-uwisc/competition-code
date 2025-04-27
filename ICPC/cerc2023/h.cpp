#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

// #define ONLINE_JUDGE
// #define MY_ASSERT

#ifndef ONLINE_JUDGE
#define cerr cout
#define FILEIO() \
    do { \
        freopen(__FILE__".in", "r", stdin); \
        freopen(__FILE__".out", "w", stdout); \
    } while (0)
#ifndef MY_ASSERT
#define MY_ASSERT
#endif
#else
#define cerr if (0) cerr
#define FILEIO() 0
#endif

#ifdef MY_ASSERT
#define M_ASSERT(cond, msg) \
    do { \
        if (!(cond)) { \
            cerr << "Assertion failed: " << #cond << '\n'; \
            cerr << "Message: " << msg << '\n'; \
            cerr << "File: " << __FILE__ << ", Line: " << __LINE__ << std::endl; \
            exit(1); \
        } \
    } while (0)
#else
#define M_ASSERT(cond, msg) 0
#endif

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

map<string, int> name_list;
map<int, string> rev_name_list;

vector<int> G[N];
int fa[N];

int get_id(string s) {
    static int COUNT = 0;
    if (name_list.find(s) != name_list.end()) {
        return name_list[s];
    } else {
        name_list[s] = ++COUNT;
        rev_name_list[COUNT] = s;
        return COUNT;
    }
}

map<int, int> dep_sum;
int dep[N], vis[N];

struct Node {
    int val;
    string s;
    Node *l, *r;
    Node(int val) : val(val) {}
};

Node* dfs_to_bros(int x) {
    vis[x] = 1;
    Node *cur = new Node(x);
    if (!G[x].empty()) cur->l = dfs_to_bros(G[x][0]);
    for (int y : G[fa[x]]) {
        if (vis[y]) continue;
        cur->r = dfs_to_bros(y);
        break;
    }
    return cur;
}

int max_depth = -1;

void dfs(Node* cur, int depth) {
    if (!cur) return;
    int x = cur->val;
    dep[x] = depth;
    max_depth = max(max_depth, depth);
    dep_sum[depth]++;
    dfs(cur->l, depth + 1);
    dfs(cur->r, depth + 1);
}

vector<Node*> ans[N];

void encode(){
    string buf;
    while (getline(cin, buf)) {
        stringstream ss(buf);

        string temp_string;

        ss >> temp_string;
        int parent = get_id(temp_string.substr(0, temp_string.length() - 1));

        while (ss >> temp_string) {
            int x = get_id(temp_string);
            G[parent].emplace_back(x);
            fa[x] = parent;
        }
    }

    Node *root = dfs_to_bros(1);
    dfs(root, 1);
    queue<Node*> q;
    ans[1].push_back(root);
    q.push(root);
    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();
        if (!cur) continue;
        cout << rev_name_list[cur->val] << '\n';
        q.push(cur->l);
        q.push(cur->r);
        ans[dep[cur->val] + 1].emplace_back(cur->l);
        ans[dep[cur->val] + 1].emplace_back(cur->r);
    }

    for (int d = 1; d <= max_depth; ++d) {
        for (int i = 0; i < ans[d].size(); ++i) {
            if (ans[d][i] == nullptr) cout << "0";
            else cout << "1";
        }
    }
}

string bits;


void create(int l, vector<Node*>& last, vector<string>& name) {
    static int i_have_no_name_to_use = 0;
    if (l >= bits.size()) return;
    int r = l + last.size() * 2;
    if (r > bits.size()) return;

    vector<Node*> current;
    int index = 0;
    for (int i = l; i < r; i += 2) {
        // assert(index < last.size());
        // assert(i_have_no_name_to_use <= name.size());
        if (bits[i] == '0') {
            last[index]->l = nullptr;
        } else {
            last[index]->l = new Node(++i_have_no_name_to_use);
            current.emplace_back(last[index]->l);
        }

        if (bits[i + 1] == '0') {
            last[index]->r = nullptr;
        } else {
            last[index]->r = new Node(++i_have_no_name_to_use);
            current.emplace_back(last[index]->r);
        }
        ++index;
    }
    create(r, current, name);
}

void debug_print(Node* cur) {
    if (!cur) {
        cout << "null ";
        return;
    }
    cout << "hi ";
    debug_print(cur->l);
    debug_print(cur->r);
}

void dfs2(Node* cur, int f) {
    if (!cur) return;
    if (f != -1)
        G[f].emplace_back(cur->val);
    fa[cur->val] = f;
    dfs2(cur->l, cur->val);
    dfs2(cur->r, f);
}


void print_decode(int x, vector<string>& name) {
    if (G[x].empty()) return;
    cout << name[x] << ":";
    for (int y : G[x]) {
        cout << ' ' << name[y];
    }
    cout << '\n';
    for (int y : G[x]) {
        print_decode(y, name);
    }
}

void decode() {
    string buf;
    vector<string> name;
    while (getline(cin, buf)) {
        if (buf[0] == '0' || buf[0] == '1') break;
        name.emplace_back(buf);
    }
    bits = buf;

    Node *root = new Node(0);
    vector<Node*> v = {root};
    create(1, v, name);
    dfs2(root->l, 0);

    print_decode(0, name);
}

void solve(){
    string buf;
    getline(cin, buf);
    if (buf == "ENCODE") encode();
    else decode();
}

int main() {
    FILEIO();

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