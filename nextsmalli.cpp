// C++ program that gives the ndex of the just next smallest element after it in an array
//it uses stack 0(n)
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int a[] = {1, 5, 8, 9, 6, 7, 3, 4,2};
    int n = sizeof(a)/sizeof(a[0]);
        
    int b[n];
    stack <int> g;
     
    int i=0;
     g.push(i);

    for(int j=1;j<n;j++)
    {
    if(a[g.top()]<a[j]) //this is not what we wanted
	{
	g.push(j);
	i=g.size();
	}
	else
	{
	while(i>=0&&a[g.top()]>a[j]) //this is what it is!
 		{
		b[g.top()]=j;  //pop out till where it would be satisfied
		g.pop();
		i=g.size();
		j--; //if not written this element wont come under consideration
		}
	}

    }
while(!g.empty())
{
b[g.top()]=0;
g.pop();
}

   for(i=0;i<n;i++)
	cout<<a[i]<<" ";
   cout<<"\n";
   for(i=0;i<n;i++)
	cout<<b[i]<<" ";
  cout<<"\n";
    return 0;
}
