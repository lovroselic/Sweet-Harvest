// https://www.codeabbey.com/index/task_view/sweet-harvest
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Console.h"
#include "CodeAbbey.h"
#include "LS_library.h"
#define VERSION "1.0"

using namespace std;

int Harvest(vector<int>& data);

int main()
{
	cout << "Sweet Harvest v" << VERSION << "!\n\n";
	//string path = "Test.txt";
	string path = "Try.txt";
	vector<string> raw_data = loadData(path);
	//printVector(raw_data);
	//unpack
	const int COUNT = stoi(raw_data[0]);
	vector<int> solution;

	for (int c = 0; c < COUNT; c++) {
		vector<int> data = splitToInt(raw_data[c + 1], " ");
		solution.push_back(Harvest(data));
	}

	cout << "Solution: " << joinVector(solution, " ") << endl;
}

int Harvest(vector<int>& data) {
	data.at(1) = 0;
	int  two, three;
	for (int i = 2; i < data.size(); i++) {
		if (i - 3 < 0) {
			three = 0;
		}
		else {
			three = data[i] + data[i - 3];
		}
		two = data[i] + data[i - 2];
		data[i] = max({ two, three });
	}
	return max({ data.rbegin()[0], data.rbegin()[1] });
}