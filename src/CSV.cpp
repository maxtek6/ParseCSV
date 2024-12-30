#include "CSV.h"

CSV::CSV()
{
	columnCount = 0;
	rowCount = 0;
	columnName = "Column";
	rowName = "Row";
}

CSV::CSV(std::string fileName)
{
	this->fileName = fileName;
	Input();
}

CSV::~CSV()
{
	// delete[]Column;
	// delete[]Row;
}

//Public

void CSV::setRowName(std::string row)
{
	rowName = row;
}

void CSV::setColName(std::string col)
{
	columnName = col;
}

std::string CSV::getRowName() const
{
	return rowName;
}

std::string CSV::getColName() const
{
	return columnName;
}

//Protected

void CSV::Input()
{
	
	//char *temp = new char[1];
	fin.open(fileName);

	while (fin.good())
	{
		std::getline(fin, fileName);
	}

	

	//delete[] temp;

}

//Only finds the first instance of a user's query, to be updated.
//Almost no error checking in place
void CSV::Search(std::string query)
{
	for(int x=0; x<rowCount; x++)
	{
		for(int y=0; y<columnCount; y++)
		{
			if(matrix.at(x).at(y) == query)
			{
				std::string in;
				std::cout << "\"" << query << "\" was discovered at (" << (x+1) << ", " << (y+1) << ").\n\n";
				std::cout << "Would you like to print to a file (Y/N)? ";
				
				std::cin >> in;

				if(in == "Y" || in == "y")
				{

					std::cin.clear();
					std::cout << "Enter file name (no extentions): ";
					std::cin >> in;
					fout.close();
					fout.open(in + ".txt");

					std::cout << "Any pre existing files that share the name " << in << ".txt will be erased and overwritten, press 'N' to change the file name...";

					fout << "Query: " << query << "\nLocation: (" << (x+1) << ", " << (x+1) << ").\nInstances: 1";

					fout.close();
					fout.open(this->fileName);

				}
			}
		}
	}
}

void CSV::Editor(int *row, int *col)
{

	std::string input;
	std::cout << "Current output at (" << (*--row) << ", " << (*--col) << "): " << matrix.at(*row).at(*col) << std::endl;

	std::cout << "Enter updated data: ";
	std::cin.ignore();
	getline(std::cin, input);

	matrix.at(*row).at(*col) = input;

	// for(int x=0; x<*row; x++)
	// {
	// 	for(int y=0; y<*col; y++)
	// 	{
	// 		matrix.at(x).at(y) = "";
	// 		std::cout << "Enter updated data: ";

	// 		std::cin.clear();
	// 		std::cin.ignore();
	// 		getline(std::cin, input);
	// 	}
	// }

	PrintToFile();

}

//9 is filler
int CSV::counter(std::string *query)
{

	instanceCount = 0;
	instances = new std::string[instanceCount];

	for(int x=0; x<rowCount; x++)
	{
		for(int y=0; y<columnCount; y++)
		{
			if(matrix.at(x).at(y) == *query)
			{

				*instances = matrix.at(x).at(y);
				instanceCount++;

			}
		}
	}

	loc = instanceCount;

	return instanceCount;
}