#include<iostream>
using namespace std;

void coin(int *deno,int i,int j)
{i++;
int v[i][j]={0};
if(deno[0]==1)
for(int k=0;k<i;k++)
v[k][0]=k;

for(int l=0;l<j;l++)
v[0][l]=0;

for(int k=1;k<i;k++)
for(int l=1;l<j;l++)
	{
	v[k][l]=v[k][l-1];
	if(k>=deno[l]&&v[k][l]>(1+v[k-deno[l]][l]))
	v[k][l]=1+(v[k-deno[l]][l]);
	}
cout<<"number of coins used: "<<v[i-1][j-1];
cout<<"\ndenominations of coin used :";
i--; j--; //bringing it to the last place

while(i!=0)
{

if(j==0 && deno[0]==1)
{
for(int m=0;m<i;m++)
cout<<deno[0]<<" ";
cout<<"\n";
break;
}

if(v[i][j]==v[i][j-1])
j=j-1;
else
	{
	cout<<deno[j]<<" ";
	i=i-deno[j];

	}
}

}
int main()
{
int deno[]={1,7,10};
int size=sizeof(deno)/sizeof(*deno);

coin(deno,24,size);



}
