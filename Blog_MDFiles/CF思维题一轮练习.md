---
title: CF思维题一轮练习
date: 2020-12-14 15:42:06
tags:
- ACM
- 思维题
---

### 前言

注册了两年CF才发现原来有按难度区间做题的功能...

嘤...我以前只会打打比赛没细玩过CF...<!-- more -->

突然把CF提上日程，大概是上次复盘的时候演队友演的太惨了，快进到罚时爆炸喜提铁首。

签到题老是写不出来，就过来再好好肝一轮思维题了。

不然就真的快进到铁牌寄到家了（一个梗）...

### 题单

#### 1455D - Sequence and Swaps

##### 题意

现在有一个数列$\{a_n\}$，给定一个数$x$，$x$可以与$\{a_n\}$中满足$a_i > x$的数交换，求能否通过交换使$\{a_n\}$有序。

##### 分析

贪心解法。

从左往右扫一遍，若发现可以操作的数就立刻操作，直到序列有序为止。

可以假设答案存在，当前序列未有序。

并且，在遇到了可以交换的数$a_i$时不交换。

则有两种情况：

①形如【$1,2,4,3,5$】（$x = 3$），若不交换，则再也没有机会交换使得序列有序。

②形如【$3,5,4$】（$x=2$），若在$a_i=3$时不进行交换，则在$a_i > 3$时也无法进行交换。因为一旦交换，会出现【$3,2,4$】（$x=5$），【$3,5,2$】（$x=4$）这种情况，此时序列不可能再变得有序。

由上，在序列未有序前，遇到可以交换的数时立刻交换，并计算次数即可。

##### Code

```c++
#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n, x, a[maxn];
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        int ans = 0;
        scanf("%d %d", &n, &x);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for(int i = 1; i <= n; i++)
        {
            if(is_sorted(a+1, a+n+1))
                break;
            if(a[i] > x)    
            {
                swap(x, a[i]);
                ans++;
            }
        }
        printf("%d\n", is_sorted(a+1, a+n+1) ? ans : -1);
    }
    return 0;
}
```



---



#### 1453B - Suffix Operations

这题我直接写的时候总是过不了样例几个点，改不动...

后面面向百度编程才会...呜呜呜...

##### 题意

现在有一个数列$\{a_n\}$，你可以做两种操作：

① 将数列某一后缀的元素全部增加$1$；

② 将数列某一后缀的元素全部减少$1$；

同时，你有一次机会，可以任意选择一个数字变为另一数字。这次机会不算入操作数。

问若要使数列$\{a_n\}$中所有元素都相等，需要的最少操作次数是多少。

##### 分析

看到区间操作，很快就想到了利用差分去做。

设差分数组为$d[i] = a[i+1] - a[i]$；

然后，若没有修改数字，答案就是：$\sum_{i=1}^{n-1}|d[i]|$。

因为，若序列中每个元素都相等，则这样构造得的差分数组每一项元素都为$0$，而每次操作都只能$+1$或$-1$。为了使这些元素变为$0$，需要进行这些元素的大小的绝对值次操作。因此，可得到答案为差分数组的和。

若考虑修改呢？

我最初的想法是寻找到修改后对减少操作数贡献最大的数的位置，在差分数组中完成修改后，再进行一次求和。

但是细节写崩了...

参考标程之后，大致思路还是差不多的，不过很多标程是枚举每一个数，记录最大能够减少的值，最后直接减去就好。

设现在修改$a_i = a_{i-1}$。

①先求出修改前，与$a_i$有关的值

应为$|a_i-a_{i-1}|+|a_{i+1}-a_i|$，

对应到差分数组，即为$|d[i-1]|+|d[i]|$；

---

②再求出修改后，与$a_i$有关的值

设修改后，$a_i$用$a_i'$表示。

此时与其有关的值，$a_i-a_{i-1}=0$，则原式等于$|a_{i+1}-a_i'|$。

又有$a_i' = a_i - d[i-1]$，化入原式，得：

$|a_{i+1}-a_i+d[i-1]|$，即为：$|d[i]+d[i-1]|$；

---

最后，求出两者相减的值$|d[i]| + |d[i-1]| - |d[i] + d[i-1]|$，即为所求的能够减少的值。

再特判一下位于区间两端的情况，就可以$AC$该题。

代码不长，但是细节不少，如果开局直接莽上去，不慢慢推一下式子，$90\%$就凉了。

##### Code

```c++
#include <bits/stdc++.h>
#define maxn 200005
#define int long long
using namespace std;
int t, n, a[maxn], d[maxn];
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        for(int i = 1; i <= n - 1; i++)
            d[i] = a[i + 1] - a[i];
        int ans = 0, maxx = max(abs(d[1]), abs(d[n - 1]));
        for(int i = 2; i <= n - 1; i++)
            maxx = max(maxx, abs(d[i]) + abs(d[i - 1]) - abs(d[i - 1] + d[i]));
        for(int i = 1; i <= n - 1; i++)
            ans += abs(d[i]);
        printf("%lld\n", ans - maxx);
    }   
    return 0;
}
```

---



#### 1452D - Radio Towers

##### 题意

有$n+1$座信号塔，分布在$0,1,2,...,n+1$上，其中$[1, n]$内的信号塔均有$50\%$的概率可以发射信号，信号范围自定，求$[1,n]$内所有信号塔都被**唯一**信号覆盖的概率。答案对$998244353$取模。

##### 分析

设$ans[n]$为当前状态下满足题意的方案数。

容易发现，由于概率均等且互相独立，最后所求期望值一定为$\frac{ans[n]}{2^n} \ mod \ 998244353$。

手算$ans[n]$的小情况，发现好像是斐波那契数列：

| n    | ans[n] |
| ---- | ------ |
| 1    | 1      |
| 2    | 1      |
| 3    | 2      |
| 4    | 3      |
| 5    | 5      |

后面考虑手推一下转移的过程，确认正确性。

~~写的时候发现我手推的证明过程正确性炸掉了，后面在CF评论区找到了说的很好的解释~~

首先，每一个发射信号的信号塔的覆盖塔数一定是奇数（$p$为能量，则数目为$2*(p-1) + 1$）；

也就是说，问题可以转化为将$[1,n]$分为区间长度为奇数的不相交区间的方案数。

设当前区间长度为$len$

①假设$len$为奇数：

若进行分割，则有$len-1,len-3,len-5, \dots , 4, 2,0$等后继局面。

即可写为$F[len] = F[len-1]+F[len-3]+\dots+F[4]+F[2]+F[0]$。

②假设$len$为偶数：

若进行分割，则有$len-1,len-3,len-5, \dots, 3,1$等后继局面。

即可写为$F[len] = F[len-1]+F[len-3]+\dots+F[5]+F[3]+F[1]$；

令$F[0]=1$，计算小样例得$F[1]=F[2]=1$，恰好对应斐波那契数列的递推式：

奇数项求和满足：$a_{2n}=a_1+a_3+a_5+a_7+\dots+a_{2n-1}$

偶数项求和满足：$a_{2n+1}-1=a_2+a_4+a_6+a_8+\dots+a_{2n}$

推导至此，可以确定方案数$ans[n]$即为斐波那契数列的第$n$项。

然后使用费马小定理求解即可。

##### Code

```c++
#include <bits/stdc++.h>
#define maxn 200005
#define mod 998244353
#define int long long
using namespace std;
int n, fib[maxn];
int quickpow(int a, int b){
    if(b == 1)
        return a;
    int tmp = quickpow(a, b / 2);
    tmp = (tmp * tmp) % mod;
    if(b & 1)
        tmp = (tmp * a) % mod;
    return tmp;
}   
signed main(void)
{
    scanf("%lld", &n);
    fib[1] = fib[2] = 1;
    for(int i = 3; i <= n; i++)
        fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    if(n == 1)
        printf("%lld", quickpow(2, mod - 2));
    else if(n <= 3)
        printf("%d", 748683265);
    else
        printf("%lld", (fib[n] * quickpow(quickpow(2, n), mod - 2)) % mod);
    return 0;
}
```

---



#### 1452B - Toy Blocks

##### 题意

共有$n$个盒子，每个盒子里面都有一定数量的球。现在要求往某些盒子里面添加**最少**的球，使得选中任一盒子，都可以将盒子里面的**所有球**通过某一分配方式，使得余下$n-1$个盒子中球的数目相等。

##### 分析

最开始的时候，想到数目相等，口胡了一个差分算法，理论上是没什么问题的，但是实现起来非常复杂。

后面观察一下，有另一解法：

假设加入了$add$个球，最终每个盒子中的球数是$\frac{sum + add}{n-1}$，且应满足$sum + add \equiv 0 (mod \ n-1)$。

要使得$add$最小，则可以先考虑一种特殊情况，取$mx$为球数的最大值，在分配后所有盒子球数均为$mx$。

例如【$1,4,5$】，选中$1$时，添加到$4$，使局面变为【$5,5$】，各种球数目相等。

但是，可以构造一种特殊情况，当有多个$mx$值时，如【$1,5,5$】，则不可能存在分配后所有盒子球数均为$mx$的情况，若使用$\frac{sum + add}{n-1}=mx$求解，会得到$add = -1 < 0$。这显然是不合法的。

因此，需要再给每个盒子加一个球，即$add + (n - 1)$，直到该值大于等于$0$为止。

##### Code

```c++
#include <bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
int t, n, a[maxn], sum, mx;
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        sum = mx = 0;
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &a[i]), sum += a[i], mx = max(mx, a[i]);
        int add = mx * (n - 1) - sum;
        printf("%lld\n", add < 0 ? ((add % (n - 1)) + (n - 1)) % (n - 1) : add);
    }
    return 0;
}

```

---



#### 1451C - String Equality

##### 题意

现在给出两个长度均为$n$的字符串$a,b$，和一个正整数$k$。有两种操作：

①交换两个相邻的字符

②将一段长度为$k$且所有字符都相同的字符串，均增加一。（$k=2,aaa \rightarrow abb \rightarrow acc$）

求能否将字符串$a$通过这两个操作变为字符串$b$。

##### 分析

最开始的时候，没有仔细看题，忘了$all \_equal$的条件限制。写的是对字符串$a$,$b$排序后做差，计算相差的ASCII值，若做差时出现正数，则说明$a$中存在字符$ch$比字符串$b$中所有的字符都要大，则不可能由字符串$a$变为字符串$b$。

若上面那个条件满足，由于能够任意交换，因此只需要计算这些做差后数的绝对值的和，判断能否被$k$整除就可以了。

但是这有个问题。

做差之后，损失了字母是否相同的信息。虽然这好巧不巧能过样例，但这是一个错解也是很明显的。

后来，参考官方的题解，发现是维护了一个桶。桶对应字符串内字母的出现次数，然后由$a$开始往后推导（字符只能增大不能减少）。

若在不断往后推导的过程中，存在不合法的情况，则返回$No$，否则$Yes$。

不合法的情况包括：

①当前字符串$a$拥有的字母$have[i]$小于字符串$b$拥有的字母$need[i]$

②增大的字符数目不能被$k$整除，即为$(have[i]-need[i]) \% k \neq 0$。

代码只根据这两个不合法情况往后推导就好了。

##### Code

```c++
#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;
int t, n, k, have[30], need[30];
char str1[maxn], str2[maxn];
bool check(){
    memset(have, 0, sizeof(have));
    memset(need, 0, sizeof(need));
    for (int i = 1; i <= n; i++)
        have[str1[i] - 'a']++, need[str2[i] - 'a']++;
    bool flag = true;
    for(int i = 0; i <= 25; i++)
    {
        if(have[i] < need[i] || (have[i] -= need[i]) % k)
        {
            flag = false;
            break;
        }
        have[i + 1] += have[i]; 
    }
    return flag;
}
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &k);
        getchar();
        scanf("%s", str1+1);
        scanf("%s", str2+1);
        printf(check() ? "Yes\n" : "No\n");
    }
    return 0;
}
```

---



