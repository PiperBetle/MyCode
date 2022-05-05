#include <bits/stdc++.h>
using namespace std;

int a[5];
char opt[5]= {' ','+','-','*','/'};

int F(int x,int k, int y)                                 
{
  if(k==1)
    return x+y;
  if(k==2)
    return max(x,y)-min(x,y);
  if(k==3)
    return x*y;
  return (y==0 || x<y || x%y!=0) ? -999999 : x/y;
}

void Out(int a,int b,int c,int d,int e,int f,int k1,int k2,int k3)
{
  printf("%d%c%d=%d\n",max(a,b),opt[k1],min(a,b),F(max(a,b),k1,min(a,b)));
  printf("%d%c%d=%d\n",max(c,d),opt[k2],min(c,d),F(max(c,d),k2,min(c,d)));
  printf("%d%c%d=%d\n",max(e,f),opt[k3],min(e,f),F(max(e,f),k3,min(e,f)));
  exit(0);                                                  //直接退出程序
}

int main()
{
  scanf("%d%d%d%d", &a[1],&a[2],&a[3],&a[4]);
  sort(a+1,a+5);                                            //保证遍历所有情况
  do
  {
    for (int i = 1; i <= 4; i++)                            //暴力枚举3个运算符
      for (int j = 1; j <= 4; j++)
        for (int k = 1; k <= 4; k++)
          if (F(F(F(a[1],i,a[2]),j,a[3]),k,a[4])==24)       //((a?b)?c)?d
            Out(a[1],a[2],F(a[1],i,a[2]),a[3],F(F(a[1],i,a[2]),j,a[3]),a[4],i,j,k);
          else if (F(F(a[1],i,a[2]),k,F(a[3],j,a[4])) == 24)//(a?b)?(c?d)
            Out(a[1],a[2],a[3],a[4],F(a[1],i,a[2]),F(a[3],j,a[4]),i,j,k);
  }  while (next_permutation(a + 1, a + 5));
  puts("No answer!");
  return 0;
}
