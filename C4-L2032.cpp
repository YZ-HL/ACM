#include <bits/stdc++.h>
#define maxn 1005
using namespace std;
int n, m, k, a[maxn];
struct Stack{
    int tops, s[maxn];
    int top(){
        return s[tops];
    }
    void pop(){
        tops--;
    }
    void push(int x){
        s[++tops] = x;
    }
    int size(){
        return tops;
    }
} st;
int main(void)
{
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= k; i++)
    {
        st.tops = 0;
        int nowpos = 1, flag = 1;

        for(int j = 1; j <= n; j++)    scanf("%d", &a[j]);
        
        for(int j = 1; j <= n && flag; j++)
        {
            while(st.top() != j && nowpos <= n)
            {
                st.push(a[nowpos]);
                nowpos++;
            }
            if(st.size() > m + 1)
            {
                flag = 0;
                break;
            }
            if(st.top() == j)    st.pop(); 
            else                 flag = 0;
        }
        printf(flag ? "YES\n" : "NO\n");
    }
    return 0;
}