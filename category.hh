#ifndef CATEGORY
#define CATEGORY

#include <vector>

#include "tournament.hh"

using namespace std;

class Category {
private:
    vector<int> points_per_level; // points won on the category based in
    // the position of result
    string id; // name of the category
    vector<string> tournaments; // vector of the tournaments in the
    // category

public:
    Category(string id);

    ~Category();

    /* Pre: id is a tournament id */
    /* Post: id is added to the implicit parameter */
    void add_tournament(string id);

    /* Pre: id is a tournament id */
    /* Post: id is deleted from the implicit parameter */
    void delete_tournament(string id);

    /* Pre: levels >= 1, levels integers in the standard channel */
    /* Post: added the inputted elements to the implicit parameter */
    void set_points_per_level(int levels);

    /* Pre: true */
    /* Post return the id from the implicit parameter */
    string get_name();

    /* Pre: true */
    /* Post: return the points_per_level vector from the implicit parameter */
    vector<int> get_points_per_level();
};

#endif