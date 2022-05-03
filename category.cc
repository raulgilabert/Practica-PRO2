#include "category.hh"
#include <algorithm>

using namespace std;

Category::Category(string id) {
    this->id = id;
    // vector<string> tournaments(0);
}

Category::Category() {}

Category::~Category() {}

void Category::set_points_per_level(int levels) {
    points_per_level = vector<int>(levels);

    for (int i = 0; i < levels; ++i) {
        cin >> points_per_level[i];
    }
}

vector<int> Category::get_points_per_level() {
    return points_per_level;
}

string Category::get_name() const {
    return id;
}

string Category::get_name() {
    return id;
}
