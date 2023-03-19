s=input()
try:
	ans=""
	for j in range(len(s)):
		if s[j]=='@':
			break
	for i in range(j):
		ans+=s[i]
	print(int(eval(ans)))
except:
	print('NO')