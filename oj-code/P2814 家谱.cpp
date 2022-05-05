#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<map>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
string s,fa;
map<string,string>f;
string find(string x){return f[x]==x?x:f[x]=find(f[x]);}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	char c;
	
	cin>>c;
	while(c!='$')
	{
		cin>>s;
		if(c=='#')
        {
            fa=s;
            if(f[s]=="")f[s]=s;
        }
        if(c=='+')
            f[s]=fa;
        if(c=='?')
            cout<<s<<' '<<find(s)<<endl; 
		cin>>c;
	}
	
	return 0;
}
