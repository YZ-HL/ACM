#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;
int A, B, C, m, hp[maxn];
int D[maxn];
int calc(int x, int y, int z){
    if(x > A || y > B || z > C)    return 0;
    return ((x - 1) * B + (y - 1)) * C + (z - 1) + 1;
}
struct At{
    int ht;
    int lat, rat, lbt, rbt, lct, rct;
} attack[maxn];
bool check(int now){
    memset(D, 0, sizeof(D));
    for(int i = 1; i <= now; i++)
    {
        int dhp = attack[i].ht;
        int nx1 = attack[i].lat, ny1 = attack[i].lbt, nz1 = attack[i].lct;
        int nx2 = attack[i].rat, ny2 = attack[i].rbt, nz2 = attack[i].rct;
        D[calc(nx1, ny1, nz1)] += dhp;
        D[calc(nx1, ny1, nz2 + 1)] -= dhp;
        D[calc(nx2 + 1, ny1, nz1)] -= dhp;
        D[calc(nx1, ny2 + 1, nz1)] -= dhp;
        D[calc(nx2 + 1, ny1, nz2 + 1)] += dhp;
        D[calc(nx1, ny2 + 1, nz2 + 1)] += dhp;
        D[calc(nx2 + 1, ny2 + 1, nz1)] += dhp;
        D[calc(nx2 + 1, ny2 + 1, nz2 + 1)] -= dhp;
    }
    for(int i = 1; i <= A; i++)
        for(int j = 1; j <= B; j++)
            for(int k = 1; k <= C - 1; k++)
                D[calc(i, j, k + 1)] += D[calc(i, j, k)];
    for(int i = 1; i <= A; i++)
        for(int j = 1; j <= B - 1; j++)
            for(int k = 1; k <= C; k++)
                D[calc(i, j + 1, k)] += D[calc(i, j, k)];
    for(int i = 1; i <= A - 1; i++)
        for(int j = 1; j <= B; j++)
            for(int k = 1; k <= C; k++)
                D[calc(i + 1, j, k)] += D[calc(i, j, k)];
    for(int i = 1; i <= A * B * C; i++)
        if(D[i] > hp[i])    return true;
    return false;
}
int main(void)
{
    scanf("%d %d %d %d", &A, &B, &C, &m);
    for(int i = 1; i <= A * B * C; i++)    scanf("%d", &hp[i]);
    for(int i = 1; i <= m; i++)
        scanf("%d %d %d %d %d %d %d", &attack[i].lat, &attack[i].rat, &attack[i].lbt, &attack[i].rbt, &attack[i].lct, &attack[i].rct, &attack[i].ht);
    int L = 1, R = m, ans = 1;
    while(L <= R)
    {
        int mid = (L + R) / 2;
        check(mid) ? ans = mid, R = mid - 1 : L = mid + 1;
    }
    printf("%d\n", ans);
    return 0;
}