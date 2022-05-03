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
#include "set_categories.hh"

using namespace std;

/** @class Tournament
 * @brief Represents a tournament. */
class Tournament {
private:
    string id;
    int num_registered;
    vector<map<string, Player>::iterator> players;
    int category;
    BinTree<int> matches;

    /** @brief Return the result of the tournament
     * \pre true
     * \post Returned a binary tree of strings with the positions of the
     * players */
    BinTree<string> result_tournament();

public:
    Tournament(string id, int category);

    Tournament();

    ~Tournament();

    /** @brief Add the player to the tournament
     * \pre player is a valid player not included in the implicit parameter
     * \post Added player to the implicit parameter */
    void add_player(map<string, Player>::iterator player);

    void create_matches();

    /** @brief Get the number of the category of the tournament
     * \pre true
     * \post Return category from the implicit parameter */
    int get_category() const;


    /** @brief Generate the BinTree of matches
     * \pre 0 < nodes <= 2^(k-1), 8 <= n <= 2^(k-1), 0 < pos <= 2^(k-1)
     * \post returned the binary tree of matches
     */
    BinTree<int> inscriptions_t(int nodes, int n, int pos);

    /** @brief Call to generate the matches tree with the players data
     * \pre 8 <= n <= 2^(k-1)
     * \post BinTree of matches creates
     */
    void inscriptions(int n);


    /** @brief En the tournament
     * \pre Players is a set of players
     * \post The tournament is ended, updating the matches' tree showing the
     * results of the matches and modifying the players data */
    void end_tournament(Set_players& players);

    /** @brief Print the results of the tournament
     * \pre true
     * \post The results are printed in the standard channel */
    void print_results();

    /** @brief Print the name and the category of the tournament
     * \pre true
     * \post print in the standard channel id and category from the implicit paramenter */ 
    void print(const Set_categories& cat) const;
};

#endif
