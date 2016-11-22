void floyd()
{
	int i,j,k;
	tr(k,1,n) tr(i,1,n)
		if (a[i][k]) tr(j,1,n)
			if (i!=j&&a[k][j]&&(!a[i][j]||(a[i][j]&&a[i][k]+a[k][j]<a[i][j])))
                a[i][j]=a[i][k]+a[k][j];
}
