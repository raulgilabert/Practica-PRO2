/** @file category.hh
 * @brief Especificación de la clase Category.
 */

#ifndef CATEGORY
#define CATEGORY

#ifndef NO_DIAGRAM
#include <vector>
#include <iostream>
#endif

using namespace std;

/** @class Category
 * @brief Representa una categoría */
class Category {
private:
    vector<int> points_per_level; //!< Puntos que se ganan en la categoría en base al nivel en el que se queda en el árbol de resultados
    string id; //!< Nombre de la categoría
    vector<string> tournaments; //!< Vector de los nombres de los torneos que pertenecen a la categoría

public:
    Category(string id);

    Category();

    ~Category();

    /** @brief Asigna los puntos por nivel
     * \pre levels >= 1, levels enteros por el canal estándar
     * \post Añade los elementos recibidos por el canal estándar al vector de
     * puntos por nivel del parámetro implícito */
    void set_points_per_level(int levels);

    /** @brief Devuelve el nombre de la categoría
     * \pre cierto
     * \post Devuelve id del parámetro implícito */
    string get_name() const;

    /** @brief Devuelve el nombre de la categoría
     * \pre cierto
     * \post Devuelve id del parámetro implícito */
    string get_name();

    /** @brief Devuelve los puntos por nivel
     * \pre cierto
     * \post Devuelve el vector points_per_level del parámetro implícito */
    vector<int> get_points_per_level();
};

#endif
