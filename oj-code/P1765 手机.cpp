#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
using namespace std;
int main()
{
	string a;
	int ans=0,la,num[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4},i;
	
    getline(cin,a);
    la=a.length();
    for(i=0;i<la;i++)
    {
        if(a[i]>='a'&&a[i]<='z') ans=ans+num[a[i]-'a'];
        if(a[i]==' ') ans++;    
    }
    cout<<ans;
    return 0;
}
