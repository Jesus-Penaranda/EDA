#include<iostream>
#include<map>

using namespace std;

int main() 
{
    map<string, int> players;
    string player;
    
    while(cin >> player) 
    {
        string ins;
        cin >> ins;

        if(ins == "enters") 
        {
            if(players.find(player) != players.end()) 
                cout << player << " is already in the casino" << endl;
            else 
            {
                players[player];
            }
        }
        else if (ins == "leaves") 
        {
            if(players.find(player) == players.end()) 
                cout << player << " is not in the casino" << endl;
            else 
            {
                cout << player << " has won " << players[player] << endl;
                players.erase(player);
            }
        }
        else if (ins == "wins") 
        {
            int money;
            cin >> money;
            if(players.find(player) == players.end()) 
                cout << player << " is not in the casino" << endl;
            else 
            {
                players[player] += money; 
            }
        }
    }
    cout << "----------" << endl;
    for (auto dinero: players) cout << dinero.first << " is winning " << dinero.second << endl;
    
}