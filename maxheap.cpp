#include <iostream>
using namespace std;
class maxheap{
public:
 int *arr;
int capacity;
int len;
 
maxheap(int l);
void insert(int);
int parent(int);    //index passed
void heapify(int);  //index passed,bottom up heapify
void delmax();
void topdownheapify(int);
void viewheap();
int getmax();
int leftchild(int);
int rightchild(int);
};

maxheap::maxheap(int l)
	{
	len=0;
	capacity=l;
	arr=new int[capacity];
	}
	
void maxheap::insert(int element)
	{
	if(len==capacity)
		{	cout<<"no space";
		}
	else
		{
			len++;
			arr[len-1]=element;
			heapify(len-1);
		}
	}

int maxheap::parent(int l)
	{
	return (l-1)/2;
	}

void maxheap::heapify(int l)
	{
	int p=parent(l);
	while(l>=0 && arr[p]<arr[l])
		{
		int temp=arr[l];
		arr[l]=arr[p];
		arr[p]=temp;
		l=p;
		p=(l-1)/2;
	}

	}

int maxheap::getmax()
	{
	return arr[0];
	}


void maxheap::delmax()
	{
	
	arr[0]=arr[len-1];
	len--;
        topdownheapify(0);
	}
int maxheap::leftchild(int n)
{
return 2*n+1;
}


int maxheap::rightchild(int n)
{
return 2*n+2;
}
void maxheap::topdownheapify(int i)
	{
          int j,l=leftchild(i);
	  int r=rightchild(i);
          while(l<len)
	{
	if(arr[l]>arr[r])
	j=l;
	else
	j=r;
	if(arr[j]>arr[i])
		{
		int temp=arr[j];
		arr[j]=arr[i];
		arr[i]=temp;
		i=j;
		l=leftchild(i);
		r=rightchild(i);
		}
	else
	break;
	}

	if(l==len-1)
	if(arr[l]>arr[i])
	{
                int temp=arr[l];
		arr[l]=arr[i];
		arr[i]=temp;
	}
	}

void maxheap::viewheap()
	{
	for(int i=0;i<len;i++)
	cout<<arr[i]<<" ";
	cout<<"\n";
	}

int main()
{
int arr[]={10,98,94,65,35,75,25,55};
maxheap h(100);
for(int i=0;i<8;i++)
h.insert(arr[i]);
h.viewheap();
h.delmax();
h.viewheap();
return 0;
}

