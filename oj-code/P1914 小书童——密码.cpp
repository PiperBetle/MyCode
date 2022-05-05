#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
	int n,i;
 	string a;
	
	cin>>n;
	getchar();
	cin>>a;
	for(i=0;i<a.size();i++)
	{
		a[i]=(a[i]-'a'+n)%26+'a';
		cout<<a[i];
	}

	return 0;
}
