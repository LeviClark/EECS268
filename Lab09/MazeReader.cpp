/**
*	@file MazeReader.cpp
* 	@author Levi Clark
*	@date 2015.11.13
*
*/
#include "MazeReader.h"

using namespace std;

MazeReader::MazeReader(std::string file) throw (MazeCreationException)
{
	fileName = file;
	infile.open(fileName);
	
	if(!infile.is_open())
	{
		throw(MazeCreationException("File not open\n"));
	}
	else
	{
		infile >> m_rows;
		infile >> m_cols;
		infile >> m_startRow;
		infile >> m_startCol;
		
		if(m_rows<=1 || m_cols<=1)
		{
			throw(MazeCreationException("Rows and Columns must be greater than 1\n"));
		}
		
		else if(m_startRow>m_rows || m_startRow<0 || m_startCol>m_cols|| m_startCol<0)
		{
			throw(MazeCreationException("Error, can't start at this position\n"));
		}
		
		else
		{
			m_maze = new char*[m_rows];
			
			for(int i = 0; i<m_rows; i++)
			{
				m_maze[i] = new char [m_cols];			
			}
			
			readMaze();
		}
	}
	infile.close();
}

MazeReader::~MazeReader()
{
	for(int i = 0; i<m_rows; i++)
	{
		if(m_maze!=nullptr)
		{
			delete m_maze[i];
		}
	}
	delete m_maze;
	m_maze = nullptr;


}

const char* const* MazeReader::getMaze() const
{
	return m_maze;
}

int MazeReader::getCols() const
{
	return m_cols;
}

	
int MazeReader::getRows() const
{
	return m_rows;
}

int MazeReader::getStartCol() const
{
	return m_startCol;
}

int MazeReader::getStartRow() const
{
	return m_startRow;
}

void MazeReader::readMaze() throw (MazeCreationException)
{
	for(int i = 0; i<m_rows; i++)
	{
		for(int j = 0; j<m_cols; j++)
		{
			infile>>m_maze[i][j];
		}	
	}
}
































