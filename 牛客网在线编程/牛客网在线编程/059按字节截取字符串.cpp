#include<iostream>
#include<string>
using namespace std;

int main() {
	string str;
	while (cin >> str) {
		int bit = 0;
		cin >> bit;
		for (int j = 0; j<bit; ++j)
			cout << str[j];
		cout << endl;
	}
	return 0;
}