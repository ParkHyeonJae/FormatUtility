#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

size_t ConvertColumnCount(size_t, size_t);

void PrintCSV(map<string, vector<string>> dataSet);
int main(int argv, char* argc)
{
	map<string, vector<string>> dataSet;
	vector<string> tupleCSVData;
	vector<string> spiltCSVData;
	
	//ifstream readFromFile("words.txt");
	ifstream readFromFile("DataTable.csv");

	int csvSequence = 0;
	if (readFromFile.is_open()) {
		while (!readFromFile.eof()) {
			string str;
			getline(readFromFile, str);
			tupleCSVData.emplace_back(str);
		}
		for (size_t i = 0; i < tupleCSVData.size(); i++)
		{
			string str;
			istringstream tuple(tupleCSVData[i]);
			while (!tuple.eof()) {
				getline(tuple, str, ',');
				spiltCSVData.emplace_back(str);
			}
		}
	}

	size_t tupleCount = tupleCSVData.size();
	size_t MaxElementCount = spiltCSVData.size();
	size_t column = ConvertColumnCount(tupleCount, MaxElementCount);

	for (size_t i = 0; i < column; i++)
	{
		for (size_t j = column; j < MaxElementCount; j++)
		{
			size_t seq = j % column;
			if (seq == i)
				dataSet[spiltCSVData[i]].emplace_back(spiltCSVData[j]);
		}
	}

	PrintCSV(dataSet);
	return 0;
}
size_t ConvertColumnCount(size_t tupleCount, size_t MaxElementCount)
{
	return (MaxElementCount / tupleCount);
}
void PrintCSV(map<string, vector<string>> dataSet)
{
	map<string, vector<string>>::iterator iter;
	for (auto iter : dataSet)
	{
		cout << iter.first << " : " << endl;
		vector<string> column = iter.second;
		for (size_t i = 0; i < column.size(); i++)
		{
			if (i == column.size()) {
				cout << column[i] << endl; break;
			}
			cout << column[i] << ",";
		}
		cout << endl;
	}
}