#include "stdafx.h"
#include "CSVUtility.h"

int main(int argv, char* argc)
{
	CSVUtility* _csvFormat = new CSVUtility();
	if (_csvFormat->LoadCSV("DataTable.csv")) {
		_csvFormat->PrintCSV(&_csvFormat->GetCSVData());
	}
	delete _csvFormat;
	return 0;
}