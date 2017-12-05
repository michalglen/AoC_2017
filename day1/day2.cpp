#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream ifs;
    ifs.open("day2.txt");

    istream & is = ifs;

    int sum_part1{0};
    int sum_part2{0};

    for (string line; getline(is, line); ) {
    istringstream iss{line};
    vector<int> const nums{istream_iterator<int>{iss}, {}};

    for (auto v1 : nums) {
        for (auto v2 : nums) {
          if (v1 != v2 && v1 % v2 == 0) 
            {
                sum_part2 += v1 / v2;
            }
        }
    }   

    auto result = minmax_element(begin(nums), end(nums));
    sum_part1 += *result.second - *result.first;

    }
    ifs.close();
    cout << "part 1 solution: " << sum_part1 << endl;
    cout << "part 2 solution: " << sum_part2 << endl;

    return 0;
}