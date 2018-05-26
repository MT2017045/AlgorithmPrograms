#include <bits/stdc++.h>

using namespace std;
int max(int a,int b)
{
    return (a>b)?a:b;
}
int commonChild(string s1, string s2){
    // Complete this function
    int n=s1.length();
    int p[2][n];
    
     for(int i=0;i<2;i++)
    {
        for(int j=0;j<n;j++) //initialization
            p[i][j]=0;
     
    }
    int i,j=0;
    while(j<n)
    {
    if(j%2==0)
    { 
        if(j==0) //pehla row
        {   i=0;
         if(s1[i]==s2[i])
             p[j][i]=1;
            for(i=1;i<n;i++) //next columns
            {
                if(s1[i]==s2[i])
                    p[j][i]=1;
                else
                    p[j][i]=p[j][i-1];
            } j++;}
        else
        {
            if(s1[0]==s2[j]) p[0][0]=1;
            else p[0][0]=p[1][0]; //alternate rows
             for(i=1;i<n;i++)
            {
            if(s1[i]==s2[j])
                p[0][i]=p[1][i-1]+1;
            else
                p[0][i]=max(p[0][i-1],p[1][i]);
             }
            j++;
        }
    }
    else
    {
        if(s1[0]==s2[j]) p[1][0]=1;
        else p[1][0]=p[0][0];
        for(i=1;i<n;i++)
            {
            if(s1[i]==s2[j])
                p[1][i]=p[0][i-1]+1;
            else
                p[1][i]=max(p[1][i-1],p[0][i]);
        }
        j++;
    }
            
    }
   
    if(n%2!=0)
        return p[0][n-1];
    else
        return p[1][n-1];
    
}

int main() {
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    int result = commonChild(s1, s2);
    cout << result << endl;
    return 0;
}

