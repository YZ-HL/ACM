---
title: CF思维题练习-2
date: 2020-12-22 13:58:58
tags:
- ACM
- 思维
---

### 题单

好耶，是思维题！

现在还是在$Rating \ 1400-1600$附近跳一跳选题写。<!-- more -->

#### 1458A - Row GCD

##### 题意

给出两个序列$\{a_n\}$和$\{b_m\}$。

求解：

$(a_1+b_1,a_2+b_1+...+a_n+b_1)$，

$(a_1+b_2,a_2+b_2+...+a_n+b_2)$，

...，

$(a_1+b_m,a_2+b_m+...+a_n+b_m)$

##### 分析

需要了解到$GCD$的一个性质。

假设$x > y$，有$(x, y) = (x - y, y)$（旧时求最大公约数所使用的更相减损术）。

该条式子还可以继续推广，在这题中：

**若要求**$(a_1+b_1,a_2+b_1,...+a_n+b_1)$，

**只需求**$(a_1+b_1,(a_2+b_1)-(a_1+b_1),(a_3+b_1)-(a_1+b_1), \dots, (a_n+b_1)-(a_1+b_1))$

**化简得**$(a_1+b_1, a_2-a_1, a_3-a_1, \dots, a_n - a_1)$

重复出现的部分可定义为$t = (a_2-a_1, a_3-a_1, \dots, a_n - a_1)$

对于每个$b_i$，只需要求解$(a_1+b_i, t)$即可。

由于相减可能会出现负数，因此需要先对$\{a_n\}$从低到高排序。

##### Code

```c++
#include <bits/stdc++.h>
#define maxn 200005
using namespace std;
long long gcd(long long a, long long b){
    return b == 0 ? a : gcd(b, a % b);
}
long long n, m;
long long a[maxn], b[maxn];
signed main(void)
{
    scanf("%lld %lld", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for(int i = 1; i <= m; i++)
        scanf("%lld", &b[i]);
    if(n == 1)
    {
        for(int i = 1; i <= m; i++)
        {
            long long ans = a[1] + b[i];
            printf(i == m ? "%lld" : "%lld ", ans);
        }
        return 0;
    }
    sort(a + 1, a + n + 1);
    long long res = a[2] - a[1];
    for(int i = 3; i <= n; i++)
        res = gcd(res, a[i] - a[i - 1]);
    for(int i = 1; i <= m; i++)
    {
        long long ans = a[1] + b[i];
        printf(i == m ? "%lld" : "%lld ", gcd(ans, res));
    }
    return 0;
}
```



---



#### 1463B - Find The Array

##### 题意

给定一个数列$\{a_n\}$，构造一个数列$\{b_n\}$，满足：

①$b_i$可被$b_{i+1}$整除，或$b_{i+1}$可被$b_i$整除

②$1 \leq b_i \leq 10^9$

③$2\sum_{i=1}^{n}|a_i-b_i| \leq S$

请输出任意一个满足条件的数列$\{b_n\}$。

##### 分析

首先，从整除关系，我们考虑定义一个公因子，每个数都能被其整除，这里考虑$2$为公因子（$2^k$在$[1,10^9]$上的数目大于其他大于$2$的公因子）。

然后，观察到$\sum_{i=1}^{n}|a_i-b_i| \leq S/2$，也就是说，我只需要令每一个$a_i$，都满足$a_i-b_i > a_i/2$，就可以满足这个条件。

最后，对每一个$a_i$，只需要找最接近$a_i$的$2^k$，并填到数列中的对应位置，就可以构造出满足条件的数列。

为了便于填数字，可以用类似离散化的方法，将$a_i$排序，再通过比较逐渐要增大要填入$\{b_n\}$的$2^k$。

##### Code

```c++
#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
long long t, n, s, now, b[maxn];
struct seq{
    long long val;
    long long pos;
} a[maxn];
bool operator < (const seq &A, const seq &B){
    return A.val < B.val;
}
int main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        now = 1;
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &a[i].val), a[i].pos = i;
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; i++)
        {
            while(now * 2 < a[i].val)   now *= 2;
            b[a[i].pos] = now;
        }
        for(int i = 1; i <= n; i++)
            printf(i == n ? "%lld\n" : "%lld ", b[i]);
    }
    return 0;
}
```



---



##### 另解

出题人给出了构造 $\{b_n\}=\{a_1,1,a_3,1,a_5,…\}$和$\{b_n\}=\{1,a_2,1,a_4,1,…\}$的方向。

为了满足被整除的条件，每隔一位插入一个$1$。

而为了满足$2\sum_{i=1}^{n}|a_i-b_i| \leq S$的条件，插入$a_1,a_3,...$或$a_2,a_4,...$。

因为奇数项的和与偶数项的和，必有一个是满足$\leq S/2$的情况的。

不妨假设两个均$>S/2$，则总和$> S$。

因此，只要比较奇数项和与偶数项和，哪个满足$\leq S/2$，就用哪个去构造数列$\{b_n\}$。

**出题人代码：**

```python
for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	s = sum(a)
	cur = [0, 0]
	for i in range(n):
		cur[i % 2] += a[i] - 1
	for j in range(2):
		if 2 * cur[j] > s:
			continue
		for i in range(n):
			if i % 2 == j:
				a[i] = 1
		break
	print(*a)
```



---



#### 1462E1 - Close Tuples (easy version)

##### 题意

给定一个序列$\{a_n\}$，计算满足$i<j<k$且$max(a_i,a_j,a_j)-min(a_i,a_j,a_j) \leq 2$的三元组个数。

##### 分析

$\leq2$的条件暗示我们，我们可以从权值入手。

维护若干个桶，代表自左向右扫描的过程中，某个数字的出现个数。

然后，边维护桶边计算方案数。我们可设当前扫描到的是$a_z$，且未加入桶的统计。

这样，当前桶里的数，都是可以作为$a_i,a_j$的数。

由于这个三元组只要求下标有顺序，因此，我们不需要考虑$a_i,a_j$的相对大小，只要统计他们的数目即可。

最后，进行分类讨论计算答案即可。

对于本题的$Hard \ version$，可以排序后，使用类似做法维护区间$[x,x+k]$的数目，就能快速求出答案。

不过需要预先处理阶乘逆元。

##### Code

```c++
#include <bits/stdc++.h>
#define maxn 200005
#define int long long
using namespace std;
int t, n, ans, a[maxn], b[maxn], fac[maxn];
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        ans = 0;
        //memset(b, 0, sizeof(b));
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            //3: a-2,a-1,a; a-1,a+1,a; a+2,a+1,a;
            ans += b[a[i] - 1] * b[a[i] + 1];
            ans += b[a[i] - 2] * b[a[i] - 1];
            ans += b[a[i] + 1] * b[a[i] + 2];
            //1: a,a,a
            if(b[a[i]] >= 2)
                ans += b[a[i]] * (b[a[i]] - 1) / 2;
            //4: a,a,(a-2,a-1,a+1,a+2)
            if(b[a[i]] >= 1)
                ans += b[a[i]] * b[a[i] - 1] + 
                       b[a[i]] * b[a[i] + 1] + 
                       b[a[i]] * b[a[i] - 2] + 
                       b[a[i]] * b[a[i] + 2] ; 
            //1: a-1,a-1,a
            if(b[a[i] - 1] >= 2)
                ans += b[a[i] - 1] * (b[a[i] - 1] - 1) / 2;
            //1: a+1,a+1,a
            if(b[a[i] + 1] >= 2)
                ans += b[a[i] + 1] * (b[a[i] + 1] - 1) / 2;
            //1: a-2,a-2,a
            if(b[a[i] - 2] >= 2)
                ans += b[a[i] - 2] * (b[a[i] - 2] - 1) / 2;
            //1: a+2,a+2,a
            if(b[a[i] + 2] >= 2)
                ans += b[a[i] + 2] * (b[a[i] + 2] - 1) / 2;
            b[a[i]]++;
        }
        for(int i = 1; i <= n; i++)    b[a[i]] = 0;
        printf("%lld\n", ans);
    }
    return 0;
}
```



---



#### 1462D - Add to Neighbour and Remove

##### 题意

给定一个序列$\{a_n\}$，每次选择其中一个元素$a_i$，然后加到$a_{i-1}$或$a_{i+1}$上（如果不存在$a_{i-1}$或$a_{i+1}$则不能加），再删除掉$a_i$。求使得序列$\{a_n\}$中全部元素都相等的最小操作数是多少？

##### 分析

首先，观察到不论怎么样，元素的总和$Sum$都是不变的。

其次，若操作$k$次后，每个序列元素相等，则一定满足$Sum \% (n-k) = 0$。

最后，观察到$n \leq 3000$，考虑对每一种可能的操作数（设当前操作数目为$k$）都判断一次能否形成对应的合法序列。

因为确定了$k$之后，序列中每个元素的值也能被唯一确定。

因此，只需要从左到右判断一遍能否在$k$次操作内将序列转为每一元素都为$Sum/(n-k)$的新序列即可。

##### Code

```c++
#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n, a[maxn];
int check(int val, int aven){
    int cnt = 0, fail = 0;
    int now = a[1];
    for(int i = 2; i <= n; i++)
    {
        //printf("%d %d\n", i, now);
        if(now == val)
        {
            now = a[i];
        }
        else if(now < val)
        {
            now += a[i];
            cnt++;
        }
        else
        {
            fail = 1;
            break;
        }
    }
    //printf("%d %d %d\n", cnt, val, aven);
    return cnt == aven && !fail;
}
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        int sum = 0, flag = 0;
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]), sum += a[i];
        for(int i = n; i >= 1 && !flag; i--)
        {
            if(sum % i)    continue;
            flag = check(sum / i, n - i) ? (n - i == 0 ? -1 : n - i) : 0;
        }
        printf("%d\n", flag == -1 ? 0 : flag);
    }
    return 0;
}
```



---



#### 1443C - The Delivery Dilemma

##### 题意

给定两个序列$\{a_n\}$和$\{b_n\}$，让你选择$\{a_n\}$中$k$项元素（设这$k$个元素组成的子集为$h$），$\{b_n\}$中$n-k$项元素（设这$n-k$个元素组成的子集为$l$），使得$max ( max ( a_{h_1}, a_{h_2}, ..., a_{h_k} ) ,Sum ( b_{l_1}, b_{l_2},...,b_{l_n-k} ) )$最小。

##### 分析

考虑从$\{a_n\}$入手。

由于$\{a_n\}$的贡献只和选中的子集$h$中的最大值有关，因此，我们可以对$\{a_n\}$排升序。可设排序后，当前扫描到的元素就为$a_k$，排序后保证了当前的$a_k \geq a_{k-1} \geq ... \geq a_1$，也就是说$max=a_k$。而后，考虑处理剩下的部分，只需要预处理一个后缀和，就可以快速求解$\{b_n\}$的贡献了。当然用前缀和处理，相减一下，效果是一样的。

有没有可能排序之后，所取的$\{a_n\}$的子集$h$不是$a_1,a_2,...,a_k$的连续序列呢？实际上是不可能的。

设原来所花时间为$rtime$。假设我只取$a_1,a_2,...,a_k-1,a_k+1$，那么，所花的时间一定满足$\geq rtime$，因为$a_{k+1} \geq a_{k}$，且满足$a_k \geq a_{k-1} \geq ... \geq a_1$。

因此，根据贪心的思想，我每次取排序后，连续的$a_1,a_2,...,a_k$是最优的。

##### Code

```c++
#include <bits/stdc++.h>
#define maxn 200005
#define int long long
using namespace std;
int t, n, maxa[maxn], sumb[maxn];
struct T{
    int a;
    int b;
} order[maxn];
bool operator < (const T &A, const T &B){
    if(A.a == B.a)
        return A.b < B.b;
    return A.a < B.a;
}
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        int ans = (int)1e16;
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &order[i].a);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &order[i].b);
        sort(order+1, order+n+1);
        for(int i = 1; i <= n; i++)
            maxa[i] = max(order[i].a, maxa[i - 1]);
        for(int i = 1; i <= n; i++)
            sumb[i] = order[i].b + sumb[i - 1];
        for(int i = 0; i <= n; i++)
            ans = min(ans, max(maxa[i], sumb[n] - sumb[i]));
        printf("%lld\n", ans);
    }
    return 0;
}
```



---



