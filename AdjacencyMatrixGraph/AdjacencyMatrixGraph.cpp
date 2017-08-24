/*	AdjacencyMatrixGraph.cpp
*	Tests the AdjacencyMatrixGraph class.
*	Date:  August 6, 2017
*/


#include "AdjacencyMatrixGraph.h"

using namespace std;

int main() {


	//Read in data from Project 3 text file into an initial graph
	int inputVertexCount;
	ifstream infile("project_3_input.txt");
	infile >> inputVertexCount;


	//create graph structure and continue reading in edges
	AdjacencyMatrixGraph<int, int> p3Graph(inputVertexCount);
	cout << "Number of vertices is: " << p3Graph.vertexCount() << endl;
	int readStart, readEnd;
	while (!infile.eof()) {
		try
		{
			infile >> readStart >> readEnd;
			p3Graph.addEdge(readStart, readEnd);
		}
		catch (GraphEdgeOutOfBounds e)
		{
			cout << "Encountered graph edge out of bounds...skipping" << endl;
		}
		catch (GraphDuplicateEdge e)
		{
			cout << "Encountered duplicate graph edge...skipping" << endl;
		}
	}
	infile.close();

	/*********** THE NEXT BLOCK DEMONSTRATES SIMPLE GRAPH MANIPULATION METHODS ***************/
	//Print out graph using overloaded operator <<
	cout << "Printing graph with overloaded<< : " << endl << p3Graph << endl;
	cout << endl << endl;

	//Create new graph using copy constructor and print
	AdjacencyMatrixGraph<int, int> tmpGraph(p3Graph);
	cout << "Printing graph copied with copy constructor: " << endl << tmpGraph << endl << endl;
	cout << endl << endl;

	//Create another graph using the overloaded = operator and print
	AdjacencyMatrixGraph<int, int> tmp2Graph;
	tmp2Graph = tmpGraph;
	cout << "Printing graph copied using overloaded = operator: " << endl;
	cout << tmp2Graph << endl << endl;
	cout << endl << endl;

	//Test breadth first serach method
	cout << "************* RUNNING BFS ROUTINES ***************" << endl;
	int startBFS = 49;
	vector<int> bfsParentNodes(p3Graph.vertexCount(), 0);
	vector<int> testBFS = p3Graph.breadthFirstSearch(startBFS, bfsParentNodes);
	cout << "Order of nodes visited in BFS starting with node " <<startBFS << ": " << endl;
	p3Graph.printVector(testBFS, cout);
	cout << endl << "Parent node vector is: " << endl;
	p3Graph.printVector(bfsParentNodes, cout);
	cout << endl << endl;

	//Test depth first serach method
	cout << "************* RUNNING DFS ROUTINES ***************" << endl;
	int startDFS = 49;
	vector<int> dfsParentNodes(p3Graph.vertexCount(), 0);
	vector<int> testDFS = p3Graph.depthFirstSearch(startDFS, dfsParentNodes);
	cout << "Order of nodes visited in DFS starting with node " << startDFS << ": " << endl;
	p3Graph.printVector(testDFS, cout);
	cout << endl << "Parent node vector is: " << endl;
	p3Graph.printVector(dfsParentNodes, cout);
	cout << endl << endl;


	return 0;
}
