#include<iostream>
#include<list>
#include<stack>
using namespace std;

class graph
{public:
int v;
list<int> *array;
bool *visited;

	graph(int);
	void add(int src,int des);
	void dfs(int);
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

void graph::dfs(int v)
	{
	
	stack <int> s;
	
	s.push(v);
	visited[v]=true;
	list<int>::iterator i;
    
        while(!s.empty())
	{
        int now=s.top();
	cout<<now<<" ";
	s.pop();
	for(i=array[now].begin();i!=array[now].end();i++)
		{
		if(visited[*i]==false)
			{dfs(*i);
			//visited[*i]=true;
			}
		}
	}
	}
int main()
{
graph g(4);
g.add(0,1);
g.add(0, 2);
g.add(1, 2);
g.add(2, 0);
g.add(2, 3);
g.add(3, 3);
 
   cout << "Following is Depth First Traversal "
         << "(starting from vertex 2) \n";
    g.dfs(2);
return 0;
}
