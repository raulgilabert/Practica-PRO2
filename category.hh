#ifndef CATEGORY
#define CATEGORY

#include <vector>

class Category {
private:
    std::vector<int> points_per_level; // points won on the category based in
    // the position of result
    string identifier; // name of the category
    std::vector<string> tournaments; // vector of the tournaments in the
    // category
public:
    Category();

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
};

#endif