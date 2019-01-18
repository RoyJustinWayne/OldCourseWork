#include "WeightedGraph.h"
#include "config.h"

#define NDEBUG
#include <cassert>

WeightedGraph::WeightedGraph(int maxNumber = MAX_GRAPH_SIZE)
{
	maxSize = maxNumber;
	size = 0;
	vertexList = new Vertex[maxSize];
	adjMatrix = new int[maxSize * maxSize];
	pathMatrix = new int[maxSize * maxSize];
}

WeightedGraph::WeightedGraph(const WeightedGraph& other)
{
	maxSize = 0;
	size = 0;
	vertexList = NULL;
	adjMatrix = NULL;
	pathMatrix = NULL;

	//Simple Clone
	*this = other;
}

WeightedGraph& WeightedGraph::operator=(const WeightedGraph& other)
{
	int index = 0;
	int matrixSize = (size * size);

	if (this != &other)
	{
		if (maxSize != other.maxSize)
		{
			maxSize = other.maxSize;

			delete[] vertexList;
			vertexList = NULL;
			vertexList = new Vertex[maxSize];

			matrixSize = (other.size * other.size);
			delete[] adjMatrix;
			adjMatrix = NULL;
			adjMatrix = new int[matrixSize];

			delete[] pathMatrix;
			pathMatrix = NULL;
			pathMatrix = new int[matrixSize];
		}

		for (size = 0; size < other.size; size++)
		{
			vertexList[size] = other.vertexList[size];
		}

		for (index = 0; index < matrixSize; index++)
		{
			adjMatrix[index] = other.adjMatrix[index];
		}

		for (index = 0; index < matrixSize; index++)
		{
			pathMatrix[index] = other.pathMatrix[index];
		}
	}
	return *this;
}

WeightedGraph::~WeightedGraph()
{
	delete[] vertexList;
	vertexList = NULL;

	delete[] adjMatrix;
	adjMatrix = NULL;

	delete[] pathMatrix;
	pathMatrix = NULL;
}

void WeightedGraph::insertVertex(const Vertex& newVertex) throw(logic_error)
{
	int newIndex = Unknown;
	int index = 0;

	newIndex = getIndex(newVertex.getLabel());

	if (newIndex != Unknown)
	{
		vertexList[newIndex] = newVertex;

		for (index = 0; index < size; index++)
		{
			if (index == newIndex)
			{
				setEdge(index, newIndex, INFINITE_EDGE_WT);
			}
			else
			{
				setEdge(newIndex, index, INFINITE_EDGE_WT);
				setEdge(index, newIndex, INFINITE_EDGE_WT);
			}
		}
	}
	else if (size < maxSize)
	{
		newIndex = size;
		vertexList[newIndex] = newVertex;
		size++;

		for (index = 0; index < newIndex; index++)
		{
			setEdge(newIndex, index, INFINITE_EDGE_WT);
		}
		setEdge(newIndex, index, Cost);
		for (index = 0; index < newIndex; index++)
		{
			setEdge(index, newIndex, INFINITE_EDGE_WT);
		}
	}
	else
	{
		throw logic_error("Graph is full!");
	}
}

void WeightedGraph::insertEdge(const string& v1, const string& v2,
	const int wt) throw(logic_error)
{
	int index1 = Unknown;
	int index2 = Unknown;
	bool edgeExists = false;

	index1 = getIndex(v1);

	if (index1 != Unknown)
	{
		index2 = getIndex(v2);

		if (index2 != Unknown)
		{
			edgeExists = true;

			setEdge(index1, index2, wt);
			setEdge(index2, index1, wt);
		}
	}
	if (!edgeExists)
	{
		throw("Missing vertice needed.");
	}
}

bool WeightedGraph::retrieveVertex(const string& v, Vertex& vData) const
{
	int index = Unknown;
	bool result = false;

	index = getIndex(v);

	if (index != Unknown)
	{
		result = true;
		vData = vertexList[index];
	}
	return result;
}

bool WeightedGraph::getEdgeWeight(const string& v1, const string& v2, int& wt) const throw(logic_error)
{
	int index1 = Unknown;
	int index2 = Unknown;
	bool result = false;

	index1 = getIndex(v1);
	if (index1 != Unknown)
	{
		index2 = getIndex(v2);

		if (index2 != Unknown)
		{
			wt = getEdge(index1, index2);

			if (wt != INFINITE_EDGE_WT)
			{
				result = true;
			}
		}
	}
	if ((index1 == Unknown) || (index2 == Unknown))
	{
		throw("Missing vertice needed.");
	}
	return result;
}

void WeightedGraph::removeVertex(const string& v) throw(logic_error)
{
	int rowIndex = 0;
	int columnIndex = 0;
	int verticeIndex = Unknown;

	verticeIndex = getIndex(v);

	if (verticeIndex != Unknown)
	{
		size--;
		for (rowIndex = verticeIndex; rowIndex < size; rowIndex++)
		{
			vertexList[rowIndex] = vertexList[rowIndex + 1];
		}
		for (rowIndex = verticeIndex; rowIndex < size; rowIndex++)
		{
			for (columnIndex = 0; columnIndex <= size; columnIndex++)
			{
				setEdge(rowIndex, columnIndex, getEdge((rowIndex + 1), columnIndex));
			}
		}
		for (rowIndex = 0; rowIndex < size; rowIndex++)
		{
			for (columnIndex = verticeIndex; columnIndex < size; columnIndex++)
			{
				setEdge(rowIndex, columnIndex, getEdge(rowIndex, (columnIndex + 1)));
			}
		}
	}
	else
	{
		throw logic_error("Vertex does not exist.");
	}
}

void WeightedGraph::removeEdge(const string& v1, const string& v2) throw(logic_error)
{
	int index1 = Unknown;
	int index2 = Unknown;
	bool edgeExists = false;

	index1 = getIndex(v1);

	if (index1 != Unknown)
	{
		index2 = getIndex(v2);

		if (index2 != Unknown)
		{
			edgeExists = true;
			setEdge(index1, index2, INFINITE_EDGE_WT);
			setEdge(index2, index1, INFINITE_EDGE_WT);
		}
	}
	if (!edgeExists)
	{
		throw("Missing required Vertices");
	}
}

void WeightedGraph::clear()
{
	//simple clear.
	size = 0;
}

bool WeightedGraph::isEmpty() const
{
	return (size == 0);
}

bool WeightedGraph::isFull() const
{
	return (size == maxSize);
}

void WeightedGraph::showStructure() const
// Outputs a graph's vertex list and adjacency matrix. This operation
// is intended for testing/debugging purposes only.
{
	if (size == 0) {
		cout << "Empty graph" << endl;
	}
	else {
		cout << endl << "Vertex list : " << endl;
		for (int row = 0; row < size; row++)
			cout << row << '\t' << vertexList[row].getLabel()
#if LAB12_TEST2
			<< vertexList[row].color
#endif
			<< endl;

		cout << endl << "Edge matrix : " << endl << '\t';
		for (int col = 0; col < size; col++)
			cout << col << '\t';
		cout << endl;
		for (int row = 0; row < size; row++)
		{
			cout << row << '\t';
			for (int col = 0; col < size; col++)
			{
				int wt = getEdge(row, col);
				if (wt == INFINITE_EDGE_WT)
					cout << "- \t";
				else
					cout << wt << '\t';
			}
			cout << endl;
		}
	}
}

bool WeightedGraph::hasProperColoring() const
{
	int rowIndex = 0;
	int columnIndex = 0;
	bool hasValidColoring = true;

	for (rowIndex = 0; hasValidColoring && (rowIndex < size); rowIndex++)
	{
		for (columnIndex = 0; hasValidColoring && (columnIndex < size); columnIndex++)
		{
			if (rowIndex != columnIndex)
			{
				if (getEdge(rowIndex, columnIndex) != INFINITE_EDGE_WT)
				{
					if (vertexList[rowIndex].getColor() == vertexList[columnIndex].getColor())
					{
						hasValidColoring = false;
					}
				}
			}
		}
	}
	return hasValidColoring;
}

bool WeightedGraph::areAllEven() const
{
	bool areAllEven = true;
	int rowIndex = 0;
	int columnIndex = 0;
	int degree = 0;

	for (rowIndex = 0; areAllEven && (rowIndex < size); rowIndex++)
	{
		for (degree = 0, columnIndex = 0; columnIndex < size; columnIndex++)
		{
			if (getEdge(rowIndex, columnIndex) != INFINITE_EDGE_WT)
			{
				if (rowIndex != columnIndex)
				{
					degree++;
				}
			}
		}
		if ((degree % 2) == 1)
		{
			areAllEven = false;
		}
	}
	return areAllEven;
}