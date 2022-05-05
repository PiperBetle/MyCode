n;i++)for(int j=i-1;j;j--){
		std::cerr<<j<<' '<<i<<'\n';
		for(int k=p[j][i-1];k<=p[j+1][i];k++)if(f[j][i]<f[j][k]+f[k+1][i])
			f[j][i]=f[j][k]+f[k+1][r],p[j][i]=k;
		f[j][i]+=sum[i]-sum[j-1];
	}