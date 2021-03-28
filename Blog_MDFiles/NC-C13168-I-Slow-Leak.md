---
title: NC-C13168-I Slow Leak
date: 2021-03-28 16:49:22
tags:
- ACM
- 最短路
---



### 背景

训练联盟练习里的一题，比赛时莽了一波裸的迪杰斯特拉，然后炸了（赛后发现是过了七成数据）。

后面才发现，这一题存在可以重复走某条边的情况，因此不难够直接上最短路板子，需要转化问题。

<!-- more -->

### 题目通道

[I-Slow Leak_2021年度训练联盟热身训练赛第三场 (nowcoder.com)](https://ac.nowcoder.com/acm/contest/13168/I)



### 坑点

以这组数据为例：



```
6 8 2 10
2 4
1 3 5
1 2 10
2 3 1
2 4 10
3 5 5
4 5 1
4 6 10
5 6 5
```



---



最短的情况需要重复经过$(2, 3),(4,5)$之间的边，如图所示：



![image-20210328165232552](https://raw.githubusercontent.com/YZ-HL/yz-hl.github.io/master/img/NC13168-S1.png)



---



因此，我们需要简化问题后再跑最短路。

我们先跑一次$Floyd$，处理点与点之间的最短路，然后重新建图。

我们判断连边的两点间最短距离是否超过$d$，如无，则连接，以此为基础将$1,n$和加油站连接在一起，再跑一遍$Floyd$。这样保证了每一条路跑的时候都不会超过最大限度$d$，不需要考虑漏气的问题，转化为单纯的最短路问题。



### 代码

```c++
#include <bits/stdc++.h>
#define maxn 505
#define int long long
using namespace std;
int n, m, t, d;
int cnt, oil[maxn], g[maxn][maxn], ng[maxn][maxn];
const int INF = 1e16;
signed main(void)
{
    scanf("%lld %lld %lld %lld", &n, &m, &t, &d);
    for(int i = 1; i <= t; i++)
    {
        int tmp; scanf("%lld", &tmp);
        oil[tmp] = 1;
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
                g[i][j] = ng[i][j] = 0;
            else
                g[i][j] = ng[i][j] = INF; 
        }
    }
    
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        g[u][v] = g[v][u] = w;
    }
    
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if((i == 1 || i == n || oil[i]) && (j == 1 || j == n || oil[j]))    
                if(g[i][j] <= d)
                    ng[i][j] = g[i][j];
    
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                ng[i][j] = min(ng[i][j], ng[i][k] + ng[k][j]);
                
    if(ng[1][n] >= INF)
        printf("stuck\n");
    else
        printf("%lld\n", ng[1][n]);

    //printf("%d %d %d %d\n", d, ng[2][4], ng[1][2], ng[4][6]);
    return 0;
}
```

