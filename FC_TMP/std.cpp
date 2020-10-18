#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//li
int dp[11000];
int num[20]; //保存数量 
int price[20]; //保存价格 
int code[1100];
int st[10] = {1, 6, 36, 216, 1296,  7776, 46656 };
int state;//总的状态i
struct node
{
  int s; //该方案的状态值
  int p; //该方案话费
}plan[110]; 
int N, M;
const int inf = 0x3f3f3f3f;
//十进制转为六进制 
bool jugde( int a, int b)
{
  for( int i = 0; i < N; i++)
  {
     if( (a % 6 + b % 6) > num[i] )
         return false;
      a = a / 6;
      b = b / 6;
  }     
  return true;   
}

int sum( int x)
{
  int sumx = 0;
  for( int i = 0; i < N; i++)
  {
      sumx += (x % 6) * price[i];
      x = x / 6;     
  }    
  return sumx;  
}

int main( )
{
  int p, k, c, t;
  while( scanf("%d",&N) != EOF)
  {
     state = 0;
     memset(plan, 0, sizeof(plan));
     for( int i = 0; i < N; i++)
     {
         scanf("%d%d%d",&c, &k, &p);
         code[c] = i;        
         num[i] = k;
         price[i] = p;
         state += st[i] * k;                
     }
     scanf("%d",&M);
     for( int i = 1; i <= M; i++)
     {
         scanf("%d",&t);
         for( int j = 1; j <= t; j++)
         {
           scanf("%d%d",&c,&k);
           plan[i].s += st[code[c]] * k;      
         }
         scanf("%d",&p);
         plan[i].p = p;      
     }
     for( int i = 1; i <= state; i++)
          dp[i] = inf;
     dp[0] = 0;
     for( int j = 1; j <= M; j++)
     {
         for( int i = 0; i <= state; i++)
         {
           if( i + plan[j].s <= state && jugde(i, plan[j].s))
           {
             if( dp[i + plan[j].s] > dp[i] + plan[j].p && dp[i] != inf)
                 dp[i + plan[j].s] = dp[i] + plan[j].p;    
             
           }
         }
     }
     int ans = inf;
     for( int x = 0; x <= state; x++)
     {
        int t = sum(state - x );
        if( ans > t + dp[x] )
            ans = t + dp[x];          
          
     }
     printf("%d\n", ans);  
  }
  return 0;    
}
