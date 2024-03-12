package zadanie3;


class CircularDoublyLinkedList {
    Node head;
    int size;

    public CircularDoublyLinkedList() {
        head = null;
        size = 0;
    }

    // Metoda do wstawiania nowego elementu
    public void insert(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
        } else {
            newNode.next = head;
            newNode.prev = head.prev;
            head.prev.next = newNode;
            head.prev = newNode;
            head = newNode;
        }
        size++;
    }

    // Metoda do wyszukiwania zwracająca koszt (liczbę porównań)
    // Kierunek jest wybierany losowo
    public int searchCost(int data, boolean randomDirection) {
        if (head == null) return -1;

        Node temp = head;
        int comparisons = 0;
        do {
            comparisons++;
            if (temp.data == data) {
                return comparisons;
            }
            temp = randomDirection ? (Math.random() < 0.5 ? temp.next : temp.prev) : temp.next;
        } while (temp != head);

        return comparisons; // Element nie został znaleziony, zwróć liczbę przeszukań
    }
}
