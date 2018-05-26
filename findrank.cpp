#include<iostream>
#include<cstdlib>
using namespace std;

int randompivot(int *arr,int i,int j)
	{
	srand ( time(NULL) );
	int p=rand()%(j-i+1);
	return (i+p);
	}

int partition(int *arr,int i,int j,int p)
{
	int l=i;
        int r=j;
	
 	while(l<r)
	{
	while(arr[l]<=arr[p]&&l<p)
	l++;
	while(arr[r]>=arr[p]&&r>p)
	r--;
	if(l<r)
		{
		if(l==p) { p=r;}
		else if(r==p) { p=l;}
		int temp=arr[l];
		arr[l]=arr[r];
		arr[r]=temp;
		}
	}
	cout<<"\npartition is with respect to random element: "<<arr[p]<<"\n";
	for(int k=i;k<=j;k++)
	cout<<arr[k]<<" ";
	cout<<"\n";
	return p;
}




int findrank(int *arr, int i, int j, int r)
{  int ans;
    // If k is smaller than number of elements in array
    if (r > 0 && r <= j - i + 1)
    {
        
      int p=randompivot(arr,i,j);
	int pos=partition(arr,i,j,p);
       
     cout<<p<<"  "<<pos<<" ";
        // If position is same as k
        if (j-pos == r-1)
            { return arr[pos];}
       else if (j-pos > r-1)  // If position is more, recur for right subarray
            { return findrank(arr, pos+1, j, r);}
       else{ 
        // Else recur for left subarray
        return findrank(arr, i, pos-1, r-(j-pos+1));}
    }

    // If k is more than number of elements in array
    return 345;
}


	



int main()
{
int r, arr[]={1,67,8,4,56,90,4,87,43};
cout<<"original array"<<endl;
int k=(sizeof(arr)/sizeof(*arr));
for(int i=0;i<k;i++)
cout<<arr[i]<<" ";
cout<<"enter rank to find element : ";
cin>>r;
cout<<"\n element is   "<<findrank(arr,0,k-1,r)<<"\n";
return 0;
}

