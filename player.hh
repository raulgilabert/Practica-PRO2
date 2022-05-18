/** @file player.hh
 * @brief Especificación de la clase Player.
 */

#ifndef PLAYER
#define PLAYER

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
#endif

using namespace std;

/** @class Player
 * @brief Representa un jugador
 */
class Player {
private:
    string name; //!< Nombre del jugador

    int tournaments_played; //!< Torneos jugados
    int matches_won; //!< Partidos ganados
    int matches_lost; //!< Partidos perdidos
    int sets_won; //!< Sets ganados
    int sets_lost; //!< Sets perdidos
    int games_won; //!< Juegos ganados
    int games_lost; //!< Juegos perdidos

    int ranking; //!< Posición del ránking
    
    int points; //!< Puntos del jugador

public:
    Player(const string& id, int pos);

    Player();

    ~Player();

   /** @brief Devuelve la posición en el ránking del jugador
     * \pre cierto
     * \post Devuelve raking del parámetro implícito */
    int get_position();

    /** @brief Devuelve los puntos del jugador
     * \pre cierto
     * \post Devuelve points del parámetro implícito */
    int get_points();


    /** @brief Actualiza los datos de partidos, sets y juegos
     * \pre won es un booleano, sets_won >= 0, sets_lost >= 0,
     * games_won >= 0, games_lost >= 0
     * \post Los datos del parámetro implícito son actualizados */
    void update_data(bool won, int sets_won,
	    int sets_lost, int games_won, int games_lost);

    void increase_tournament(); 

    /** @brief Decrementa la posición del ránking por uno
     * \pre cierto
     * \post Decrementado por uno position del parámetro implícito */
    void decrease_pos();

    /** @brief Modifica los puntos del jugador
     * \pre quantity es un entero
     * \post points del parámetro implícito es modificado en quantity */
    void modify_points(int quantity);

    /** @brief Asigna la posición del ránking al jugador
     * \pre 0 < pos
     * \post ranking del parámetro implícito pasa a ser pos */
    void set_position(int pos);

    /** @brief Devuelve el nombre del jugador
     * \pre cierto
     * \post Devuelve name del parámetro implícito */
    string get_name();

    /** @brief Devuelve el ratio de juegos ganados respecto a los juegos
     * perdidos
     * \pre cierto
     * \post 0 si tournaments_played == 0, games_won/games_lost*100 en caso
     * contrario */
    double ratio_games();

    /** @brief Imprime el nombre, la posición, los puntos y los datos de
     * torneos, partidos, sets y juegos
     * \pre cierto
     * \post Escribe en el canal estándar el nombre, la posición y los datos
     * de torneos, partidos, sets y juegos del parámetro implícito */
    void print() const;

};

#endif
