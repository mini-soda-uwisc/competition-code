#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int m;

int board[N][N] = {0};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct Group
{
    int color;
    int liberties;
    vector<pair<int, int>> location;
};

int parent[N][N] = {0};
map<int, Group> groups;
int group_id = 0;

/**
 * 查找(x, y)在哪个组
 */
int findGroup(int x, int y)
{
    if (parent[x][y] == x * N + y)
    {
        return parent[x][y];
    }
    int px = parent[x][y] / N;
    int py = parent[x][y] % N;
    parent[x][y] = findGroup(px, py);
    return parent[x][y];
}

/**
 * 合并两个组
 */
void unionGroup(int x1, int y1, int x2, int y2)
{
    int id1 = findGroup(x1, y1);
    int id2 = findGroup(x2, y2);
    if (id1 == id2)
        return;

    int gid1 = id1;
    int gid2 = id2;

    // 将较小的组合并到较大的组中
    if (groups[gid1].location.size() < groups[gid2].location.size())
    {
        swap(gid1, gid2);
        swap(id1, id2);
    }

    // 更新父节点
    parent[id2 / N][id2 % N] = id1;

    // 合并位置
    groups[gid1].location.insert(
        groups[gid1].location.end(),
        groups[gid2].location.begin(),
        groups[gid2].location.end());

    // 更新气数
    groups[gid1].liberties += groups[gid2].liberties;

    // 删除已合并的组
    groups.erase(gid2);
}

/**
 * 计算(x, y)处的棋子初始气数
 */
int calculate_liberties(int x, int y, int color)
{
    int liberties = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || nx > 19 || ny < 1 || ny > 19)
            continue;
        if (board[nx][ny] == 0)
            liberties++;
    }
    return liberties;
}

/**
 * 移除一个组
 */
void remove_group(int gid, int &black_captured, int &white_captured)
{
    int color = groups[gid].color;
    for (auto &stone : groups[gid].location)
    {
        int x = stone.first;
        int y = stone.second;
        board[x][y] = 0;

        // 更新相邻组的气数
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || nx > 19 || ny < 1 || ny > 19)
                continue;
            if (board[nx][ny] == 0)
                continue;
            int neighbor_id = findGroup(nx, ny);
            if (groups[neighbor_id].color != color)
            {
                groups[neighbor_id].liberties++;
            }
        }
    }
    if (color == 1)
        black_captured += groups[gid].location.size();
    else
        white_captured += groups[gid].location.size();
    groups.erase(gid);
}

int main()
{
    scanf("%d", &m);
    for (int x = 1; x <= 19; x++)
    {
        for (int y = 1; y <= 19; y++)
        {
            parent[x][y] = x * N + y;
        }
    }

    for (int move = 1; move <= m; move++)
    {
        int x, y;
        scanf("%d%d", &x, &y);

        int color = (move % 2 == 1) ? 1 : 2; // 黑:1，白:2
        board[x][y] = color;

        parent[x][y] = x * N + y;
        int gid = parent[x][y];
        group_id = gid;

        Group new_group;
        new_group.color = color;
        new_group.location.push_back({x, y});
        new_group.liberties = calculate_liberties(x, y, color);
        groups[gid] = new_group;

        // 用于记录被提的子数
        int black_captured = 0;
        int white_captured = 0;

        // 处理相邻的单元格
        set<int> opponent_groups;
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 1 || nx > 19 || ny < 1 || ny > 19)
                continue;
            if (board[nx][ny] == 0)
                continue;
            int neighbor_id = findGroup(nx, ny);
            if (groups[neighbor_id].color == color)
            {
                // 同色组
                unionGroup(x, y, nx, ny);
            }
            else
            {
                // 对手组
                groups[neighbor_id].liberties--;
                if (groups[neighbor_id].liberties == 0)
                {
                    opponent_groups.insert(neighbor_id);
                }
            }
        }

        // 移除气数为零的对手组
        for (int gid_opponent : opponent_groups)
        {
            remove_group(gid_opponent, black_captured, white_captured);
        }

        // 在移除后重新计算玩家组的气数
        int player_gid = findGroup(x, y);
        groups[player_gid].liberties = 0;
        for (auto &stone : groups[player_gid].location)
        {
            int sx = stone.first;
            int sy = stone.second;
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = sx + dx[dir];
                int ny = sy + dy[dir];
                if (nx < 1 || nx > 19 || ny < 1 || ny > 19)
                    continue;
                if (board[nx][ny] == 0)
                {
                    groups[player_gid].liberties++;
                }
            }
        }

        // 如果玩家组的气数为零，则移除该组
        if (groups[player_gid].liberties == 0)
        {
            remove_group(player_gid, black_captured, white_captured);
        }

        // 输出结果
        printf("%d %d\n", black_captured, white_captured);
    }

    return 0;
}