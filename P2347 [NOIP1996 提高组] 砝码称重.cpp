#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<map>
#include<list>
using namespace std;
int a[100007],b[10]={0,1,2,3,5,10,20},ans=0,len=0;
bool sum[100007];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	
	for(i=1;i<=6;i++)
    {
        cin>>k;
        while(k--)a[++len]=b[i];
    }
    sum[0]=1;
    for(i=1;i<=len;i++)
        for(j=1111;j>=0;j--)if(sum[j])sum[j+a[i]]=1;
    for(i=1;i<=1111;i++)if(sum[i])ans++;
    printf("Total=%d",ans);
	
	return 0;
}
