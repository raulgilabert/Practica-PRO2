/** @file set_tournament.hh
 * @brief Specification of the class Set_tournament.
 */

#ifndef SET_TOURNAMENT
#define SET_TOURNAMENT

#include "tournament.hh"
#include "set_categories.hh"

using namespace std;

/** @class Set_tournament
 * @brief Represents a set of tournaments
 */
class Set_tournament {
private:
    int num;
    map<string, Tournament> tournaments;

public:
    Set_tournament();

    ~Set_tournament();

    /** @brief Add a tournament
     * \pre id a tournament identifier, 0 <= category <= C
     * \post Tournament added to the implicit parameter */
    void add_tournament(const string& id, int category);

    /** @brief Delete a tournament
     * \pre id a tournament identifier
     * \post Tournament deleted from the implicit parameter */
    void delete_tournament(const string& id);

    /** @brief Check if the tournament exists
     * \pre id is a tournament identifier
     * \post True if id in the implicit parameter, false if not */
    bool tournament_exists(const string& id);

    /** @brief Return the number of tournaments
     * \pre true
     * \post Return number */
    int num_tournaments();

    /** @brief Return the tournament requested
     * \pre id is a tournament identifier
     * \post Return the tournament requested */
    map<string, Tournament>::iterator get_tournament(const string& id);

    /** @brief Return all the tournaments identifiers
     * \pre true
     * \post Return the tournaments vector in the implicit parameter */
    vector<string> get_tournaments();

    /** @brief Read the tournaments
     * \pre An integer n and n pairs of string and integer
     * \post Added the data to the implicit parameter */
    void read();

    /** @brief Print the data of all the tournaments
     * \pre true
     * \post printed the data of the tournaments on the standard channel */
    void print(const Set_categories& cat);

    void delete_player(const string& id);
};

#endif
