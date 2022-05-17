#include "set_tournament.hh"
#include "tournament.hh"

#include <iostream>

Set_tournament::Set_tournament() {
    num = 0;
}

Set_tournament::~Set_tournament() {}

void Set_tournament::add_tournament(const string& id, int category) {
    Tournament tournament(id, category);
    tournaments[id] = tournament;
    
    ++num;
}

bool Set_tournament::tournament_exists(const string& id) {
    return (tournaments.find(id) != tournaments.end());
}

map<string, Tournament>::iterator Set_tournament::get_tournament(const 
	string& id) {
    return tournaments.find(id);
}

void Set_tournament::delete_tournament(const string& id) {
    tournaments.erase(id);
    --num;
}

int Set_tournament::num_tournaments() {
    return num;
}

void Set_tournament::read() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
	string name;
	int cat;
	cin >> name >> cat;

	add_tournament(name, cat);
    }
}

void Set_tournament::print(const Set_categories& cat) {
    for (map<string, Tournament>::const_iterator it = tournaments.begin(); 
	    it != tournaments.end(); ++it) {
        it->second.print(cat);
        cout << endl;
    }
}

void Set_tournament::delete_player(const string& id) {
    for (map<string, Tournament>::iterator it = tournaments.begin();
	    it != tournaments.end(); ++it) {
        it->second.delete_player(id);
    }
}
