#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<vector>
using std::cin;using std::cout;
constexpr double eps=1e-8;
double get_op(const double &x){if(fabs(x)<eps)return 0;return fabs(x)/x;}
struct vector{
	double x,y;
	bool operator<(const vector &t)const{return x==t.x?y<t.y:x<t.x;}
	bool operator==(const vector &t)const{return x==t.x&&y==t.y;}
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
	bool frontis(const vector &t){auto r=*this*t;return +eps<r;}
	bool backis(const vector &t){auto r=*this*t;return -eps>r;}
	bool leftis(const vector &t){auto r=*this/t;return +eps<r;}
	bool rightis(const vector &t){auto r=*this/t;return -eps>r;}
	friend double dis(const vector &a,const vector &b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
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
	friend vector focus(const segment &a,const segment &b){
		auto w=b.p2-b.p1,z=a.p2-a.p1;
		auto h1=fabs((a.p1-b.p1)/w),h2=fabs((a.p2-b.p1)/w),x=~z*h1/(h1+h2);
		return a.p1+z*x/~z;
	}
};
struct points:public std::vector<vector>{
#define p (*this)
	double area(){
		double ans=0;
		for(size_t i=1;i<p.size()-1;i++)ans+=(p[i]-p[0])/(p[i+1]-p[0]);
		return ans/2;
	}
	points tobag(){
		std::sort(p.begin(),p.end());
		points b;
		b.emplace_back(p[0]),b.emplace_back(p[1]);
		for(size_t i=2;i<p.size();i++){
			auto u=b.back()-b[b.size()-2],v=p[i]-b.back();
			while(u.leftis(v)){
				if(b.size()==1)break;
				b.pop_back();
				u=b.back()-b[b.size()-2],v=p[i]-b.back();
			}
			b.emplace_back(p[i]);
		}
		auto tp=b.size();
		b.emplace_back(p.back()),b.emplace_back(p[p.size()-2]);
		for(size_t i=p.size()-3;~i;i--){
			auto u=b.back()-b[b.size()-2],v=p[i]-b.back();
			while(u.leftis(v)){
				if(b.size()==tp+1)break;
				b.pop_back();
				u=b.back()-b[b.size()-2],v=p[i]-b.back();
			}
			b.emplace_back(p[i]);
		}
		std::sort(b.begin(),b.end());
		b.erase(std::unique(b.begin(),b.end()),b.end());
		return b;
	}
#undef p
};
int n;
points a;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cout<<std::setiosflags(std::ios::fixed)<<std::setprecision(1);
	cin>>n;a.resize(n);
	for(int i=0;i<n;i++)cin>>a[i];
	cout<<a.area()<<'\n';
	return 0;
}