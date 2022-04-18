#ifndef SET_CATEGORIES
#define SET_CATEGORIES

#include <vector>

#include "category.hh"

using namespace std;

class Set_categories {
private:
    int num; // Número de categorías
    int levels; // Número de niveles del árbol
    vector<Category> categories; // Vector con las categorías

public:
    Set_categories();

    ~Set_categories();

    /* Pre: the implicit parameter does not include a category with the same
     * identifier as cat */
    /* Post: cat is added to the implicit parameter */
    void add_category(const Category& cat);

    /* Pre: true */
    /* Post: return num from the implicit parameter */
    int num_categories();

    /* Pre: 1 <= category <= num, tournament is a tournament identifier */
    /* Post: added the tournament to the category */
    void add_tournament(int category, string tournament);

    /* Pre: 1 <= category <= num, tournament is a tournament identifier */
    /* Post: deleted the tournament from the category */
    void delete_tournament(int category, string tournament);

    /* Pre: true */
    /* Post: return the categories */
    vector<Category> get_categories();

    /* Pre: two integers (C and K), n categories identifiers and C*K integers
     * in the standard channel */
    /* Post: Added the data to the implicit parameter */
    void read();
};

#endif
