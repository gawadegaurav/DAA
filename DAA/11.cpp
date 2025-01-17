#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
	Graph(int vertices);
	void add_edge(int src, int dst);
	int count_paths(int src, int dst, int vertices);

private:
	int m_vertices;
	list<int>* m_neighbours;
	void path_counter(int src, int dst, int& path_count, vector<bool>& visited);
};

Graph::Graph(int vertices)
{
	m_vertices = vertices;
	m_neighbours = new list<int>[vertices];
}

void Graph::add_edge(int src, int dst)
{
	m_neighbours[src].push_back(dst);
}

int Graph::count_paths(int src, int dst, int vertices)
{
	int path_count = 0;
	vector<bool> visited(vertices, false);
	path_counter(src, dst, path_count, visited);
	return path_count;
}

void Graph::path_counter(int src, int dst, int& path_count, vector<bool>& visited)
{
	visited[src] = true;
	if (src == dst) {
		path_count++;
	}
	else {
		for (auto neighbour : m_neighbours[src]) {
			if (!visited[neighbour])
				path_counter(neighbour, dst, path_count, visited);
		}
	}
	visited[src] = false;
}

int main()
{
	Graph g(5);
	g.add_edge(0, 1);
	g.add_edge(0, 2);
	g.add_edge(0, 4);
	g.add_edge(1, 3);
	g.add_edge(1, 4);
	g.add_edge(2, 3);
	g.add_edge(2, 1);
	g.add_edge(3, 2);
	
	cout << g.count_paths(0, 4, 5);

	return 0;
}
