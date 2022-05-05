#include<cstring>
#include<string>
#include<cstdio>
#include<iostream>
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
string a;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int p1,p2,p3;
	
	cin>>p1>>p2>>p3;
	cin>>a;
	for(i=0;;i++)
		if(a[i]!='-')
			break;
		else cout<<'-';
	for(;i<a.length();i++)
		if(a[i]=='-')
		{
			char left=a[i-1],right=a[i+1];
			if(left+1==right)cout<<"";
			else if((right<=left)||(left<='9'&&right>='a'))cout<<'-';
			else
			{
				string s="";
				for(j=left+1;j<=right-1;j++)
					for(k=1;k<=p2;k++)
					{
						if(p1==3)s+='*';
						else if(p1==2&&left>='a'&&right<='z')s+=j-'a'+'A';
						else s+=j;
					}
				if(p3==1)cout<<s;
				else
					for(j=s.length()-1;j>=0;j--)
						cout<<s[j];
			}
		}
		else cout<<a[i];
	
	return 0;
}
