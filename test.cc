#include "category.hh"

#include <vector>

using namespace std;

void print_vector(const vector<string>& vec) {
    int size = vec.size();

    for (int i = 0; i < size; ++i)
        cout << vec[i] << endl;
}

int main() {
    Category cat("pizza");

    cat.add_tournament("Sexo");
    cat.add_tournament("uwu");
    cat.add_tournament("owo");

    print_vector(cat.get());

    cat.delete_tournament("uwu");

    print_vector(cat.get());
}