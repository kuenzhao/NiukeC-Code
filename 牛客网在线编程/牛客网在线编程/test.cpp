#include<iostream>
class A {
public:
	void test() { printf("test A"); }
};
int main() {
	A*pA = NULL;
	pA->test();
	return 0;
}