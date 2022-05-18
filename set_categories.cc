/** @file set_categories.cc
 * @brief Código de la clase Set_categories
 */

#include "set_categories.hh"
#include "category.hh"

Set_categories::Set_categories() {
    num = levels = 0;
}

Set_categories::~Set_categories() {}

void Set_categories::add_category(const Category &cat) {
    categories.push_back(cat);
    ++num;
}

int Set_categories::num_categories() {
    return num;
}

vector<Category> Set_categories::get_categories() {
    return categories;
}

void Set_categories::read() {
    int c, k;
    cin >> c >> k;

    levels = k;

    // Crea las categorías con el nombre y las añade al conjunto
    for (int i = 0; i < c; ++i) {
        string name;
        cin >> name;
        Category cat(name);
        add_category(cat);
    }

    // Añade los puntos por nivel a cada categoría
    for (int i = 0; i < c; ++i) {
	    categories[i].set_points_per_level(k);
    }
}

int Set_categories::get_levels() {
    return levels;
}

string Set_categories::get_name(int pos) const {
    return categories[pos - 1].get_name();
}

int Set_categories::points_level(int cat, int lvl) {
    return categories[cat - 1].get_points_per_level()[lvl];
}
