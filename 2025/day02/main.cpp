#include <fstream>
#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include <algorithm>

const std::vector<long long> genNotValidIds1(void)
{
    std::vector<long long> v;
    int i = 0;
    while (1)
    {
        std::string ns = std::to_string(i);
        std::string s =  ns + ns;
        if (s.length() > 12)
            break;
        v.push_back(std::stoll(s));
        i++;
    }
    return (v);
}

const std::vector<long long> genNotValidIds2(void)
{
    std::vector<long long> v;
    int i = 0;
    while (1)
    {
        std::string ns = std::to_string(i);
        std::string s =  ns + ns;
        while (s.length() < 13)
        {
            v.push_back(std::stoll(s));
            s += ns;
        }
        if (ns.length() > 7)
            break;
        i++;
    }
    std::sort(v.begin(), v.end());
    auto last = std::unique(v.begin(), v.end());
    v.erase(last, v.end());
    return (v);
}

long long sumInRange(const std::vector<long long>& ids, const std::string& range)
{
    long long sum = 0;
    long long llim = std::stoll(range.substr(0, range.find('-')));
    long long ulim = std::stoll(range.substr(range.find('-') + 1));
    for (auto id : ids)
    {
        if (llim <= id && id <= ulim)
            sum += id;
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
    const std::vector<long long>  v1 = genNotValidIds1();
    const std::vector<long long>  v2 = genNotValidIds2();
	std::string range;
	long long sum1 = 0;
	long long sum2 = 0;
	while (std::getline(is, range, ','))
	{
		std::cout << range << std::endl;
		sum1 += sumInRange(v1, range);
		sum2 += sumInRange(v2, range);
	}
	std::cout << "Aswer 1: " << sum1 << std::endl;
	std::cout << "Aswer 2: " << sum2 << std::endl;
	return (0);
}
