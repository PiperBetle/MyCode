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
int a[101][101]={0};
bool prime(int nn);
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k,t,m,n;
	
	cin>>n>>m;
	switch(m)
	{
		case 12:n+=30;
		case 11:n+=31;
		case 10:n+=30;
		case 9:n+=31;
		case 8:n+=31;
		case 7:n+=30;
		case 6:n+=31;
		case 5:n+=30;
		case 4:n+=31;
		case 3:n+=28;
		case 2:n+=31;
		case 1:n+=0;
	}
//	cout<<n<<endl;
	switch(n%7)
	{
		case 1:cout<<"Thursday";break;
		case 2:cout<<"Friday";break;
		case 3:cout<<"Saturday";break;
		case 4:cout<<"Sunday";break;
		case 5:cout<<"Monday";break;
		case 6:cout<<"Tuesday";break;
		case 0:cout<<"Wednesday";break;
	}
	
	return 0;
}
