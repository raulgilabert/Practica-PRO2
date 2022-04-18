#ifndef SET_PLAYERS
#define SET_PLAYERS

#include <map>
#include <vector>
#include "player.hh"

using namespace std;

class Set_players {
private:
    int num;
    map<string, Player> players_data;
    vector<string> players;
    vector<string> ranking;

    /* Pre: true */
    /* Post: players sorted by their name */
    void sort_players();

public:
    Set_players();

    ~Set_players();

    /* Pre: id is a player identifier */
    /* Post: player added to the implicit parameter */
    void add_player(string id);

    /* Pre: id is a player identifier */
    /* Post: player deleted from the implicit parameter */
    void delete_player(string id);

    /* Pre: tournament is a tournament id */
    /* Post: tournament added to all the players in the implicit parameter */
    void add_tournament(string tournament);

    /* Pre: tournament is a tournament id */
    /* Post: tournament deleted from all the players in the implicit
     * parameter */
    void delete_tournament(string tournament);

    /* Pre: true */
    /*Post: return the players in the implicit parameter */
    vector<string> get_players();

    /* Pre: true */
    /*Post: return the ranking in the implicit parameter */
    vector<string> get_ranking();

    /* Pre: true */
    /* Post: ranking in the implicit parameter is recalculated */
    void recalculate_ranking();

    /* Pre: true */
    /* Post: print in the standard channel the players */
    void print_players();

    /* Pre: id is a player identifier */
    /* Post: true if player in the implicit parameter, false if not */
    bool player_exists(string id);

    /* Pre: id is a player identifier */
    /* Post: return the player requested */
    Player get_player(string id);

    /* Pre: an integer P and P strings */
    /* Post: players added to the implicit parameter */
    void read();
};

#endif