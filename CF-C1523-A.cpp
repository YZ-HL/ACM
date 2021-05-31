/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 1005
using namespace std;
int t, n, m;
int cnt, pos[maxn];
char str[maxn];
void debug(){
    for(int i = 1; i <= n; i++)
        putchar(str[i]);
    putchar('\n');
}
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        cnt = 0;

        scanf("%d %d", &n, &m);
        scanf("%s", str + 1);
        for(int i = 1; i <= n; i++)
            if(str[i] == '1')
                pos[++cnt] = i;
        if(cnt == 0)
        {
            debug();
            continue;
        }
        for(int i = pos[1] - 1; i >= max(1, pos[1] - m); i--)        str[i] = '1';
        for(int i = pos[cnt] + 1; i <= min(n, pos[cnt] + m); i++)    str[i] = '1';
        for(int i = 2; i <= cnt; i++)
        {
            int lf = pos[i - 1], rt = pos[i], stp = 0;
            if((rt - lf) % 2 == 0)
                stp = (rt - lf) / 2 - 1;
            else
                stp = (rt - lf) / 2;
            stp = min(stp, m);
            while(lf < rt && stp > 0)
            {
                str[lf + 1] = '1';
                str[rt - 1] = '1'; 
                lf++; rt--; stp--;
            }
        }
        debug();
    }
    return 0;
}
