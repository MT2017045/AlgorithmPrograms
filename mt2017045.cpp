
#include <bits/stdc++.h>
using namespace std;
 

int main()
{
  
    int n,k;
	cin>>n>>k;
	int a[n];
	for(int l=0;l<n;l++)
	cin>>a[l];
	
	for(int m=0;m<k;m++)
{ int start,end;
	cin>>start>>end;

    int curr_max=1;
	int global_max=curr_max;
    for(int i=start+1;i<=end;i++)
	{
	if(a[i]==a[i-1])
	curr_max++;
	
	else
	{
	if(curr_max>global_max)
		{
		global_max=curr_max;
		
		}
	curr_max=1;
	}


	}
  
cout<<global_max<<endl;
}
	return 0;
    }
