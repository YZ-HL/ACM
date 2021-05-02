---
title: CodeForces 1511D - Min Cost String
date: 2021-05-02 18:20:02
tags:
- ACM
- CodeForces
---



### 题意

给定一个字符串长度$n$和一个限制条件$k$，$k$代表这个字符串只能由前$k$个小写字母组成。

设置代价为满足$S_i=S_j \ and \ S_{i+1}=S_{j+1}$的二元组$(i,j)$数目，求解任何一个代价最小的字符串。

<!-- more -->



### 思路

首先，不难想到，这是一道构造题。然后，开始考虑构造方法。

根据题意，想到对相邻两个元素进行一个$hash$，存到$set$里面判重，每次去寻找第一个不在$set$内的组合。然后理论上就有个$O(26*n)$的算法了。但是，在这种做法里面，容易陷入死局，提前结束构造，不会遍历到每一个相邻两个元素的组合（应有$k^2$种）。

比如，$k=3$时

```
a->aa->aab->aaba->aabac->aabaca->???
```

这种情况下，程序无法继续执行。

而后，我顺着这个思路继续下去，尝试打补丁解决。

只要$aa,ab,ac$三种组合都已经出现过了，则在枚举下一位元素的时候，从$b$开始枚举。

也就是$aabaca$变成$aabacb$，继续执行程序。

如果$n>$该序列长度$len$，则原样复制。

但是，这样会出现另外的问题。

我们把$n$放大一点，会发现当序列构造结束时，$aabacbbcc$会是最后答案，而$ca$这个组合被忽略了，没能正确构造。

于是，我令序列构造结束后，往后面添加第一个不同的字母。

但是这只能解决$ca$这样的形式，当$k$变大，缺失的组合会越来越多。

比如，在输入样例为$n=25,k=5$的情况下（$wa \ 7$），

$[aabacadaebbcbdccdee]abcdea$，这样的构造方式原样复制得到的是缺少$ec$这个组合的。

参考答案为：$aaeeddecdccebdbcbbeadacab$，用到了每一种组合，没有重复。

此时发现原来的路子已经走不通了。

遂研究题解，发现这是一道$dfs$欧拉回路题。

如果不看欧拉回路，在评论区，我还看到了另外一种构造方法，与我原来思路切合（尽可能使重复的序列少出现）。设$k=3$，则构造方法为：

$$a + ab+ac+b+bc+c$$

$PS:$此处是只有出现$k^2-1$个组合，还要一种组合在原样复制拼接两个字符串的时候出现，即$ca$。

这样的构造方法能够在重复序列最小的情况下，得到长度为$n$的字符串。如果是$n \ mod \ k^2 = 0$的情况下，$ca$的出现次数会比其他组合的都要少$1$。

**代码如下：**

```c++
#include <bits/stdc++.h>

using namespace std;

int n, k;
string ans;

int main()
{
    scanf("%d %d", &n, &k);
    for(int i = 0; i < k; i++)
    {
        ans += 'a' + i;
        for(int j = i + 1; j < k; j++)
        {
            ans += 'a' + i;
            ans += 'a' + j;
        }
    }
    int len = ans.length();
    while(ans.length() < n)
        ans += ans.substr(0, len);
    cout << ans.substr(0, n);
    return 0;
}
```



---



后研究官方题解，官方题解也提到，各种组合之间的出现次数差异，在$\leq1$的时候是有最优结果的。



![image-20210502190143782](https://raw.githubusercontent.com/YZ-HL/yz-hl.github.io/master/img/CF1511D-S1.png)



---



除了上面说的一种构造方法，就是官方所描述的利用欧拉路的思想去解。

将每个顶点视为一个字母，那么，每个顶点之间的连边**（有向边）**就相当于两个字母的组合。

由此，使用$dfs$的办法求解欧拉路，就可以解决这个问题。官方的代码比较精妙，压缩的很短。



**Solution (Neon)**

```
#include <bits/stdc++.h>

using namespace std;

int n, k;
int cur[26];
vector<int> path;

void dfs(int v) {
  while (cur[v] < k) {
  	//此处的cur[v]++，就相当标记当前边已经访问过，要指向下一个点了（a->a => a->b）
    int u = cur[v]++;
    dfs(u);
    path.push_back(u);
  }
}

int main() {
  scanf("%d%d", &n, &k);
  dfs(0);
  printf("a");
  for (int i = 0; i < n - 1; ++i)
    printf("%c", path[i % path.size()] + 'a');
}
```



---



### End