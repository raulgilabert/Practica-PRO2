/** @file set_players.hh
 * @brief Specification of the class Set_players.
 */

#ifndef SET_PLAYERS
#define SET_PLAYERS


#ifndef NO_DIAGRAM
#include <map>
#include <vector>
#endif

#include "player.hh"

using namespace std;

/** @class Set_players
 * @brief Represent a set of players
 */
class Set_players {
private:
    int num;
    map<string, Player> players_data;
    vector<string> players;
    vector<string> ranking;

    /** @brief Sort the players
     * \pre true
     * \post Players sorted by their name */
    void sort_players();

public:
    Set_players();

    ~Set_players();

    /** @brief Add the player
     * \pre id is a player identifier
     * \post Player added to the implicit parameter */
    void add_player(string id);

    /** @brief Delete the player
     * \pre id is a player identifier
     * \post Player deleted from the implicit parameter */
    void delete_player(string id);

    /** @brief Add a tournament to all the players
     * \pre Tournament is a tournament id
     * \post Tournament added to all the players in the implicit parameter */
    void add_tournament(string tournament);

    /** @brief Delete a tournament from all the players
     * \pre Tournament is a tournament id
     * \post Tournament deleted from all the players in the implicit
     * parameter */
    void delete_tournament(string tournament);

    /** @brief Return all the players identifiers
     * \pre true
     * \post Return the players in the implicit parameter */
    vector<string> get_players();

    /** @brief Return the ranking with the players identifier
     * \pre true
     * \post Return the ranking in the implicit parameter */
    vector<string> get_ranking();

    /** @brief Recalculate the ranking
     * \pre true
     * \post Ranking in the implicit parameter is recalculated */
    void recalculate_ranking();

    /** @brief Print the players' name
     * \pre true
     * \post Print in the standard channel the players */
    void print_players();

    /** @brief Check if the player exist
     * \pre id is a player identifier
     * \post true if player in the implicit parameter, false if not */
    bool player_exists(string id);

    /** @brief Get a player data with the identifier
     * \pre id is a player identifier
     * \post Return the player requested */
    Player get_player(string id);

    /** @brief Read the players identifier
     * \pre An integer P and P strings
     * \post Players added to the implicit parameter */
    void read();
};

#endif