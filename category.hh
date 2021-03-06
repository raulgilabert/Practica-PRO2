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

public:
    Category(string id);

    Category();

    ~Category();

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

    /** @brief Return the points per level
     * \pre true
     * \post Return the points_per_level vector from the implicit parameter */
    vector<int> get_points_per_level();
};

#endif
