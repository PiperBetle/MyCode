T=int(input());
for i in range(T):
	n=int(input());l=1;r=0;
	while n>0:
		if n%2==0:l+=r;
		else:r+=l;
		n//=2;
	print(r);