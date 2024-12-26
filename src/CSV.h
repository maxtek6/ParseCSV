#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

class CSV
{

public:
	
	CSV();
	CSV(std::string fileName);
	~CSV();

	
protected:

	void Input();
	void Search();
	void Editor(std::string /*fileName*/); //open file if it's not already open


private:

	std::string rowName, columnName;

	std::string* Column = new std::string[rowCount];
	std::string* Row = new std::string[columnCount];

	std::string fileName;

	int columnCount, rowCount;

	std::ifstream fin;
	std::ofstream fout;

};

