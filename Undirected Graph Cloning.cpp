#include<Iostream>
using namespace std;

struct Node
{
	int val;
	vector<Node*> neighbours;
};

Node *clone(Node *src)
{
	map<Node*, Node*> m;
	queue<Node*> q;

	q.push(src);
	Node *node;

	node = new Node();
	node->val = src->val;

	m[src] = node;
	while (!q.empty())
	{
		Node *u = q.front();
		q.pop();
		vector<Node *> v = u->neighbours;
		int n = v.size();
		for (int i = 0; i < n; i++)
		{
			if (m[v[i]] == NULL)
			{
				node = new Node();
				node->val = v[i]->val;
				m[v[i]] = node;
				q.push(v[i]);
			}
			m[u]->neighbours.push_back(m[v[i]]);
		}
	}

	return m[src];
}

Node *buildGraph()
{
	Node *node1 = new Node();
	node1->val = 1;
	Node *node2 = new Node();
	node2->val = 2;
	Node *node3 = new Node();
	node3->val = 3;
	Node *node4 = new Node();
	node4->val = 4;
	vector<Node *> v;
	v.push_back(node2);
	v.push_back(node4);
	node1->neighbours = v;
	v.clear();
	v.push_back(node1);
	v.push_back(node3);
	node2->neighbours = v;
	v.clear();
	v.push_back(node2);
	v.push_back(node4);
	node3->neighbours = v;
	v.clear();
	v.push_back(node3);
	v.push_back(node1);
	node4->neighbours = v;
	return node1;
}
void BFS(Node *src)
{
	map<Node*, bool> visit;
	queue<Node*> q;
	q.push(src);
	visit[src] = true;
	while (!q.empty())
	{
		Node *u = q.front();
		cout << "Value of Node " << u->val << "\n";
		cout << "Address of Node " <<u << "\n";
		q.pop();
		vector<Node *> v = u->neighbours;
		int n = v.size();
		for (int i = 0; i < n; i++)
		{
			if (!visit[v[i]])
			{
				visit[v[i]] = true;
				q.push(v[i]);
			}
		}
	}
	cout << endl;
}

int main()
{
	Node *src = buildGraph();
	cout << "BFS Traversal before cloning\n";
	BFS(src);
	Node *newsrc = clone(src);
	cout << "BFS Traversal after cloning\n";
	BFS(newsrc);
	return 0;
}
