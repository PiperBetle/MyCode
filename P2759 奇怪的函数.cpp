#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	long long i,j,k;
	long long n,m,ans=0;
	long long left=1,right=9e15;
	
	cin>>n;
	while(left<right)
	{
        long long mid=(left+right)>>1;
		m=(long long)(mid*log10(1.0*mid))+1;
        if(m<n)left=mid+1;
        else right=mid;
    }
    cout<<left;
	
	return 0;
}
