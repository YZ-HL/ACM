#include <bits/stdc++.h>
#define maxn 200005
using namespace std;
int n, m, cnt[maxn];
struct De{
    int num;
    int pos;
}D[maxn];
bool cmp(const De &A, const De &B){
    return A.pos == B.pos ? A.num < B.num : A.pos < B.pos;
}
int main(void)
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++)
    {
        int lf, rt;
        scanf("%d %d", &lf, &rt);
        D[i].num = 1;    D[i].pos = lf;
        D[i+m].num = -1; D[i+m].pos = rt + 1;
    }
    sort(D + 1, D + m * 2 + 1, cmp);
    int sum = 0, maxx = 1;
    for(int i = 1; i <= 2 * m; i++)
    {
        cnt[sum] += D[i].pos - D[i - 1].pos;
        sum += D[i].num;
        maxx = max(maxx, sum);
    }
    int l1 = ceil(1.0 * n / 10);
    int l2 = ceil(1.0 * n / 4);
    int l3 = ceil(1.0 * n / 2);
    /*
    int ans1 = -1, ans2 = -1, ans3 = -1;
    for(int i = maxx; i >= 0; i--)
    {
        cnt[i] += cnt[i + 1];
        if(~ans1 && cnt[i] >= l1)    ans1 = i;
        
    }
    */
    
    int now = 0, ans1 = 0, ans2 = 0, ans3 = 0;
    for(int i = maxx; i >= 1; i--)
    {
        now += cnt[i];
        if(now >= l1 && !ans1)         ans1 = i;
        if(now >= l2 && !ans2)         ans2 = i;
        if(now >= l3 && !ans3)         ans3 = i;
    }
    int r1 = 0, r2 = 0, r3 = 0;
    for(int i = maxx; i >= max(1, ans1); i--)        r1 += cnt[i];
    for(int i = ans1 - 1; i >= max(1, ans2); i--)    r2 += cnt[i];
    for(int i = ans2 - 1; i >= max(1, ans3); i--)    r3 += cnt[i];
    
    printf("%d %d %d\n", r1, r2, r3);
    return 0;
}
//HACK
/*
4 6
1 2
1 4
2 3
2 3
3 4
3 4
*/