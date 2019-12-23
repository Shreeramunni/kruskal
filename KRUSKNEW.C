#include<stdio.h>
#include<conio.h>
int p[10];
int find(int v)
{if(p[v]==v)
 return v;
 return find(p[v]);
}

void main()
{
 int a[10][10],i,j,ne=1,x,y,u,v,cost,n,min=999,mincost=0;
 clrscr();
  printf("enter the no. of nodes");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  p[i]=i;
  for(i=0;i<n;i++)
  {a[i][i]=999;
   for(j=0;j<n;j++)
   {if(i>=j)
     continue;
    printf("connection cost %d->%d is (cost/0)",i,j);
    scanf("%d",&cost);
    if(cost==0)
     {a[i][j]=999;
      a[j][i]=999;
      }
    else
     {a[i][j]=cost;
      a[j][i]=cost;
      }
    }
  }
   for(i=0;i<n;i++)
  {for(j=0;j<n;j++)
   {if(a[i][j]==999)
   printf("0 ");
   else
   printf("%d ",a[i][j]);
   }
   printf("\n");
     }
    printf("the min. cost spanning tree will be\n");
  while(ne<n)
  {for(i=0,min=999;i<n;i++)
  {
   for(j=0;j<n;j++)
   {if(a[i][j]<min)
     {min=a[i][j];
     x=u=i;
     y=v=j;
      }
     }
  }

   x=find(x);
   y=find(y);


   if(x!=y)
  { printf("cost of edge(%d,%d):%d\n",u,v,min);
   ne++;
   p[x]=y;
   mincost+=min;
   }
   a[u][v]=a[v][u]=999;
   }

  printf("the total min. cost will be:%d",mincost);
getch();
}