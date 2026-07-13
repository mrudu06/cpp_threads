#include <iostream>
#include <vector>
using namespace std;


class Games{
    private:
        string player;
        int level;

    public:
        Games(string name,int level) : player(name) , level(level) {}

        string getName() const { return player;}
        int getLevel() const {return level;}
};

int main() {

    vector <Games> game0bjects;
    game0bjects.push_back(Games("meeraaj",10));
    game0bjects.push_back(Games("mrudu",5));

    for(const auto& game : game0bjects){
        cout << "Name" << game.getName() << endl;
        cout << "level" << game.getLevel() << endl;
    }

    return 0;
}