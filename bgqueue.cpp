#include<iostream>
using namespace std;
int main()
{
int n,s;
cin>>n>>s;
string m;
cin>>m;
while(s--)
{
for(int i=0;i<n;i++)
{
if(m[i]=='B'&&m[i+1]=='G')
	{
	m[i]='G';
	m[i+1]='B';
	i++;
	}
}
}
cout<<m;
return 0;
}
