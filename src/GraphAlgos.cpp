#include "GraphAlgos.h"
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <stack>

Graph::Graph()
{
}
Graph::Graph(std::string fileName)
{
  readGraph(fileName);
  populateAdjacencyList();
}

std::vector<int> Graph::DFS(int startVertex)
{
  std::vector<int> visitedVertices;
  std::stack<int> scratchPad;
  int currentVertex = startVertex;
  visitedVertices.emplace_back(startVertex);
  
  for(auto i : adjacencyList[currentVertex])
  {
    scratchPad.push(i);
  }

  
}

int Graph::populateAdjacencyMatrix()
{
  return 0;
}

int Graph::populateAdjacencyList()
{
  for (auto j : edgeList)
  {
    adjacencyList[j[0]].emplace_back(j[1]);
    if(!directed)
    {
      adjacencyList[j[1]].emplace_back(j[0]);
    }
  }

  return 0;
}

void Graph::printGraph()
{
  std::cout << "Weighted:" << weighted << " Directed: " << directed << '\n';
  std::cout << "Printing Node List:\n";

  for (auto i : nodeList)
  {
    std::cout << i << " ";
  }
  std::cout << '\n';

  std::cout << "Printing Edge List:\n";

  for (auto i : edgeList)
  {
    std::cout << i[0] << " --> " << i[1] << '\n';
  }

  std::cout << "Printing adjacency list\n";
  for (auto i : nodeList)
  {
    std::cout << i << " --> ";
    for (auto k : adjacencyList[i])
    {
      std::cout << k << " ";
    }
    std::cout << '\n';
  }
}

int Graph::readGraph(std::string fileName)
{
  int retVal = 0;
  std::ifstream file{fileName};

  if (!file)
  {
    return -1;
  }
  else
  {
    std::cout << "Opened file " << fileName << '\n';
  }

  std::string lineRead;
  if (std::getline(file, lineRead))
  {
    std::stringstream ss(lineRead);

    ss >> numNodes >> numEdges >> weighted;
    std::vector<std::vector<int>> adjList1;

    if (std::getline(file, lineRead))
    {
      std::stringstream ss(lineRead);
      int node;
      while (ss >> node)
      {
        nodeList.emplace_back(node);
      }
      int node1, node2, weight;
      for (int i = 0; i < numEdges; i++)
      {
        if (std::getline(file, lineRead))
        {
          std::stringstream ss(lineRead);
          if (weighted)
          {
            ss >> node1 >> node2 >> weight;
            weightList.emplace_back(weight);
          }
          else
          {
            ss >> node1 >> node2;
          }

          edgeList.emplace_back(std::vector<int>{node1, node2});
        }
        else
        {
          std::cout << "Error reading data. Check the data format\n";
          retVal = -1;
        }
      }
    }
    else
    {
      std::cout<<"Error reading data. Check the data format\n";
      retVal = -1;
    }

    if (std::getline(file, lineRead))
    {
      std::stringstream ss(lineRead);
      ss >> directed;
    }
    else
    {
      std::cout << "Error reading data. Check the data format\n";
      retVal = -1;
    }
  }
  else
  {
    std::cout << "Error reading data. Check the data format\n";
    retVal = -1;
  }

  return retVal;
}
