---
title: CodeForces 1498D - Bananas in a Microwave
date: 2021-05-10 21:23:27
tags:
- ACM
- CodeForces
- 动态规划
- 背包
---



### 题意

搬运$luogu$的翻译：

![image-20210510212501174](https://raw.githubusercontent.com/YZ-HL/yz-hl.github.io/master/img/CF1498D-S-S1.png)

<!-- more -->



### 思路

五一休闲计划~~（其实变成了每日一题计划）~~最后一题。

首先很容易想到$O(nm^2)$的做法，以多重背包为基础，写$dp$转移哪些数字是可达的。

![](https://raw.githubusercontent.com/YZ-HL/yz-hl.github.io/master/img/CF1498D-S-S2.png)



---



```c++
for(int i = 1; i <= n; i++)
    for(int j = m; j >= 0; j--)
    {
        for(int k = 1; k <= group[i]; k++)
        {
            /*转移部分*/
        }
    }
```



---



然后，本题中，我们的转移方程分为两个：

$$dp[j + Ceil(k \cdot val)] \ = dp[j] \quad | \quad dp[j + Ceil(k \cdot val)]$$

$$dp[Ceil(j \cdot k \cdot val)] \ = dp[j] \quad | \quad dp[Ceil(j \cdot k \cdot val)]$$

考虑优化时间复杂度。多重背包转为$01$背包求解，有两种常见的优化【单调队列优化】和【二进制拆分】。二进制拆分复杂度为$O(nm \cdot logm)$，对于本题来说还是有些勉强，而且也不能支持操作二。因此可能只能够使用单调队列优化来帮助解决该题。

但是学习了一下这种优化之后发现，它依赖于对余数进行分类，很难对操作二进行优化，因此这条路也走不通。

后面思考设二维$dp$，$dp[i][j]$为前$i$个元素选完后，哪些$j$能够被达到。

但实际上，这个设计并没有用，和普通的$01$背包的某些值是否可达问题是等价的。

下午学习题解，才发现在原来暴力枚举$O(nm^2)$上添加一点语句，就可以降低时间复杂度为$O(nm)$。

当然，这主要是因为本题只需要求**最早在哪次操作后出现**，不需要求一个最优解，因此可以这么优化。

第一，由于我们的转移依赖$dp[j]$，因此可以设$dp[j]$为不可达到时，$continue$，不进入枚举$k$的状态，这步也是方便后面进行讨论。

即：

```c++
for(int j = m; j >= 0; j--)
{
    if(!dp[j])    continue;
    ...
}
```



第二，**这步是重点**，我们称要被转移的下一个数为$num = j + Ceil(k \cdot val) \ or \ Ceil(j \cdot k \cdot val)$。

那么，在枚举取$k$个元素时，考虑在遇到$ans[num]$已经被更新时，直接$break$。$ans[num]$为$num$这个数字出现的最小操作时间。

为什么可以这么做呢？我们的枚举是$m \rightarrow 0$的，在发现$num$的答案已经被更新时，代表着在比当前$m$更大的时候，$num$的答案已经被更新。而在那个时候，也进行了一轮$k$的枚举，能够更新的值一定比当前$m$再进行$k$的枚举所能更新的值要多。因此，可以直接$break$。

当然，另一重要原因是，对于任何一个数$num$，在$k,val$相同的情况下，转移时的路线是唯一的。在操作一的情况下，你想要达到$num$，那么就只能从$num-k*val$转移过来。

操作二的情况一样，可以参考这个[证明](https://www.cnblogs.com/PPLPPL/p/14729149.html)：

![image-20210510221555433](https://raw.githubusercontent.com/YZ-HL/yz-hl.github.io/master/img/CF1498D-S-S3.png)



---



由此，我们可以将时间复杂度从$O(nm^2)$优化到$O(nm)$，因为每个数都只会被**最合适**的$j$所更新，这里的最合适是指不会存在重复更新的操作。



### Code

```c++
#include <bits/stdc++.h>
#define maxn 2000005
#define int long long
using namespace std;
int n, m, ans[maxn], vis[maxn];
int dp[maxn];
struct op{
    int t;
    int val;
    int cnt;
}o[maxn];
int Ceil(int val){
    return ((val + 100000 - 1) / 100000);
}
signed main(void)
{
    scanf("%lld %lld", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%lld %lld %lld", &o[i].t, &o[i].val, &o[i].cnt);
    //memset(dp, 0x3f, sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = m; j >= 0; j--)
        {
            if(!dp[j])    continue;
            int val = j;
            for(int k = 1; k <= o[i].cnt; k++)
            {
                val = (o[i].t == 1 ? val + Ceil(o[i].val) : Ceil(val * o[i].val));
                if(val > m)    break;
                dp[val] |= dp[j];
                //key
                if(!ans[val])               ans[val] = i;
                else                        break;
                //printf("debug: %lld %lld %lld %lld\n", i, j, k, val);
            }
        }
    }
    for(int i = 1; i <= m; i++)
        printf("%lld ", !ans[i] ? -1 : ans[i]);
    return 0;
}
```



---



### End