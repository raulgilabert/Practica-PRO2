/** @file tournament.hh
 * @brief Especificación de la clase Tournament.
 */

#ifndef TOURNAMENT
#define TOURNAMENT

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#endif

#include "set_players.hh"
#include "set_categories.hh"

using namespace std;

/** @struct element
 * @brief Struct de elementos del árbol de partidos
 */
struct element {
    int player; //!< Número asignado al jugador en base al orden de entrada
    string points; //!< Resultado del partido jugado en ese nodo
    int left; //!< Jugador que participa en el partido procedente del subárbol izquierdo
    int right; //!< Jugador que participa en el partido procedente del subárbol derecho
};

/** @struct last_played
 * @brief Struct de datos necesarios de almacenar de los jugadores para
 * eliminar los puntos ganados en caso de jugarse otra edición del torneo
 */
struct last_played {
    string player; //!< Nombre del jugador
    int points; //!< Altura en la que se ha quedado el jugador que determina los puntos que gana
};

/** @class Tournament
 * @brief Representa un torneo. */
class Tournament {
private:
    string id; //!< Nombre del torneo
    int num_registered; //!< Número de jugadores registrados en el torneo
    vector<map<string, Player>::iterator> players; //!< Iteradores de los jugadores registrados
    int category; //!< Número de la categoría del torneo
    vector<last_played> last_tournament; //!< Datos de los jugadores del mismo torneo anteriormente jugado

    BinTree<element> matches; //!< Árbol en el que se almacenan los partidos

    /** @brief Devuelve el ganador de un partido y lo añade a la lista de
     * datos de jugadores que han participado
     * \pre 0 < a <= num_registered; 0 < b <= num_registered; matches es un
     * string con los juegos en formato "juegos_a-juegos_b"; height < 0
     * \post Devuelve el entero del jugador que ha ganado en base a los
     * juegos recibidos */
    int get_winner(int a, int b, const string& matches, int height);

    /** @brief Genera el árbol binario de partidos
     * \pre 0 < nodes <= 2^(k-1), 8 <= n <= 2^(k-1), 0 < pos <= 2^(k-1)
     * \post Devuelve el árbol binario generado de partidos */
    BinTree<element> inscriptions_t(int nodes, int n, int pos);

    /** @brief Añade los resultados de los partidos al árbol binario de
     * partidos
     * \pre results es un árbol binario con el elemento player escrito en
     * cada nodo
     * \post El resultado de los partidos se guarda en el parámetro points de
     * cada nodo */
    void get_results(BinTree<element>& results);

    /** @brief Calcula los resultados de todos los partidos y la puntuación
     * que debe recibir cada jugador
     *  \pre a es un árbol binario; height < 0
     *  \post Devuelve el ganador final del árbol binario recibido */
    int calc_winners(BinTree<element>& a, int height);

    /** @brief Escribe en el canal estándar los jugadores de cada partido
     * junto con su posición dentro del vector de jugadores y el resultado
     * del partido
     * \pre a es un árbol binario con todos los parámetros escritos
     * correctamente
     * \post Escrito en el canal estándar siguiendo la siguiente forma:
     * posición dentro del vector del primer jugador, nombre del primer
     * jugador, posición dentro del vector del segundo jugador, nombre del
     * segundo jugador y resultado del partido
     * */
    void print_tree(const BinTree<element>& a);

public:
    Tournament(const string& id, int category);

    Tournament();

    ~Tournament();

    /** @brief Añade el jugador al torneo
     * \pre player es un iterador válido a la clase Player correspondiente
     * \post Añade el jugador al parámetro implícito */
    void add_player(map<string, Player>::iterator player);

    /** @brief Devuelve el número de la categoría a la que pertenece
     * \pre cierto
     * \post Devuelve category del parámetro implícito */
    int get_category() const;


    /** @brief Genera el árbol de partidos únicamente con el identificador de
     * los jugadores
     * \pre 8 <= n <= 2^(k-1)
     * \post Árbol binario de partidos creado con los identificadores de
     * jugadores
     */
    void inscriptions(int n);

    /** @brief Añade los resultados de los partidos al árbol de partidos
     * \pre El árbol de partidos del parámetro implícito contiene los
     * identificadores de jugadores y hay un string por nodo del árbol por
     * el canal estándar
     * \post Los partidos son añadidos al árbol de partidos */
    void get_results_i();

    /** @brief Calcula el jugador ganador del torneo y añade todos los
     * jugadores con sus respectivos identificadores de puntuación en el
     * parámetro implícito
     * \pre El árbol de partidos incluye el jugador y el resultado de en
     * cada nodo */
    int calc_winners_i();

    /** @brief Imprime el nombre y la categoría del torneo
     * \pre cierto
     * \post Escribe en el canal estándar id y category del parámetro implícito
     * */
    void print(const Set_categories& cat) const;

    /** @brief Imprime el resultado de los partidos desde el árbol de
     * partidos
     * \pre El árbol de partidos tiene todos los elementos llenos con los
     * datos correspondientes
     * \post Todo el árbol imprimido */
    void print_tree_i();

    /**
     * @brief Devuelve el vector que contiene los nombres y puntos de los
     * jugadores de la edición finalizada anteriormente del torneo
     * \pre cierto
     * \post Devuelve el vector del parámetro implícito */
    vector<last_played> last_tournament_played();

    /** @brief Prepara el torneo para estar listo para una nueva
     * inicialización
     * \pre cierto
     * \post num_registered = 0; players vaciado */
    void clear();

    /** @brief Elimina un jugador del torneo
     * \pre id es el identificador de un jugador
     * \pre jugador eliminado de todos los datos del torneo en caso de que
     * esté */
    void delete_player(const string& id);

    /** @brief Imprime los jugadores que hayan puntuado en el torneo
     * \pre cierto
     * \post Impresos por el canal estándar todos los jugadores con points >
     * 0 */
    void print_players();
};
#endif
