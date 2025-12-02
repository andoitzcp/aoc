#include <fstream>
#include <iostream>

int calcOperation(const std::string &line)
{
    if (line[0] == 'R')
        return std::stoi(line.substr(1));
    else if (line[0] == 'L')
        return -1 * std::stoi(line.substr(1));
    else
        exit(1);
}

int hits(int dial, int operation)
{
    int counter = 0;
    int flag = 1;
    std::cout << operation << std::endl;
    if (operation < 0)
        flag = -2;
    std::cout << flag << std::endl;
    for (int i = 0; i < std::abs(operation); i++)
    {
        dial = (100 + dial + flag) % 100;
        if (dial == 0)
            counter++;
    }
    return counter;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return(1);
    std::string fileName = argv[1];
    std::fstream is;
    is.open(fileName, is.in);
    if (!is.is_open())
        std::cout << "failed to open the file" << std::endl;
    int dial = 50;
    int counter1 = 0;
    int counter2 = 0;
    std::string line;
    while (is >> line)
    {
        int ops = calcOperation(line);
        int hit = hits(dial, ops);
        dial = (100 + dial + ops) % 100;
        if (dial == 0)
            counter1++;
        counter2 += hit;
    }
    std::cout << "Part 1 answer: " + std::to_string(counter1) << std::endl;
    std::cout << "Part 1 answer: " + std::to_string(counter2) << std::endl;
    return (0);
}

