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
int sum[300],ans;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	string s;
	
	cin>>s>>k;
	if(k>s.length())
	{
		cout<<"impossible";
		return 0;
	}
	for(i=0;i<s.length();i++)
	{
		sum[s[i]]++;
	}
	for(i='a';i<='z';i++)
	{
		if(sum[i]>0)ans++;
	}
	cout<<max(0,k-ans);
	
	return 0;
}

