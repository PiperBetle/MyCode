#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>
using std::cin;using std::cout;
constexpr double eps=1e-8;
double get_op(const double &x){if(fabs(x)<eps)return 0;return fabs(x)/x;}
struct vector{
	double x,y;
	vector(const double &a=0,const double &b=0):x(a),y(b){}
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
	bool isleft(const vector &t){auto r=*this*t;return +eps<r;}
	bool isright(const vector &t){auto r=*this*t;return -eps>r;}
	bool isfront(const vector &t){auto r=*this*t;return +eps<r;}
	bool isback(const vector &t){auto r=*this*t;return -eps<r;}
};
struct segment{
	vector p1,p2;
	segment(const vector &a={0,0},const vector &b={0,0}):p1(a),p2(b){};
	template<typename any>friend any &operator>>(any &a,segment &b){return a>>b.p1>>b.p2;}
	template<typename any>friend any &operator<<(any &a,const segment &b){return a<<b.p1<<' '<<b.p2;}
	friend bool operator&(const segment &a,const segment &b){return fabs((a.p2-a.p1)*(b.p2-b.p1))<eps;}
	friend bool operator|(const segment &a,const segment &b){return fabs((a.p2-a.p1)/(b.p2-b.p1))<eps;}
	friend bool banana(const segment &a,const segment &b){
		if(std::min(a.p1.x,a.p2.x)>std::max(b.p1.x,b.p2.x)||std::min(b.p1.x,b.p2.x)>std::max(a.p1.x,a.p2.x)||std::min(a.p1.y,a.p2.y)>std::max(b.p1.y,b.p2.y)||std::min(b.p1.y,b.p2.y)>std::max(a.p1.y,a.p2.y))return false;
		return get_op(((a.p2-a.p1)/(b.p1-a.p1))*((a.p2-a.p1)/(b.p2-a.p1)))<=0&&get_op(((b.p2-b.p1)/(a.p1-b.p1))*((b.p2-b.p1)/(a.p2-b.p1)))<=0;
	}
};
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cout<<std::setiosflags(std::ios::fixed)<<std::setprecision(10);
	int T;cin>>T;while(T--){
		segment l1,l2;cin>>l1>>l2;
		cout<<banana(l1,l2)<<'\n';
	}
	return 0;
}