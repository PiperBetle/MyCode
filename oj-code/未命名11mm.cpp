#include<iostream>
using namespace std;
int main()
{
    int a[100];
    int m;
    int i,j,k;
    int t;
   
    cin>>m;
    for (i=1;i<=m;i++)              
       cin>>a[i];
    for (i=1;i<=m-1;i++)          
    {
	    for (j=i;j<=m;j++)       
	    {
	    	if (a[i]==a[j])      
		    for (k=i;k<m;k++) 
		    {
				a[k]=a[k+1];
			    m--;                    
			    i--;                    
		    }
	    }
    }                             
   for (i=1;i<=m;i++)       
   {
        for (j=i+1;j<=m;j++)
        {
            if (a[i]>a[j])
            {
	            t=a[i];
	            a[i]=a[j];
	            a[j]=t;
            }
        }
    }                          
   cout<<m<<endl;              
   for (i=1;i<=m;i++)        
   {
      cout<<a[i];
   }
   
   return 0;
}
