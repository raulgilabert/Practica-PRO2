/**
 * @mainpage PRO2 Practice: Tennis tournaments circuit.
 *
 * Classes:
 * <ul>
 * <li>Player</li>
 * <li>Set_players</li>
 * <li>Category</li>
 * <li>Set_categories</li>
 * <li>Tournament</li>
 * <li>Set_tournament</li>
 * </ul>
 *
 * Files:
 * <ul>
 * <li>main.cc</li>
 * <li>player.hh</li>
 * <li>set_players.hh</li>
 * <li>Category.hh</li>
 * <li>set_categories.hh</li>
 * <li>tournament.hh</li>
 * <li>set_tournament.hh</li>
 * </ul>
 *
 */

/** @file main.cc
 * @brief Main program for the practice.
 */

#include "set_categories.hh"
#include "set_players.hh"
#include "set_tournament.hh"
#include "category.hh"
#include "player.hh"
#include "tournament.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>

#include "BinTree.hh"
#endif

using namespace std;

/** @brief Main program for the practice */
int main() {
    Set_categories categories;
    categories.read();

    Set_tournament tournaments;
    //tournaments.read();
    // Read tournaments
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string name;
        int cat;
        cin >> name >> cat;

        tournaments.add_tournament(name, cat);
    }

    Set_players players;
    players.read();

    map<string, map<string, Tournament>::iterator> tournaments_playing;


    string command;
    cin >> command;

    while (command != "fin") {
        cout << '#' << command;
        if (command == "nuevo_jugador" or command == "nj") {
            string id;
            cin >> id;

            cout << ' ' << id << endl;

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

            if (c > 0 and c <= C) {
                if (tournaments.tournament_exists(t)) {
                    cout << "error: ya existe un torneo con ese nombre" << endl;
                }
                else {
                    tournaments.add_tournament(t, c);
                    //players.add_tournament(t);
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

            if (players.player_exists(p)) {
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

            if (tournaments.tournament_exists(t)) {
                map<string, Tournament>::iterator tournament = tournaments.get_tournament(t);

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

                tournaments.delete_tournament(t);
                cout << tournaments.num_tournaments() << endl;
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

            if (tournaments.tournament_exists(t)) {
                int n;
                cin >> n;

                map<string, Tournament>::iterator tournament = 
                    tournaments.get_tournament(t);

                vector<last_played> points_to_delete =
                    tournament->second.last_tournament_played();

                tournament->second.clear();

                for (int i = 0; i < n; ++i) {
                    int position_in_ranking;
                    cin >> position_in_ranking;

                    tournament->second.add_player(
                            players.get_iterator(position_in_ranking
                            - 1));
                }

                tournament->second.inscriptions(n);

                tournaments_playing[t] = tournament;
            }
            else {
                //cout << "error: el torneo no existe" << endl;
            }
        }
        else if (command == "finalizar_torneo" or command == "ft") {
            string t;
            cin >> t;

            cout << ' ' << t << endl;

            map<string, map<string, Tournament>::iterator>::iterator
            tournament = tournaments_playing.find(t);
            // Check if tournament is being played
            if (tournament != tournaments_playing.end()) {
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

                tournament->second->second.get_results_i();
                tournament->second->second.calc_winners_i();
                tournament->second->second.print_tree_i();

                vector<last_played> points_to_add = tournament->second->second
                    .last_tournament_played();

                size = points_to_add.size();

                int counter = 0;

                for (int i = 0; i < size; ++i) {
                    int points = categories.points_level(
                        tournament->second->second.get_category(),
                        points_to_add[i].points);

                    if (points_to_add[i].player != "") {
                        players.get_iterator(points_to_add[i].player)->second
                        .increase_tournament();
                        players.modify_points(points_to_add[i].player, points);

                        if (points != 0) {
                            ++counter;
                            cout << counter << '.' << points_to_add[i].player
                            <<  ' ' << points << endl;
                        }
                    }
                }
                players.recalculate_ranking();
            }
        }
        else if (command == "listar_ranking" or command == "lr") {
            cout << endl;
            vector<map<string, Player>::iterator> ranking = 
		players.get_ranking();

            int size = ranking.size();

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
