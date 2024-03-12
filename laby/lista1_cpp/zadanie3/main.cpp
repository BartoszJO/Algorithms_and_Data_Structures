#include "DoublyCircularLinkedList.hpp"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime> 

void displayList(DoublyCircularLinkedList& list) {
    if (list.head == nullptr) {
        std::cout << "Lista jest pusta." << std::endl;
        return;
    }
    Node* temp = list.head;
    do {
        std::cout << temp->value << " ";
        temp = temp->next;
    } while (temp != list.head);
    std::cout << std::endl;
}

int main() {
    std::srand(std::time(0)); // Inicjalizacja generatora liczb losowych

    // Demonstracja działania funkcji merge
    DoublyCircularLinkedList list1, list2;
    
    for (int i = 10; i < 20; ++i) {
        list1.insert(i);
    }
    for (int i = 20; i < 30; ++i) {
        list2.insert(i);
    }

    std::cout << "List 1 before merge: ";
    displayList(list1);
    std::cout << "List 2 before merge: ";
    displayList(list2);

    DoublyCircularLinkedList mergedList = DoublyCircularLinkedList::merge(list1, list2);

    std::cout << "Merged list: ";
    displayList(mergedList);

    // Eksperyment z wyszukiwaniem
    DoublyCircularLinkedList searchList;
    const int N = 10000;
    const int I_MAX = 100000;
    std::vector<int> numbers;

    for (int i = 0; i < N; ++i) {
        int num = std::rand() % (I_MAX + 1);
        numbers.push_back(num);
        searchList.insert(num);
    }

    long long totalComparisonsExists = 0, totalComparisonsRandom = 0;

    for (int i = 0; i < 1000; ++i) {
        // Wyszukiwanie liczby, która jest na liście
        int existsIndex = std::rand() % numbers.size();
        int existsValue = numbers[existsIndex];
        totalComparisonsExists += searchList.search(existsValue);

        // Wyszukiwanie losowej liczby
        int randomNum = std::rand() % (I_MAX + 1);
        totalComparisonsRandom += searchList.search(randomNum);
    }

    std::cout << "Średni koszt wyszukiwania liczby, która jest na liście: " << (double)totalComparisonsExists / 1000 << std::endl;
    std::cout << "Średni koszt wyszukiwania losowej liczby: " << (double)totalComparisonsRandom / 1000 << std::endl;

    return 0;
}
