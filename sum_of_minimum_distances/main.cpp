#include <iostream>
#include <vector>
#include <iterator>
#include <cassert>

static std::vector<int>* graph;
static int** distances;
static int** visited;
static int nodeNumber;

static inline void makeGraph()
{
    FILE* fp = fopen("./input.txt", "r");
    assert(fp);

    int lineNumber;
    fscanf(fp, "%d %d", &lineNumber, &nodeNumber);

    graph = new std::vector<int>[nodeNumber + 1]();
    assert(graph);

    distances = new int*[nodeNumber + 1]();
    assert(distances);
    visited = new int*[nodeNumber + 1]();
    assert(visited);
    for (register int i = 1; i <= nodeNumber; i++) {
        distances[i] = new int[nodeNumber + 1]();
        assert(distances[i]);
        visited[i] = new int[nodeNumber + 1]();
        assert(visited[i]);
    }

    int node1, node2, distance;
    for (register int i = 0; i < lineNumber; i++) {
        fscanf(fp, "%d %d %d", &node1, &node2, &distance);
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
        distances[node1][node2] = distance;
        distances[node2][node1] = distance;
    }

    fclose(fp);
}

static inline void deleteGraph()
{
    for (register int i = 1; i <= nodeNumber; i++) {
        delete visited[i];
        delete distances[i];
    }

    delete[] visited;
    delete[] distances;
    delete[] graph;
}

static int getDistanceSumFrom(const int s)
{
    std::vector<int> queue;
    queue.push_back(s);

    int sumOfDistances = 0;
    while (!queue.empty()) {
        const int u = queue.front();
        queue.erase(queue.begin());
        visited[s][u] = 1;
        
        std::vector<int>* pAdjacencies = &(graph[u]);
        std::vector<int>::const_iterator cItr;
        for (cItr = pAdjacencies->cbegin(); cItr != pAdjacencies->cend(); ++cItr) {
            const int v = *cItr;
            if (visited[s][v] == 0) {
                queue.push_back(v);
                if (visited[v][s] == 0) {
                    distances[s][v] = distances[s][u] + distances[u][v];
                    std::cout << s << " ~ " << v << " -> " << distances[s][u] << "(" << s << "~" << u << ") + " << distances[u][v] << "(" << u << "~" << v << ") = " << distances[s][v] << std::endl;
                    sumOfDistances += distances[s][v];
                }
            }
        }
    }

    return sumOfDistances;
}

static inline void doCalculate()
{
    int sum = 0;
    for (register int n = 1; n <= nodeNumber; n++) {
        sum += getDistanceSumFrom(n);
    }
    std::cout << "Total sum : " << sum << std::endl;
}

int main()
{
    makeGraph();
    doCalculate();
    deleteGraph();
    return 0;
}