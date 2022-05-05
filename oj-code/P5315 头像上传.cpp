#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
using namespace std;
int main()
{
	int i,j,k,l,n,g,x,y;
	
	cin>>n>>l>>g;
	while(n--)
	{
		cin>>x>>y;
		while((x>g)||(y>g))
		{
			x/=2;
			y/=2;
		}
		if((x<l)||(y<l))
			cout<<"Too Young"<<endl;
		else
		{
			if(x!=y)cout<<"Too Simple"<<endl;
			else cout<<"Sometimes Naive"<<endl;
		}
	}
	
	return 0;
}
