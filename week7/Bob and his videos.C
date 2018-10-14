#include<iostream>
#define MAX 102
#define DIV 100003
typedef long long int lli;
 
using namespace std;
 
int main()
{
	lli a,b,c;
	cin>>a>>b>>c;
	lli arr[MAX][MAX]={0};
	arr[0][0]=1;
	for(int i=0;i<c;i++)
	{
		for(int j=0;j<=a;j++)
		{
			if(j>=b)
			{
				arr[i+1][j]+=arr[i][j]*(j-b);
				arr[i+1][j]%=DIV;
				arr[i+1][j+1]+=arr[i][j]*(a-j);
				arr[i+1][j+1]%=DIV;
			}
			else
			{
				arr[i+1][j+1]+=arr[i][j]*(a-j);
				arr[i+1][j+1]%=DIV;
			}
		}
	}
	cout<<arr[c][a]<<endl;
	return 0;
} 
