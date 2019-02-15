/**
*	@file Main.cpp
* 	@author Levi Clark
*	@date 2015.11.13
*
*/


#include "MazeReader.h"
#include "MazeCreationException.h"
#include "MazeWalker.h"
#include "Position.h"
#include <iostream>
#include "Test.h"

using namespace std;
int main(int argc, char** argv)
{
	//makes sure you enter either 2 or 3 arguments
	if(!(argc == 2 || argc == 3))
	{
		cout <<"Sorry, invalid arguments. \n";
		return 0;
	}
	
	string argumentType = argv[1];
	
	//test
	if(argc == 2 && argumentType == "-test")
	{
		Test myTester; 
		myTester.runTests();
		return 0;
	}
	
	string fileName = argv[2];
	
	//makes sure they enter a valid search type
	if(argumentType != "-dfs" || argumentType != "-bfs")
	{
		return 0;
	}
	
	MazeReader* maze = nullptr;
	MazeWalker* walker = nullptr;
	
	try
	{
		maze = new MazeReader(fileName);
	}
	catch(MazeCreationException& e)
	{
		cout<<e.what();
		return 0;
	}
	
	if(argumentType == "-dfs")
	{
		walker = new MazeWalker(maze->getMaze(),maze->getStartRow(),maze->getStartCol(),maze->getRows(),maze->getCols(),Search::DFS);
	}
	if(argumentType == "-bfs")
	{
		walker = new MazeWalker(maze->getMaze(),maze->getStartRow(),maze->getStartCol(),maze->getRows(),maze->getCols(),Search::BFS);
	}
	
		
	
	cout<<"Starting Position: "<<maze->getStartRow()<<","<<maze->getStartCol()<<"\n";
	cout<<"Size: "<<maze->getRows()<<","<<maze->getCols()<<endl;
	
	bool end = walker->walkMaze();
	
	const int* const* visited = walker->getVisited();
	
	for(int i = 0; i<maze->getRows(); i++)
	{
		for(int j = 0; j<maze->getCols(); j++)
		{
			cout<<visited[i][j]<<" ";
		}
		cout<<endl;
	}
	
	//if they got through the maze
	if(end)
	{
		cout<<"We got through the maze!\n";
	}
	else
	{
		cout<<"There is no way out, we are doomed to die in here! \n";
	}
	
	delete maze;
	maze = nullptr;
	delete walker;
	walker = nullptr;
	
	return 0;
	
}






















//check possible moves in a clockwise order(up, right, down, left)

/*
int** m_visited=nullptr;

m_visited = new int*[5];
|       5 6
V       3 0
[0] ->  W W W W W W
[1] ->  W P W W P E
[2] ->  W P W P P W
[3] ->  S P W P W W
[4] ->  W P P P W W


for(int i = 0; i<5; i++)
{
	m_visited[i] = new int [6]
}


STACK

*/
