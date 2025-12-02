#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

int isValidId(const long long id)
{
	std::string idString= std::to_string(id);
	std::string s = idString.substr(0, idString.length() / 2);
	//std::cout << "idString: " << idString << "\ts+s: " << s + s << std::endl;
	return (idString.compare(s + s) != 0);
}

int processRange(const std::string& range)
{
	std::vector<std::string> sv;
	std::stringstream ss (range);
	std::string item;

	while(std::getline(ss, item, '-'))
		sv.push_back(item);
	long long lowrl = std::stoll(sv[0]);
	long long uprl = std::stoll(sv[1]);
	long long sum = 0;
	for (int i = lowrl; i <= uprl; i++)
	{
		if (!isValidId(i))
			sum += i;
	}
	return sum;
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	std::ifstream is;
	std::string fileName = argv[1];
	is.open(fileName, is.in);
	if (!is.is_open())
		return (1);
	std::string line;
	long long sum = 0;
	while (std::getline(is, line, ','))
	{
		std::cout << line << std::endl;
		sum += processRange(line);
	}
	std::cout << "Aswer 1: " << sum << std::endl;
	return (0);
}
