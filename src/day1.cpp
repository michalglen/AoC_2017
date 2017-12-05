#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

template<typename V, typename F, typename... P>
void testEQ(V v, F f, P&& ... p){
    if (v == f(p...))
    {
        cout << "\033[1;32mPASSED\033[0m" << endl;
    }
    else {
        cout << "\033[1;31mFAILED\033[0m" << endl;
    }
}

string get_file_2string(const string & path){
    ifstream inFile;
    inFile.open(path);

    stringstream strStream;
    strStream << inFile.rdbuf();
    inFile.close();

    return strStream.str();
}


int solution(const string & s, int offset)
{
    int sum{0};
    std::size_t const N{s.size()};

    for(uint it = 0; it != N; ++it)
    {
        if(s[it] == s[(it+offset) % N])
        {
            sum +=s[it] - '0';
        }
    }

    return sum;
}

int part2(const string & s)
{
    return solution(s,s.size()/2);
}

int part1(const string & s)
{
    return solution(s,1);
}

int main(int argc, char const *argv[])
{
    auto str = get_file_2string("../inputs/day1.txt");

    testEQ(3,part1,"1122");
    testEQ(4,part1,"1111");
    testEQ(0,part1,"1234");
    testEQ(9,part1,"91212129");

    testEQ(3,part1,"331");
    testEQ(5,part1,"12345567890");

    testEQ(6,part2,"1212");
    testEQ(0,part2,"1221");
    testEQ(12,part2,"123123");
    testEQ(4,part2,"12131415");


    cout << "part 1 solution: " << part1(str) << endl;
    cout << "part 2 solution: "<< part2(str) << endl;

    return 0;
}