---
title: CodeForces 1512G - Short Task
date: 2021-05-03 15:36:03
tags:
- ACM
- CodeForces
- 数论
---



### 题意

令$d(n)=\sum_{k | n} k$，给定$t$组询问，每组询问给定一个正整数$c$，问满足$d(n)=c$的最小正整数$n$为多少？<!-- more -->



### 思路

本题$c \leq 10^7$，因此考虑欧拉筛求约数和即可。

忘了这个欧拉筛求约数和怎么推导，这里再推一推记录学习一下。



### 推导

设$S(n)$为$n$的约数和，$n=p_1^{k_1} * p_2^{k_2} * p_3 ^{k_3} * \dots * p_m^{k_m}$

有$S(n)=(1+p_1+p_1^2+\dots + p_1^{k_1}) * (1+p_2+p_2^2+\dots + p_2^{k_2}) * \dots * (1+p_m+p_m^2+ \dots + p_m^{k_m}) \quad ①$

显然，$S(n)$是一个积性函数。

将多项式展开，得到的就是一个约数和的式子$\sum_{k|n}k$。

为了帮助我们求解$S(n)$，我们另设一个数组$Psum(n)$，代表$n$的**最小素因子**的贡献。

如在$①$式中，$Psum(n)=(1+p_1+p_1^2+\dots + p_1^{k_1})$。

形象地说，$Psum(n)$实际取得是$S(n)$第一个括号的内容。

下面开始分类讨论：

- **当$n$为素数时：**

  $S(n) = 1 + n, Psum(n) = 1 + n$

  

- **当$n$不为素数时，由下面两种情况进行更新**

- 当$n \ mod \ pri[j] \neq 0$时：

  $S(n * pri[j]) = S(n) * S(pri[j])$；（积性函数性质）

  $Psum(n * pri[j])= 1+pri[j]$；

  在这种情况下，$S(n)$和$Psum(n)$在$n$更小的时候就已经被更新了。

  确切的说，设$n$的最小素因子为$G$，则在$n'=\frac{n}{G}$时，会有$pri[j]=G$的情况，更新掉$S(\frac{n}{G} * G)$。

- 当$n \ mod \ pri[j] = 0时$：

  $S(n) = (1+p_1+p_1^2+\dots + p_1^{k_1}) * \dots$ 

  $S(n * pri[j]) = (1+p_1+p_1^2+\dots + p_1^{k_1} + p_1^{k_1+1}) * \dots$

  可见，$S(n)$与$S(n*pri[j])$只有第一个括号是不一样的，可以得到递推关系：

  $Psum(n * pri[j]) = Psum(n) * pri[j] + 1$

  $S(n*pri[j])=\frac{S(n)}{Psum(n)} * Psum(n * pri[j])$

  其中，$Psum$的递推关系与字符串$hash$的比较相似。

由上，我们已经确定了递推关系，能够在$O(n)$时间内通过欧拉筛得到约数和。

顺便看了一下约数个数的递推，求法类似，只要维护一个$num$表示最小素因子的出现次数即可。

本质上都是利用了欧拉筛用于提高效率，在最小素因子的时候$break$这一点来进行递推。



### 继续思路

回到刚刚的题目，我们可以求到所有的约数和。

那么，如何在每次询问时快速回答符合条件的最小正整数呢？

可以考虑使用$map$预处理一遍。

但是，由于$n$较大，使用$map$会多一个$log$的复杂度，很可能会$TLE$。

因此考虑使用$unordered\ map$，即可通过该题。

$AC$后学习题解，发现也可逆着枚举$N$来存储符合条件的最小正整数：

```c++
//Author: CodeForces@MikeMirzayanov

fill(ans, ans + N, -1);
for (int i = N - 1; i > 0; i--) {
    if (s[i] < N) {
        ans[s[i]] = i;
    }
}
```



---



### 代码

```c++
#include <bits/stdc++.h>
#define maxn 10000005
using namespace std;
int t, c;
int cnt, pri[maxn];
int s[maxn], psum[maxn];
bool isp[maxn];
void euler(int lim){
    s[1] = psum[1] = 1;
    memset(isp, true, sizeof(isp));
    for(int i = 2; i <= lim; i++)
    {
        if(isp[i])
        {
            pri[++cnt] = i;
            s[i] = psum[i] = i + 1;
        }
        for(int j = 1; j <= cnt && i * pri[j] <= lim; j++)
        {
            isp[i * pri[j]] = false;
            if(i % pri[j] == 0)
            {
                psum[i * pri[j]] = pri[j] * psum[i] + 1;
                s[i * pri[j]] = s[i] / psum[i] * psum[i * pri[j]];
                break;
            }
            else
            {
                psum[i * pri[j]] = pri[j] + 1;
                s[i * pri[j]] = s[i] * s[pri[j]];
            }
        }
    }
}
unordered_map<int, int> mp;
int main(void)
{
    const int lim = 1e7;
    euler(lim);    
    for(int i = 1; i <= lim; i++)
    {
        if(!mp.count(s[i]))
            mp[s[i]] = i;
    }
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &c);
        if(mp.count(c))
            printf("%d\n", mp[c]);
        else
            printf("-1\n");
    }
    return 0;
}
```



---



### End