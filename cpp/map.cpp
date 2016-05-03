
#include <iostream>
#include <string>
using namespace std;

void map() {
	string line;
	while (cin>>line) {
		//cout<<"Line: "<<line<<endl;
		size_t i;
		size_t start = 0, stop = 0;
		size_t len = line.size();
		bool inAWord = false;
		for (size_t i=0;i<len;++i) {
			if (line[i]==' ' || line[i]=='\t') {
				if (inAWord) {
					inAWord = false;
					cout<<line.substr(start,stop + 1).c_str()<<"\t1"<<endl;
				}
				start = i;
			} else {
				if (!inAWord)
					inAWord = true;
				stop = i;
			}
		}
		if (inAWord) {
			cout<<line.substr(start,stop + 1).c_str()<<"\t1"<<endl;
		}
	}
}

int main() {
	map();
}
