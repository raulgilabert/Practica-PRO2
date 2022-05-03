#include "player.hh"

#include <iostream>

Player::Player(string id, int pos) {
    name = id;

    tournaments_played = matches_won = matches_lost = sets_won = sets_lost = games_won = games_lost = points = 0;

    ranking = pos;
}

Player::Player() {}

Player::~Player() {
}

void Player::add_tournament(string id) {
    points_per_tournament[id] = 0;
}

void Player::delete_tournament(string id) {
    points_per_tournament.erase(id);
}

int Player::get_points() {
    return points;
}

int Player::get_position() {
    return ranking;
}

// Se puede hacer más eficiente recalculando los puntos eliminando únicamente
// al acabar un torneo los puntos que están guardados en el vector del total y
// sumando la nueva puntuación del torneo

void Player::calc_points() {
    points = 0;
    for (map<string, int>::iterator it = points_per_tournament.begin();
	    it != points_per_tournament.end(); ++it) {
	points += it->second;
    }
}

void Player::update_data(int matches_won, int matches_lost, int sets_won,
	int sets_lost, int games_won, int games_lost) {
    this->tournaments_played += 1;

    this->matches_won += matches_won;
    this->matches_lost += matches_lost;

    this->sets_won += sets_won;
    this->sets_lost += sets_lost;
    this->games_won += games_won;
    this->games_lost += games_lost; 
}

string Player::get_name() {
    return name;
}

void Player::print() const {
    cout << name;
    cout << " Rk:" << ranking;
    cout << " Ps:" << points;
    cout << " Ts:" << tournaments_played;
    cout << " WM:" << matches_won << " LM:" << matches_lost;
    cout << " WS:" << sets_won << " LS:" << sets_lost;
    cout << " WG:" << games_won << " LG:" << games_lost << endl;
}

void Player::decrease_pos() {
    --ranking;
}