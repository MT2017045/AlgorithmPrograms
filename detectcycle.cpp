#include<iostream>
#include<list>
#include<stack>
using namespace std;

class graph
{public:
int v;
list<int> *array;
stack <int> s;
bool *visited;

	graph(int);
	void add(int src,int des);
	int isCycle(int);
};

graph::graph(int a)
	{
	v=a;
	array=new list<int>[v];
 	visited=new bool[v+1];
	for(int i=0;i<=v;i++)
	visited[i]=false;
	}

void graph::add(int src,int des)
	{
	array[src].push_back(des);
	}

int graph::isCycle(int v)
	{
	
	
	int ans=0;
	s.push(v);
	visited[v]=true;
	list<int>::iterator i;
    
        while(!s.empty())
	{
        int now=s.top();
	//cout<<now<<" ";
	s.pop();
	for(i=array[now].begin()+1;i!=array[now].end();i++)
		{
		if(visited[*i]==false)
			{ans=isCycle(*i);
			//visited[*i]=true;
			}
		else
		{ans=1; cout<<now<<" ";
		}
		}
	}
	return ans;
	}
int main()
{
graph g(4);
g.add(0,1);
g.add(0, 2);
g.add(1, 2);
g.add(2, 3);
//g.add(2, 3);
//g.add(3, 3);
 if(g.isCycle(0))
	cout<<"there is a cycle"<<endl;
else
	cout<<"no cycle"<<endl;
 return 0;
}
