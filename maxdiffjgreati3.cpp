
Erroneous!!

// C++ program given an array find max(aj-ai) where j>i within an INTERVAL of l days
//*******CAUTION: NOT TO SORT******
// j is selling day and i is buying day , when to buy and when to sell to get the maximum profit within l days of time
#include <bits/stdc++.h>
using namespace std;
 

int main()
{
   
/*
   deque <int> g;
   g.push_back(0);
	int j=1;
	int m=a[j]-a[i];
	int maxj=j;
	int mini=i;
    for(j=1;i<n;i++)
	{
	//maintaining stack before j
	if(g.empty())
	g.push_back(j);
	else if(a[g.back()]<a[j])
	g.push_back(j);
	else
	{
	while(a[g.back()]>a[j]&&(!g.empty()))
	{
	g.pop_back();
	}
	g.push_back(j);
	}	
	//stack maintainence ended
	//retrieving the minimum element from stack
	if(g.front()<(j-i+1))
	{ 
	while(g.front()<(j-i+1))
		{
		g.pop_front();
		}
	}
	i=g.front(); //this will maintain i to be the smallest among the traversed j
	
        if(a[j]-a[i]>m)
	{m=a[j]-a[i];  //finding the maximum difference
	maxj=j;
	mini=i;
	}
		
	}*/
 int a[] = {3,6,8,7,5,2,1,10};
    int n = sizeof(a)/sizeof(a[0]);

cout<<"\n";
for(int k=0;k<n;k++)
  cout<<k<<" ";
cout<<"\n";
for(int k=0;k<n;k++)
  cout<<a[k]<<" ";
cout<<"\n";
    int l=3,i=0;
   int g[n];
   int front=0;
   g[0]=i;
	int j=1;
	int m=a[j]-a[i];
	int maxj=j;
	int mini=i;
    for(j=1;j<n;j++)
	{
	//maintaining stack before j
	 if(a[i]<a[j])
	{g[++i]=j;
	}
	else
	{
	while(a[i]>a[j]&&i>=0)
	i--;
	
	g[++i]=j;
	}
		
	//stack maintainence ended
	//retrieving the minimum element from stack
	if(front<(j-l+1))
	{ 
	while(front<(j-l+1))
		{
		front++; 
		}
	}
	 //this will maintain i to be the smallest among the traversed j
	
        if(a[j]-a[front]>m)
	{m=a[j]-a[front];  //finding the maximum difference
	maxj=j;
	mini=front;
	}
	}	
cout<<"the max diff for j>i is with index "<<maxj<<" and "<<mini<<" which is "<<m<<endl;  

}
