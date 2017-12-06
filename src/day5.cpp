#include <iostream>
#include <fstream>

#include <iterator>
#include <vector>

using namespace std;

namespace {const bool PART2 = true;}

int solve(vector<int> commands, bool part2 = false)
{
    int steps{0};
    int index{0};
    int size = commands.size();    
    while(0<=index && index < size)
    {
        steps++;
        if(part2 && commands[index]>=3)
        {
                index += commands[index]--;
        }
        else
        {
            index += commands[index]++;
        }
    }
    return steps;
}

int main(int argc, char const *argv[])
{
    ifstream ifs;
    ifs.open("../inputs/day5.txt");

    istream & is = ifs;

    vector<int> commands{istream_iterator<int>{is}, {}};

    ifs.close();
    cout << "part 1 solution: " << solve(commands) << endl;
    cout << "part 2 solution: " << solve(commands,PART2) << endl;

    return 0;
}