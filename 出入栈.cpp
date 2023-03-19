#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char str1[21],str2[21],s[21];
	int i,j,len,top;
	
	while(cin>>str1)
	{
		len=strlen(str1);
		for(i=0;i<len;i++)
		{
			s[top++]=str1[i];
		}
		while(top>0)
		{
			putchar(s[--top]);
		}
		cout<<endl; 
	}
	
	return 0;
} 
