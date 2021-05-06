---
title: CodeForces 1514C - Product 1 Modulo N
date: 2021-05-05 01:28:08
tags:
- ACM
- CodeForces
- 数论
- 裴蜀定理
---



### 题意

给定一个$\geq2$的正整数$n$，求在$[1,2,\dots,n-1]$中选出最多的数字，使得$\prod c_i \ mod \ n = 1$。

其中，$c_i$为被选出的数字。<!-- more -->



### 思路

最开始拿到这道题的时候，想的是质因数分解。容易知道最后的答案的乘积一定能够被表示为$k*n+1$，则考虑枚举乘积，然后分解，在$[1,n-1]$中寻找对应的数字并标记。

对于第一个样例，$6=2*3$，标记得$[1,2,3]$，看起来非常可做。

然后到第二个样例，发现$n=8$时，最优答案是由$105=3*5*7$得到的。如果只是像前面那样分解为两个数的积，是容易做的，但是分解为三个数的积，就基本很难在规定复杂度内完成了。

因此放弃这个想法。

后面考虑，$\prod c_i \ mod \ n = 1$这个形式，是否能使用乘法逆元来解决。

我假设$[1,n-1]$内全部数字乘起来，求解这个数在$mod \ n$意义下的逆元。

发现这样做虽然可以得到一个逆元，但是我很难从逆元中，还原出那些数是被选择出来的。

因此这个想法也凉了。

至此陷入僵局，一时不知道怎么写。

后学习题解，发现：

我们只需要选择所有$gcd(c_i,n)=1$的数，乘起来。

若$\prod c_i \ mod \ n = 1$，则当前所选择的这些数就已经是答案。

否则，在所有选择的$c_i$中，排除掉$\prod c_i \ mod \ n$的结果，则得到答案。

对于样例$1$，$1,2,3,4$与$5$互质，且$\prod c_i \ mod \ n = 4$，最终答案排除掉$4$，则得到答案$1,2,3$。

为什么这个是正确的呢？

首先，我们证明最终的答案里面，所有的$c_i$一定与$n$互质。

假设，存在某个$c_i \ mod \ n = 0$，则在$\prod c_i \geq n$时，$\prod c_i \mod n = 0$，与题意不符。

而$\prod c_i \leq n$的情况，在本题中仅在$n=2$时才成立，此时$gcd(1,2)=1$。

因此，证得所有的$c_i$一定与$n$互质。

我们要使得选择的数**最多**，那么就应该选择全部与$n$互质的元素。

这时我们分类讨论，若$\prod c_i \ mod \ n = 1$，则这些就是答案了，不需要再处理。

若$\prod c_i \ mod \ n = G, G \neq 1$，则：**$G$是一个$[1, n-1]$内，与$n$互质的数**

证明：由前文条件，假设$\prod c_i \geq n$，得$gcd(\prod c_i, n) = 1$，则$gcd(\prod c_i \ mod \ n, n) = 1$。

而$\prod c_i \ mod\ n = G$，所以$gcd(G, n) = 1$。

又因为前文选择的是所有与$n$互质的数作为$c_i$，则$G$一定包含在我们所选择的$c_i$内。

所以，在$\prod c_i \ mod \ n = G, G \neq 1$的情况下，只要排除$c_i$中的元素$G$，得到的就是选择的数最多的最终答案。



### 代码

```c++
#include <bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
int res = 1, flag = -1;
int n, cnt, ans[maxn];
signed main(void)
{
    //freopen("tmp.txt", "w", stdout);
    scanf("%lld", &n);
    for(int i = 1; i <= n - 1; i++)
    {
        if(__gcd(i, n) == 1)
            ans[++cnt] = i, res = (res * i) % n;
    }
    if(res != 1)    flag = res;
    printf("%lld\n", (~flag) ? cnt - 1 : cnt);
    for(int i = 1; i <= cnt; i++)
    {
        if(ans[i] == flag)    continue;
        printf("%lld ", ans[i]);
    }
    return 0;
}
```



---



### End

