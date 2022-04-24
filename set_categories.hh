/** @file set_categories.hh
 * @brief Specification of the class Set_categories
 */

#ifndef SET_CATEGORIES
#define SET_CATEGORIES

#ifndef NO_DIAGRAM
#include <vector>
#endif

#include "category.hh"

using namespace std;

/** @class Set_categories
 * @brief Represent a set of categories
 */
class Set_categories {
private:
    int num; // Número de categorías
    int levels; // Número de niveles del árbol
    vector<Category> categories; // Vector con las categorías

public:
    Set_categories();

    ~Set_categories();

    /** @brief Add a category
     * \pre The implicit parameter does not include a category with the same
     * identifier as cat
     * \post cat is added to the implicit parameter */
    void add_category(const Category& cat);

    /** @brief Get the quantity of categories
     * \pre true
     * \post Return num from the implicit parameter */
    int num_categories();

    /** @brief Add a tournament to a category
     * \pre 1 <= category <= num, tournament is a tournament identifier
     * \post Added the tournament to the category */
    void add_tournament(int category, string tournament);

    /** @brief Delete a tournament from a category
     * \pre 1 <= category <= num, tournament is a tournament identifier
     * \post Deleted the tournament from the category */
    void delete_tournament(int category, string tournament);

    /** Get all the categories data
     * \pre true
     * \post Return the categories */
    vector<Category> get_categories();

    /** @brief Read the categories data
     * \pre Two integers (C and K), n categories identifiers and C*K integers
     * in the standard channel
     * \post Added the data to the implicit parameter */
    void read();
};

#endif
