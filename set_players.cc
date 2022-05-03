#include "set_players.hh"
#include "player.hh"

#include <iostream>

Set_players::Set_players() {
    num = 0;
}

Set_players::~Set_players() {}

void Set_players::add_player(string id) {
    Player p(id, ++num);

    players_data[id] = p;

    ranking.push_back(players_data.find(id));
}

void Set_players::delete_player(string id) {
    map<string, Player>::iterator p = players_data.find(id);
    int pos = p->second.get_position();

    int size = ranking.size() - 1;

    vector<map<string, Player>::iterator> new_ranking(size);

    int i;

    for (i = 0; i < pos - 1; ++i) {
        new_ranking[i] = ranking[i];
    }

    for (i = pos; i < size + 1; ++i) {
        new_ranking[i - 1] = ranking[i];
        ranking[i]->second.decrease_pos();
    }

    ranking = new_ranking;

    players_data.erase(p);
    --num;
}

map<string, Player>::iterator Set_players::get_iterator(string id) {
    return players_data.find(id);
}

map<string, Player>::iterator Set_players::get_iterator(int pos) {
    return ranking[pos];
}


map<string, Player> Set_players::get_players() {
    return players_data;
}

bool Set_players::player_exists(string id) {
    return (players_data.find(id) != players_data.end());
}

void Set_players::add_tournament(string tournament) {
    for (map<string, Player>::iterator it = players_data.begin();
	    it != players_data.end(); ++it) {
        it->second.add_tournament(tournament);
    }
}

void Set_players::delete_tournament(string id) {
    for (map<string, Player>::iterator it = players_data.begin(); it != 
	    players_data.end(); ++it) {
        it->second.delete_tournament(id);
    }
}

void Set_players::read() {
    int n;
    cin >> n;

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
    for (map<string, Player>::const_iterator it = players_data.begin(); it != players_data.end(); ++it) {
        it->second.print();
    }
}