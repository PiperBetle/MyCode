s=input()
try:
	ans=""
	# if s=="1+2*8-9@":
	# 	print(8)
	# else:
	for i in range(len(s)-1):
		ans+=s[i]
	print(int(str(eval(ans))))
except:
	print('NO')