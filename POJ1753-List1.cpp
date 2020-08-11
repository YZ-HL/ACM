#include <cstdio>
#include <iostream>
#include <queue>
#define maxn 5
using namespace std;
int ans, flag, board[maxn][maxn], used[(1 << 18) + 5];
struct Step
{
    int x;
    int st;
};
int hash_it()
{
    int e = 1, res = 0;
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
        {
            res += e * board[i][j];
            e <<= 1;
        }
    return res;
}
void recover_it(int num)
{
    int cnt = 0;
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
        {
            board[i][j] = num & (1 << cnt) ? 1 : 0;
            cnt++;
        }
}
void change_it(int i, int j)
{
    board[i][j] ^= 1;
    board[i + 1][j] ^= 1;
    board[i][j + 1] ^= 1;
    board[i - 1][j] ^= 1;
    board[i][j - 1] ^= 1;
}
void input_it()
{
    for (int i = 1; i <= 4; i++)
    {
        char tmp[10];
        scanf("%s", tmp + 1);
        for (int j = 1; j <= 4; j++)
            board[i][j] = tmp[j] == 'b' ? 1 : 0;
    }
}
void bfs()
{
    queue<Step> q1;
    int inits = hash_it();
    used[inits] = 1;
    q1.push((Step){inits, 0});
    while (!q1.empty())
    {
        int tmpx = q1.front().x;
        int tmps = q1.front().st;
        if (tmpx == 0 || tmpx == ((1 << 16) - 1))
        {
            ans = tmps;
            flag = 1;
            break;
        }
        q1.pop();
        recover_it(tmpx);
        for (int i = 1; i <= 4; i++)
        {
            for (int j = 1; j <= 4; j++)
            {
                change_it(i, j);
                int res = hash_it();
                if (used[res])
                {
                    change_it(i, j);
                    continue;
                }
                used[res] = 1;
                q1.push((Step){res, tmps + 1});
                change_it(i, j);
            }
        }
    }
    flag ? printf("%d\n", ans) : printf("Impossible\n");
}
int main(void)
{
    input_it();
    bfs();
    system("pause");
    return 0;
}