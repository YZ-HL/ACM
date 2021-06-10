---
title: CodeForces 1535C - Unstable String
date: 2021-06-09 17:58:47
tags:
- ACM
- CodeForces
- 动态规划
---



### 题意

![image-20210609180436498](https://raw.githubusercontent.com/YZ-HL/yz-hl.github.io/master/img/CF1535C-S1.png)

<!-- more -->



### 思路

拿到这题之后，注意到这题算是一个计数题，要求我们计算出所有$beautiful$的$substring$。

遇到关于$substring$的题目，考虑一下子串的性质与子串的子串是否会有联系。

发现在本题中，如果某一子串是$beautiful$的，那么，它的所有子串也是$beautiful$的。

由此，可以考虑这么一种算法：

1. 从某一位置出发，找到最长能够到达的位置使得这个串是$beautiful$的
2. 若这个$beautiful$的串长度为$len$，则可以对答案增加$len * (len + 1) / 2$的贡献。
3. 设这个串的末尾位置为$pos$，如果$str[pos]=?$，则以$pos+1$为起点寻找下一个能够到达的最长位置。
4. 如果不为$?$，则考虑$1010??? \dots ??[?]$的情形，其中$[?]$对应位置$pos$，我们可以回退到连续的$?$中的第一个$?$，便于改变$?$对应的值以达到更长的能够到达的位置。

这里我们可以类比$Manacher$算法，知道当前已经计算到的最长可到达位置是单调不减的，因此理论上这个算法写出来是接近$O(N)$的。

代码实现如下：

```c++
/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 200005
#define int long long
using namespace std;

int t, len, ans, lfq[maxn], dis[maxn]; 
string str;
void inits(){
    ans = 0;
    memset(lfq, 0, sizeof(lfq));
    memset(dis, 0, sizeof(dis));

    int pos = 1;
    while(pos <= len)
    {
        if(str[pos] == '?')
        {
            int nowpos = pos;
            while(str[pos] == '?')
                lfq[pos] = nowpos, pos++;
        }
        else    pos++;
    }
}
int calc(int nowrt){
    stack<char> s1;
    int nowpos = nowrt;
    s1.push(str[nowpos]); 
    nowpos++;
    while(nowpos <= len)
    {
        if(s1.top() != '?')
        {
            if(str[nowpos] == '?')
                s1.top() == '0' ? s1.push('1') : s1.push('0');
            else if(str[nowpos] != s1.top())
                s1.push(str[nowpos]);
            else
                break;
        }
        else
        {
            if(str[nowpos] == '?')
                s1.push(str[nowpos]);
            else if(str[nowpos] == '1')
                s1.pop(), s1.push('0'), s1.push('1');
            else
                s1.pop(), s1.push('1'), s1.push('0');
        }
        nowpos++;
    }
    return nowpos - 1;
}
signed main(void)
{
    //IO;
    cin >> t;
    while(t--)
    {
        cin >> str;
        str = "#" + str;
        len = str.length() - 1; inits();
        int now = 0, las = 1;
        for(int i = 1; i <= len; )
        {
            now = calc(las);
            int seqlen = now - i + 1;
            if(str[now] == '?')
            {
                int ri = i;
                i = max(lfq[now], i + 1);
                las = now;
                if(i > len)    break;
                ans += (i - ri) * (i - ri + 1) / 2;
                //printf("debug1: i:%lld ri:%lld sq:%lld a:%lld\n", i, ri, seqlen, (i - ri) * (i - ri + 1) / 2);
            }
            else
            {
                i = now + 1;
                las = i;
                ans += seqlen * (seqlen - 1) / 2;
                //printf("debug2: %lld %lld %lld %lld\n", i, now, seqlen, seqlen * (seqlen - 1) / 2);
            }
        }
        int pos = len;
        printf("%lld\n", ans + len);
    }
    return 0;
}
```



---



那么，这个算法是否是正确的呢？

事实上并不，主要问题出现在当前拓展到的最远位置为$?$时，回退操作该回退到什么位置，才能够【不重不漏】。

比如：

```
1
0?10??
```



---



这组数据就能够把我卡掉。每次拓展寻找的段信息如下：

```txt
debug:	lf:1	rt:2	len:2	delta_ans:1
debug:	lf:2	rt:5	len:5	delta_ans:6
debug:	lf:5	rt:6	len:2	delta_ans:1
```



---



可以发现，按照上面的思路进行拓展，最后$[0??]$这一段会被忽略掉，不被计算，只计算了$[??]$这一段。

因此，这个算法是存在一个相当大的问题的。

如果我们直接计算了$[0??]$这一段，然后跳到$??$后的第一个位置，则可能会使得后面的某些串贡献减少。

如果我们直接往前拓展，找到不满足$[...0??]$的最长一段，那么就需要处理与前面计数的重复问题。

由于这两个问题我都没能解决，因此这个算法理论上可以，但实际上没能写出来。

后面学习题解，有一个很简练的$dp$做法。

```c++
//CodeForces @kj1809
dp[0][0] = 0;
dp[0][1] = 0;
long long ans = 0;
for(ll i = 1 ; i <= n; ++i){
    if(s[i-1] == '?'){
        dp[i][0] = dp[i-1][1] + 1LL;
        dp[i][1] = dp[i-1][0] + 1LL;
    }else if(s[i-1] == '0'){
        dp[i][0] = dp[i-1][1] + 1LL;
        dp[i][1] = 0;
    }else if(s[i-1] == '1'){
        dp[i][1] = dp[i-1][0] + 1LL;
        dp[i][0] = 0;
    }
    ans += max(dp[i][0] ,  dp[i][1]);
}
```



---



核心思想是设置$dp[i][0/1]$，代表位置为$i$且结尾为$0/1$的合法字符串数目。如果$i-1$位是$1$，则$dp[i][1]$直接置为$0$，因为子串是连续的，而两个相邻的$1$是不$beautiful$的。由此便可以进行转移。



而官方题解为我们提供了关于这道题奇偶性的一个讨论。



![image-20210609185318390](https://raw.githubusercontent.com/YZ-HL/yz-hl.github.io/master/img/CF1535C-S2.png)



---



```c++
//CodeForces @Neon
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    vector<vector<int>> lst(2, vector<int>(2, -1));
    long long ans = 0;
    for (int i = 0; i < int(s.size()); ++i) {
      int j = i - 1;
      int p = i & 1;
      if (s[i] != '1') j = min(j, max(lst[0][p ^ 1], lst[1][p]));
      if (s[i] != '0') j = min(j, max(lst[0][p], lst[1][p ^ 1]));
      ans += i - j;
      if (s[i] != '?') lst[s[i] - '0'][p] = i;
    }
    cout << ans << '\n';
  }
}
```



---



### 结尾

我倒是想把我那个做法写出来...

但是一直找不到一种可以【不重不漏】的解法（

理论上我可以再预处理反向能够拓展到的最大距离，然后开一个$bool$数组记录那些会重复，每次一边加一边减（

有读者看到的话，可以帮我想一想简便写法（

非常感谢QAQ