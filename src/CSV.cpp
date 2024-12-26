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
	delete[]Column;
	delete[]Row;
}

void CSV::Input()
{
	
	char *temp = new char[1];

	while (fin.good())
	{
		fin.open(fileName);
		std::getline(fin, fileName);
	}

	

	delete[] temp;

}
