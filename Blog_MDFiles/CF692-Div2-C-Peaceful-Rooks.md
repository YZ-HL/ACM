---
title: CF692-Div2-C Peaceful Rooks
date: 2021-04-17 17:55:23
tags:
- ACM
- Codeforces
---



### 背景

明天蓝桥杯？有点快。

今天补个远古$CF$题...明天就要上了...

希望不白给...

下周还有个天梯赛，嗯，争取个人奖。<!-- more -->



### 题目

![image-20210417180932620](https://raw.githubusercontent.com/YZ-HL/yz-hl.github.io/master/img/1465C-P)



---



### 题意

现在有一个$n * n$的国际象棋棋盘，上面摆着$m$个车（能横着走，竖着走，每次走的步数不限），坐标分别为$(x_1, y_1), (x_2, y_2), \dots, (x_m, y_m)$，现在要将这$m$个车都移到主对角线（坐标为$(i, i)$，$1 \leq i \leq n$）上，问在不与其他车发生冲突的情况下，需要的最少移动步数是多少？

题目保证开始时这些车都不会冲突（即没有某一个车在另一个车的攻击范围内）。



### 样例

$INPUT$

```
4
3 1
2 3
3 2
2 1
1 2
5 3
2 3
3 1
1 2
5 4
4 5
5 1
2 2
3 3
```



---



$OUTPUT$

```
1
3
4
2
```



---



### 思路

这道题在赛时拿到手的时候，没有什么头绪。考虑对$x$进行排序，然后由小到大满足对应的点。

然后，考虑通过维护$usedx[]$,$usedy[]$，来确定某行某列是否被占用，同时确定是被谁所占用。

如果被均占用，则考虑更换掉**正在占用某行某列的点**，然后再对当前的点进行移动。

这种方案在我的这种写法下，能够通过样例。但是，如果**正在占用某行某列的点**同样无法移动，这个算法就失效了。

$HACK \ INPUT$：

```
5 4
4 5
5 1
1 3
3 4
```



---



$HACK \  OUTPUT$

```
5
```



---



**图例**

![image-20210417204320122](https://raw.githubusercontent.com/YZ-HL/yz-hl.github.io/master/img/CF692-C-S1.png)



---



对于这种写法，我的代码是：

```c++
#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n, m, flag[maxn];
int usedx[maxn], usedy[maxn], newid[maxn];
struct Point{
    int x;
    int y;
    int id;
} P[maxn];
bool operator < (const Point &A, const Point &B){
    return A.x < B.x;
}
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        /*
        memset(usedx, 0, sizeof(usedx));
        memset(usedy, 0, sizeof(usedy));
        memset(newid, 0, sizeof(newid));
        memset(flag, 0, sizeof(flag));
        */

        scanf("%d %d", &n, &m);

        for(int i = 1; i <= n; i++)
            usedx[i] = usedy[i] = newid[i] = flag[i] = 0;

        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d", &P[i].x, &P[i].y);
            P[i].id = i;
            usedx[P[i].x] = i;
            usedy[P[i].y] = i;
        }
        sort(P+1, P+m+1);
        for(int i = 1; i <= m; i++)    newid[P[i].id] = i;
        
        int cnt = 0;
        
        for(int i = 1; i <= m; i++)
        {
            int px = P[i].x, py = P[i].y;
            if(px == py || flag[i])
                continue;
            
            if(!usedy[px])
            {
                usedy[py] = 0;
                usedx[px] = i;
                usedy[px] = i;
                cnt++;
                flag[i] = 1;
            }
            
            else if(!usedx[py])
            {
                usedx[px] = 0;
                usedx[py] = i;
                usedy[py] = i;
                cnt++;
                flag[i] = 1;
            }

            else
            {
                int apx = newid[usedx[py]];
                int apy = newid[usedy[px]];

                if(!flag[apx])
                {
                    //printf("%d %d\n", apx, apy);

                    flag[apx] = 1;

                    usedx[px] = 0;
                    usedy[py] = 0;
                    
                    usedx[P[apx].x] = apx;
                    usedy[P[apx].x] = apx;

                    usedx[P[apx].y] = i;
                    usedy[P[apx].y] = i;
                }
                else
                {
                    flag[apy] = 1;

                    usedx[px] = 0;
                    usedy[py] = 0;
                    
                    usedx[P[apy].x] = apy;
                    usedy[P[apy].x] = apy;
                    
                    usedx[P[apy].y] = i;
                    usedy[P[apy].y] = i;
                }
                cnt += 3;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
```



---



赛后，研究题解，才发现这是一道并查集的妙题！

我们考虑将图上主对角线和棋子都抽象成点，将棋子能够最快到达的主对角线上的点和棋子连边。

如下图所示：

![image-20210417204951680](https://raw.githubusercontent.com/YZ-HL/yz-hl.github.io/master/img/CF692-Div2-S2.png)



---



我们可以发现，这种情况下，形成的图由若干个环和一些边和点组成。

对于某一个环，假设环内有$k$个棋子，则至少需要移动$k+1$次才能将环恢复。

而至少移动$k+1$次是由题目的限制条件$m<n$所确定的。如果没有这个限制条件，就不能够说对于某一环都可以通过$k+1$次操作恢复了。

那么存在一个问题，有没有可能存在共点的环？

答案是没有，如果存在共点的环，至少会有两个及以上的棋子在最初的局面冲突，与题意不符。

那么，每个环的影响都是独立的。不存在将某个环内棋子全部放入主对角线后，影响另一个环的情况。

因此，问题转化为统计图中到底有多少个环。

这个时候我们可以使用并查集，将主对角线编号为$n+1,n+2,\dots,2n$，棋子编号为$1,2,\dots,m$，连边操作转化为集合合并，可以判断出有多少个环。

另外，我们设初始时，答案应为$m$（没有环），而每找到一个环，答案就应该$+1$。

同时，我们还要考虑一种特殊情况：当棋子已经在主对角线上时，不需要移动，则答案应$-1$。

由此，便可以编写代码如下：

```c++
#include <bits/stdc++.h>
#define maxn 2000005
using namespace std;
int t, n, m, uset[maxn];
int find(int x){
    return x == uset[x] ? x : uset[x] = find(uset[x]);
}
bool unioon(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx == fy)    return false;
    uset[fx] = fy;
    return true;
}
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        int cnt = 0;
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n + n; i++)    uset[i] = i;
        for(int i = 1; i <= m; i++)
        {
            int tx, ty;
            scanf("%d %d", &tx, &ty);
            if(tx == ty)    
            {
                cnt--;
                continue;
            }
            else
            {
                int nd1 = tx + n, nd2 = ty + n;
                bool flag = (unioon(nd1, i) && unioon(nd2, i));
                if(flag == false)    cnt++;
            }
        }
        printf("%d\n", cnt + m);
    }
    return 0;
}
```



---



### 别的

鸽了好久来着？这周确实有点忙...下周还要打天梯赛，心累...