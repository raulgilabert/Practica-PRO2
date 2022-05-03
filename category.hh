/** @file category.hh
 * @brief Specification of the class Category.
 */

#ifndef CATEGORY
#define CATEGORY

#ifndef NO_DIAGRAM
#include <vector>
#include <iostream>
#endif

using namespace std;

/** @class Category
 * @brief Represents a category */
class Category {
private:
    vector<int> points_per_level; // points won on the category based in
    // the position of result
    string id; // name of the category
    vector<string> tournaments; // vector of the tournaments in the
    // category

    /** @brief Search a tournament returning the position in the vector
     * \pre  0 <= left <= tournaments.size(), 0 <= right <= tournaments.size(),
     * search is a valid string, tournaments in the implicit parameter is
     * sorted in alphabetic order
     * \post return -1 if string not in tournaments, if not return the
     * position in tournaments of search */
    int search(int left, int right, string to_search);

    /** @brief comparator for sorting
     * \pre a and b are valid strings
     * \post true if a is higher than b, false if not */
    static bool cmp(string a, string b);
public:
    Category(string id);

    Category();

    ~Category();

    /** @brief Add tournament to category
     * \pre id is a tournament id
     * \post id is added to the implicit parameter */
    void add_tournament(string id);

    /** @brief Delete tournament from category
     * \pre id is a tournament id
     * \post id is deleted from the implicit parameter */
    void delete_tournament(string id);

    /** @brief Set the points per level of the category
     * \pre Levels >= 1, levels integers in the standard channel
     * \post Added the inputted elements to the implicit parameter */
    void set_points_per_level(int levels);

    /** @brief Return the name of the category
     * \pre true
     * \post Return the id from the implicit parameter */
    string get_name() const;

    /** @brief Return the name of the category
     * \pre true
     * \post Return the id from the implicit parameter */
    string get_name();


    vector<string> get();

    /** @brief Return the points per level
     * \pre true
     * \post Return the points_per_level vector from the implicit parameter */
    vector<int> get_points_per_level();
};

#endif
