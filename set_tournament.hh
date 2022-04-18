#ifndef SET_TOURNAMENT
#define SET_TOURNAMENT

#include "tournament.hh"

using namespace std;

class Set_tournament {
private:
    int number;
    map<string, Tournament> tournaments_data;
    vector<string> tournaments;

    /* Pre: true */
    /* Post: tournaments sorted by their name */
    void sort_tournaments();

public:
    Set_tournament();

    ~Set_tournament();

    /* Pre: id a tournament identifier */
    /* Post: tournament added to the implicit parameter */
    void add_tournament(string id);

    /* Pre: id a tournament identifier */
    /* Post: tournament deleted from the implicit parameter */
    void delete_tournament(string id);

    /* Pre: id is a tournament identifier */
    /* Post: true if id in the implicit parameter, false if not */
    bool tournament_exists(string id);

    /* Pre: true */
    /* Post: return number */
    int num_tournaments();

    /* Pre: id is a tournament identifier */
    /* Post: return the tournament requested */
    Tournament get_tournament(string id);

    /* Pre: true */
    /* Post: return the tournaments vector in the implicit parameter */
    vector<string> get_tournaments();

    /* Pre: an integer n and n pairs of string and integer */
    /* Post: added the data to the implicit parameter */
    void read();
};

#endif