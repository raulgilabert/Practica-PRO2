#ifndef CJT_CATEGORIES
#define CJT_CATEGORIES

#include <vector>

#include "category.hh"

class Cjt_categories {
private:
    int num; // Número de categorías
    int levels; // Número de niveles del árbol
    std::vector<Category> categories; // Vector con las categorías

public:
    Cjt_categories();

    ~Cjt_categories();

    /* Pre: the implicit parameter does not include a category with the same
     * identifier as cat */
    /* Post: cat is added to the implicit parameter */
    void add_category(const Category& cat);

    /* Pre: true */
    /* Post: print in the standard channel all the categories */
    void print_categories();
};

#endif
