#include <bits/stdc++.h>
#define maxn 5000005
#define BLOCK_LENGTH 5000000
using namespace std;
int lf, rt, cnt, isp[maxn], sp[maxn]; bool iisp[maxn];
void euler(int lim){
    memset(iisp, true, sizeof(iisp));
    iisp[1] = false;
    for(int i = 2; i <= lim; i++)
    {
        if(iisp[i])    
        {
            cnt++;
            sp[cnt] = i;
        }
        for(int j = 1; j <= cnt && i * sp[j] <= lim ; j++)
        {
            iisp[i * sp[j]] = false;
            if(i % sp[j] == 0)  break;
        }
    }
}
int count(int lf, int rt){
    memset(isp, 0, sizeof(isp));    int num = 0;
    for(int i = 1; sp[i] * sp[i] <= rt && i <= cnt; i++)
    {
        int st = lf / sp[i];
        while(st <= 1 || sp[i] * st < lf)  st++;
        for( ;sp[i] * st <= rt; st++)	
            isp[sp[i] * st - lf] = 1;
    }   
    for(int i = 0; i <= rt - lf; i++)
        if(!isp[i])    num++;
    return num;
}
int main(void)
{
    euler(50000); 
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int l, r;
        scanf("%d %d", &l, &r); 
        if(r - l + 1 > 10000)
            printf("Yes");
        else
            printf(1.0 * count(l, r) / (r - l + 1) < 1.0 / 3 ? "Yes" : "No");
        putchar('\n');
    }
    return 0;
}