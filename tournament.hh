/** @file tournament.hh
 * @brief Specification of the class Tournament.
 */

#ifndef TOURNAMENT
#define TOURNAMENT

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#endif

#include "player.hh"
#include "set_players.hh"

using namespace std;

/** @class Tournament
 * @brief Represents a tournament. */
class Tournament {
private:
    string id;
    int num_registered;
    vector<Player> players;
    int category;
    BinTree<string> matches;

    /** @brief Return the result of the tournament
     * \pre true
     * \post Returned a binary tree of strings with the positions of the
     * players */
    BinTree<string> result_tournament();

public:
    Tournament(string id, int category);

    ~Tournament();

    /** @brief Add the player to the tournament
     * \pre player is a valid player not included in the implicit parameter
     * \post Added player to the implicit parameter */
    void add_player(Player player);

    /** @brief Get the number of the category of the tournament
     * \pre true
     * \post Return category from the implicit parameter */
    int get_category() const;

    /** @brief En the tournament
     * \pre Players is a set of players
     * \post The tournament is ended, updating the matches' tree showing the
     * results of the matches and modifying the players data */
    void end_tournament(Set_players& players);

    /** @brief Print the results of the tournament
     * \pre true
     * \post The results are printed in the standard channel */
    void print_results();
};

#endif