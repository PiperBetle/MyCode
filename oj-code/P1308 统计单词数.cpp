#include<cstring>
#include<string>
#include<cstdio>
#include<iostream>
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
string a,b;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,sum=0,first=1e9;
	
	getline(cin,a);
	getline(cin,b);
	int la=a.length(),lb=b.length();
	for(i=0;i<la;i++)
		if(a[i]>='A'&&a[i]<='Z')
			a[i]=a[i]-'A'+'a';
	for(i=0;i<lb;i++)
		if(b[i]>='A'&&b[i]<='Z')
			b[i]=b[i]-'A'+'a';
//	cout<<la<<' '<<lb<<'\n';
//	cout<<a[0]<<a[1]<<' '<<b[0]<<b[1]<<'\n';
	
	lb+=11;
	for(i=0;i<lb;i++)
	{
		if((b[i]==' '&&b[i+1]!=' ')||(i==0))
		{
//			cout<<"check "<<i<<": "<<b[i]<<endl;
			bool flag=0;
			for(j=0;j<la;j++)
				if(a[j]!=b[i+j+(i==0?0:1)])
				{
					flag=1;
					break;
				}
			if(b[i+j+(i==0?0:1)]!=' ')continue;
			if(flag==0)
			{
				first=min(first,i+(i==0?0:1));
				sum++;
				i+=j;
			}
		}
	}
	if(first==1e9)cout<<-1;
	else cout<<sum<<" "<<first;
	
	return 0;
}
