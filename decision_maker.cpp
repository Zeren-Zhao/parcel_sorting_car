#include <list>
#include <cstdio>
#include <string>
using namespace std;

class decision_maker
{
private:
    /* data */
    int current_pos[2], goal_pos[2];
    list<string> route = {};
public:
    decision_maker(int car_pos[2], int goal_loc[2]){
        for (int i = 0; i < 2; i++) {
            current_pos[i] = car_pos[i];
            goal_pos[i] = goal_pos[i];
        }
    };

    list<string> path_planing(){

        int x_dis, y_dis;

        route = {};
        x_dis = goal_pos[0] - current_pos[0];
        y_dis = goal_pos[1] - current_pos[1];

        if (y_dis > 0){
            route.push_back("front");
        }
        printf("%s", route);

        return route;

    };
};

int main(){
    int car[2], goal[2];
    car[0] = 0;
    car[1] = 0;
    goal[0] = 1;
    goal[1] = 1;
    decision_maker try_1(car, goal);

    try_1.path_planing();
    return 0;
    
}