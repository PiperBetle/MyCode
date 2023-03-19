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
	int i,j;
	unsigned long long n,k;
	
	cin>>n>>k;
	k^=k>>1;
    while((--n)+1)cout<<(k>>n&1);
	
	return 0;
}

