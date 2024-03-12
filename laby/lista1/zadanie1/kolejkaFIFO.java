package zadanie1;
import java.util.LinkedList;
import java.util.Queue;

public class kolejkaFIFO {
    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>();

        // Dodawanie 50 elementów do kolejki za pomocą offer()
        for (int i = 1; i <= 50; i++) {
            if (queue.offer(i)) {
                System.out.println("Dodano do kolejki: " + i);
            } else {
                System.out.println("Nie udało się dodać elementu do kolejki: " + i);
            }
        }

        // System.out.println(queue);

        // Pobieranie i wyświetlanie elementów z kolejki za pomocą poll()
        Integer number;
        while ((number = queue.poll()) != null) {
            System.out.println("Pobrano i usunięto z kolejki: " + number);
        }
        // System.out.println(queue);
    }
}



// import java.util.LinkedList;
// import java.util.Queue;

// public class zadanie1_kolejkaFIFO {
//     public static void main(String[] args) {

//         Queue<Integer> queue = new LinkedList<>();

//         //Dodanie 50 elementów do kolejki
//         for (int i = 1; i <= 50; i++) {

//             // Użycie add() może spowodować wyrzucenie wyjątku, a offer tylko null
//             // przy próbie pobrania elementu z pustej kolejki
//             queue.offer(i);
//             System.out.println("Dodano do kolejki: " + i);
//         }

//         // Pobieranie i wyświetlanie elementów z kolejki
//         while (!queue.isEmpty()) {
//             try {


//                 int removed = queue.poll();
//                 System.out.println("Usunięto z kolejki: " + removed);
//             } catch (Exception e) {
//                 System.out.println("Błąd: Kolejka jest pusta.");
//             }
//         }


//     }
// }