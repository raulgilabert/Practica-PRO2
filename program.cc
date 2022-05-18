/**
 * @mainpage Práctica PRO2: Circuito de torneos de tenis.
 *
 * Clases:
 * <ul>
 * <li>Player</li>
 * <li>Set_players</li>
 * <li>Category</li>
 * <li>Set_categories</li>
 * <li>Tournament</li>
 * <li>Set_tournament</li>
 * </ul>
 *
 * Archivos:
 * <ul>
 * <li>program.cc</li>
 * <li>player.hh</li>
 * <li>set_players.hh</li>
 * <li>Category.hh</li>
 * <li>set_categories.hh</li>
 * <li>tournament.hh</li>
 * <li>set_tournament.hh</li>
 * </ul>
 *
 */

/** @file program.cc
 * @brief Programa principal de la práctica.
 */

#include "set_categories.hh"
#include "set_players.hh"
#include "set_tournament.hh"

using namespace std;

/** @brief Programa principal de la práctica */
int main() {
    Set_categories categories;
    // Lee las categorías
    categories.read();

    Set_tournament tournaments;
    // Lee los torneos
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string name;
        int cat;
        cin >> name >> cat;

        tournaments.add_tournament(name, cat);
    }

    Set_players players;
    // Le los jugadores
    players.read();

    // Sirve para almacenar los torneos que se estén jugando, de forma que
    // son más accesibles y permite comprobar fácilmente si se han iniciado ya
    map<string, map<string, Tournament>::iterator> tournaments_playing;

    string command;
    cin >> command;

    while (command != "fin") {
        cout << '#' << command;
        if (command == "nuevo_jugador" or command == "nj") {
            string id;
            cin >> id;

            cout << ' ' << id << endl;

            // Añade el jugador solo si no existe
            if (players.player_exists(id)) {
                cout << "error: ya existe un jugador con ese nombre" << endl;
            }
            else {
                players.add_player(id);
                cout << players.get_num() << endl;
            }
        }
        else if (command == "nuevo_torneo" or command == "nt") {
            int C = categories.num_categories(), c;
            string t;

            cin >> t >> c;

            cout << ' ' << t << ' ' << c << endl;

            // Comprueba que la categoría sea válida
            if (c > 0 and c <= C) {
                // Añade el torneo solo si no existe
                if (tournaments.tournament_exists(t)) {
                    cout << "error: ya existe un torneo con ese nombre" << endl;
                }
                else {
                    tournaments.add_tournament(t, c);
                    cout << tournaments.num_tournaments() << endl;
                }
            }
            else {
                cout << "error: la categoria no existe" << endl;
            }
        }
        else if (command == "baja_jugador" or command == "bj") {
            string p;
            cin >> p;

            cout << ' ' << p << endl;

            // Elimina el jugador solo si este existe
            if (players.player_exists(p)) {
                // Elimina el jugador de todos los torneos antes de
                // eliminarlo en sí del conjunto de jugadores
                tournaments.delete_player(p);
                players.delete_player(p);
                cout << players.get_num() << endl;
            }
            else {
                cout << "error: el jugador no existe" << endl;
            }
        }
        else if (command == "baja_torneo" or command == "bt") {
            string t;
            cin >> t;

            cout << ' ' << t << endl;

            // Elimina el torneo solo si este existe
            if (tournaments.tournament_exists(t)) {
                map<string, Tournament>::iterator tournament = tournaments.get_tournament(t);

                // Elimina los puntos de la última edición de todos los
                // jugadores
                vector<last_played> points_to_delete = tournament->second
                        .last_tournament_played();

                int size = points_to_delete.size();

                for (int i = 0; i < size; ++i) {
                    int points = categories.points_level(
                            tournament->second.get_category(),
                            points_to_delete[i].points);

                    if (points_to_delete[i].player != "") {
                        players.modify_points(points_to_delete[i].player,
                                              -points);
                    }
                }

                // Elimina el torneo
                tournaments.delete_tournament(t);
                cout << tournaments.num_tournaments() << endl;
                // Reordena el ránking
                players.recalculate_ranking();
            }
            else {
                cout << "error: el torneo no existe" << endl;
            }
        }
        else if (command == "iniciar_torneo" or command == "it") {
            string t;
            cin >> t;

            cout << ' ' << t << endl;

            // Inicia el torneo solo en caso de que exista uno con ese nombre
            if (tournaments.tournament_exists(t)) {
                // Lo inicia solo si no ha sido iniciado con anterioridad
                if (tournaments_playing.find(t) == tournaments_playing.end()) {
                    int n;
                    cin >> n;

                    // Vacía el torneo de los datos innecesarios de una
                    // edición anterior
                    map<string, Tournament>::iterator tournament =
                        tournaments.get_tournament(t);

                    tournament->second.clear();

                    // Añade los jugadores al torneo
                    for (int i = 0; i < n; ++i) {
                        int position_in_ranking;
                        cin >> position_in_ranking;

                        tournament->second.add_player(
                                players.get_iterator(position_in_ranking
                                - 1));
                    }

                    // Crea el árbol de jugadores inicial
                    tournament->second.inscriptions(n);

                    // Añade el torneo al conjunto de torneos que se están
                    // jugando
                    tournaments_playing[t] = tournament;
                }
                else {
                    cout << "error: el torneo ya se esta jugando" << endl;
                }
            }
            else {
                cout << "error: el torneo no existe" << endl;
            }
        }
        else if (command == "finalizar_torneo" or command == "ft") {
            string t;
            cin >> t;

            cout << ' ' << t << endl;

            // Recibe el iterador del torneo que se está jugando
            map<string, map<string, Tournament>::iterator>::iterator
            tournament = tournaments_playing.find(t);

            // Comprueba que se esté jugando
            if (tournament != tournaments_playing.end()) {
                // Elimina los puntos del los jugadores de la anterior edición
                vector<last_played> points_to_delete =
                        tournament->second->second.last_tournament_played();

                int size = points_to_delete.size();

                for (int i = 0; i < size; ++i) {
                    int points = categories.points_level(
                            tournament->second->second.get_category(),
                            points_to_delete[i].points);

                    if (points_to_delete[i].player != "") {
                        players.modify_points(points_to_delete[i].player,
                                              -points);
                    }
                }

                // Añade los resultados al árbol de partidos, calcula las
                // posiciones en las que quedan los jugadores e imprime los
                // datos
                tournament->second->second.get_results_i();
                tournament->second->second.calc_winners_i();
                tournament->second->second.print_tree_i();

                // Añade los puntos a los jugadores de esta edición
                vector<last_played> points_to_add = tournament->second->second
                    .last_tournament_played();

                size = points_to_add.size();

                for (int i = 0; i < size; ++i) {
                    // Calcula los puntos basándose en la posición en la queda
                    // el jugador
                    int points = categories.points_level(
                        tournament->second->second.get_category(),
                        points_to_add[i].points);

                    if (points_to_add[i].player != "") {
                        // Incrementa la cantidad de torneos disputados por el
                        // jugador en uno y añade los puntos
                        players.get_iterator(points_to_add[i].player)->second
                        .increase_tournament();
                        players.modify_points(points_to_add[i].player, points);

                        /*
                        // Imprime la información necesaria del jugador en
                        // caso de que haya puntuado
                        if (points != 0) {
                            ++counter;
                            cout << i + 1 << '.' << points_to_add[i].player
                            <<  ' ' << points << endl;
                        }
                         */
                    }
                }
                players.recalculate_ranking();
            }
            tournaments_playing.erase(t);
        }
        else if (command == "puntos_torneo" or command == "pt") {
            string t;
            cin >> t;

            cout << ' ' << t << endl;

            // Comprueba si el torneo existe
            if (tournaments.tournament_exists(t)) {
                // Comprueba si el torneo ya ha finalizado
                if (tournaments_playing.find(t) == tournaments_playing.end()) {
                    map<string, Tournament>::iterator tournament = tournaments
                            .get_tournament(t);
                    vector<last_played> data = tournament->second
                            .last_tournament_played();

                    int size = data.size();

                    if (size > 0) {
                        for (int i = 0; i < size; ++i) {
                            int points = categories.points_level
                                    (tournament->second.get_category(),
                                     data[i].points);

                            if (points != 0) {
                                cout << i + 1 << '.' << data[i].player << ' '
                                << points << endl;
                            }
                        }
                    }
                    else {
                        cout << "error: torneo no disputado" << endl;
                    }
                }
                else {
                    cout << "error: torneo en juego" << endl;
                }
            }
            else {
                cout << "error: el torneo no existe" << endl;
            }
        }
        else if (command == "mejor_jugador_games" or command =="mjg") {
            cout << endl;
            players.best_player();
        }
        else if (command == "listar_ranking" or command == "lr") {
            cout << endl;

            // Recibe el ránking
            vector<map<string, Player>::iterator> ranking = players
                    .get_ranking();

            int size = ranking.size();

            // Imprime la información necesaria de cada jugador
            for (int i = 0; i < size; ++i) {
                map<string, Player>::iterator player = ranking[i];
                cout << i + 1 << ' ' << player->second.get_name() << ' ' <<
                player->second.get_points() << endl;
            }
        }
        else if (command == "listar_jugadores" or command == "lj") {
            cout << endl << players.get_num() << endl;
            players.print();
        }
        else if (command == "consultar_jugador" or command == "cj") {
            string p;
            cin >> p;

            cout << ' ' << p << endl;

            // Imprime la información del jugador en caso de que exista
            if (players.player_exists(p)) {
                players.get_iterator(p)->second.print();
            }
            else {
                cout << "error: el jugador no existe" << endl;
            }
        }
        else if (command == "listar_torneos" or command == "lt") {
            cout << endl << tournaments.num_tournaments() << endl;

            tournaments.print(categories);
        }
        else if (command == "listar_categorias" or command == "lc") {
            cout << endl;
            vector<Category> categories_data = categories.get_categories();
            int size = categories_data.size();

            cout << size << ' ' << categories.get_levels() << endl;

            // Imprime la información necesaria de las categorías
            for (int i = 0; i < size; ++i) {
                Category category = categories_data[i];
                cout << category.get_name();

                vector<int> points_per_level = category.get_points_per_level();
                int size2 = points_per_level.size();

                for (int j = 0; j < size2; ++j) {
                    cout << ' ' << points_per_level[j];
                }
                cout << endl;
            }
        }

        cin >> command;
    }
}
