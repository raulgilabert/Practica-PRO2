/** @file tournament.cc
 * @brief Código de la clase Tournament
 */

#include "tournament.hh"
#include "BinTree.hh"

Tournament::Tournament(const string& id, int category) {
    this->id = id;
    this->category = category;
    this->num_registered = 0;
    this->last_tournament = vector<last_played>(0);
    this->players = vector<map<string, Player>::iterator>(0);
}

Tournament::Tournament() {
    num_registered = 0;
    last_tournament = vector<last_played>(0);
    players = vector<map<string, Player>::iterator>(0);
}

Tournament::~Tournament() {}

void Tournament::add_player(map<string, Player>::iterator player) {
    players.push_back(player);
}

int Tournament::get_category() const {
    return category;
}

void Tournament::get_results(BinTree<element>& a) {
    string result;
    cin >> result;

    // En caso de que el elemento sea diferente a "0" se añade la puntuación
    // y se pasa a los hijos del nodo
    if (result != "0") {
        element elem = a.value();

        elem.points = result;

        BinTree<element> left = a.left(), right = a.right();

        get_results(left);
        get_results(right);


        a = BinTree<element>(elem, left, right);
    }
}

void Tournament::get_results_i() {
    get_results(matches);
}

int Tournament::get_winner(int a, int b, const string& matches, int height) {
    int size = matches.size();

    // Los resultados de partidos de 3 caracteres son los partidos que tienen
    // puntuación 1-0 o 0-1
    if (size == 3) {
        // Caso en el que gana el primero
        if (matches[0] == '1') {
            this->last_tournament[b - 1].points = -height;
            this->last_tournament[b - 1].player = players[b - 1]->second.get_name();
            players[a - 1]->second.update_data(true, 0, 0, 0, 0);
            players[b - 1]->second.update_data(false, 0, 0, 0, 0);
            return a;
        }
        // Caso en el que gana el segundo
        this->last_tournament[a - 1].points = -height;
        this->last_tournament[a - 1].player = players[a - 1]->second.get_name();
        players[a - 1]->second.update_data(false, 0, 0, 0, 0);
        players[b - 1]->second.update_data(true, 0, 0, 0, 0);
        return b;
    }

    int win_a = 0, win_b = 0, a_points = 0, b_points = 0, a_games = 0,
	b_games = 0;

    // Recorre los sets y viendo quién va ganando cada uno
    for (int i = 0; i < size/4 + 1; ++i) {
        ++a_games;
        ++b_games;

        a_points += matches[i*4] - '0';
        b_points += matches[i*4 + 2] - '0';

        if (matches[i*4] > matches[i*4 + 2])
            ++win_a;
        else
            ++win_b;
    }

    // Actualiza los datos de los jugadores
    bool a_won = (win_a > win_b);

    players[a - 1]->second.update_data(a_won, win_a, win_b, a_points, 
	    b_points);

    players[b - 1]->second.update_data(not a_won, win_b, win_a, b_points, 
	    a_points);

    // Caso en el que gana el primero
    if (a_won) {
        this->last_tournament[b - 1].points = -height;
        this->last_tournament[b - 1].player = players[b - 1]->second.get_name();
        return a;
    }
    // Caso en el que gana el segundo
    this->last_tournament[a - 1].points = -height;
    this->last_tournament[a - 1].player = players[a - 1]->second.get_name();
    return b;
}

int Tournament::calc_winners(BinTree<element>& a, int height) {
    if (a.empty()) {
        return 0;
    }

    BinTree<element> left = a.left(), right = a.right();

    int left_w = calc_winners(left, --height),
	right_w = calc_winners(right, height);

    // En caso de que ambos hijos estén vacíos devuelve el valor de este nodo
    if (left_w == 0) {
        if (right_w == 0) {
            return a.value().player;
        }
        return right_w;
    }

    element elem = a.value();

    elem.left = left_w;
    elem.right = right_w;

    a = BinTree<element>(elem, left, right);

    return get_winner(left_w, right_w, a.value().points, height);
}

int Tournament::calc_winners_i() {
    last_tournament = vector<last_played>(num_registered);

    int winner = calc_winners(matches, 0);

    // Añade los datos del ganador, ya que estos no se incluyen en la función
    // recursiva
    last_tournament[winner - 1].player = players[winner - 1]->
	second.get_name();
    last_tournament[winner - 1].points = 0;

    return winner;
}


void Tournament::print_tree(const BinTree<element>& a) {
    if (not a.left().empty()) {
	cout << '(';
	cout << a.value().left << '.' << 
	    players[a.value().left - 1]->second.get_name() << " vs " << 
	    a.value().right << '.' << 
	    players[a.value().right - 1]->second.get_name() << ' ' <<
	    a.value().points;

	print_tree(a.left());
	print_tree(a.right());
	cout << ')';
    }
}


void Tournament::print_tree_i() {
    print_tree(matches);
    cout << endl;
}


void Tournament::print(const Set_categories& cat) const {
    cout << id << ' ' << cat.get_name(category);
}

BinTree<element> Tournament::inscriptions_t(int nodes, int n, int pos) {
    element elem;
    elem.player = pos;

    if (n <= nodes) {
        cout << pos << '.' << players[pos - 1]->second.get_name();
        return BinTree<element>(elem);
    }

    nodes *= 2;

    // Cambio necesario para árboles de hojas impares al emparejar la hoja
    // con jugador con identificador igual a la cantidad de hojas
    if (nodes > n) {
        // Caso de jugadores impar
        if (n%2 == 1) {
            // Lo primero es para evitar que se cree una hoja con
            // identificador mayor que el número máximo de hojas y el segundo
            // condicional permite la creación de la hoja de pos = n
            if (nodes - n + 1 == pos or nodes - n > pos) {
                cout << pos << '.' << players[pos - 1]->second.get_name();
                return BinTree<element>(elem);
            }
        }
        // Condición que ya funcionaba de la práctica normal
        else if (nodes - n >= pos) {
            cout << pos << '.' << players[pos - 1]->second.get_name();
            return BinTree<element>(elem);
        }
    }
    BinTree<element> left, right;
    cout << '(';
    left = inscriptions_t(nodes, n, pos);
    cout << ' ';

    int new_pos_r;
    // Caso que se queda como la práctica normal para el nodo de la derecha
    // en nivel 2
    if (nodes == 2) {
        new_pos_r = nodes - pos + 1;
    }
    // Para niveles > 2 y nodo padre par el nodo de la derecha se calcula
    // sacando el número máximo de nodos del nivel - valor del nodo de la
    // izquierda + 2
    else if (pos%2 == 0) {
        new_pos_r = nodes - pos + 2;
    }
    // Para niveles > 2 y nodo padre impar el nodo de la derecha se calcula
    // sacando el número máximo de nodos del nivel - valor del nodo de la
    // izquierda
    else {
        new_pos_r = nodes - pos;
    }

    right = inscriptions_t(nodes, n, new_pos_r);

    cout << ')';
    return BinTree<element>(elem, left, right);
}

void Tournament::inscriptions(int n) {
    num_registered = n;

    matches = inscriptions_t(1, n, 1);
    cout << endl;
}

vector<last_played> Tournament::last_tournament_played() {
    return last_tournament;
}

void Tournament::clear() {
    num_registered = 0;
    players = vector<map<string, Player>::iterator>(0);
}

void Tournament::delete_player(const string& id) {
    bool found = false;
    int last_tournament_size = last_tournament.size();

    // Recorre los datos de los jugadores que jugaron la edición anterior
    for (int i = 0; i < num_registered and last_tournament_size > 0; ++i) {
        if (last_tournament[i].player == id) {
            found = true;
        }

        // En caso de que se haya encontrado el jugador mueve todos los
        // siguientes uno atrás y elimina el último elemento
        if (found) {
            if (i < num_registered - 1)
                last_tournament[i] = last_tournament[i + 1];
            else
                last_tournament.pop_back();
        }
    }
    if (found)
        --num_registered;
}

void Tournament::print_players() {
    int counter = 0;
    for (int i = 0; i < num_registered; ++i) {
        if (last_tournament[i].points != 0) {
            ++counter;
            cout << counter << '.' << last_tournament[i].player << ' ' <<
            last_tournament[i].points << endl;
        }
    }
}