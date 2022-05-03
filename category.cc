#include "category.hh"
#include <algorithm>

using namespace std;

int Category::search(int left, int right, string to_search) {
    if (left > right)
        return -1;

    int mid = (left + right)/2;
    if (tournaments[mid] < to_search)
        return search(mid + 1, right, to_search);

    if (tournaments[mid] > to_search)
        return search(left, mid - 1, to_search);

    return mid;
}

Category::Category(string id) {
    this->id = id;
    // vector<string> tournaments(0);
}

Category::Category() {}

Category::~Category() {}

bool Category::cmp(string a, string b) {
    return a > b;
}

void Category::add_tournament(string id) {
    tournaments.push_back(id);
    sort(tournaments.begin(), tournaments.end(), cmp);
}

void Category::delete_tournament(string id) {
    int pos = search(0, tournaments.size() - 1, id);

    vector<string> new_tournaments(tournaments.size() - 1);
    for (int i = 0; i < pos; ++i) {
        new_tournaments[i] = tournaments[i];
    }

    int tournaments_size = tournaments.size();
    for (int i = pos + 1; i < tournaments_size; ++i) {
        new_tournaments[i - 1] = tournaments[i];
    }

    tournaments = new_tournaments;
}

void Category::set_points_per_level(int levels) {
    points_per_level = vector<int>(levels);

    for (int i = 0; i < levels; ++i) {
        cin >> points_per_level[i];
    }
}

vector<int> Category::get_points_per_level() {
    return points_per_level;
}

vector<string> Category::get() {
    return tournaments;
}

string Category::get_name() const {
    return id;
}

string Category::get_name() {
    return id;
}
