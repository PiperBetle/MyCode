#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
#define double long double
using namespace std;
struct bigint
{
	vector<int> num;
	void ament(string s)
	{
		reverse(s.begin(),s.end());
		num.resize(s.size());
		for(int i=0;i<num.size();i++)
			num[i]=s[i]-48;
	}
	int operator %(const int &n)
	{
		int c=0;
		for(int i=num.size()-1;i>=0;i--)
			c=(c+num[i])%n;
		return c;
	}
};
string s;
int b[11];
bigint a;
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,ans;

	cin>>s;
	n=s.length();
	for(i=0;i<n;i++)b[s[i]-'0']++;
	s.clear();
	b[1]--;b[6]--;b[8]--;b[9]--;
	for(i=1;i<=9;i++)for(j=1;j<=b[i];j++)s.append(1,i+'0');
	a.ament(s);
	cout<<s;
	m=a%7;
	m=7-m;
	if(m==7)m=0;
	switch(m)
	{
		case 0:cout<<9681;break;
		case 1:cout<<1968;break;
		case 2:cout<<8619;break;
		case 3:cout<<6891;break;
		case 4:cout<<8691;break;
		case 5:cout<<9168;break;
		case 6:cout<<1896;break;
	}
	for(j=1;j<=b[0];j++)cout<<0;
	
	return 0;
}