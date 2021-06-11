/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 400005
#define int long long
using namespace std;
int t, n, a, b, k;
int cntp, pri[maxn];
bool isp[maxn];
int calc(int val){
    int cnt = 0;
    for(int i = 1; i <= cntp && pri[i] * pri[i] <= val; i++)
        while(val % pri[i] == 0)    val /= pri[i], cnt++;
    if(val > 1)    cnt++;
    return cnt;
}
void euler(int lim){
    memset(isp, true, sizeof(isp));
    isp[1] = false;
    for(int i = 2; i <= lim; i++)
    {
        if(isp[i] == true)    pri[++cntp] = i;
        for(int j = 1; j <= cntp && i * pri[j] <= lim; j++)
        {
            isp[i * pri[j]] = false;
            if(i % pri[j] == 0)
                break;
        } 
    }
}
signed main(void)
{
    scanf("%lld", &t);    euler(40000);
    //printf("%lld\n", cntp);
    while(t--)
    {
        scanf("%lld %lld %lld", &a, &b, &k);
        int g = __gcd(a, b);
        int maxcnt = calc(a / g) + calc(b / g);
        //k = 1, only maxcnt = 1
        if(k == 1)
            printf(((a == g && b != g) || (a != g && b == g)) ? "Yes\n" : "No\n");
        else
        {
            //k >= 2
            if(k <= maxcnt)    //to (a / gcd(a, b))
                printf("Yes\n");
            else
            {
                //min -> 1, max -> calc(g) * 2 + 1;
                if(maxcnt == 1)
                {
                    int maxcnt2 = calc(g) * 2;
                    if(k >= maxcnt && k <= maxcnt + maxcnt2)
                        printf("Yes\n");
                    else
                        printf("No\n");
                }
                else
                {
                    //min -> 2, max -> maxcnt + maxcnt2
                    int maxcnt2 = calc(g) * 2;
                    if(k <= maxcnt + maxcnt2)
                        printf("Yes\n");
                    else
                        printf("No\n");
                }
            }
        }
    }
    return 0;
}
