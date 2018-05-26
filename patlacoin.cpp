#include<iostream>
using namespace std;

void coin(int *deno,int i,int j)
{i++;
int v[i]={0};

for(int k=0;k<i;k++)
v[k]=k;


for(int k=1;k<i;k++)
for(int l=1;l<j;l++)
	{
	if(k>=deno[l]&&v[k]>(1+v[k-deno[l]]))
	v[k]=1+v[k-deno[l]];
	}
cout<<"number of coins used: "<<v[i-1]<<"\n";

}
int main()
{
int deno[]={1,7,10};
int size=sizeof(deno)/sizeof(*deno);

coin(deno,14,size);



}
