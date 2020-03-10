#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b)
{
	return (*(int *)a- *(int *)b);
}

int main()
{
	int num[3];
	while(scanf("%d%d%d",&num[0],&num[1],&num[2]))
	{
		if(num[0]==0)
			break;
		qsort(num,3,sizeof(int),cmp);
		if(num[0]== num[2])
		{
			if(num[0]!=13)
			{
				int ans = num[0]+1;
				printf("%d %d %d\n",ans,ans,ans);
			}
			else
			{
				printf("*\n");
			}
		}
		else if(num[0]==num[1])
		{
			if(num[2] < 13)
			{
				if(num[2]+1 == num[1])
					num[2]++;
				num[2]++;
				qsort(num,3,sizeof(int),cmp);
				printf("%d %d %d\n",num[0],num[1],num[2]);
			}
			else
			{
				if(num[0]==13)
				{
					printf("1 1 1\n");
				}
				else
				{
					num[0] = num[1] = num[0]+1;
					num[2] = 1;
					qsort(num,3,sizeof(int),cmp);
					printf("%d %d %d\n",num[0],num[1],num[2]);
				}
			}
		}
		else if(num[1]==num[2])
		{
			if(num[0] < 13)
			{
				if(num[0]+1 ==num[1])
					num[0]++;
				num[0]++;
				if(num[0]==14)
				{
					printf("1 1 1\n");
				}
				else
				{
					qsort(num,3,sizeof(int),cmp);
					printf("%d %d %d\n",num[0],num[1],num[2]);
				}
			}
			else
			{
				if(num[2] == 13)
				{
					printf("1 1 1\n");
				}
				else
				{	
					printf("%d %d %d\n",1,num[1]+1,num[2]+1);
				}
			}
		}
		else
		{
			
			printf("1 1 2\n");
		}
		
	}	
	return 0;
}
