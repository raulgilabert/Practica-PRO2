#ifndef PLAYER
#define PLAYER

#include <map>

using namespace std;

class Player {
private:
    string name;

    int tournaments_played;
    int tournaments_won;
    int tournaments_lost;
    int sets_won;
    int sets_lost;
    int games_won;
    int games_lost;

    int points;
    map<string, int> points_per_tournament;

    int ranking_position;

public:
    Player(string name);

    ~Player();

    /* Pre: id is a tournament id */
    /* Post: added key id to the map in the implicit parameter */
    void add_tournament(string id);

    /* Pre: id is a tournament id */
    /* Post: removed key id from the map in the implicit parameter */
    void delete_tournament(string id);

    /* Pre: true */
    /* Post: return points from the implicit parameter */
    int get_points();

    /* Pre: true */
    /* Post: the points in the implicit parameter are recalculated */
    void calc_points();

    /* Pre: tournament_won is true if the tournament is won by the player,
     * sets_won >= 0, sets_lost >= 0, games_won >= 0, games_lost >= 0 */
    /* Post: The data in the implicit parameter is updated */
    void update_data(bool tournament_won, int sets_won, int sets_lost, int
    games_won, int games_lost);

    /* Pre: true */
    /* Post: prints in the standard channel the name, the position in the
     * ranking, the points and all the data about tournaments, sets and games */
    void print();
};


#endif