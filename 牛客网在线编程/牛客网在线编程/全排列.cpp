#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstdio>

using namespace std;


void Permutation(char* pStr, char* pBegin)
{
	if (pStr == NULL || pBegin == NULL)
	{
		return;
	}

	if (*pBegin == '\0')
		printf("%s\n", pStr);
	else
	{
		for (char* temp = pBegin; *temp != '\0'; temp++)
		{
			swap(*pBegin, *temp);
			Permutation(pStr, pBegin + 1);
			swap(*pBegin, *temp);
		}
	}
}
int main()
{
	char str[] = "123";
	Permutation(str, str);
	return 0;

	
	return 0;

}