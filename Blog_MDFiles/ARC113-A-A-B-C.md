---
title: ARC113-A A*B*C
date: 2021-03-30 00:12:34
tags:
- ACM
- AtCoder
- 前缀和
---



### 题意

给定一个正整数$K \ (K \le 2 * 10^5)$，求满足$A * B * C \le K$的三元组$(A,B,C)$的个数。

注：$A,B,C$的位置不同也视为不同答案，如$(1,1,2)$和$(2,1,1)$是两个答案。<!-- more -->



### 做题思路

遇到有三个变量的题，首先考虑枚举其中一个变量，简化问题。

我考虑枚举$A$，复杂度$O(K)$。此时问题转化为求$B * C \leq \lfloor \frac{K}{A} \rfloor$的个数。

求小于等于某个数的个数，让我联想到前缀和。

考虑预处理满足$B * C = K^{'}$的二元组$(B, C)$的方案数，有：

![image-20210330002720677](https://raw.githubusercontent.com/YZ-HL/yz-hl.github.io/master/img/ARC113-A-S1.png)



---



以此为依据，做前缀和操作，就可以$AC$该题，实测最大耗时$500ms$左右，估计时间复杂度是$O(N \sqrt{N})$。



**代码：**

```c++
#include <bits/stdc++.h>
#define maxn 200005
#define int long long
using namespace std;
int k, sum[maxn], res[maxn];
int cnt, pri[maxn];
bool isp[maxn];
void euler(int lim){
    memset(isp, true, sizeof(isp));
    isp[1] = false;
    for(int i = 2; i <= lim; i++)
    {
        if(isp[i])    pri[++cnt] = i;
        for(int j = 1; j <= cnt && i * pri[j] <= lim; j++)
        {
            isp[i * pri[j]] = false;
            if(i % pri[j] == 0)    break;
        }
    }
}
signed main(void)
{
    scanf("%lld", &k);
    euler(k);
    for(int i = 1; i <= k; i++)
    {
        if(i == 1)    
            res[i] = 1;
        else if(isp[i])
            res[i] = 2;
        else
        {
            for(int j = 1; j * j <= i; j++)
            {
                if(j * j == i)  
                    res[i]++;
                else if(i % j == 0)
                    res[i] += 2;
            }
        }        
    }
    /*
    for(int i = 1; i <= k; i++)
        printf("%lld ", res[i]);
    putchar('\n');
    */
    for(int i = 1; i <= k; i++)
        sum[i] = sum[i - 1] + res[i];
    int ans = 0;
    for(int i = 1; i <= k; i++)
        ans += sum[k / i];
    printf("%lld\n", ans);
    return 0;
}
```



---



### 官方题解

后面看官方题解，发现有一个调和级数复杂度的算法，即$O(\frac{n}{1} + \frac{n}{2}+\dots+\frac{n}{n})$，整理得$O(nlogn)$。

简而言之就是枚举$A,B$两个量，再快速计算出$C$有多少种，就可以通过该题。

这种做法比我上面那种要快很多，官方的$Python$跑的$100ms$。

**官方代码：**

```c++
#!/usr/local/bin/pypy3
import sys
readline = sys.stdin.buffer.readline
sys.setrecursionlimit(10**6)

k=int(readline())

ans=0
for a in range(1,k+1):
	for b in range(1,k//a+1):
		ans+=k//(a*b)
print(ans)
```



---



#### 别的

还有半个月就是天梯赛和蓝桥杯，还没怎么刷过天梯赛，感觉今年要白给啊...

想至少要个三等奖保底...（o´・ェ・｀o）