/*
You are given 
N
N strings. You have to answer 
Q
Q queries, each containing a string 
S
S.

Write a program to print the answer to each query using the following rules:

If 
S
S contains no string from the 
N
N given strings as its substring, then print 0.
If 
S
S contains multiple strings from the 
N
N given strings as its substrings, then print -1.
If 
S
S contains exactly one string from the 
N
N given strings as its substring, then print the index of that string (1-indexed).
Input format

First line: Two space separated integers 
N
N and 
Q
Q
Next 
N
N lines: Single word (containing lowercase alphabets)
Next 
Q
Q lines: Single word (containing lowercase alphabets and denoting each query)
Output format

For each query, print the answer in a separate line.

Constraints

1
≤
N
≤
10000
1≤N≤10000
 1
≤
Q
≤
10000
1≤Q≤10000
 1
≤
1≤ 
l
e
n
g
t
h
length 
o
f
of 
e
a
c
h
each 
s
t
r
i
n
g
string 
≤
10
≤10
 1
≤
|
S
|
≤
10000
1≤|S|≤10000
 1
≤
1≤ 
S
u
m
Sum 
o
f
of 
a
l
l
all 
|
S
|
≤
100000
|S|≤100000
SAMPLE INPUT 
2 3
spider
mantis
spiderman
spidermantis
spidy
SAMPLE OUTPUT 
1
-1
0

// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<string> s;
    vector<string>::iterator i;
    int n,q,count;
    cin>>n>>q;
    while(n--)
    {
        string v;
        cin>>v;
        s.push_back(v);
    }
    while(q--)
    {
        string check;
         count=0;
        cin>>check;
        size_t found;
        int flag=0,ans;
        int index=0;
        for(i=s.begin();i!=s.end();i++)
        { index++;
            found = check.find(*i);
             if (found!=string::npos)
             {
                 if(flag==0) 
                 {
                     ans=index;
                     flag=1;
                 }
             count++;
             }
        }
        if(count==0) cout<<"0";
        else if(count==1) cout<<ans;
        else cout<<"-1";
        cout<<endl;
    }
    return 0;
}

