/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

int t, n, k;
void solve1(){
    for(int i = 1; i <= k; i++)
        printf("1 ");
    putchar('\n');
}
void solve2(){
    for(int i = 1; i <= k - 1; i++)
        printf("1 ");
    printf("2");
    putchar('\n');
}
void solve3(){
    if(n == 4)
        printf("2 2\n");
    else if(n == 5)
        printf("2 2 1\n");
    else
    {
        for(int i = 1; i <= k - 1; i++)
            printf("1 ");
        printf("3\n");
    }
}
void solveC1(int n){
    if(n & 1)
		printf("%d %d %d\n", n / 2, n / 2, 1);
	else if((n / 2) & 1)
		printf("%d %d %d\n", n / 2 - 1, n / 2 - 1, 2);
	else
		printf("%d %d %d\n", n / 2, n / 4, n / 4);
}
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &k);
        if(n == k)           solve1();
        else if(n == k + 1)  solve2();
        else if(n == k + 2)  solve3();
        else
        {
            for(int i = 1; i <= k - 3; i++)
                printf("1 ");
            solveC1(n - k + 3);
        }
    }
    return 0;
}
