#include<iostream>
using namespace std;

void knapsack(int *weight,int *value,int size,int sac)
{
int v[size+1][sac+1]={0};

for(int k=1;k<=sac;k++)
{
if(k>=weight[0]) //weight index is one less than that of matrix
v[1][k]=value[0];
}

for(int i=2;i<=size;i++)
{
for(int j=1;j<=sac;j++)
	{
	v[i][j]=v[i-1][j];
	if(j>=weight[i-1])
	{
	if((value[i-1]+v[i-1][j-weight[i-1]])>(v[i-1][j]))
	v[i][j]=value[i-1]+v[i-1][j-weight[i-1]];
 	}
	}
}
cout<<v[size][sac]<<endl;
cout<<"items picked :"<<endl;

int i=size;
int j=sac;
while(i!=0){
if(v[i][j]==v[i-1][j])
i--;
else
{
cout<<"item "<<(i-1)<<" weight :"<<weight[i-1]<<" value :"<<value[i-1]<<endl;
i--;
j=j-weight[i-1];
}
}
}
int main()
{
int weight[]={2,1,3,2};
int value[]={12,10,21,15};

int size=sizeof(weight)/sizeof(*weight);

cout<<"the max value that could be taken is :";
knapsack(weight,value,size,7);



}
