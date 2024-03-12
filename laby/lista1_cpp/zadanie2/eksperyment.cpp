#include "CircularLinkedList.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

int main() {
    std::srand(std::time(0)); // Inicjalizacja generatora liczb losowych.

    CircularLinkedList list;
    std::vector<int> insertedNumbers; // Wektor przechowujący wstawione liczby
    const int N = 10000;
    const int I_MAX = 100000;

    // Wstawianie losowych liczb do listy i zapisywanie ich.
    for (int i = 0; i < N; ++i) {
        int num = std::rand() % (I_MAX + 1);
        list.insert(num);
        insertedNumbers.push_back(num); // Zapisanie liczby do wyszukiwania później
    }

    // Eksperyment wyszukiwania
    long long totalComparisonsExists = 0, totalComparisonsRandom = 0;

    for (int i = 0; i < 1000; ++i) {
        // Wyszukiwanie liczb, które są na liście
        int existsIndex = std::rand() % N;
        int existsValue = insertedNumbers[existsIndex]; // Pobieranie wartości, która na pewno jest na liście
        totalComparisonsExists += list.search(existsValue);

        // Wyszukiwanie losowej liczby z I
        int randomNum = std::rand() % (I_MAX + 1);
        totalComparisonsRandom += list.search(randomNum);
    }

    std::cout << "Średni koszt wyszukiwania liczby, która jest na liście: " << (double)totalComparisonsExists / 1000 << std::endl;
    std::cout << "Średni koszt wyszukiwania losowej liczby: " << (double)totalComparisonsRandom / 1000 << std::endl;

    return 0;
}
