#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k;
struct Point{
    int x;
    int y;
    Point(int nx, int ny){
        x = nx;
        y = ny;
    }
};
Point dfs(int k, int m){
    //printf("%d %d\n", k, m);
    //system("pause");
    if(k == 1)
    {
        if(m == 1)    return Point(1, 1);
        if(m == 2)    return Point(1, 2);
        if(m == 3)    return Point(2, 2);
        if(m == 4)    return Point(2, 1);
    }
    int bas = (1 << (k - 1));
    int part = (m + bas * bas - 1) / (bas * bas);
    Point now = dfs(k - 1, m - (part - 1) * bas * bas);
    //part 1
    if(part == 1)
    {
        swap(now.x, now.y);
    }
    //part 2
    else if(part == 2)
    {
        now.y += bas;
    }
    //part 3
    else if(part == 3)
    {
        now.x += bas;
        now.y += bas;
    }
    //part 4
    else
    {
        swap(now.x, now.y);
        now.x = bas * 2 - now.x + 1;
        now.y = bas - now.y + 1;
    }
    //printf("%d %d %d\n", k, now.x, now.y);
    return now;
}
signed main(void)
{
    scanf("%lld %lld", &n, &m);
    k = log2(n);
    Point res = dfs(k, m);
    printf("%lld %lld\n", res.x, res.y);
    return 0;
}
