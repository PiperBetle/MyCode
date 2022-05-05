#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n,k,num=1;
	int i,j;
	
	cin>>n>>k;
    if(k==0)
    {
        cout<<n;
        return 0;
    }
    for(i=1;i<k;i++)
    {
    	n/=10;
		num*=10;
	}
    if(n%10>=5)
    {
    	n/=10;
		n++;
		num*=10;
	}
    else
    {
    	n/=10;
		num*=10;
	}
    cout<<n*num;
	
	return 0;
}

