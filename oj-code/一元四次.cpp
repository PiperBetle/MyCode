#include <math.h>
#include<iostream>
#include<iomanip>
using namespace std;


double x,error=1e-8;


int sign(double number) {
if (abs(number)<error) return 0;
if (number>0) return 1;
else return -1;
}
void QD(int n, double a1[], double b1[][120])
{


int i, t = 0;


for (i = n - 2; i>=0; i--)
{
if (i == n - 2)
{
for (t = 0; t <= n; t++)
b1[i][t] = a1[t];
}


else {
for (t = 0; t <=i + 2; t++)
b1[i][t] = b1[i + 1][t] * (i - t + 3);
}
}
}


void QE(double h, double j, double k,int n,double r[][120])
{
double x1, x2,t;

t = j*j - 4 * h*k;
if (t == 0)
{
x1 = -j / (2 * h);
r[0][0] = 1;
r[0][1] = x1;

}
else if (t > 0)
{
x1 = (-j - sqrt(t)) / (2 * h);
x2 = (-j + sqrt(t)) /( 2 * h);
r[0][0] = 2;
r[0][1] = x1;
r[0][2] = x2;

}
else if (t <0)
{
r[0][0] = 0;
}
}


double ABX(double a, double b, double c[], int n)
{
double y1, y2, y3;
int i;
for (i = 0, y1 = y2 = 0; i<n + 1; i++)
{
y1 = y1 + c[i] * pow(a, i);
y2 = y2 + c[i] * pow(b, i);
}


switch (sign(y1)*sign(y2))
{
case 0: return (abs(y1) < error) ? y1 : y2;
case 1: return 0;
case -1:
{       while (abs(y1)>error) {



double x = (a + b) / 2;


for (i = 0, y3 = 0; i < n + 1; i++)
{
y3 = y3 + c[i] * pow(x, i);
}
if (sign(y3) == 0) return x;
if (sign(y3)*sign(y1) == -1) {
b = x;
y2 = y3;
}
else {
a= x;
y1 = y3;
}
}
}
}


}
double QJ1(double min,double c[],int n)
{
double y1, y2,y=0, t = 0;
int i,j=1;


for (i = 0, y1=0; i<n + 1; i++)
{
y1 = y1 + c[i] * pow(min, i);
}
t = min - j;
for (i = 0,  y2 = 0; i<n + 1; i++)
{
y2 = y2 + c[i] * pow(t, i);
}
if (abs(y2) < error)
{
return t;
}
if (y1<0 && y1 < y2)
{
while(y2<0)
{
j = 2 * j;
t = min - j;
for (i = 0, y1 = y2 = 0; i<n + 1; i++)
{
y2 = y2 + c[i] * pow(t, i);
}
}
ABX(t,min,c,n);
return   ABX(t, min, c, n);
}
else if (y1>0 && y1 > y2)
{
while (y2>0)
{
j = 2 * j;
t = min - j;
for (i = 0, y1 = y2 = 0; i<n + 1; i++)
{
y2 = y2 + c[i] * pow(t, i);
}
}
ABX(t, min, c, n);
return ABX(t, min, c, n);
}
else return 0;

}
double QJ2(double max, double c[], int n)
{
double y1, y2, y=0, t = 0;
int i, j = 1;


for (i = 0, y1 =  0; i<n + 1; i++)
{
y1 = y1 + c[i] * pow(max, i);
}
t = max +j;
for (i = 0, y2 = 0; i<n + 1; i++)
{
y2 = y2 + c[i] * pow(t, i);
}
if (abs(y2) < 0.00000001)
{
return t;
}
if (y1<0 && y1 < y2)
{
while (y2<0)
{
j = 2 * j;
t = max + j;
for (i = 0, y1 = y2 = 0; i<n + 1; i++)
{
y2 = y2 + c[i] * pow(t, i);
}


}
ABX(t,max, c, n);
return ABX(t, max, c, n);
}
else if (y1>0 && y1 > y2)
{
while (y2>0)
{
j = 2 * j;
t = max + j;
for (i = 0, y1 = y2 = 0; i<n + 1; i++)
{
y2 = y2 + c[i] * pow(t, i);
}
}
ABX(t, max, c, n);
return  ABX(t, max, c, n);
}
else return 0;

}
void CJ(double r[][120], int n, double h, double j, double k, double a1[120], double b1[][120])
{
double c[120];
double q;
int i, t = 1, z, p=0,j1=0;
QE(h, j, k, n, r);
if (r[0][0] != 0)
{
for (i = 1; i <= n - 2; i++)
{
j1 = r[i - 1][0] - 1;
p = r[i - 1][0];
if (p != 0)
{
p = 0;
for (z = 0; z <= i + 2; z++)
{
c[z] = *(*(b1 + (i)) + i + 2 - z);
}
q = QJ1(r[i - 1][1], c, i + 2);
if (q != 0)
{
p++;
r[i][p] = q;


}
else { p = p + 0; }
for (t = 1; t <= j1; t++)
{
ABX(*(*(r + i - 1) + t), *(*(r + i - 1) + t + 1), c, i + 2);
q = ABX(*(*(r + i - 1) + t), *(*(r + i - 1) + t + 1), c, i + 2);
if (q != 0)
{
p++;
r[i][p] = q;


}
else { p = p + 0; }
}
QJ2(*(*(r + (i - 1)) + t), c, i + 2);
q = QJ2(*(*(r + i - 1) + t), c, i + 2);
if (q != 0)
{
p++;
r[i][p] = q;
}
else { p = p + 0; }
r[i][0] = p;
}
else { cout << "此方程无解" << endl; }

}
}
else {
r[n-2][0] = 0;
cout << "此方程无解" << endl;
}
}


int main()
{
int n, i;
double c[120], a1[120], b1[120][120],r[120][120];
double h=0,j=0,k=0;




cout << "请输入方程最高次数：";
cin >> n;
for (i = 0; i <= n; i++)
{
cout << "请输入方程系数：";
cin >>a1[i];
}


QD(n, a1, b1);
h = *(*(b1 + 0) + 0);
j = *(*(b1 + 0) + 1);
k = *(*(b1 + 0) + 2);
CJ(r, n,h,j,k,a1,b1);
cout << "此方程共有" << *(*(r + n - 2) + 0) << "个解" << endl;
for (i = 1; i <= *(*(r + n - 2) + 0); i++)
{
cout << "x" << i << "=" << setiosflags(ios::fixed) << setprecision(14) << *(*(r + n - 2) + i) << endl;
}
system("pause");
return 0;
}
