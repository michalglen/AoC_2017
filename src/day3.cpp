#include <iostream>

#include <vector>
#include <cstdlib>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    int end{289326};
 
    int moves_index{0};
    vector<pair<int,int>> moves = {
    {1, 0},
    {0,  1},
    {-1, 0},
    {0,  -1}
};
    int steps{1};
    int steps_count{1};
    pair<int,int> point{0,0};

    while(steps!=end)
    {
        for(auto i = 0;i<steps_count;++i)
        {
            if(steps!=end)
            {
                point.first += moves[moves_index].first;
                point.second += moves[moves_index].second;
                steps++;
            }
            else{break;}
        }
        moves_index =(moves_index+1)% 4;

        for(auto i = 0;i<steps_count;++i)
        {
            if(steps!=end)
            {
                point.first += moves[moves_index].first;
                point.second += moves[moves_index].second;
                steps++;
            }
            else{break;}
        }

        moves_index =(moves_index+1)% 4;
        steps_count++;

    }
    cout << "part 1 solution: " << abs(point.first) + abs(point.second) << endl;


    moves_index=0;
    steps=1;
    steps_count=1;
    point=pair<int,int>(0,0);


    map<pair<int,int>,int> neighbors;
    neighbors.insert(std::make_pair(pair<int,int>(0,0), 1));

auto stuff = [&]()
    {
    point.first += moves[moves_index].first;
    point.second += moves[moves_index].second;

    steps = neighbors[pair<int,int>(point.first-1,point.second+1)] +neighbors[pair<int,int>(point.first,point.second+1)] +neighbors[pair<int,int>(point.first+1,point.second+1)]
            + neighbors[pair<int,int>(point.first-1,point.second)]                                            +neighbors[pair<int,int>(point.first+1,point.second)]
            + neighbors[pair<int,int>(point.first-1,point.second-1)] + neighbors[pair<int,int>(point.first,point.second-1)] + neighbors[pair<int,int>(point.first+1,point.second-1)];

    neighbors[pair<int,int>(point.first,point.second)] = steps;

    };

    while(steps<=end)
    {
        for(auto i = 0;i<steps_count;++i)
        {
            if(steps<=end)
            {
                stuff();
            }
            else{break;}
        }
        moves_index =(moves_index+1)% 4;

        for(auto i = 0;i<steps_count;++i)
        {
            if(steps<=end)
            {
                stuff();
            }
            else{break;}
        }

        moves_index =(moves_index+1)% 4;
        steps_count++;

    }

    cout << "part 2 solution: " <<  steps << endl;

    return 0;
}