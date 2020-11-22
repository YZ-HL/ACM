#include <bits/stdc++.h>
#define maxn 4005
using namespace std;
int t, n;
struct seg{
    int lf;
    int rt;
    int val;
} s[maxn];
bool cmp(const seg &A, const seg &B){
    return A.lf < B.lf;
    //return A.rt < B.rt;
}
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        memset(s, 0, sizeof(s));

        int num = 0, ans = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d %d", &s[i].lf, &s[i].rt);
            if(s[i].lf > s[i].rt)
                swap(s[i].lf, s[i].rt);
        }
        sort(s+1, s+n+1, cmp);
        while(num < n)
        {
            //printf("%d\n", num);
            int nrt = 0;
            for(int i = 1; i <= n; i++)
            {
                if(s[i].val)    continue;
                //printf("%d %d %d\n", s[i].lf, s[i].rt, s[i].val);
                if(s[i].lf & 1 && s[i].lf > nrt)
                {
                    s[i].val = 1;
                    nrt = s[i].rt;
                    num++;
                }
                if(s[i].lf % 2 == 0 && s[i].lf > nrt + 1)
                {
                    s[i].val = 1;
                    nrt = s[i].rt;
                    num++;
                }
            }        
            ans += 10;
        }
        printf("%d\n", ans);
    }
    return 0;
}