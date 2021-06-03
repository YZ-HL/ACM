---
title: CodeForces 六一の复健题单
date: 2021-06-01 14:05:06
tags:
- ACM
- CodeForces
---



## 背景

最近开了蛮多$vp$，上次的$div1+div2$鸽了感觉真的血亏（之前一场没鸽就那天晚上鸽了），本来可以上一把分的...

然后感觉迅速写$AB$应该还算可以了，看的`Masataka Yoneda`大神的攻略，感觉我应该还是再按$rating$筛选做多一些题会比较好，或者去写$AtCoder\  Beginner \ Contest$的$CD$？

顺便按$dp$的$tag$做一下，因为已经知道了是$dp$，$rating$选了$[1700,1800]$，应该还是容易接受的。

挑战困难，快狠准的切掉它们！

望一切顺利。<!-- more -->



## Problem,R1500-1600

[✔ 2021.06.01] [Problem - 1506E - Codeforces](https://codeforces.com/problemset/problem/1506/E)

- $set$处理一下最小值和最接近$q[i]$的数即可

[✔ 2021.06.01] [Problem - 1499C - Codeforces](https://codeforces.com/problemset/problem/1499/C)

- 奇偶分类讨论，由于独立，分拆$x,y$轴贡献。需要特别注意奇数的情况判别。

[✔ 2021.06.02] [Problem - 1497C2 - Codeforces](https://codeforces.com/problemset/problem/1497/C2)

- 构造。除去最后三位，其他全部填$1$，转化为$C1$的简单问题即可。写的时候还分类了$k=n,k=n-1,k=n-2$特殊情况，其实没有必要。

[✔ 2021.06.02] [Problem - 1492C - Codeforces](https://codeforces.com/problemset/problem/1492/C)

- 贪心，思路是先找合法值，再在里面挑选出最优值。维护某一合法值的最小下标和最大下标即可。

  开始的时候$wa7$，后面发现，维护某一合法值的最小下标和最大下标要分别从左往右扫和从右往左扫。

[✔ 2021.06.02] [Problem - 1490F - Codeforces](https://codeforces.com/problemset/problem/1490/F)

- 出现次数由小到大排序，优先处理小的情况。由于只存在删除操作，因此，如果最后$C=k$，那么$C<k$的部分都要被删除。因此，删除了$C<k$的问题之后，可以转化成一个与$C=min(appear \ cnt)$相似的问题。

  然后，维护一下即可，我的写法是三个$map$维护，较为麻烦（

[✔ 2021.06.03] [Problem - 1487D - Codeforces](https://codeforces.com/problemset/problem/1487/D)

- 联立两个条件，消去$a^2$，得$c=b+1$。可以得到，$a^2 = 2b + 1$，问题可以转化为，在$\le n$的情况下，有多少个奇数（$>1$）为完全平方数。这个过程可以预处理后用$lower \ bound$求解，时间复杂度为$O(tlogn)$。在本题里，测试数据较小，也可以直接在每次询问时都$\sqrt{n}$暴力求解。

[✔ 2021.06.03] [Problem - 1487C - Codeforces](https://codeforces.com/problemset/problem/1487/C)

- 使用的是[分治+分类讨论的写法](https://oi-liu.com/2021/06/03/CodeForces-1487C-Minimum-Ties/)解决了这个问题=_=，比官方题解复杂多了...

【】Problem - 1486C1 - Codeforces
https://codeforces.com/problemset/problem/1486/C1

【】Problem - 1486B - Codeforces
https://codeforces.com/problemset/problem/1486/B



---



## DP,R1700-1800

【】Problem - 1525D - Codeforces
https://codeforces.com/problemset/problem/1525/D

【】Problem - 1491D - Codeforces
https://codeforces.com/problemset/problem/1491/D

【】Problem - 1491C - Codeforces
https://codeforces.com/problemset/problem/1491/C

【】Problem - 1476D - Codeforces
https://codeforces.com/problemset/problem/1476/D

【】Problem - 1475D - Codeforces
https://codeforces.com/problemset/problem/1475/D

【】Problem - 1473D - Codeforces
https://codeforces.com/problemset/problem/1473/D

【】Problem - 1472E - Codeforces
https://codeforces.com/problemset/problem/1472/E

【】Problem - 1446B - Codeforces
https://codeforces.com/problemset/problem/1446/B

【】Problem - 1442A - Codeforces
https://codeforces.com/problemset/problem/1442/A

【】Problem - 1437C - Codeforces
https://codeforces.com/problemset/problem/1437/C