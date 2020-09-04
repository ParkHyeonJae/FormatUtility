#pragma once
class CSVUtility
{
private:
	map<string, vector<string>> dataSet;
	vector<string> tupleCSVData;
	vector<string> spiltCSVData;

	size_t ConvertColumnCount(size_t*, size_t*);
public:
	CSVUtility();
	~CSVUtility();
	bool LoadCSV(const string& _filename);
	bool ReadCSVFile(const string& filename, vector<string>&, vector<string>&);
	map<string, vector<string>> ConvertCSVMap(const vector<string> & const, const vector<string>& const);
	void PrintCSV(const map<string, vector<string>>const* dataSet);

	map<string, vector<string>> GetCSVData() { return dataSet; }
};

