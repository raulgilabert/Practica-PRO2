#ifndef TOURNAMENT
#define TOURNAMENT

#include "BinTree.hh"

#include "player.hh"
#include "set_players.hh"

using namespace std;

class Tournament {
private:
    string id;
    int num_registered;
    vector<Player> players;
    int category;
    BinTree<string> matches;

    /* Pre: true */
    /* Post: returned a binary tree of strings with the positions of the
     * players */
    BinTree<string> result_tournament();

public:
    Tournament(string id, int category);

    ~Tournament();

    /* Pre: player is a valid player not included in the implicit parameter */
    /* Post: added player to the implicit parameter */
    void add_player(Player player);

    /* Pre: true */
    /* Post: return category from the implicit parameter */
    int get_category() const;

    /* Pre: players is a set of players */
    /* Post: the tournament is ended, updating the matches' tree showing the
     * results of the matches and modifying the players data */
    void end_tournament(Set_players& players);

    /* Pre: true */
    /* Post: the results are printed in the standard channel */
    void print_results();

    /*
    * Pre: 1 <= category <= C *
    * Post: category is set in the implicit parameter *
    void set_category(int category);
*/
};

#endif