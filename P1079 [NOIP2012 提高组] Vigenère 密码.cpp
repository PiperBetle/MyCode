#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
char To[27][27];
char a[1007],b[1007];
int la,lb;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	
	for(i=1;i<=26;i++)To[1][i]='a'-1+i;
	for(i=2;i<=26;i++)
	{
		for(j=1;j<=26;j++)
		{
			To[i][j]=To[i-1][j]+1;
			if(To[i][j]=='z'+1)To[i][j]='a';
		}
	}
	
//	for(i=1;i<=26;i++)
//	{
//		for(j=1;j<=26;j++)
//		{
//			cout<<To[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	
	scanf("%s%s",a,b);
	la=strlen(a);
	lb=strlen(b);
	for(i=0;i<la;i++)
	{
		if(a[i]<='Z')a[i]=a[i]-'A'+'a';
	}
//	puts(a);puts(b);
	for(i=0;i<lb;i++)
	{
//		cout<<endl<<a[i%la]<<"&"<<b[i]<<"  :";
		if(b[i]<='Z')
		{
//			cout<<char(To[a[i%la]-'a'+1][b[i]-'A'+1]-'a'+'A');
			for(j=1;j<=26;j++)
			{
				if(To[j][a[i%la]-'a'+1]==b[i]-'A'+'a')
				{
					cout<<char('A'+j-1);
					break;
				}
			}
		}
		else
		{
//			cout<<char(To[a[i%la]-'a'+1][b[i]-'a'+1]);
			for(j=1;j<=26;j++)
			{
				if(To[j][a[i%la]-'a'+1]==b[i])
				{
					cout<<char('a'+j-1);
					break;
				}
			}
		}
	}
	
	return 0;
}
