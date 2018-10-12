    #include<stdio.h>
     
    int main()
    {
     long long a,x;
     
     scanf("%lld", &a);
     
     if((a%6==0)||(a%6==1)||(a%6==3))
       {
        printf("YES");
       }
     else
        printf("NO");
     
      return 0;
    } 
