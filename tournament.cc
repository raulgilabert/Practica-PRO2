#include "tournament.hh"
#include "BinTree.hh"

#include <iostream>

Tournament::Tournament(const string& id, int category) {
    this->id = id;
    this->category = category;
    this->num_registered = 0;
    this->height = vector<int>(0);
    this->last_tournament = vector<last_played>(0);
    this->players = vector<map<string, Player>::iterator>(0);
}

Tournament::Tournament() {
    num_registered = 0;
    height = vector<int>(0);
    last_tournament = vector<last_played>(0);
    players = vector<map<string, Player>::iterator>(0);
}

Tournament::~Tournament() {}

void Tournament::add_player(map<string, Player>::iterator player) {
    players.push_back(player);
}

int Tournament::get_category() const {
    return category;
}

void Tournament::get_results(BinTree<element>& a) {
    string result;
    cin >> result;

    if (result != "0") {
	element elem = a.value();

	elem.points = result;

	BinTree<element> left = a.left(), right = a.right();

	get_results(left);
	get_results(right);
	

	a = BinTree<element>(elem, left, right);
    }
}

void Tournament::get_results_i() {
    get_results(matches);
}

void Tournament::print_results() {

}

int Tournament::get_winner(int a, int b, const string& matches, int height,
	int& num) {
    ++num;
    int size = matches.size();
    if (size == 3) {
	if (matches[0] == '1') {
        this->last_tournament[b - 1].points = -height;
        this->last_tournament[b - 1].player = players[b - 1]->second.get_name();
        players[a - 1]->second.update_data(true, 0, 0, 0, 0);
        players[b - 1]->second.update_data(false, 0, 0, 0, 0);
        return a;
    }
    this->last_tournament[a - 1].points = -height;
    this->last_tournament[a - 1].player = players[a - 1]->second.get_name();
    players[a - 1]->second.update_data(false, 0, 0, 0, 0);
    players[b - 1]->second.update_data(true, 0, 0, 0, 0);
    return b;
}

    int win_a = 0, win_b = 0, a_points = 0, b_points = 0, a_games = 0,
	b_games = 0;

    for (int i = 0; i < size/4 + 1; ++i) {
	++a_games;
	++b_games;

	a_points += matches[i*4] - '0';
	b_points += matches[i*4 + 2] - '0';

	if (matches[i*4] > matches[i*4 + 2])
	    ++win_a;
	else
	    ++win_b;
    }

    bool a_won = (win_a > win_b);

    players[a - 1]->second.update_data(a_won, win_a, win_b, a_points, 
	    b_points);

    players[b - 1]->second.update_data(not a_won, win_b, win_a, b_points, 
	    a_points);

    if (a_won) {

        this->last_tournament[b - 1].points = -height;
        this->last_tournament[b - 1].player = players[b - 1]->second.get_name();
        return a;
    }
    this->last_tournament[a - 1].points = -height;
    this->last_tournament[a - 1].player = players[a - 1]->second.get_name();
    return b;
}

int Tournament::calc_winners(BinTree<element>& a, int height, int& pos) {
    if (a.empty()) {
	return 0;
    }

    BinTree<element> left = a.left(), right = a.right();

    int left_w = calc_winners(left, --height, pos),
	right_w = calc_winners(right, height, pos);

    if (left_w == 0) {
	if (right_w == 0) {
	    return a.value().player;
	}
	return right_w;
    }

    element elem = a.value();

    elem.left = left_w;
    elem.right = right_w;

    a = BinTree<element>(elem, left, right);

    return get_winner(left_w, right_w, a.value().points, height, pos);
}

int Tournament::calc_winners_i() {
    last_tournament = vector<last_played>(num_registered);

    int pos = -1;
    int winner = calc_winners(matches, 0, pos);

    last_tournament[winner - 1].player = players[winner - 1]->
	second.get_name();
    last_tournament[winner - 1].points = 0;

    return winner;
}


void Tournament::print_tree(const BinTree<element>& a) {
    if (not a.left().empty()) {
	cout << '(';
	cout << a.value().left << '.' << 
	    players[a.value().left - 1]->second.get_name() << " vs " << 
	    a.value().right << '.' << 
	    players[a.value().right - 1]->second.get_name() << ' ' <<
	    a.value().points;

	print_tree(a.left());
	print_tree(a.right());
	cout << ')';
    }
}


void Tournament::print_tree_i() {
    print_tree(matches);
    cout << endl;
}


void Tournament::print(const Set_categories& cat) const {
    cout << id << ' ' << cat.get_name(category);
}

BinTree<element> Tournament::inscriptions_t(int nodes, int n, int pos) {
    element elem;
    elem.player = pos;

    if (n <= nodes) {
        cout << pos << '.' << players[pos - 1]->second.get_name();
        return BinTree<element>(elem);
    }

    nodes *= 2;
    if ((nodes > n) and (nodes - n >= pos)) {
        cout << pos << '.' << players[pos - 1]->second.get_name();
        return BinTree<element>(elem);
    }
    BinTree<element> left, right;
    cout << '(';
    left = inscriptions_t(nodes, n, pos);
    cout << ' ';
    right = inscriptions_t(nodes, n, nodes + 1 - pos);
    cout << ')';
    return BinTree<element>(elem, left, right);
}

void Tournament::inscriptions(int n) {
    num_registered = n;

    matches = inscriptions_t(1, n, 1);
    cout << endl;
}

vector<last_played> Tournament::last_tournament_played() {
    return last_tournament;
}

vector<int> Tournament::get_heights() {
    return height;
}

void Tournament::clear() {
    num_registered = 0;
    players = vector<map<string, Player>::iterator>(0);
    height = vector<int>(0);
}

void Tournament::delete_player(const string& id) {
    bool found = false;
    int last_tournament_size = last_tournament.size();
    for (int i = 0; i < num_registered and last_tournament_size > 0; ++i) {
        if (last_tournament[i].player == id) {
            found = true;
        }

        if (found) {
            if (i < num_registered - 1)
                last_tournament[i] = last_tournament[i + 1];
            else
                last_tournament.pop_back();
        }
    }
    if (found)
        --num_registered;
}

void Tournament::print_players() {
    int counter = 0;
    for (int i = 0; i < num_registered; ++i) {
        if (last_tournament[i].points != 0) {
            ++counter;
            cout << counter << '.' << last_tournament[i].player << ' ' <<
            last_tournament[i].points << endl;
        }
    }
}