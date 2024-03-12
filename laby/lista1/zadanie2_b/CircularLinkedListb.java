package zadanie2_b;


public class CircularLinkedListb {
    Node_b head = null;
    int size = 0;

    public void insert(int data) {
        Node_b newNode = new Node_b(data);
        if (head == null) {
            head = newNode;
            newNode.next = head;
        } else {
            Node_b temp = head;
            while (temp.next != head) {
                temp = temp.next;
            }
            temp.next = newNode;
            newNode.next = head;
        }
        size++;
    }

    public static CircularLinkedListb merge(CircularLinkedListb l1, CircularLinkedListb l2) {
        if (l1.head == null) return l2;
        if (l2.head == null) return l1;

        Node_b temp = l1.head;
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
            Node_b temp = head;
            do {
                System.out.println(temp.data + " ");
                temp = temp.next;
            } while (temp != head);
            System.out.println();
        }
    }

    // Metoda do wyszukiwania zwracająca koszt (liczbę porównań)
    public int searchCost(int data) {
        int cost = 0;
        if (head != null) {
            Node_b temp = head;
            do {
                cost++; // Zwiększamy koszt dla każdego porównania
                if (temp.data == data) {
                    return cost; // Znaleziono element
                }
                temp = temp.next;
            } while (temp != head);
        }
        return -1; // Element nie został znaleziony, zwracamy -1
    }
}
