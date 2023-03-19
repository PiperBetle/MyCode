#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>
using std::cin;using std::cout;
constexpr double eps=1e-8;
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
};
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cout<<std::setiosflags(std::ios::fixed)<<std::setprecision(10);
	int T;cin>>T;while(T--){
		segment l1,l2;cin>>l1>>l2;
		if(l1&l2){cout<<"1\n";continue;}
		if(l1|l2){cout<<"2\n";continue;}
		cout<<"0\n";
	}
	return 0;
}