#include<iostream>
#include<list>
using namespace std;

class graph
{public:
int v;
list<int> *array;

	graph(int);
	void add(int src,int des);
	void bfs(int);
};

graph::graph(int a)
	{
	v=a;
	array=new list<int>[v];
	}

void graph::add(int src,int des)
	{
	array[src].push_back(des);
	}

void graph::bfs(int v)
	{
	bool visited[v+1]={false};
	list <int> queue;
	
	queue.push_back(v);
	visited[v]=true;
	list<int>::iterator i;
    
        while(!queue.empty())
	{
        int now=queue.front();
	cout<<now<<" ";
	queue.pop_front();
	for(i=array[now].begin();i!=array[now].end();i++)
		{
		if(visited[*i]==false)
			{queue.push_back(*i);
			visited[*i]=true;
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
 
   cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.bfs(2);
return 0;
}
