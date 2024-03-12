package zadanie3;
public class Node {
    int data;
    Node prev;
    Node next;

    // Konstruktor
    public Node(int data) {
        this.data = data;
        this.prev = this; // Początkowo wskazuje na siebie
        this.next = this; // Początkowo wskazuje na siebie
    }
}
