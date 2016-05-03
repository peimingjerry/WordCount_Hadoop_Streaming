
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

void strip(string &str) {
	size_t len = str.size();
	size_t i = 0;
	size_t start = 0, stop = 0;
	while (i<len) {
		if (str[i] != ' ' && str[i] != '\t') {
			start = i;
			break;
		}
	}
	i = len - 1;
	while (i>=start) {
		if (str[i] != ' ' && str[i] != '\t') {
			stop = i + 1;
		}
	}
	str = str.substr(start, stop);
}

void reduce() {
	string line, key, value;
	string curKey = "";
	int curCount = 0;
	while (cin>>key>>value) {
		//strip(line);
		//cout<<"Line: "<<line<<endl;
		//size_t pos = line.find('\t');
		//string key = line.substr(0,pos);
		//string value = line.substr(pos+1);
		//cout<<"Line: "<<key.c_str()<<"\t"<<value.c_str()<<endl;
		int count = atoi(value.c_str());
		if (!curKey.empty() && key.compare(curKey)==0) {
			curCount += count;
		} else {
			if (!curKey.empty()) {
				cout<<curKey.c_str()<<"\t"<<curCount<<endl;
			}
			curKey = key;
			curCount = count;
		}
	}
	cout<<curKey.c_str()<<"\t"<<curCount<<endl;
}

int main() {
	reduce();
}
