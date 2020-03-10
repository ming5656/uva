#include<stdio.h>

int main()
{
	long int c,n,w,px,py,area[40][40];
	int sx,sy,ex,ey,bk[40][40];
	char d;
	scanf("%ld",&c);
	while(c--)
	{
		scanf("%ld",&n);
		scanf("%d %d",&sx,&sy);
		scanf("%d %d",&ex,&ey);
		scanf("%ld",&w);
		int i,j;
		for(i=0;i<40;i++)
		{
			for(j=0;j<40;j++)
			{
				bk[i][j] = 0;
				area[i][j] = 0;
			}
		}
		for(i=0;i<w;i++)
		{
			scanf("%ld %ld %c",&px,&py,&d);
			if(d=='S' && !(bk[px][py-1]&1))
				bk[px][py-1]+=1;

			if(d=='W' && !(bk[px-1][py]&2))
				bk[px-1][py]+=2;

			if(d=='N' && !(bk[px][py]&1))
				bk[px][py]+=1;

			if(d=='E' && !(bk[px][py]&2))
				bk[px][py]+=2;
			
		}
		
		area[sx][sy] = 1;
		for(i=sx;i<=ex;i++)
		{
			for(j=sy;j<=ey;j++)
			{
				if(!(bk[i][j]&1))
				{
					area[i][j+1] += area[i][j];
				}
				if(!(bk[i][j]&2))
				{
					area[i+1][j] += area[i][j];
				}
			}
		}
		printf("%ld\n",area[ex][ey]);
	}
	return 0;
}
