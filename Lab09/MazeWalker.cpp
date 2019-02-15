/**
*	@file MazeWalker.cpp
* 	@author Levi Clark
*	@date 2015.11.13
*
*/

#include "MazeWalker.h"


MazeWalker::MazeWalker(const char* const* mazePtr, int startRow, int startCol, int rows, int cols, Search searchChoice): m_curPos(Position(startRow, startCol)), m_startPos(Position(startRow, startCol))
{
	m_maze = mazePtr;
	m_rows = rows;
	m_cols = cols;
	m_searchType = searchChoice;
	m_curStep = 1;
	m_visited = new int*[m_rows];
	
	for(int i = 0; i<m_rows; i++)
	{
		m_visited[i] = new int[m_cols];
	}
	
	for(int i = 0; i<m_rows; i++)
	{
		for(int j = 0; j<m_cols; j++)
		{
			m_visited[i][j] = 0;
		}
	}
	
	m_visited[startRow][startCol] = m_curStep;
	m_curStep++;
}

MazeWalker::~MazeWalker()
{
	for(int i=0; i<m_rows; i++)
	{
		delete m_visited[i];
		m_visited[i] = nullptr;
	}
	delete m_visited;
	m_visited = nullptr;
	
}

bool MazeWalker:: walkMaze()
{
	if(m_searchType == Search::DFS)
	{
		m_moveStack.push(m_startPos);
		
		while(!(m_moveStack.empty() || isGoalReached()))
		{
			storeValidMoves();
			move(m_moveStack.top());
			m_moveStack.pop();
			
		}
	}
	else
	{
		m_moveQueue.push(m_startPos);
		while(!(m_moveQueue.empty() || isGoalReached()))
		{
			storeValidMoves();
			m_moveQueue.pop();
			
			if(!m_moveQueue.empty())
			{
				move(m_moveQueue.front());
			}
		}
	}
	return isGoalReached();
	
}


const int* const* MazeWalker::getVisited() const
{
	return m_visited;
}
	
int MazeWalker:: getVisitedRows() const
{
	return m_rows;
}
	
int MazeWalker:: getVisitedCols() const
{
	return m_cols;
}
	
const char* const* MazeWalker:: getMaze() const
{
	return m_maze;
}

void MazeWalker:: storeValidMoves()
{

	if(m_searchType == Search::DFS)
	{		
		//up
		if(m_curPos.getRow()>0 && m_maze[m_curPos.getRow()-1][m_curPos.getCol()]!= 'W' && m_visited[m_curPos.getRow()-1][m_curPos.getCol()] == 0)
		{
			Position p(m_curPos.getRow()-1,m_curPos.getCol());
			m_moveStack.push(p);
		}
		//right
		if(m_curPos.getCol()<m_cols-1 && m_maze[m_curPos.getRow()][m_curPos.getCol()+1]!= 'W' && m_visited[m_curPos.getRow()][m_curPos.getCol()+1] == 0)
		{
			Position p(m_curPos.getRow(),m_curPos.getCol()+1);
			m_moveStack.push(p);
		}
		//down
		if(m_curPos.getRow()<m_rows-1 && m_maze[m_curPos.getRow()+1][m_curPos.getCol()]!= 'W' && m_visited[m_curPos.getRow()+1][m_curPos.getCol()] == 0)
		{
			Position p(m_curPos.getRow()+1,m_curPos.getCol());
			m_moveStack.push(p);
		}
		//left
		if(m_curPos.getCol()>0 && m_maze[m_curPos.getRow()][m_curPos.getCol()-1]!= 'W' && m_visited[m_curPos.getRow()][m_curPos.getCol()-1] == 0)
		{
			Position p(m_curPos.getRow(),m_curPos.getCol()-1);
			m_moveStack.push(p);
		}
		
	}
	else if(m_searchType == Search::BFS)
	{
		
		//up
		if(m_curPos.getRow()>0 && m_maze[m_curPos.getRow()-1][m_curPos.getCol()]!= 'W' && m_visited[m_curPos.getRow()-1][m_curPos.getCol()] == 0)
		{
			Position p(m_curPos.getRow()-1,m_curPos.getCol());
			m_moveQueue.push(p);
		}
		//right
		if(m_curPos.getCol()<m_cols-1 && m_maze[m_curPos.getRow()][m_curPos.getCol()+1]!= 'W' && m_visited[m_curPos.getRow()][m_curPos.getCol()+1] == 0)
		{
			Position p(m_curPos.getRow(),m_curPos.getCol()+1);
			m_moveQueue.push(p);
		}
		//down
		if(m_curPos.getRow()<m_rows-1 && m_maze[m_curPos.getRow()+1][m_curPos.getCol()]!= 'W' && m_visited[m_curPos.getRow()+1][m_curPos.getCol()] == 0)
		{
			Position p(m_curPos.getRow()+1,m_curPos.getCol());
			m_moveQueue.push(p);
		}
		//left
		if(m_curPos.getCol()>0 && m_maze[m_curPos.getRow()][m_curPos.getCol()-1]!= 'W' && m_visited[m_curPos.getRow()][m_curPos.getCol()-1] == 0)
		{
			Position p(m_curPos.getRow(),m_curPos.getCol()-1);
			m_moveQueue.push(p);
		}
			
	}

}

void MazeWalker:: move(Position& p)
{
	m_curPos = p;
	
	if(m_visited[m_curPos.getRow()][m_curPos.getCol()] == 0)
	{
		m_visited[m_curPos.getRow()][m_curPos.getCol()] = m_curStep;
		m_curStep++;
	}
}

bool MazeWalker:: isGoalReached() const
{
	return m_maze[m_curPos.getRow()][m_curPos.getCol()] =='E';
}












































































