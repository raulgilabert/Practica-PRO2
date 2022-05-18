/** @file set_tournament.hh
 * @brief Especificación de la clase Set_tournament.
 */

#ifndef SET_TOURNAMENT
#define SET_TOURNAMENT

#include "tournament.hh"

using namespace std;

/** @class Set_tournament
 * @brief Representa un conjunto de torneos
 */
class Set_tournament {
private:
    int num; //!< Número de torneos
    map<string, Tournament> tournaments; //!< Torneos identificados por el nombre

public:
    Set_tournament();

    ~Set_tournament();

    /** @brief Añade un torneo
     * \pre id es un identificador de torneo, 0 <= category <= C
     * \post Torneo añadido al parámetro implícito */
    void add_tournament(const string& id, int category);

    /** @brief Elimina un torneo
     * \pre id es un identificador de torneo
     * \post Torneo eliminado del parámetro implícito */
    void delete_tournament(const string& id);

    /** @brief Elimina un jugador de todos los torneos
     * \pre id es un identificador de jugador válido
     * \post El jugador es eliminado de todos los torneos */
    void delete_player(const string& id);

    /** @brief Comprueba si el torneo existe
     * \pre id es un identificador de torneo
     * \post Cierto si id se encuentra en el map del parámetro implícito,
     * falso si no */
    bool tournament_exists(const string& id);

    /** @brief Devuelve el número de torneos
     * \pre Cierto
     * \post Devuelve num del parámetro implícito */
    int num_tournaments();

    /** @brief Devuelve un iterador que apunta al torneo pedido
     * \pre id es un identificador de torneo
     * \post Devuelve el iterador requerido */
    map<string, Tournament>::iterator get_tournament(const string& id);

    /** @brief Lee los torneo
     * \pre Un entero n y n strings y enteros por el canal estándar
     * \post Datos añadidos al parámetro implícito */
    void read();

    /** @brief Imprime los datos de todos los torneos
     * \pre cierto
     * \post Datos de los torneos escritos en el canal estándar */
    void print(const Set_categories& cat);
};

#endif
