#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 1005
using namespace std;
int n, m, a, b, k, tmp[maxn], sex[maxn];
int cnt1, cnt2; 
double va[maxn][maxn];
struct Love{
    int num;
    double val;
} L1[maxn], L2[maxn];
inline bool cmp(const Love &A, const Love &B){
    if(fabs(A.val - B.val) <= 1e-8)
        return A.num < B.num;
    return A.val > B.val;
}
inline int read(){
    int sum = 0, se = 1; char ch;
    ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-')
        {
            se = -1;
            ch = getchar();
            break;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        sum = sum * 10 + (ch - '0');
        ch = getchar();
    }
    sex[sum] = se;
    return sum;
}
int main(void)
{
    scanf("%d %d", &n, &m);
    for(register int i = 1; i <= m; i++)
    {
        scanf("%d", &k);
        for(register int j = 1; j <= k; j++)    
        {
            tmp[j] = read();
            //printf("%d %d\n", sex[tmp[j]], tmp[j]);
        }
        for(register int j = 1; j <= k; j++)
            for(register int l = j + 1; l <= k; l++)
            {
                int nowa = tmp[j], nowb = tmp[l];
                if(sex[nowa] * sex[nowb] > 0)    continue;
                va[nowa][nowb] += 1.0 / k;
                va[nowb][nowa] += 1.0 / k;
            }
    }
    //scanf("%d %d", &a, &b);
    int ra = read(), rb = read();
    for(register int i = 0; i <= n - 1; i++)
        if(va[ra][i])   
        {
            ++cnt1;
            L1[cnt1].num = i;
            L1[cnt1].val = va[ra][i];
        }
    for(register int i = 0; i <= n - 1; i++)
        if(va[rb][i])   
        {
            ++cnt2;
            L2[cnt2].num = i;
            L2[cnt2].val = va[rb][i];
        }
    sort(L1+1, L1+cnt1+1, cmp);
    sort(L2+1, L2+cnt2+1, cmp);
    double maxx1 = L1[1].val, maxx2 = L2[1].val;
    if((!maxx1 && !maxx2) || (fabs(va[ra][rb] - maxx1) <= 1e-8 && fabs(va[ra][rb] - maxx2) <= 1e-8))
    {
        if(ra == 0)
        {
            if(sex[ra] == -1)
                putchar('-');
            printf("%d %d\n", sex[ra] * ra, rb);
        }
        else if(rb == 0)
        {
            if(sex[rb] == -1)
                printf("%d -%d\n", sex[ra] * ra, rb);
            else
                printf("%d %d", sex[ra] * ra, sex[rb] * rb);
        }
        else
            printf("%d %d", sex[ra] * ra, sex[rb] * rb);
        return 0;         
    }
    for(register int i = 1; i <= n; i++)
        if(fabs(L1[i].val - maxx1) <= 1e-8)
        {
            if(ra == 0)
            {
                if(sex[ra] == -1)
                    putchar('-');
                printf("%d %d\n", sex[ra] * ra, -1 * sex[ra] * L1[i].num);
                continue;
            }
            if(L1[i].num)
                printf("%d %d\n", sex[ra] * ra, -1 * sex[ra] * L1[i].num);
            else
                sex[ra] == 1 ? printf("%d -%d\n", sex[ra] * ra, 0) : printf("%d %d\n", sex[ra] * ra, 0);
        }
    for(register int i = 1; i <= n; i++)
        if(fabs(L2[i].val - maxx2) <= 1e-8)
        {
            if(rb == 0)
            {
                if(sex[rb] == -1)
                    putchar('-');
                printf("%d %d\n", sex[rb] * rb, -1 * sex[rb] * L2[i].num);
                continue;
            }
            if(L2[i].num)
                printf("%d %d\n", sex[rb] * rb, -1 * sex[rb] * L2[i].num);
            else
                sex[rb] == 1 ? printf("%d -%d\n", sex[rb] * rb, 0) : printf("%d %d\n", sex[rb] * rb, 0);
        }
    return 0;
}
