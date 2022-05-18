/** @file set_players.cc
 * @brief Código de la clase Set_players
 */

#include "set_players.hh"
#include "player.hh"

#include <algorithm>

Set_players::Set_players() {
    num = 0;
}

Set_players::~Set_players() {}

void Set_players::add_player(const string& id) {
    Player p(id, ++num);

    players_data[id] = p;

    ranking.push_back(players_data.find(id));
}

void Set_players::delete_player(const string& id) {
    map<string, Player>::iterator p = players_data.find(id);
    int pos = p->second.get_position();

    int size = ranking.size();

    for (int i = pos; i < size; ++i) {
        ranking[i]->second.decrease_pos();
        ranking[i - 1] = ranking[i];
    }

    ranking.pop_back();
    players_data.erase(p);
    --num;
}

map<string, Player>::iterator Set_players::get_iterator(const string& id) {
    return players_data.find(id);
}

map<string, Player>::iterator Set_players::get_iterator(int pos) {
    return ranking[pos];
}

bool Set_players::player_exists(const string& id) {
    return (players_data.find(id) != players_data.end());
}

void Set_players::read() {
    int n;
    cin >> n;

    // Lee el nombre y añade el jugador
    for (int i = 0; i < n; ++i) {
        string name;
        cin >> name;

        add_player(name);
    }
}

int Set_players::get_num() {
    return num;
}

vector<map<string, Player>::iterator> Set_players::get_ranking() {
    return ranking;
}

void Set_players::print() {
    for (map<string, Player>::const_iterator it = players_data.begin(); it
    != players_data.end(); ++it) {
        it->second.print();
    }
}

void Set_players::modify_points(const string& id, int quantity) {
    map<string, Player>::iterator player = get_iterator(id);

    player->second.modify_points(quantity);
}

void Set_players::recalculate_ranking() {
    // Ordena el ránking
    stable_sort(ranking.begin(), ranking.end(), cmp);

    for (int i = 0; i < num; ++i) {
        ranking[i]->second.set_position(i + 1);
    }
}

bool Set_players::cmp(map<string, Player>::iterator a, map<string,
                             Player>::iterator b) {
    int a_points = a->second.get_points(), b_points = b->second.get_points();

    // En caso de que los puntos sean diferentes devuelve cierto si los del
    // primero son mayores que los del segundo o falso si son menores. En
    // caso de que sean iguales devuelve cierto si la posición del primero es
    // menor que la del segundo o falso al contrario
    if (a_points != b_points)
        return (a_points > b_points);
    return (a->second.get_position() < b->second.get_position());
}

void Set_players::best_player() {
    double best_ratio = 0;
    int player = 0;
    for (int i = 0; i < num; ++i) {
        double ratio = ranking[i]->second.ratio_games();

        if (ratio > best_ratio) {
            best_ratio = ratio;
            player = i;
        }
    }

    cout << ranking[player]->second.get_name() << ' ' << best_ratio << endl;
}