#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
    double y[20][20],x[20],sum,fy,xr;
  
    int i,j,k,n,t,m;
    
    printf("\n     NEWTON'S DIVIDED DIFFERENCES INTERPOLATION METHOD");
    printf("\n\nEnter the number of entries (max 20) = ");
  
    scanf("%d",&n);
    for(i = 0; i < n; i++)
        {
          
            printf("x%d = ",i);
            scanf("%lf",&x[i]);
            printf("           y%d = ",i);
            scanf("%lf",&y[i][0]);
        }
    printf("\nEnter the value of xr at which y = f(x) is to be"
           " calculated xr = ");
    scanf("%lf",&xr);
    k = n;
    for(j = 1; j < n; j++)
        {
           
            k = k - 1;
            for(i = 0; i < k; i++)
                {
                    y[i][j] = (y[i+1][j-1] - y[i][j-1])/(x[i+j]-x[i]);
                }
        }
    sum = 0;
    for(t = 1; t < n; t++)
        {
          
            fy = 1;
            for(m = 0; m < t; m++)
                {
                    fy = fy * (xr - x[m]);
                }
            sum = sum + (fy * y[0][t]);
        }
    sum = sum + y[0][0];
    printf("\nThe interpolated value of y at xr = %lf"
           " is yr = %lf\n",xr,sum);
           return 0;
}
