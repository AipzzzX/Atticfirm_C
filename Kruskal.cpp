#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct Edge
{
	int u, v, w;   					//u、v：两个顶点  w：权
	Edge() {}
	Edge(int u0, int v0, int w0) :u(u0), v(v0), w(w0) {}
};
int n;          					//n:顶点个数
vector<Edge> edges;   				//edges：图g的所有边
int sum;                  			//sum:最小生成树长度
vector<Edge>mst;   				//mst：最小生成树（用边集表示）

class DisjSets
{
	vector<int>s;
public:
	DisjSets(int n) :s(n, -1) {}
	int find(int x)
	{
		if (s[x] < 0) return x;
		else return s[x] = find(s[x]);   	//压缩路径
	}
	void unionSets(int root1, int root2)
	{
		if (s[root1] > s[root2])   			//按个数求并（个数用负数表示）
		{
			s[root2] += s[root1];
			s[root1] = root2;
		}
		else
		{
			s[root1] += s[root2];
			s[root2] = root1;
		}
	}
};

bool Cmp(const Edge &lhs, const Edge &rhs)
{
	return lhs.w > rhs.w;
}
bool Kruskal()
{
	DisjSets ds(n);
	make_heap(edges.begin(), edges.end(), Cmp);//对边集建堆
	int root1, root2;
	Edge e;
	while (!edges.empty())  				  //遍历所有边
	{								  //从未选边集中寻找最小权的边e
		e = edges.front();
		pop_heap(edges.begin(), edges.end(), Cmp);
		edges.pop_back();
		root1 = ds.find(e.u), root2 = ds.find(e.v); //获取u、v所在的点集
		if (root1 != root2)        		  //如果u、v不是同一个点集
		{
			sum += e.w; 			  //调整最小生成树长度
			mst.push_back(e);  		  //把边e放入最小生成树mst中
			ds.unionSets(root1, root2);   //合并两点所在的点集
		}
		if (mst.size() == n - 1)return true;      //如果选取边个数为n-1，成功
	}
	return false;
}
int main()
{
	n = 6;
	edges.clear();
	edges.push_back(Edge(0, 1, 6)); edges.push_back(Edge(0, 2, 15));
	edges.push_back(Edge(0, 3, 10));
	edges.push_back(Edge(1, 3, 11)); edges.push_back(Edge(1, 4, 8));
	edges.push_back(Edge(2, 3, 5)); edges.push_back(Edge(2, 5, 9)); edges.push_back(Edge(4, 5, 12));
	sum = 0;
	mst.clear();
	if (Kruskal())
	{
		cout << sum << endl;
		for (vector<Edge>::iterator it = mst.begin(); it != mst.end(); ++it)
			cout << it->u << "->" << it->v << endl;
	}
	else
	{
		cout << "有顶点不能到达！" << endl;
	}
	return 0;
}
