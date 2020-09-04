#include "stdafx.h"
#include "CSVUtility.h"

CSVUtility::CSVUtility()
{
}

CSVUtility::~CSVUtility()
{
}



bool CSVUtility::ReadCSVFile(const string filename, vector<string>& tupleCSVData, vector<string>& spiltCSVData)
{
	if (filename.find(".csv") == string::npos)
		return false;
	ifstream readFromFile(filename);

	if (readFromFile.is_open()) {
		while (!readFromFile.eof()) {
			string str;
			getline(readFromFile, str);
			tupleCSVData.emplace_back(str);

			istringstream tuple(str);
			string splitStr;
			while (!tuple.eof()) {
				getline(tuple, splitStr, ',');
				spiltCSVData.emplace_back(splitStr);
			}
		}
		return true;
	}
	return false;
}

size_t CSVUtility::ConvertColumnCount(size_t *tupleCount, size_t *MaxElementCount)
{
	return ((*MaxElementCount) / (*tupleCount));
}

map<string, vector<string>> CSVUtility::ConvertCSVMap(const vector<string>& const _tupleCSVData, const vector<string>& const _spiltCSVData)
{
	map<string, vector<string>> _dataSet;
	size_t tupleCount = _tupleCSVData.size();
	size_t MaxElementCount = _spiltCSVData.size();
	size_t column = ConvertColumnCount(&tupleCount, &MaxElementCount);

	for (size_t i = 0; i < column; i++)
	{
		for (size_t j = column; j < MaxElementCount; j++)
		{
			size_t seq = j % column;
			if (seq == i)
				_dataSet[_spiltCSVData[i]].emplace_back(_spiltCSVData[j]);
		}
	}
	return _dataSet;
}

void CSVUtility::PrintCSV(const map<string, vector<string>>const* dataSet)
{
	map<string, vector<string>>::iterator iter;
	for (auto iter : (*dataSet))
	{
		cout << iter.first << " : " << endl;
		vector<string> column = iter.second;
		size_t columnSize = column.size();
		for (size_t i = 0; i < columnSize; i++)
		{
			if (i != columnSize)
			{
				cout << column[i] << ",";
				continue;
			}
			cout << column[i] << endl;
		}
		cout << endl;
	}
}
bool CSVUtility::LoadCSV(const string _filename)
{
	if (ReadCSVFile(_filename, tupleCSVData, spiltCSVData)) {
		dataSet = ConvertCSVMap(tupleCSVData, spiltCSVData);
		return true;
	}
	return false;
}