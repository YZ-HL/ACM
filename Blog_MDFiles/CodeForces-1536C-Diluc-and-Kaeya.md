---
title: CodeForces 1536C - Diluc and Kaeya
date: 2021-06-09 15:42:02
tags:
- ACM
- CodeForces
---



### 题意

给定一个只含有$D,K$的字符串$str$。你要将字符串分成若干块，**每一块**的$D:K$的比率都相等，并求解最大的块数。现在，对字符串$str$的每一前缀，请你给出对应的最大块数。<!-- more -->



### 思路

最开始的时候，看错题，认为是**最大化**$D:K$比率相同的块数...

于是就没写出来...

这道题一个关键地方在于，对于某一前缀$pstr$，当前已经出现了$numD$次$ "D"$，$numK$次$"K"$。则被分割成的若干块，由于$a:b = c:d = (a+c) : (b+d)$，比率一定满足$(numD:numK)$。

为了化简比率，只需要除上两个数的$gcd$即可。

当然，题解里面提到把这个性质几何化，如：



![image-20210609155834079](https://raw.githubusercontent.com/YZ-HL/yz-hl.github.io/master/img/1536C-S1.png)



---



通过这个性质，使用$map$维护一下$pair<int, int>$的出现次数，就能$ac$本题。



### 代码

```c++
/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

int t, n;
string str;
int main(void)
{
    IO;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cin >> str;
        int len = str.length();
        int numD = 0, numK = 0;
        map<pair<int, int>, int> mp;
        for(int i = 0; i < len; i++)
        {
            str[i] == 'D' ? numD++ : numK++;
            int nowgcd = __gcd(numD, numK);
            mp[make_pair(numD / nowgcd, numK / nowgcd)]++;
            printf("%d ", mp[make_pair(numD / nowgcd, numK / nowgcd)]);
        }
        putchar('\n');
    }
    return 0;
}
```



---



### 结尾

$6.20$广东省赛？

我感觉要无了（

队友也要跑路了（