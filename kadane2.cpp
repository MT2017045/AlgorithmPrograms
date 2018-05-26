// C++ program applying kadane's algorithm to find the maximum sum aubarray
#include <bits/stdc++.h>
using namespace std;
 

int main()
{
    int a[] = { 15, 8, -28,-24, 26};
    int n = sizeof(a)/sizeof(a[0]);
    int curr_max=a[0];
    int start=0;  //just to maintain the index to know where the max subarray lies, COULD BE IGNORED
    int end=0;
    int global_start=0,global_end=0;
    int global_max=a[0];
    for(int i=1;i<n;i++)
	{
	if((curr_max+a[i])>a[i]) //the maximum sum could be itself or itself + the previous maximum subarray
	{curr_max=curr_max+a[i];
	end=i;
	}
	else
	{ start=i; end=i;
	curr_max=a[i];
	}

	if(curr_max>global_max)
	{
	global_max=curr_max;
	global_start=start;
	global_end=end;
	}

	}
  
cout<<"the maximum sum array is "<<global_max<<" in index "<<global_start<<" to "<<global_end<<endl;
	return 0;
    }
