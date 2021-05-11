---
title: CodeForces 1519D - Maximum Sum of Products
date: 2021-05-10 00:08:02
tags:
- ACM
- CodeForces
- 动态规划
---



### 题意

给定两个长度为$n$的数列$[a_i],[b_i]$，你可以对数列$[a_i]$进行**至多一次**的区间反转，使得：

$$\sum_{i=1}^{n} a_i * b_i$$

这个表达式求出的值最大。$(1 \leq n \leq 5000)$<!-- more -->



### 思路

最开始拿到这题的时候，想到的是排序不等式（反序和 ≤ 乱序和 ≤ 顺序和），可能会和逆序数有关。

但是，看了一下，题目没有对$[a_i],[b_i]$的顺序做出任何的约束，因此这个做法难以实现。

后面思考，$O(n^2)$枚举翻转的区间，是否有可能快速求解出翻转后整个序列的？

首先对于未被翻转的部分，我们可以通过对两个序列的乘积做一个前缀和来快速求解。设有$sum[i]=sum[i-1]+a[i]*b[i]$，翻转区间为$[lf, rt]$，则未翻转部分的序列乘积和为：

$$sum[lf - 1] + (sum[n] - sum[rt])$$

下面，就是需要快速求解出序列的翻转部分的值。

$n \leq 5000$，$CodeForces$给出的内存限制是$256M$，考虑设计$dp[lf][rt]$表示翻转了$[lf,rt]$内的数所得到的结果，进行记忆化搜索。这样需要开一个$5000*5000$的数组，如果设为$long \ long$类型大概是$200M$，理论是可以过题的。

然后，考虑记忆化搜索的边界情况，有两个：

1. $lf=rt$时，$dp[lf][rt] = a[lf] * b[lf]$
2. $lf=rt+1$时，$dp[lf][rt]=a[lf] * b[rt] + b[rt] * a[lf]$

其余情况，都可以转移到这两个情况中来：

$$dp[lf][rt] = dfs(lf + 1, rt - 1) + a[lf] * b[rt] + a[rt] * b[lf]$$

由此记忆化搜索即可$AC$。

官方题解是利用前缀和性质来对【区间长度为偶数】和【区间长度为奇数】分类讨论求解。

空间上更为节省，不过实现上要复杂一点。

![image-20210510002740341](https://raw.githubusercontent.com/YZ-HL/yz-hl.github.io/master/img/CF1519D-S.png)



### 代码（me）

```c++
#include <bits/stdc++.h>
#define maxn 5005
#define int long long
using namespace std;
int n, a[maxn], b[maxn], sum[maxn], dp[maxn][maxn];
int dfs(int lf, int rt){
    if(~dp[lf][rt])
        return dp[lf][rt];
    if(lf == rt)
        return dp[lf][rt] = a[lf] * b[lf];
    if(lf + 1 == rt)
        return dp[lf][rt] = a[lf] * b[rt] + a[rt] * b[lf];
    return dp[lf][rt] = a[rt] * b[lf] + a[lf] * b[rt] + dfs(lf + 1, rt - 1);
}
signed main(void)
{
    memset(dp, -1, sizeof(dp));
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &b[i]);
        sum[i] = sum[i - 1] + a[i] * b[i];
    }
    int ans = sum[n];
    //printf("debug:%lld\n", ans);
    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            int val = dfs(i, j);
            int newval = sum[i - 1] + (sum[n] - sum[j]) + val;
            //printf("debug: %d %d %d\n", i, j, newval);
            if(ans < newval)
                ans = newval;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
```



---



### 代码（Neon）

```c++
#include <bits/stdc++.h>

using namespace std;

using li = long long;

int main() {
  int n;
  cin >> n;
  vector<li> a(n), b(n);
  for (auto& x : a) cin >> x;
  for (auto& x : b) cin >> x;
  vector<li> pr(n + 1, 0);
  for (int i = 0; i < n; ++i)
    pr[i + 1] = pr[i] + a[i] * b[i];
  li ans = pr[n];
  for (int c = 0; c < n; ++c) {
    li cur = a[c] * b[c];
    for (int l = c - 1, r = c + 1; l >= 0 && r < n; --l, ++r) {
      cur += a[l] * b[r];
      cur += a[r] * b[l];
      ans = max(ans, cur + pr[l] + (pr[n] - pr[r + 1]));
    }
    cur = 0;
    for (int l = c, r = c + 1; l >= 0 && r < n; --l, ++r) {
      cur += a[l] * b[r];
      cur += a[r] * b[l];
      ans = max(ans, cur + pr[l] + (pr[n] - pr[r + 1]));
    }
  }
  cout << ans << endl;
}
```



---



### End