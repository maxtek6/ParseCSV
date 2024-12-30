#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

/*add a temporary secret command to activate a developer mode, 
which will include the ability to set a location for the dynamic
array to prevent a memory leak.
*/
class CSV
{

public:
	
	CSV();
	CSV(std::string fileName);
	~CSV();

	void setRowName(std::string);
	void setColName(std::string); 
	std::string getRowName() const;
	std::string getColName() const;

	

	
protected:

	void Input();
	void Search(std::string);
	void Editor(int*, int*); //open file if it's not already open
	void PrintToFile(); //To be used in the future
	int counter(std::string*);

private:

	std::string rowName, columnName;

	// std::string* Column = new std::string[columnCount];
	// std::string* Row = new std::string[rowCount];
	std::string fileName;

	int columnCount, rowCount;

	std::ifstream fin;
	std::ofstream fout;

	std::vector<std::vector<std::string>> matrix;

	std::string* instances; //declare as dynamic array later in program
	int instanceCount = 0, loc = 0;

};

