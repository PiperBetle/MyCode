#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
void beford(string a,string b)
{
    if (a.size()>0){
        char ch=b[b.size()-1];
        cout<<ch;
        int k=a.find(ch);
        beford(a.substr(0,k),b.substr(0,k));
        beford(a.substr(k+1),b.substr(k,a.size()-k-1));
    }
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	string a,b;
	
	cin>>a>>b;
	beford(a,b);
	
	return 0;
}