#include <iostream>
#include <vector>

using namespace std;

// Function to check if the current color assignment is safe for the vertex
bool isSafe(int v, vector<vector<int>>& graph, vector<int>& color, int c) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[v][i] == 1 && color[i] == c) // If adjacent vertex has the same color
            return false;
    }
    return true;
}

// Backtracking function to solve the graph coloring problem
bool graphColoringUtil(vector<vector<int>>& graph, int m, vector<int>& color, int v) {
    if (v == graph.size())  // All vertices are colored
        return true;

    // Try different colors for the vertex `v`
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;  // Assign color `c` to vertex `v`

            // Recur to color the rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;

            // If no color assignment works, backtrack
            color[v] = 0;
        }
    }

    return false;  // No valid color assignment found
}

// This function solves the graph coloring problem using backtracking
bool graphColoring(vector<vector<int>>& graph, int m) {
    vector<int> color(graph.size(), 0);  // Initialize all vertices with no color (0)

    // Start coloring from vertex 0
    if (graphColoringUtil(graph, m, color, 0)) {
        cout << "Solution exists with the following color assignment:" << endl;
        for (int i = 0; i < color.size(); i++)
            cout << "Vertex " << i << " ---> Color " << color[i] << endl;
        return true;
    } else {
        cout << "No solution exists with " << m << " colors." << endl;
        return false;
    }
}

int main() {
    int n, m;
    
    // Input number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> n;

    // Input the number of colors available
    cout << "Enter the number of colors: ";
    cin >> m;

    // Adjacency matrix to represent the graph
    vector<vector<int>> graph(n, vector<int>(n, 0));
    
    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter the edges (pairs of vertices):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;  // Because the graph is undirected
    }

    // Function call to solve the graph coloring problem
    graphColoring(graph, m);

    return 0;
}
