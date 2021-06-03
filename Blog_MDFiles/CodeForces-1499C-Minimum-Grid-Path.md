---
title: CodeForces 1499C - Minimum Grid Path
date: 2021-06-01 19:08:49
tags:
- ACM
- CodeForces
- 分类讨论
- 贪心
---



### 题意

最开始的时候，你处在$(0,0)$的位置，你需要到达$(n, n)$。

移动的过程中，你只能往上走或往右走（$x \rightarrow x+1 \quad or \quad y \rightarrow y + 1$）。

改变方向时被认为开启了一段新的路径。对于第$i$段路径，最终代价为$length_i * C_i$。现在给定$n$和$C_i$，请你求出最小的$\sum C_i * length_i$。<!-- more -->



### 思路

最开始的时候，我贪心的想，我一定走完这$n$条可能的路径，那么排序之后，只选择代价$C_i$最小的两个元素尽可能的去走，就能够得到最优解。但是很明显这是错误的。

其一，我不一定会走完$n$条可能的路径。其二，排序之后会破坏原有的顺序，你不能在第一段的时候以$C_3$的代价来走，这并不总是等价的。

因此，考虑别的做法。

此时我想到了分类讨论，讨论一下当前只选择前$k$条路径，然后这$k$条路径里面，最小值是分布在：①最后两条路，②最后一条路和一条别的路，③另外的两条路。

尝试这样进行分类讨论。分类讨论的第一种情况是对应我的排序算法的处理情况的。但无果，依然难以实现。

然后开始奇怪的想起了$dp$，有没有线性的方案递推能够做到呢？

尝试了一下是不行的，前面的最优选择会影响到后面的结果，有后效性，普通的$dp$难以解决。

此时条条路都不怎么通，搜索了一个提示：

- 每条路的长度对$x$方向和对$y$方向的贡献是独立的

这个提示非常重要，说明我们可以单独考虑$x$方向的最优和$y$方向下的最优。

于是，考虑选择前$k$条路径，分类讨论如下：

1. $k \ mod \ 2 = 0$时，选择$x$方向上代价最小的路径$C_x$，$y$方向下代价最小的路径$C_y$。

   那么，为了最小化代价，我们要尽可能多的走这两条路径，因此，我们设其他的路径长度均为$1$。

   容易得到，这种情况下，两种方向上最小代价的路径的长度均为$n - (k - 2)/ 2$。

   因此，此时的代价为$(C_x + C_y) * [n - (k - 2) / 2] + \sum C_{other} $

2. $k \ mod \ 2 \neq 0$时，同样选择$x$方向上代价最小的路径$C_x$，$y$方向下代价最小的路径$C_y$。

   不同的是，我们先假设，最初的一条路径方向为$x$方向。

   此时，两种方向上最小代价的路径长度有一些改变。

   由于最初路径的方向为$x$方向，$k$为奇数，那么就有$k/2 + 1$条$x$方向的路径，$k/2$条$y$方向上的路径。

   那么，$C_x$对应的最大长度为$n - k/2$，而$C_y$对应的最大长度为$n - k/2 + 1$。

   同理，假设最初的一条路径方向为$y$方向，可以得到$C_x$对应的最大长度为$n - k/2 + 1$，$C_y$对应的最大长度为$n - k/2$。

   这样分类讨论比较麻烦，我们注意到第$i$条路径的**编号i为奇数**的情况下，对应的长度就是较小的那个。

   因此，我们在这种情况下，直接对奇偶线段分析即可。

最后，为了优化时间复杂度，需要维护一个前缀和$sum$，帮助快速解答长度为$1$的线段的代价。以及维护奇数位置$[1,3,5,\dots]$上对应的最小值和偶数位置$[2,4,6,\dots]$上对应的最小值。这样可以做到$O(1)$回答选择前$k$条路径时的最小代价。



### 代码

```c++
/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 800005
#define int long long
using namespace std;

int t, n, c[maxn], sum[maxn], mino[maxn], mine[maxn];
signed main(void)
{
    scanf("%lld", &t);
    mine[0] = 1e17;
    while(t--)
    {
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &c[i]);
            sum[i] = sum[i - 1] + c[i];
            i & 1 ? mino[i] = (i == 1 ? c[i] : min(c[i], mino[i - 2])) : mine[i] = min(c[i], mine[i - 2]);
        }
        int ans = 1e17, nowcost;
        for(int i = 2; i <= n; i++)
        {
            if(i & 1)
            {
                int ost = ((i - 2) + 1) / 2;
                nowcost = mino[i] * (n - ost) + mine[i - 1] * (n - ost + 1);
                nowcost += sum[i] - mino[i] - mine[i - 1];
                ans = min(ans, nowcost);
                //printf("debug2: %lld %lld %lld %lld %lld\n", mino[i] * (n - ost) + mine[i - 1] * (n - ost + 1), mine[i - 1], mino[i], sum[i], nowcost);
            }
            else
            {
                int ost = (i - 2) / 2;
                nowcost = mino[i - 1] * (n - ost) + mine[i] * (n - ost);
                nowcost += sum[i] - mino[i - 1] - mine[i];
                ans = min(ans, nowcost); 
                //printf("debug1: %lld %lld %lld %lld\n", mino[i - 1], mine[i], sum[i], nowcost);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
```



---



### 别的

I am so vegetable...