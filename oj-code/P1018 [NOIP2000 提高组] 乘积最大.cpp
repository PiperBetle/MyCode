#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define int long long
using namespace std;
struct very_long
{
	int _data[107],_len;
	very_long()
	{
		memset(_data,0,sizeof _data);
		_len=1;
	}
	very_long(int _n)
	{
		memset(_data,0,sizeof _data);
		_len=0;
		for(;;)
		{
			_len++;
			_data[_len]=_n%10;
			_n/=10;
			if(_n==0)break;
		}
	}
	very_long operator *(const int &_n)
	{
		very_long _a;
		int _i;
		for(_i=1;_i<=_len;_i++)
			_a._data[_i]=_data[_i]*_n;
		for(_i=1;;_i++)
		{
			_a._data[_i+1]+=_a._data[_i]/10;
			_a._data[_i]%=10;
			if(_a._data[_i+1]==0)break;
		}
		_a._len=_i;
		return _a;
	}
	bool operator <(const very_long _a)const
	{
		if(_len==_a._len)
		{
			int _i;
			for(int _i=_len;_data[_i]==_a._data[_i]&&_i>1;_i--);
			if(_i>=1)return _data[_i]<_a._data[_i];
			else return 0;
		}
		else
			return _len<_a._len;
	}
};
ostream& operator <<(ostream& _out,const very_long &_n)
{
	for(int _i=1;_i<=_n._len;_i++)
		_out<<_n._data[_n._len-_i+1];
	return _out;
}
string s;
const int TIMES=10;
very_long f[57][57];
int qw(int x,int y)
{
	int sum=0,t=1;
	int i;
	for(i=y;i>=x;i--)
	{
		sum=sum+(s[i]-'0')*t;
		t=t*TIMES;
	}
	return sum;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	
	cin>>n>>t>>s;
	for(i=0;i<n;i++)f[0][i]=qw(0,i);
	for(i=1;i<=t;i++)
        for(j=1;j<=n;j++)
            for(k=j;k>=i;k--)
            	if(f[i][j]<f[i-1][k-1]*qw(k,j))
            	    f[i][j]=f[i-1][k-1]*qw(k,j);
    cout<<f[t][n-1];
	
	return 0;
}
