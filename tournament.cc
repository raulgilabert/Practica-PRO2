#include "tournament.hh"

#include <iostream>

Tournament::Tournament(string id, int category) {
    this->id = id;
    this->category = category;
}

Tournament::Tournament() {}

Tournament::~Tournament() {}

void Tournament::add_player(map<string, Player>::iterator player) {
    players.push_back(player);
}

int Tournament::get_category() const {
    return category;
}



/*
void Tournament::end_tournament(Set_players &players) {

}
*/

void Tournament::print_results() {

}


void Tournament::print(const Set_categories& cat) const {
    cout << id << ' ' << cat.get_name(category);
}

BinTree<int> Tournament::inscriptions_t(int nodes, int n, int pos) {
    if (n <= nodes) {
        cout << pos << '.' << players[pos - 1]->second.get_name();
        return BinTree<int>(pos);
    }

    nodes *= 2;
    if ((nodes > n) and (nodes - n >= pos)) {
        cout << pos << '.' << players[pos - 1]->second.get_name();
        return BinTree<int>(pos);
    }
    BinTree<int> left, right;
    cout << '(';
    left = inscriptions_t(nodes, n, pos);
    cout << ' ';
    right = inscriptions_t(nodes, n, nodes + 1 - pos);
    cout << ')';
    return BinTree<int>(pos, left, right);
}

void Tournament::inscriptions(int n) {
    matches = inscriptions_t(1, n, 1);
    cout << endl;
}