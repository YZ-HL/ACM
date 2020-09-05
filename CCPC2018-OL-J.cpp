#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;
int n, dp[maxn], tree[maxn];
struct Point{
    int x;
    int y;
    int rky;
    int val;
} P[maxn];
bool cmp1(const Point &A, const Point &B){
    return A.y < B.y;
}
bool cmp2(const Point &A, const Point &B){
    if(A.x != B.x)
        return A.x < B.x;
    return A.y > B.y;
}
int lowbit(int x){
    return x & (-x);
}
int Query(int x){
    int ans = 0;
    for(int i = x; i; i -= lowbit(i))
        ans = max(ans, tree[i]);
    return ans;
}
void Update(int x, int k){
    for(int i = x; i <= n; i += lowbit(i))
        tree[i] = max(tree[i], k);
}
int main(void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        memset(dp, 0, sizeof(dp));
        memset(tree, 0, sizeof(tree));

        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d %d %d", &P[i].x, &P[i].y, &P[i].val);
        sort(P+1, P+n+1, cmp1);
        for(int i = 1; i <= n; i++)
            P[i].y == P[i-1].y ? P[i].rky = P[i-1].rky : P[i].rky = P[i-1].rky+1;
        sort(P+1, P+n+1, cmp2);
        for(int i = 1; i <= n; i++)
        {
            dp[i] = max(dp[i], Query(P[i].rky-1)+P[i].val);
            Update(P[i].rky, dp[i]);
        }
        printf("%d\n", Query(n));
    }
    system("pause");
    return 0;
}
