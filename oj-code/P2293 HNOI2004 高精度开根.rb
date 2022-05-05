a=Integer(gets);b=Integer(gets);
left=0;right=1;ans=-1;
while(right**a<=b)do left=right;right=right<<1;end
while(left<=right)do
	mid=(left+right)>>1;
	if(mid**a<=b)then left=mid+1;else ans=right=mid-1;end
end
print(ans);