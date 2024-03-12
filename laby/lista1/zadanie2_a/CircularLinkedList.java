package zadanie2_a;

// Pierwsza kropka zadania
public class CircularLinkedList {

    Node head = null;
    int size = 0;

    public void insert(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            newNode.next = head;
        } else {
            Node temp = head;
            while (temp.next != head) {
                temp = temp.next;
            }
            temp.next = newNode;
            newNode.next = head;
        }
        size++;
    }

    public static CircularLinkedList merge(CircularLinkedList l1, CircularLinkedList l2) {
        if (l1.head == null) return l2;
        if (l2.head == null) return l1;

        Node temp = l1.head;
        while (temp.next != l1.head) {
            temp = temp.next;
        }
        temp.next = l2.head;

        temp = l2.head;
        while (temp.next != l2.head) {
            temp = temp.next;
        }
        temp.next = l1.head;

        l1.size += l2.size;
        return l1;
    }

    // Metoda do wyśiwetlania listy (dla celów demonstrayjnych)
    public void display() {
        if (head != null) {
            Node temp = head;
            do {
                System.out.println(temp.data + " ");
                temp = temp.next;
            } while (temp != head);
            System.out.println();
        }
    }

}
