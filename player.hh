/** @file player.hh
 * @brief Specification of the class Player.
 */

#ifndef PLAYER
#define PLAYER

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
#endif

using namespace std;

/** @class Player
 * @brief Represents a player
 */
class Player {
private:
    string name;

    int tournaments_played;
    int matches_won;
    int matches_lost;
    int sets_won;
    int sets_lost;
    int games_won;
    int games_lost;

    int ranking;
    
    int points;

public:
    Player(const string& id, int pos);

    Player();

    ~Player();

   /** @brief Return the position in ranking of the player
     * \pre true
     * \post Return position in ranking from the implicit parameter */
    int get_position();

    /** @brief Return the points of the player
     * \pre true
     * \post Return points from the implicit parameter */
    int get_points();


    /** @brief update the tournaments, sets and games data
     * \pre matches_won >= 0, matches_lost >= 0, sets_won >= 0, sets_lost >= 0,
     * games_won >= 0, games_lost >= 0
     * \post The data in the implicit parameter is updated */
    void update_data(bool won, int sets_won,
	    int sets_lost, int games_won, int games_lost);

    void increase_tournament(); 

    /** @brief Decrease the ranking position by one
     * \pre true
     * \post position in the implicit parameter decreased by one */
    void decrease_pos();

    /** @brief return player's name
     * \pre true
     * \post return player's name from the implicit parameter */
    string get_name();
    
    void modify_points(int quantity);

    /** @brief Print the name, the position and the tournaments, sets and games
     * data
     * \pre true
     * \post Prints in the standard channel the name, the position in the
     * ranking, the points and all the data about tournaments, sets and
     * games */
    void print() const;

    void set_position(int pos);
};


#endif
