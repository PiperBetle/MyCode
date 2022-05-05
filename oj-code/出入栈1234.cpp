#include<iostream>
#include<string>
#include<cstring>
using namespace std;

struct student
{
	string name;
	int no;
	int math;
	student(string s,int n,int m)
	{
		name=s;
		no=n;
		math=m;
	}
	student(){}
};

int main()
{
	student s[21];
	int i,j,len,top,a,b;
	int no,name,math;
	
	while(cin>>a)
	{
		if(a==0)
		{
			cin>>name>>no>>math;
			if(top==20)cout<<"满"<<endl;
			else
			{
				s[top]=student(name,no,math);
				top++;
				cout<<"成功"<<endl;
			}
		}
		else
		{
			if(top==0)cout<<"空"<<endl;
			else
			{
				top--;
				cout<<s[top].math<<s[top].name<<s[top].no<<endl;
				
				cout<<"成功"<<endl;
			}
		}
	}
	
	return 0;
} 
