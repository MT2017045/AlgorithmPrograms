#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {int n,q,sum;
            string str;
            cin>>str;
            sum=str[0]-96;
            cin>>n;
            vector<int> vec;
            for(int i=1;i<str.length();i++){
                if(str[i]!=str[i-1]){
                    //cout<<"sum pushed back at "<<i<<" is "<<sum<<endl;
                    vec.push_back(sum);
                    sum=str[i]-96;
                }
                else { // cout<<"sum pushed back at "<<i<<" is "<<sum<<endl;
                    vec.push_back(sum);
                    sum=sum+str[i]-96;
                     }
            }
            vec.push_back(sum);
           for(int i=0;i<n;i++){
               cin>>q;
               vector<int>::iterator it;
               it=find(vec.begin(),vec.end(),q);
               if(it!=vec.end()){
                   cout<<"Yes"<<endl;
               }
               else
                   cout<<"No"<<endl;
           }
         
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
