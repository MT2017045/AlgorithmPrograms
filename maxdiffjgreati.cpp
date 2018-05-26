// C++ program given an array find max(aj-ai) where j>i
//*******CAUTION: NOT TO SORT******
// j is selling day and i is buying day , when to buy and when to sell to get the maximum profit
#include <bits/stdc++.h>
using namespace std;
 

int main()
{
    int a[] = { 15, 8, 19, 1, 4};
    int n = sizeof(a)/sizeof(a[0]);
    
   int i=0; // assuming smallest value to be in i
   int j=1;
	int maxj=j;
	int mini=i;
   int m=a[j]-a[i];
   j++;
   while(j<n)
   {
	if(a[i]>a[j-1]) 
	i=j-1; //this will maintain i to be the smallest among the traversed j

	if(a[j]-a[i]>m)
	{m=a[j]-a[i];  //finding the maximum difference
	maxj=j;
	mini=i;
	}
        j++;
   }
  cout<<"the max diff for j>i is with "<<a[maxj]<<" and "<<a[mini]<<" which is "<<m<<endl;
}
