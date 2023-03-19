#include<iostream>
#include<string>
#include<cstring>
#include<stack>
using namespace std;

stack<char> s;

int main()
{
	int i,j,len,top,b;
	int no,name,math,n,k,a[101];
	char s1[50],s2[50];
	

	while(~scanf("%d%s%s",&n,s1,s2))
	{
		while(!s.empty())s.pop();
		j=0;
		for(i=0;i<n;i++)
		{
			s.push(s1[i]);
			a[k++]=0;
			while(!s.empty()&&s.top()==s2[j])
			{
				s.pop();
				j++;
				a[k++]=1;
			}
		}
		if(j==n)
		{
			cout<<"Yes."<<endl;
			for(i=0;i<k;i++)
			if(a[i]==0)cout<<"in"<<endl;
			else cout<<"out"<<endl;
		}
		else cout<<"No."<<endl;
		cout<<"FINISH"<<endl;
	}
	
	return 0;
} 
