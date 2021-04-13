#include <bits/stdc++.h>
#define maxn 100005
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
    if(k == 2)
    {
        if(m == 1)    return Point(1, 1);
        if(m == 2)    return Point(1, 2);
        if(m == 3)    return Point(2, 2);
        if(m == 0)    return Point(2, 1);
    }
    Point now = dfs(k - 1, m % (1 << (k - 1)));
    int part = m % (1 << (k + 1)), bas = (1 << (k - 1));
    //part4
    if(part == 0)
    {

    }
    //part 1
    else if(part <= bas)
    {
        swap(now.x, now.y);
    }
    //part 2
    else if(part <= 2 * bas)
    {
        now.y += bas;
    }
    //part 3
    else if(part <= 3 * bas)
    {
        now.x += bas;
        now.y += bas;
    }
    //also part 4
    else
    {
        
    }
}
int main(void)
{
    scanf("%d %d", &n, &m);
    k = log2(n);
    Point res = dfs(k, m);
    return 0;
}
