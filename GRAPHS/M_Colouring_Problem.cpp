#include <bits/stdc++.h>
using namespace std;

class M_Colouring{
public:
    bool isValid(bool graph[101][101], int colour[], int n) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; i < n; j++) {
                if (graph[i][j] && colour[j] == colour[i]) {
                    return 0;
                }
            }
        }
        return 1;
    }
    bool solution(bool graph[101][101], int m, int i, int colour[], int n) {
        if (i == n) {
            if (isValid(graph, colour, n)) {
                return 1;
            }
            return 0;
        }
        for (int j = 1; j <= m; j++) {
            colour[i] = j;
            if (solution(graph, m, i + 1, colour, n)) {
                return 1;
            }
            colour[i] = 0;
        }
        return 0;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        int colour[n];
        for (int i = 0; i < n; i++) {
            colour[i] = 0;
        }
        return solution(graph, m, 0, colour, n);
    }
};

int main() {
  int n, m, e;
  cin >> n >> m >> e;
  bool graph[101][101];
  for (int i = 0; i < n; i++) {
    memeset(graph[i], 0, sizeof(graph[i]));
  }
  for (int i = 0; i < e; i++) {
    int a, b;
    cin >> a >> b;
    graph[a - 1][b - 1] = 1;
    graph[b - 1][a - 1] = 1;
  }
  M_Colouring obj;
  cout << ob.graphColouring(graph, m, n) << endl;
  return 0;
}
