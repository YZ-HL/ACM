#include <bits/stdc++.h>
#define maxn 205
using namespace std;
int t, n, a[maxn], blk[maxn], tblk[maxn];
int check(int x){
    int cnt = 0;
    for (int i = 1; i <= n; i++)    tblk[i] = blk[i];
    for (int i = 1; i <= x-1; i++)
    {
        while(tblk[i] && tblk[x-i])
        {
            if(i == x-i)
            {
                cnt += tblk[i] / 2;
                tblk[i] = 0;
                break;
            }
            tblk[i]--;
            tblk[x-i]--;
            cnt++;
            //printf("1.tblk[%d]=%d cnt=%d\n", i, tblk[i], cnt);
            //printf("2.tblk[%d]=%d cnt=%d\n", x-i, tblk[x-i], cnt);
        }
    }
    return cnt;
}
int main(void)
{
    scanf("%d", &t);
    while (t--)
    {
        int ans = 0;
        memset(blk, 0, sizeof(blk));
        memset(tblk, 0, sizeof(tblk));

        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]), blk[a[i]]++;
        for (int i = 2; i <= n + n; i++)
        {
            int res = check(i);
            //printf("res:%d i:%d\n", res, i);
            ans = max(ans, res);
        }
        printf("%d\n", ans);
    }
    system("pause");
    return 0;
}