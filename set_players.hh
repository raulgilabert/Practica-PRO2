/** @file set_players.hh
 * @brief Especificación de la clase Set_players.
 */

#ifndef SET_PLAYERS
#define SET_PLAYERS


#ifndef NO_DIAGRAM
#include <map>
#include <vector>
#endif

#include "player.hh"

using namespace std;

/** @class Set_players
 * @brief Representa un conjunto de jugadores
 */
class Set_players {
private:
    int num; //!< Número de jugadores
    map<string, Player> players_data; //!< Jugadores identificados por su nombre
    vector<map<string, Player>::iterator> ranking; //!< Ránking de jugadores

    /** @brief Comparador de jugadores para la función de ordenación de ránking
     * \pre a y b son iteradores válidos de jugadores
     * \post cierto si los puntos del jugador al que apunta a son mayores que
     * los del jugador al que apunta b, falso si son menores y en caso de que
     * sean iguales cierto si la posición en el ránking del jugador al que
     * apunta a es menor que la del jugador al que apunta b o falso al contrario
     */
    static bool cmp(map<string, Player>::iterator a, map<string,
                    Player>::iterator b);

public:
    Set_players();

    ~Set_players();

    /** @brief Añade el jugador
     * \pre id es un identificador de jugador
     * \post Jugador añadido al parámetro implícito */
    void add_player(const string& id);

    /** @brief Elimina el jugador
     * \pre id es un identificador de jugador
     * \post Jugador eliminado del parámetro implícito */
    void delete_player(const string& id);

    /** @brief Devuelve un iterador al jugador requerido
     * \pre id es un identificador de jugador
     * \post Devuelve un iterador que apunta al jugador requerido */
    map<string, Player>::iterator get_iterator(const string& id);

    /** @brief Devuelve un iterador al jugador en la posición del ránking
     * requerida
     * \pre 0 < pos <= num
     * \post Devuelve un iterador al jugador requerido */
    map<string, Player>::iterator get_iterator(int pos);


    /** @brief Devuelve el ránking
     * \pre cierto
     * \post Devuelve el ránking del parámetro implícito */
    vector<map<string, Player>::iterator> get_ranking();

    /** @brief Devuelve la cantidad de jugadores
     * \pre cierto
     * \post Devuelve num del parámetro implícito */
    int get_num();

    /** @brief Modifica los puntos del jugador requerido
     * \pre id es un identificador de jugador; quantity es un entero
     * \post El jugador con identificador id tiene una modificación de
     * quantity puntos */
    void modify_points(const string& id, int quantity);

    /** @brief Recalcula el ránking
     * \pre cierto
     * \post El ránking es reordenado */
    void recalculate_ranking();

    /** @brief Comprueba si el jugador existe
     * \pre id es un identificador de jugador
     * \post Cierto sie l jugador existe, falso si no */
    bool player_exists(const string& id);

    /** @brief Imprime el jugador con el mejor ratio de juegos ganados y el
     * porcentaje
     * \pre num > 0; ya se ha disputado algún torneo
     * \post Escrito por el canal estándar el nombre del jugador con mejor
     * ratio de juegos ganados respecto a los juegos perdidos. En caso de
     * empate se imprime el jugador con mejor posición en el ránking */
    void best_player();

    /** @brief Lee los identificadores de los jugadores y los añade al
     * conjunto de estos
     * \pre Un entero P y p strings
     * \post Jugadores añadidos al parámetro implícito */
    void read();

    /** @brief Imprime los datos de todos los jugadores
     * \pre cierto
     * \post Imprime los datos de los jugadores del parámetro implícito en
     * el canal estándar */
    void print();

};

#endif
