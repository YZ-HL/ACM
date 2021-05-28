---
title: CodeForces 1509D - Binary Literature
date: 2021-05-28 15:29:19
tags:
- ACM
- CodeForces
- 构造
---



### 题意

给定一个数字$n$，三个长度为$2n$的$01$字符串$a,b,c$，现在构造一个长度至多为$3n$的字符串$d$，使得$a,b,c$中至少两个字符串是第四个字符串$d$的子序列。<!-- more -->



### 样例

```
[INPUT]
3
011001
111010
010001

[ANS]
011001010
```



### 样例解释

In the second test case all three input strings are subsequences of the output string:

**011**0**0**1**01**0, 0**11**00**1010** and **0**1**100**1**01**0.



### 思路

刚开始拿到这一题，想的突破点是$3$个字符串。这么少的字符串，我是否可以两两选择，看能不能从选择的两个字符串中构造出新的字符串$d$呢？或者是从单个字符串出发，去插入一些元素呢？

为了使得字符串尽可能短，由于题目说保证有解，我猜测了这样一个方法：

首先选定一个主字符串$str$，剩下两个字符串为$s1,s2$，构造两个指针指向$s1,s2$的开头。

然后，我自左向右遍历$str$，如果$s1[p1] = str$，答案加$1$，$p1++ $。对于另一字符串$s2$也是同理。

通过这样的方法，遍历完$str$后，得到两个$p1, p2$，然后，我只需要比较$p1, p2$哪个更大，有更多与主字符串相似的地方。假设$p1$更大，构造所得的答案就是$str + s1.substr(p1, 2 * n - p1)$。

由于可能出现全$0$或全$1$的极端情况，我考虑三个字符串都分别做一次主字符串$str$，理论上总有一个是有解的。

接着，我编写代码交了一发，$wa2$。

**此时代码：**

```c++
#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n;
string str1, str2, str3;
string solve(string s1, string s2, string s3){
    int p1 = 0, p2 = 0;
    string res = "";
    for(int i = 0; i < 2 * n; i++)
    {
        res += s1[i];
        if(s1[i] == s2[p1])    p1++;
        if(s1[i] == s3[p2])    p2++;
    }
    if(p1 >= n)
        res += s2.substr(p1, 2 * n - p1);
    else if(p2 >= n)
        res += s3.substr(p2, 2 * n - p2);
    else
        return "GG";
    //while(res.length() < 3 * n)    res += '0';
    return res;
}
int main(void)
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        cin >> str1 >> str2 >> str3;
        string r1 = solve(str1, str2, str3);
        if(r1 == "E")
            r1 = solve(str2, str1, str3);
        if(r1 == "E")
            r1 = solve(str3, str1, str2);
        cout << r1 << '\n';
    }
    return 0;
}
```



---



当时来去改了几回，暂时没发现啥问题。遂偷了一下测试数据。

$hack$数据：

```
[INPUT]
1
10
11100100000100001100
01010001010000000010
11111111100111110111
[ANS]
11101010001010100001100010
[MY_OUTPUT]
GG
```



---



发现这组可以把我卡掉。

后面分析了一下我第一次的做法，规定了主字符串$str$，相当于另一个额外的字符串$s1$或$s2$的前缀一定是$str$的子集。**这个性质比题目要求的要更强，是不保证有解的。**因为有可能出现这种情况：【部分前缀】【主字符串】【剩余部分】。

由此，只能另寻他法。

我们可以按着原来的思路，设三个指针在开始的时候都指向字符串首，然后两两比较对应的字符是否相等即可。

因为字符串只有$0,1$组成，因此，一定存在一组指针对应的字符相等。

$$s1[p1]=s2[p2],s1[p1]=s3[p3],s2[p2]=s3[p3]$$



**AC代码：**

```c++
#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n;
string str1, str2, str3;
int main(void)
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        cin >> str1 >> str2 >> str3;
        string res = "";
        int p1 = 0, p2 = 0, p3 = 0;
        while(p1 < 2 * n && p2 < 2 * n && p3 < 2 * n)
        {
            if(str1[p1] == str2[p2])        res += str1[p1], p1++, p2++;
            else if(str1[p1] == str3[p3])   res += str1[p1], p1++, p3++;
            else                            res += str2[p2], p2++, p3++;
        }
        if(p1 >= 2 * n)
            res += (p2 > p3 ? str2.substr(p2, 2 * n - p2) : str3.substr(p3, 2 * n - p3));
        else if(p2 >= 2 * n)
            res += (p1 > p3 ? str1.substr(p1, 2 * n - p1) : str3.substr(p3, 2 * n - p3));
        else
            res += (p1 > p2 ? str1.substr(p1, 2 * n - p1) : str2.substr(p2, 2 * n - p2));
        cout << res << '\n';
    }
    return 0;
}
```



---



当然，除了仅有三个字符串外，还有别的特点可以突破。

由于只有$0,1$两个元素组成字符串，那么，$max(cnt_0, cnt_1) \geq n$。由此，我们可以选择多数的部分，然后再插入少数的部分构造答案字符串。



### 结尾

**菜**

