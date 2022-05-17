#include "player.hh"

#include <iostream>

Player::Player(const string& id, int pos) {
    name = id;

    tournaments_played = matches_won = matches_lost = sets_won = sets_lost =
            games_won = games_lost = points = 0;

    ranking = pos;
}

Player::Player() {}

Player::~Player() {
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


void Player::update_data(bool won, int sets_won,
	int sets_lost, int games_won, int games_lost) {
/*    this->tournaments_played += 1;

    this->matches_won += matches_won;
    this->matches_lost += matches_lost;
*/
    if (won)
	++this->matches_won;
    else
	++this->matches_lost;

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

void Player::modify_points(int quantity) {
    points += quantity;
}

void Player::set_position(int pos) {
    this->ranking = pos;
}

void Player::increase_tournament() {
    ++this->tournaments_played;
}