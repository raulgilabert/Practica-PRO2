/** @file set_tournament.hh
 * @brief Specification of the class Set_tournament.
 */

#ifndef SET_TOURNAMENT
#define SET_TOURNAMENT

#include "tournament.hh"

using namespace std;

/** @class Set_tournament
 * @brief Represents a set of tournaments
 */
class Set_tournament {
private:
    int number;
    map<string, Tournament> tournaments_data;
    vector<string> tournaments;

    /** @brief Sort the tournaments by their name
     * \pre true
     * \post tournaments sorted by their name */
    void sort_tournaments();

public:
    Set_tournament();

    ~Set_tournament();

    /** @brief Add a tournament
     * \pre id a tournament identifier
     * \post Tournament added to the implicit parameter */
    void add_tournament(string id);

    /** @brief Delete a tournament
     * \pre id a tournament identifier
     * \post Tournament deleted from the implicit parameter */
    void delete_tournament(string id);

    /** @brief Check if the tournament exists
     * \pre id is a tournament identifier
     * \post True if id in the implicit parameter, false if not */
    bool tournament_exists(string id);

    /** @brief Return the number of tournaments
     * \pre true
     * \post Return number */
    int num_tournaments();

    /** @brief Return the tournament requested
     * \pre id is a tournament identifier
     * \post Return the tournament requested */
    Tournament get_tournament(string id);

    /** @brief Return all the tournaments identifiers
     * \pre true
     * \post Return the tournaments vector in the implicit parameter */
    vector<string> get_tournaments();

    /** @brief Read the tournaments
     * \pre An integer n and n pairs of string and integer
     * \post Added the data to the implicit parameter */
    void read();
};

#endif