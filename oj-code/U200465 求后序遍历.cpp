#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
using namespace std;
void after(string a,string b)
{
    if(a.size()>0)
	{
        char ch=a[0];
        int k=b.find(ch);
		after(a.substr(1,k),b.substr(0,k));
		after(a.substr(k+1),b.substr(k+1));
        cout<<ch;
    }
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	string a,b;
	
	cin>>a>>b;
	after(a,b);
	cout<<'\n';
	
	return 0;
}