#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>
using std::cin;using std::cout;
constexpr double eps=1e-8;
struct vector{
	double x=0,y=0;
	double operator~(){return sqrt(x*x+y*y);}
	template<typename any>friend any &operator>>(any &a,vector &b){return a>>b.x>>b.y;}
	template<typename any>friend any &operator<<(any &a,const vector &b){return a<<b.x<<' '<<b.y;}
	friend vector operator+(const vector &a,const vector &b){return {a.x+b.x,a.y+b.y};}
	vector &operator+=(const vector &t){x+=t.x,y+=t.y;return *this;}
	friend vector operator-(const vector &a,const vector &b){return {a.x-b.x,a.y-b.y};}
	vector &operator-=(const vector &t){x-=t.x,y-=t.y;return *this;}
	friend vector operator*(const vector &a,const double &b){return {a.x*b,a.y*b};}
	vector &operator*=(const double &t){x*=t,y*=t;return *this;}
	friend vector operator/(const vector &a,const double &b){return {a.x/b,a.y/b};}
	vector &operator/=(const double &t){x/=t,y/=t;return *this;}
	friend double operator*(const vector &a,const vector &b){return a.x*b.x+a.y*b.y;}
	friend double operator/(const vector &a,const vector &b){return a.x*b.y-a.y*b.x;}
	bool frontis(const vector &t){auto r=*this*t;return +eps<r;}
	bool backis(const vector &t){auto r=*this*t;return -eps>r;}
	bool leftis(const vector &t){auto r=*this/t;return +eps<r;}
	bool rightis(const vector &t){auto r=*this/t;return -eps>r;}
};
inline double get_op(const double &x){if(x>eps)return 1;if(x<-eps)return -1;return 0;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	std::cout<<std::setiosflags(std::ios::fixed)<<std::setprecision(10);
	vector p0,p1,p2;int T;
	cin>>p0>>p1>>T;
	while(T--){
		cin>>p2;vector a=p1-p0,b=p2-p0;
		if(a.leftis(b)){cout<<"COUNTER_CLOCKWISE\n";continue;}
		if(a.rightis(b)){cout<<"CLOCKWISE\n";continue;}
		if(a.backis(b)){cout<<"ONLINE_BACK\n";continue;}
		cout<<(fabs(a.x)<fabs(b.x)||fabs(a.y)<fabs(b.y)?"ONLINE_FRONT\n":"ON_SEGMENT\n");
	}
	return 0;
}