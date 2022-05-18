/** @file set_categories.hh
 * @brief Especificación de la clase Set_categories
 */

#ifndef SET_CATEGORIES
#define SET_CATEGORIES

#ifndef NO_DIAGRAM
#include <vector>
#endif

#include "category.hh"

using namespace std;

/** @class Set_categories
 * @brief Representa un conjunto de categorías
 */
class Set_categories {
private:
    int num; //!< Número de categorías
    int levels; //!< Número de niveles del árbol
    vector<Category> categories; //!< Vector con las categorías

public:
    Set_categories();

    ~Set_categories();

    /** @brief Añade una categoría
     * \pre El parámetro implícito no incluye una categoría con ese nombre
     * \post cat se añade al parámetro implícito */
    void add_category(const Category& cat);

    /** @brief Devuelve la cantidad de categorías
     * \pre cierto
     * \post Devuelve num del parámetro implícito */
    int num_categories();

    /** @brief Añade un torneo a una categoría
     * \pre 1 <= category <= num; tournament es un identificador de torneo
     * \post Añade el torneo a la categoría */
    void add_tournament(int category, string tournament);

    /** @brief Elimina un torneo de la categoría
     * \pre 1 <= category <= num; tournament es un identificador de torneo
     * \post Torneo eliminado de la categoría */
    void delete_tournament(int category, string tournament);

    /** @brief Devuelve todas las categorías
     * \pre cierto
     * \post Devuelve el vector de categorías del parámetro implícito */
    vector<Category> get_categories();

    /** @brief Devuelve el nombre de la categoría en la posición requerida
     * \pre 0 < pos <= nun
     * \post Devuelve el nombre de la categoría requerida */
    string get_name(int pos) const;

    /** @brief Devuelve la cantidad de niveles de las categorías
     * \pre cierto
     * \post Devuelve la cantidad de niveles de las categorías
     */
    int get_levels();

    /** @brief Devuelve los puntos en un nivel de una categoría
     * \pre 0 < cat <= num; 0 < lvl <= levels
     * \post Puntos de la categoría cat en el nivel lvl */
    int points_level(int cat, int lvl);

    /** @brief Lee los datos de la categoría
     * \pre Dos enteros (C y K), n identificadores de categoría y C*K enteros
     * en el canal estándar
     * \post Añadidos los datos al parámetro implícito */
    void read();
};

#endif
