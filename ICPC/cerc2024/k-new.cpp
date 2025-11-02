#include <bits/stdc++.h>
using namespace std;

static const int MAXR = 4096; // n<=64 => n*n<=4096

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.length();
    int m = 0;
    vector<int> pre;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '#') {
            ++m;
            pre.emplace_back(i);
        }
    }
    if (n == 1) {
        cout << "1\n#\n";
        return 0;
    }

    // 如果输入是 1-based，下行打开：for (int &x: pre) --x;

    // 校验
    for (int x: pre) {
        if (x < 0 || x >= n) {
            cerr << "preselected index out of range\n";
            cout << "-1\n";
            return 0;
        }
    }

    // 标记预选左点
    vector<char> is_pre(n, 0);
    for (int x: pre) is_pre[x] = 1;

    // 先把被预选左点覆盖的右点全部“预覆盖”
    // 右点用 (r, c) 的线性编号 rid = r*n + c
    vector<char> preCovered(n * n, 0);

    auto cover_by_i = [&](int i, auto&& touch) {
        // 行 i
        for (int c = 0; c < n; ++c) if (c != i) touch(i, c);
        // 列 i
        for (int r = 0; r < n; ++r) if (r != i) touch(r, i);
        // 副对角 r + c = 2i
        int lo = max(0, 2 * i - (n - 1));
        int hi = min(n - 1, 2 * i);
        for (int r = lo; r <= hi; ++r) {
            int c = 2 * i - r;
            if (r == i && c == i) continue; // 不含自身
            touch(r, c);
        }
    };
    for (int i = 0; i < n; ++i) if (is_pre[i]) {
        cover_by_i(i, [&](int r, int c){ preCovered[r * n + c] = 1; });
    }

    // 右点重新编号：仅保留“未被预覆盖”且与未预选左点相连的点
    vector<int> rightId(n * n, -1);
    int R = 0;

    // 左点重映射：剔除预选的，只保留未预选的
    vector<int> idx;               // 新左点 -> 原始 i
    vector< bitset<MAXR> > cover;  // 新左点的覆盖右点集
    for (int i = 0; i < n; ++i) if (!is_pre[i]) {
        int newi = (int)idx.size();
        idx.push_back(i);
        cover.emplace_back();
        // 链接函数：若此右点未建过编号，则分配之
        auto link = [&](int r, int c) {
            int id = r * n + c;
            if (preCovered[id]) return;         // 已由预选覆盖，跳过
            if (rightId[id] == -1) rightId[id] = R++;
            cover[newi].set(rightId[id]);
        };
        cover_by_i(i, link);
    }
    int L = (int)idx.size();

    // 若无剩余右点，新增选择为 0
    if (R == 0) {
        sort(pre.begin(), pre.end());
        // cout << 0 << "\n\n";
        // 如果你想输出总方案（含预选），可取消下行注释：
        cout << pre.size() << "\n";
        cout << s << '\n';
        return 0;
    }
    if (L == 0) { // 还有未覆盖右点但没有可选左点
        cout << "-1\n";
        return 0;
    }
    if (L > 64) { // 理论上不会发生
        cout << "-1\n";
        return 0;
    }

    // 构造 rmask[r]：能覆盖右点 r 的左点(<=64) 的位掩码
    vector<uint64_t> rmask(R, 0ULL);
    for (int i = 0; i < L; ++i) {
        for (int r = cover[i]._Find_first(); r < (unsigned)R; r = cover[i]._Find_next(r)) {
            rmask[r] |= (1ULL << i);
        }
    }
    // 若存在右点不可覆盖 => 无解
    for (int r = 0; r < R; ++r) if (rmask[r] == 0ULL) {
        cout << "-1\n";
        return 0;
    }

    // —— 以下为与前版相同的“精确最小集合覆盖”求解（分支剪枝）——

    // 删除被支配的左点 (N(i) ⊆ N(j))
    {
        vector<int> removed(L, 0);
        for (int i = 0; i < L; ++i) if (!removed[i]) {
            for (int j = 0; j < L; ++j) if (!removed[j] && i != j) {
                bool i_sub_j = ((cover[i] & ~cover[j]).none());
                bool j_sub_i = ((cover[j] & ~cover[i]).none());
                if (i_sub_j && !j_sub_i) { removed[i] = 1; break; }
                if (i_sub_j && j_sub_i) { // 完全相等：保留原始下标小的
                    if (idx[i] > idx[j]) { removed[i] = 1; break; }
                }
            }
        }
        vector< bitset<MAXR> > ncover;
        vector<int> nidx;
        vector<int> mapOld2New(L, -1);
        for (int i = 0; i < L; ++i) if (!removed[i]) {
            mapOld2New[i] = (int)nidx.size();
            ncover.push_back(cover[i]);
            nidx.push_back(idx[i]);
        }
        cover.swap(ncover);
        idx.swap(nidx);
        L = (int)idx.size();

        // 重新构造 rmask
        fill(rmask.begin(), rmask.end(), 0ULL);
        for (int i = 0; i < L; ++i) {
            for (int r = cover[i]._Find_first(); r < (unsigned)R; r = cover[i]._Find_next(r)) {
                rmask[r] |= (1ULL << i);
            }
        }
        if (L == 0) {
            cout << "0\n\n";
            return 0;
        }
    }

    // 强制选择：度为1的右点
    bitset<MAXR> covered; covered.reset();
    uint64_t chosen_mask = 0ULL;
    vector<int> chosen_list; // 用新左点编号

    auto apply_choose = [&](int i){
        if (((chosen_mask >> i) & 1ULL) == 0ULL) {
            chosen_mask |= (1ULL << i);
            chosen_list.push_back(i);
            covered |= cover[i];
        }
    };
    bool changed = true;
    while (changed) {
        changed = false;
        for (int r = 0; r < R; ++r) if (!covered.test(r)) {
            uint64_t cand = rmask[r] & ~chosen_mask;
            if (cand == 0ULL) { cout << "-1\n"; return 0; }
            if (__builtin_popcountll(cand) == 1) {
                int i = __builtin_ctzll(cand);
                apply_choose(i);
                changed = true;
            }
        }
    }

    auto greedy_finish = [&](bitset<MAXR> curCovered, uint64_t curChosenMask){
        vector<int> picks;
        bitset<MAXR> remain = ~curCovered;
        for (int x = R; x < MAXR; ++x) remain.reset(x);
        while (remain.any()) {
            int best = -1, bestGain = -1;
            for (int i = 0; i < L; ++i) if (!((curChosenMask >> i) & 1ULL)) {
                int g = (int)((cover[i] & remain).count());
                if (g > bestGain) { bestGain = g; best = i; }
            }
            if (best == -1 || bestGain <= 0) break;
            curChosenMask |= (1ULL << best);
            picks.push_back(best);
            curCovered |= cover[best];
            remain = ~curCovered;
            for (int x = R; x < MAXR; ++x) remain.reset(x);
        }
        return picks;
    };

    vector<int> greedy_more = greedy_finish(covered, chosen_mask);
    vector<int> best_pick = chosen_list;
    best_pick.insert(best_pick.end(), greedy_more.begin(), greedy_more.end());
    int BEST = (int)best_pick.size();
    {
        bitset<MAXR> chk = covered;
        for (int i: greedy_more) chk |= cover[i];
        if ((int)chk.count() < R) BEST = L + (int)chosen_list.size(); // 保险上界
    }

    vector<int> stack_pick = chosen_list;
    function<void(bitset<MAXR>, uint64_t)> dfs = [&](bitset<MAXR> curCovered, uint64_t curChosenMask){
        if ((int)curCovered.count() >= R) {
            if ((int)stack_pick.size() < BEST) {
                BEST = (int)stack_pick.size();
                best_pick = stack_pick;
            }
            return;
        }
        bitset<MAXR> remain = ~curCovered;
        for (int x = R; x < MAXR; ++x) remain.reset(x);
        int rem = (int)remain.count();
        int bestGain = 0;
        for (int i = 0; i < L; ++i) if (!((curChosenMask >> i) & 1ULL)) {
            int g = (int)((cover[i] & remain).count());
            if (g > bestGain) bestGain = g;
        }
        if (bestGain == 0) return;
        int needLB = (rem + bestGain - 1) / bestGain;
        if ((int)stack_pick.size() + needLB >= BEST) return;

        int target = -1, minDeg = INT_MAX;
        for (int r = remain._Find_first(); r < (unsigned)R; r = remain._Find_next(r)) {
            int deg = __builtin_popcountll(rmask[r] & ~curChosenMask);
            if (deg == 0) return;
            if (deg < minDeg) { minDeg = deg; target = r; if (deg == 1) break; }
        }
        uint64_t options = rmask[target] & ~curChosenMask;
        struct Cand {int i, gain;};
        vector<Cand> cands;
        for (uint64_t m = options; m; m &= (m - 1)) {
            int i = __builtin_ctzll(m);
            int gain = (int)((cover[i] & remain).count());
            cands.push_back({i, gain});
        }
        sort(cands.begin(), cands.end(), [](const Cand& a, const Cand& b){
            if (a.gain != b.gain) return a.gain > b.gain;
            return a.i < b.i;
        });
        for (auto &c : cands) {
            stack_pick.push_back(c.i);
            dfs(curCovered | cover[c.i], curChosenMask | (1ULL << c.i));
            stack_pick.pop_back();
            if ((int)stack_pick.size() + 1 >= BEST) break;
        }
    };
    dfs(covered, chosen_mask);

    // 映回原始下标，输出“新增需要选择的左点”
    vector<int> add_orig;
    add_orig.reserve(best_pick.size());
    for (int i : best_pick) add_orig.push_back(idx[i]);
    sort(add_orig.begin(), add_orig.end());
    cout << add_orig.size() + m << "\n";
    // for (int i = 0; i < (int)add_orig.size(); ++i) {
    //     if (i) cout << ' ';
    //     cout << add_orig[i];
    // }
    vector<char> ans = vector<char>(n, '.');
    for (int i = 0; i < add_orig.size(); ++i) {
        ans[add_orig[i]] = '#';
    }
    for (int i = 0; i < m; ++i) {
        ans[pre[i]] = '#';
    }
    for (char c : ans) cout << c;
    cout << "\n";
    return 0;
}
