package zadanie2_a;

// Pierwsza kropka zadania
public class Main {
    public static void main(String[] args) {

        CircularLinkedList list1 = new CircularLinkedList();
        CircularLinkedList list2 = new CircularLinkedList();

        // Wypełniamy obie listy danymi
        for (int i = 10; i < 20; i++) {
            list1.insert(i);
        }
        for (int i = 20; i < 30; i++) {
            list2.insert(i);
        }

        System.out.println("Lista 1 przed scaleniem:");
        list1.display();

        System.out.println("Lista 2 przed scaleniem:");
        list2.display();

        // Scalanie lsit
        CircularLinkedList mergedList = CircularLinkedList.merge(list1, list2);
        System.out.println("Lista po scaleniu:");
        mergedList.display();
    }
}
