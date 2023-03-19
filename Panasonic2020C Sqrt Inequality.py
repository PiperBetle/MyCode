a,b,c=map(float,input().split());
a**=0.5;b**=0.5;c**=0.5;
if(a+b<c-0.000000000001):print("Yes");
else:print("No");