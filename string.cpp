/*
Given a string s, display the alternate words in the reverse order.

Input: 
The first line of input contains integer T denoting the number of test cases. For each test case, we input a string s.

Output: 
For each test case, the output is a string displaying the words at even position in reverse order.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	 string s;
    getline(cin,s);
	while(t--)
	{
	    string s;
	   
	    getline(cin,s);
	     string::iterator p=s.begin(),q=s.begin();
	    int i=1,j=0,flag=0;
	   
	    while(j<s.length())
	    {
	        if(isspace(s[j]))
	        {
		    while(isspace(s[++j]))
	            {   if(j==s.length()) break;
	                p++; q++;
	            }
	            i++;
	            if(i%2==0)
	            {
	                p++; q++;
	                flag=1;
	            }
	            else if(i!=1)
	            {
	                reverse(p,q);
	                p=q;
	                p++;
	                q++;
	                flag=0;
	            }
	        }
	        else
	        {   
	             q++; 
	             
	            if(flag==0)
	            {
	            p++;
	           
	            }
	            
	        }
	        j++;
	    }
            if(flag==1)
		reverse(p,q);

	    cout<<s<<endl;
	}
	return 0;
}
