---
title: CodeForces 1516B - AGAGA XOOORRR
date: 2021-05-06 21:00:46
tags:
- ACM
- CodeForces
- 杂题
---



### 题意

给定一个有$n(2 \leq n \leq 2000)$个元素的数列，你可以对这个数列进行若干次操作。每次操作可以选择**相邻**两个元素，删除这两个元素，并在原位置插入这两个元素**异或**的结果。问是否存在一个方案，使得在若干次操作后整个数列的元素相同？

需要特别注意的是，操作结束后的数列**至少要有两个元素**。

<!-- more -->



### 思路

看到异或，首先想到异或有着非常优秀的性质：交换律。可以对数列进行一个前缀异或的操作，使得能在$O(1)$时间内求出某一段数字的异或值。

然后，观察数据范围，应该是需要一个$O(n^2)$的算法，考虑枚举左右端点，以这区间内的异或值为答案。

由于题目给定了只能选择相邻元素进行异或，因此我这样是能够枚举**所有**可能的最终序列的值的。

那么，我通过枚举左右端点，得到了一个可能的最终序列的值，接下来就是验证这个值能不能被实现了。

手推了几个小样例，我认为令$C$是所有元素异或的结果，当前区间内的异或结果为$G$，若$G==C$，则存在方案。

这个代码顺利通过了样例，交，返回$wa \ 5$。

后构造一组数据：$[3, 3, 1, 2, 3, 1, 2, 3]$，我选定$[1,2]$异或作为最终答案时，其余元素的异或值不为$3$，又尝试了别的几个区间，将我上面的想法否决了。

此时我发现我的代码对于这种情况无能为力，思考要不要分成三个区间？但仍没能搞出来。

后看题解，发现离正解已经很接近了。

按照题解的意思，我们可以将这个数列划分为若干块，只要**这若干块的异或值相同**就行。

那么，我们假设我们已经得到一种划分方式，划分的若干块异或值相同。

是否一定需要这么多块？有没有更优的解法？

不需要。其实我们只需要考虑两块或三块的情况就可以了。

假设我们有四块，比如$[1, 2][3][1,2][3]$，他们的异或值都为$3$。则我们可以任意选择三个相邻的块，通过异或将他们变为一块，即$[1,2][3]$，答案没有改变，但块数却减少了。

其他情况以此类推。

因此，我们只需要考虑分为两块或三块的情况就可以了。

而分成两块的情况，充要条件是全部元素异或值为$0$，因此不需要枚举计算。

下面考虑分成三块的情况，只需要将我之前用于枚举区间左右端点的代码，改为枚举三块区间的两个分割点的代码，就可以在$O(n^2)$的时间内，找到所有划分为三块的情况。

通过这种方法，我们可以确定给定的序列是否能够通过一定的操作使其变为$0$。

对上面那个$hack$数据，我们划分$[3,3][1,2,3][1,2,3]$，异或值均为$0$，可以得到答案。



### 代码

由于参考了出题人给出的代码，所以实现细节基本相同...

```c++
#include <bits/stdc++.h>
#define maxn 2005
using namespace std;
int t, n, a[maxn], sum[maxn];
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            sum[i] = sum[i - 1] ^ a[i];
        }
        int flag = (sum[n] == 0);
        for(int i = 1; i <= n && !flag; i++)
        {
            for(int j = i + 1; j < n && !flag; j++)
            {
                flag |= (sum[i] == (sum[j] ^ sum[i])) &&
                        (sum[i] == (sum[n] ^ sum[j]));
            }
        }
        printf(flag ? "YES\n" : "NO\n");
    }
    return 0;
}
```



---



### 进阶

出题人还提到，这一题其实可以在$O(n)$的时间内解决。

[PR_0202@CodeForces](https://codeforces.com/profile/PR_0202)在评论区给出了一个很漂亮的解法。

假设分成了若干块为$[c_1][c_2]\dots[c_n]$，我们可以知道，$[c_1] \ xor \ [c_2] \ xor \ \dots \ xor [c_n]=C$。

常数$C$为所有元素的异或和。

若$C$为$0$，则一定存在一种划分方式，将数列划为两块且异或值相同，这点我们在普通情况已经考虑了。

若$C$不为$0$，我们可以知道，一定存在划分方案可以将数列分成**奇数块**$[c_i]$。

因为如果分成了偶数块，由异或性质，结果为$0$。

那么，我们问题转为求$[c_1] \ xor \ [c_2] \ xor \ \dots \ xor\ [c_n] = C$，这条式子里面，等号左边能够被划分为多少块。

如果只能被划分为$1$块，即$[c_1]=C$，则不能够通过异或实现数列内元素相等。

如果能够划分为$3$块及以上，则能够通过异或来实现数列内元素相等。

我们怎么确定能够划分为几块？

只需要从左到右，求异或值。当异或值为$C$时，块数加一，并清空现在的异或值重新计算。

事实上，这样求得的是最多能够被划分的块数，如果题目拓展为是否能划为$k$块，就可以用这个思路求解。



### 进阶代码（PR_0202）

```c++
// Author: Pawan Raj
// Problem: B. AGAGA XOOORRR
// Contest: Codeforces - Codeforces Round #717 (Div. 2)
// URL: https://codeforces.com/contest/1516/problem/B

#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
#define F(i, n) for (int i = 0; i < n; i++)
#define all(x)(x).begin(), (x).end()
#define show(A) for (auto i: A) cout << i << " "; cout << '\n';
#define show_(A, n) F(i, n) { show(A[i]) }

using namespace std;
using ld = long double;
using vi = vector < int > ;
using mi = map < int, int > ;
using pi = pair < int, int > ;

const int N = 300005;
const int MOD = 1e9 + 7;
const int inf = 1e18 + 1;
/***************************code begins here*****************************/

void solve() {
    int n, ans = 0; cin >> n;
    int xr = 0;
    vi a(n);
    F(i, n) {
    	cin >> a[i];
    	xr ^= a[i];
    }
    if(xr == 0){
    	cout << "YES" << '\n';
    }
    else{
    	int t = 0, c = 0;
    	for(int i=0;i<n;i++) {
    		t^=a[i];
    		if(t==xr){
    			c++;
    			t = 0;
    		}
    	}
    	if(c >= 3 ){
    		cout << "YES" << '\n';
    	}
    	else{
	    	cout << "NO" << '\n';
    	}
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}
```



---



### End