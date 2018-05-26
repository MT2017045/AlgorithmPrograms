/*
Given an array of integers of size N. Assume ‘0’ as invalid number and all other as valid number. Write a program that modifies the array in such a way that if just next valid number is same as current number, double its value and replace the next number with 0. After the modification, rearrange the array such that all 0’s are shifted to the end and the sequence of the valid number or new doubled number is maintained as in the original array.
*/
#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    int i=0,current=0,next=0;
	    while(i<n)
	    {
	        while(a[i]==0&&i<n)
	        i++;
	        current=i++;
	        while(a[i]==0&&i<n)
	        i++;
	        next=i;
	       // cout<<current<<" "<<next<<endl;
	        if(a[current]==a[next])
	        {
	            a[current]=a[current]*2;
	            a[next]=0;
	           // cout<<"changes "<<a[current]<<" "<<a[next];
	        }
	       // cout<<"changes "<<a[current]<<" "<<a[next];
	        i=current+1;
	    }
	    int j=0;
	    for(i=0;i<n;i++)
	    {
	        if(a[i]!=0)
	       {cout<<a[i]<<" "; j++;}
	    }
	    for(;j<n;j++)
	    cout<<"0 ";
	}
	return 0;
}
