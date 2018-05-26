// C++ program given an raay find whether a given number PRESENT in array is present as the sum of two numbers in array
//ax+ay=az
#include <bits/stdc++.h>
using namespace std;
 
bool check(int a[],int n,int x)
{
int l=0;
int r=n-1;

while(l<=r)
{
if((a[l]+a[r])>x)
r--;
else if((a[l]+a[r])<x)
l++;
else
return true;
}
return false;
}

int main()
{
    int arr[] = { 5, 8, 9, 3, 4, };
    int n = sizeof(arr)/sizeof(arr[0]);
    
    sort(arr, arr+n);

    for(int k=0;k<n;k++)
    {
	if(check(arr,n,arr[k]))
	cout<<"true for"<<arr[k]<<endl;
    }
    return 0;
}
