#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

int getLargestComb(const std::string& s)
{
	size_t i = 0;
	std::vector<int> v;
	v.insert(v.begin(), s[i++] - '0');
	while (i < s.length() && v[0] != 9)
	{
		if (v.empty() || s[i] > v[0] + '0')
		{
			assert(0 <= s[i] - '0' && s[i] - '0' <= 9);
			v.insert(v.begin(), s[i] - '0');
		}
		i++;
	}
	std::vector<int> t;
	while (i < s.length() && s[i] != 9)
	{
		if (t.empty() || s[i] > t[0] + '0')
		{
			assert(0 <= s[i] - '0' && s[i] - '0' <= 9);
			t.insert(t.begin(), s[i] - '0');
		}
		i++;
	}
	if (!t.empty())
	{
		int result = v[0] * 10 + t[0];
		std::cout << "t is empty" << std::endl;
		std::cout << v << std::endl;
		std::cout << result << std::endl;
		assert(0 <= result && result <= 99);
		return result;
	}
	else
	{
		int result = v[1] * 10 + v[0];
		std::cout << "t is NOT empty" << std::endl;
		std::cout << s << std::endl;
		std::cout << v << std::endl;
		std::cout << result << std::endl;
		assert(0 <= result && result <= 99);
		return result;
	}
}

int main (int argc, char **argv)
{
	if (argc != 2)
		return (1);
	std::string inputFile = argv[1];
	std::ifstream is;
	is.open(inputFile, is.in);
	if (!is.is_open())
		return (1);
	long sum = 0;
	std::string line;
	while (getline(is, line))
	{
		//std::cout << line << "\n";
		//std::cout << getLargestComb(line) << "\n";
		sum += getLargestComb(line);
	}
	std::cout << "Aswer 1: " << sum << std::endl;
	return (0);
}
