#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <xutility>

template <typename T, int N>
class Array 
{
public:
	int getSize() const 
	{
		return N;
	}
private:
	T elem[N];
};

struct Man
{
	const char* name;
	int age;
};

int main(int argc, char* argv[])
{
	std::vector<int> vec = { 1,2,3,4,5,6,7,8,9 };
	std::vector<std::string> str = { "Programming", "in", "a", "functional", "style." };

	std::transform(vec.begin(), vec.end(), vec.begin(), [](int i) {return i * i; });

	//auto it = std::remove_if(vec.begin(), vec.end(), [](int i) { return ((i < 3) or (i > 8)); }); // {3,4,5,6,7,8}
	auto it2 = std::remove_if(str.begin(), str.end(), [](std::string s) { return (s[0]); });

	//auto deref = *it;

	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << std::endl;
	}

	return 0;
}