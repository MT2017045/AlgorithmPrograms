
#include <iostream>
using namespace std;
class minheap{
public:
 int *arr;
int capacity;
int len;
 
minheap(int l);
void insert(int);
int parent(int);    //index passed
void heapify(int);  //index passed,bottom up heapify
void delmin();
//void changekey(int,int);
void topdownheapify(int);
void viewheap();
int getmin();
//void del(int); //deleting arbritrary element,index passed
int leftchild(int);
int rightchild(int);
};

minheap::minheap(int l)
	{
	len=0;
	capacity=l;
	arr=new int[capacity];
	}
	
void minheap::insert(int element)
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

int minheap::parent(int l)
	{
	return (l-1)/2;
	}

void minheap::heapify(int l)
	{
	int p=parent(l);
	while(l>=0 && arr[p]>arr[l])
		{
		int temp=arr[l];
		arr[l]=arr[p];
		arr[p]=temp;
		l=p;
		p=(l-1)/2;
	}

	}

int minheap::getmin()
	{
	return arr[0];
	}



void minheap::delmin()
	{
	
	arr[0]=arr[len-1];
	len--;
        topdownheapify(0);
	}
int minheap::leftchild(int n)
{
return 2*n+1;
}


int minheap::rightchild(int n)
{
return 2*n+2;
}
void minheap::topdownheapify(int i)
	{
          int j,l=leftchild(i);
	  int r=rightchild(i);
          while(l<len)
	{
	if(arr[l]<arr[r])
	j=l;
	else
	j=r;
	if(arr[j]<arr[i])
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
	if(arr[l]<arr[i])
	{
                int temp=arr[l];
		arr[l]=arr[i];
		arr[i]=temp;
	}
	}

void minheap::viewheap()
	{
	for(int i=0;i<len;i++)
	cout<<arr[i]<<" ";
	cout<<"\n";
	}

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

void median(int u)
{
    static maxheap max(100);
    static minheap min(100);
    static int median=0;
    static int n1=0,n2=0;
     if(u<median){
     max.insert(u); n1++;
     }
     else if(u>median){
         min.insert(u); n2++;
     }
    if(n1+1<n2)
    {   int s=min.getmin();
        min.delmin();
        max.insert(s);
        n2--;
        n1++;
    }
    else if(n1>=n2+1)
    {   int s=max.getmax();
        max.delmax();
        min.insert(s);
        n2++;
        n1--;
    }
    if((n1+n2)%2==1)
    median=min.getmin();
    else
    median=(min.getmin()+max.getmax())/2;
    cout<<"ans is"<<median<<"\n";
    
}

int main()
{
int t,u;
cin>>t;
while(t)
{
    cin>>u;
    median(u);
    t--;
}
return 0;
}
