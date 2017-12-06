#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <algorithm>
#include <iterator>
#include <vector>
#include <set>

using namespace std;

namespace {const bool PART2 = true;}

int solve(vector<string> words, bool part2 = false){

int sum{0};
set<string> lex;

sum += all_of(words.begin(), words.end(),
    [part2,&lex](string word)
        {
            if (part2){sort(word.begin(),word.end());}
            return lex.insert(word).second;        
        });

    return sum;
}

int main(int argc, char const *argv[])
{
    ifstream ifs;
    ifs.open("../inputs/day4.txt");

    istream & is = ifs;

    int sum_part1{0};
    int sum_part2{0};

    for (string line; getline(is, line); ) 
    {
        istringstream iss{line};
        vector<string> const words{istream_iterator<string>{iss}, {}};

        sum_part1 += solve(words);
        sum_part2 += solve(words,PART2);
    }

     ifs.close();
     cout << "part 1 solution: " << sum_part1 << endl;
     cout << "part 2 solution: " << sum_part2 << endl;

    return 0;
}