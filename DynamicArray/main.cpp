#include <iostream>
#include "tVector.h"

int main()
{
	tVector<int> original;
	original.push_back(4);
	original.push_back(5);
	original.push_back(6);

	tVector<int> copy = original;
	copy.pop_back();
	copy.pop_back();
	copy.pop_back();

	std::cout << original.size() << std::endl;
	std::cout << copy.size() << std::endl;
}