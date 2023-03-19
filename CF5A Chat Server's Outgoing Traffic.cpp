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
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int pe=0,ans=0;
	char s[1001];
	
	while(gets(s))
	{
		if(s[0]=='+')pe++;
		else if(s[0]=='-')pe--;
		else
		{
			for(i=0;;i++)
			{
				if(s[i]==':')break;
			}
			ans+=(strlen(s)-1-i)*pe;
		}
	}
	printf("%d",ans);
	
	return 0;
}
