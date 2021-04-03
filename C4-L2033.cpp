#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, a[maxn], op[maxn];
int top1, s1[maxn], top2, s2[maxn], fail, val;
char get_op(){
    char ch = getchar();
    while(ch != '+' && ch != '-' && ch != '*' && ch != '/')
        ch = getchar();
    return ch;
}
int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &s1[i]);
    for(int i = 1; i <= n - 1; i++)
        s2[i] = get_op();
    top1 = n; top2 = n - 1;
    while(top2)
    {
        if(s2[top2] == '+' || s2[top2] == '-')
        {
            int bas1 = s1[top1]; top1--;
            int bas2 = s1[top1]; top1--;
            s1[++top1] = (s2[top2] == '+' ? bas2 + bas1 : bas2 - bas1);
            top2--;
        }
        else if(s2[top2] == '*')
        {
            int bas1 = s1[top1]; top1--;
            int bas2 = s1[top1]; top1--;
            s1[++top1] = bas2 * bas1;
            top2--;
        }
        else
        {
            int bas1 = s1[top1]; top1--;
            int bas2 = s1[top1]; top1--;
            if(bas1 == 0)
            {
                fail = 1;
                val = bas2;
                break;
            }
            s1[++top1] = bas2 / bas1;
            top2--;
        }
    }
    if(fail)
        printf("ERROR: %d/0", val);
    else
        printf("%d\n", s1[1]);
    return 0;
}
