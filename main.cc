#include <iostream>
#include <map>

#include "BinTree.hh"

#include "set_categories.hh"
#include "set_players.hh"
#include "set_tournament.hh"
#include "category.hh"
#include "player.hh"
#include "tournament.hh"

using namespace std;

int main() {
    Set_categories categories;
    categories.read();

    Set_tournament tournaments;
    tournaments.read();

    Set_players players;
    players.read();

    map<string, Tournament> tournaments_playing;

    string command;
    cin >> command;

    while (command != "end") {
        // Process commands
        if (command == "nuevo_jugador" or command == "nj") {
            string id;
            cin >> id;

            if (players.player_exists(id)) {
                players.add_player(id);
            }
            else {
                cout << "Error: Player exists in the circuit." << endl;
            }
        }
        else if (command == "nuevo_torneo" or command == "nt") {
            int C = categories.num_categories(), c;
            string t;

            cin >> t >> c;

            if (c <= C) {
                if (tournaments.tournament_exists(t)) {
                    cout << "Error: tournament exists in the circuit." << endl;
                }
                else {
                    tournaments.add_tournament(t);
                    categories.add_tournament(c, t);
                    players.add_tournament(t);
                    cout << tournaments.num_tournaments() << endl;
                }
            }
            else {
                cout << "Error: category not exists." << endl;
            }
        }
        else if (command == "baja_jugador" or command == "bj") {
            string p;
            cin >> p;

            if (players.player_exists(p)) {
                players.delete_player(p);
            }
            else {
                cout << "Error: player does not exist." << endl;
            }
        }
        else if (command == "baja_torneo" or command == "bt") {
            string t;
            cin >> t;

            if (tournaments.tournament_exists(t)) {
                const Tournament tournament = tournaments.get_tournament(t);
                tournaments.delete_tournament(t);
                players.delete_tournament(t);
                categories.delete_tournament(tournament.get_category(), t);
            }
            else {
                cout << "Error: tournament does not exist" << endl;
            }
        }
        else if (command == "iniciar_torneo" or command == "it") {
            string t;
            cin >> t;

            Tournament tournament = tournaments.get_tournament(t);

            int n;
            cin >> n;

            vector<string> ranking = players.get_ranking();

            for (int i = 0; i < n; ++i) {
                int position_in_ranking;
                cin >> position_in_ranking;
                tournament.add_player(players.get_player
                (ranking[position_in_ranking - 1]));
            }

            tournaments_playing[t] = tournament;
        }
        else if (command == "finalizar_torneo" or command == "ft") {
            string t;
            cin >> t;

            if (tournaments_playing.find(t) != tournaments_playing.end()) {
                Tournament tournament = tournaments.get_tournament(t);
                tournament.end_tournament(players);
                tournament.print_results();
            }
        }
        else if (command == "listar_ranking" or command == "lr") {
            vector<string> ranking = players.get_ranking();

            int size = ranking.size();

            for (int i = 0; i < size; ++i) {
                Player player = players.get_player(ranking[i]);
                cout << i + 1 << ' ' << ranking[i] << ' ' <<
                player.get_points() << endl;
            }
        }
        else if (command == "listar_jugadores" or command == "lj") {
            vector<string> players_names = players.get_players();

            int size = players_names.size();

            for (int i = 0; i < szie; ++i) {
                Player player = players.get_player(players_names[i]);
                player.print();
            }
        }
        else if (command == "consultar_jugador" or command == "cj") {
            string p;
            cin >> p;

            if (players.player_exists(p)) {
                Player player = players.get_player(p);
                player.print();
            }
            else {
                cout << "Error: player does not exist." << endl;
            }
        }
        else if (command == "listar_torneo" or command == "lt") {
            vector<string> tournaments_name = tournaments.get_tournaments();
            int size = tournaments_name.size();

            for (int i = 0; i < size; ++i) {
                Tournament tournament = tournaments.get_tournament
                        (tournaments_name[i]);

                cout << tournaments_name[i] << ' ' <<
                tournament.get_category() << endl;
            }
        }
        else if (command == "listar_categorías" or command == "lc") {
            vector<Category> categories_data = categories.get_categories();
            int size = categories_data.size();

            for (int i = 0; i < size; ++i) {
                Category category = categories_data[i];
                cout << category.get_name() << ' ' << endl;

                vector<int> points_per_level = category.get_points_per_level();
                int size2 = points_per_level.size();

                for (int j = 0; j < size; ++j) {
                    cout << j + 1 << ' ' << points_per_level[j] << endl;
                }
            }
        }

        cin >> command;
    }
}
