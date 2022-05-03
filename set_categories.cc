#include "set_categories.hh"
#include "category.hh"

#include <iostream>

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

void Set_categories::add_tournament(int category, string tournament) {
    categories[category - 1].add_tournament(tournament);
}

void Set_categories::delete_tournament(int category, string tournament) {
    categories[category - 1].delete_tournament(tournament);

}

vector<Category> Set_categories::get_categories() {
    return categories;
}

void Set_categories::read() {
    int c, k;
    cin >> c >> k;

    levels = k;

    for (int i = 0; i < c; ++i) {
        string name;
        cin >> name;
        Category cat(name);
        add_category(cat);
    }

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
