#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

template<typename T>
T add(T &x, T &y)
{
	return x + y;
}

const int(*pfun1)(const int &a, const int &b);
const int(*pfun2)( int &a,  int &b);
 int(*pfun3)(const int &a, const int &b);
 int(*pfun4)( int &a,  int &b);

 std::string test_str()
 {
	 std::string str = "test";
	 return str;
 }
 int main()
 {
	 std::string str_ref = test_str();
	 std::cout << str_ref << std::endl;
	 return 0;
 }