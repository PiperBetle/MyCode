#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
struct st
{
	string name;
	int year;
	int month;
	int day;
	int number;
};
int main()
{
	st a[101];
	int n,i,j,k;

	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].name>>a[i].year>>a[i].month>>a[i].day;
		a[i].number=i;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(a[j].year>a[j+1].year)
			{
				swap(a[j].day,a[j+1].day);
				swap(a[j].month,a[j+1].month);
				swap(a[j].name,a[j+1].name);
				swap(a[j].year,a[j+1].year);
				swap(a[j].number,a[j+1].number);
			}
			else
			{
				if(a[j].year==a[j+1].year)
				{
					if(a[j].month>a[j+1].month)
					{
						swap(a[j].day,a[j+1].day);
						swap(a[j].month,a[j+1].month);
						swap(a[j].name,a[j+1].name);
						swap(a[j].year,a[j+1].year);
						swap(a[j].number,a[j+1].number);
					}
					else
					{
						if(a[j].month==a[j+1].month)
						{
							if(a[j].day>a[j+1].day)
							{
								swap(a[j].day,a[j+1].day);
								swap(a[j].month,a[j+1].month);
								swap(a[j].name,a[j+1].name);
								swap(a[j].year,a[j+1].year);
								swap(a[j].number,a[j+1].number);
							}
							else
							{
								if(a[j].day==a[j+1].day)
								{
									if(a[j].number<a[j+1].number)
									{
										swap(a[j].day,a[j+1].day);
										swap(a[j].month,a[j+1].month);
										swap(a[j].name,a[j+1].name);
										swap(a[j].year,a[j+1].year);
										swap(a[j].number,a[j+1].number);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		cout<<a[i].name<<endl;
	}

	return 0;
}
