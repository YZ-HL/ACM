/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 205
using namespace std;
int t, n, ans[maxn][maxn];
void dfs(int lf, int rt){
    //printf("debug2: %d %d\n", lf, rt);
    int len = rt - lf + 1, nlen = len / 2;
    int mid = lf + nlen - 1;
    if(nlen & 1)
    {
        for(int i = lf; i <= rt; i++)
        {
            int flag = 1;
            for(int j = i + 1; j <= rt; j++)
            {
                if(j - i == nlen)    ans[i][j] = 0;
                else                 ans[i][j] = flag, flag *= (-1);
            }
        }
        return;
    }
    else if(nlen == 2)
    {
        int p1 = lf, p2 = lf + 1, p3 = rt - 1, p4 = rt;
        ans[p1][p2] = 0; ans[p3][p4] = 0;
        ans[p1][p3] = 1; ans[p1][p4] = -1;
        ans[p2][p3] = -1; ans[p2][p4] = 1; 
        return;
    }
    else
    {
        int flag = 1;
        for(int i = lf; i <= mid; i++)
        {
            for(int j = mid + 1; j <= rt; j++)
                ans[i][j] = flag, flag *= (-1);
            flag *= (-1);
        }
        dfs(lf, mid); 
        dfs(mid + 1, rt);
    }
}
int sc[maxn];
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        memset(ans, 0, sizeof(ans));
        scanf("%d", &n);
        if(n & 1)
        {
            int flag = 1;
            for(int i = 1; i <= n; i++)
                for(int j = i + 1; j <= n; j++)
                    ans[i][j] = flag, flag *= (-1);
        }
        else    dfs(1, n);
        for(int i = 1; i <= n; i++)
            for(int j = i + 1; j <= n; j++)
            {
                if(ans[i][j] == 1)
                    sc[i] += 3;
                else if(ans[i][j] == -1)
                    sc[j] += 3;
                else
                    sc[i]++, sc[j]++;
                
                printf("%d ", ans[i][j]);
            }
        putchar('\n');
        /*
        printf("debug: ");
        for(int i = 1; i <= n; i++)
            printf("%d ", sc[i]);
        */
    } 
    return 0;
}