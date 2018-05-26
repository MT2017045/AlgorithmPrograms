// C++ program given an raay find whether a given number is present as the sum of two numbers in array
//ax+ay=x
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
    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x=6;
    sort(arr, arr+n);
 
    cout<<"ans is "<<check(arr,n,x)<<endl;
 
    return 0;
}
