# Συμβουλές και Παραδείγματα Προγραμματισμού με OpenMP

Αυτό το README παρέχει οδηγίες για τη χρήση των OpenMP directives, με παραδείγματα και οδηγίες για την εξάσκηση στις βασικές έννοιες παράλληλου προγραμματισμού σε γλώσσα C.

## Περιεχόμενα
- [Χρησιμοποιημένες Εντολές](#χρησιμοποιημένες-εντολές)
- [Παραδείγματα Προγραμμάτων](#παραδείγματα-προγραμμάτων)
- [Οδηγίες και Ασκήσεις](#οδηγίες-και-ασκήσεις)

## Χρησιμοποιημένες Εντολές

Οι ακόλουθες OpenMP εντολές και συναρτήσεις καλύπτονται:

1. **Parallel for**: 
   - Χρησιμοποιείται για την παραλληλοποίηση των βρόχων.
2. **Κρίσιμη Ενότητα (`#pragma omp critical`)**:
   - Εξασφαλίζει ότι μόνο ένα νήμα εκτελεί ένα τμήμα κώδικα τη φορά, αποτρέποντας τα race conditions.
3. **Ατομική Ενημέρωση και Μείωση**:
   - `#pragma omp atomic`: Ατομική ενημέρωση μιας κοινής μεταβλητής.
   - `#pragma omp reduction`: Μειώνει μια μεταβλητή (π.χ., άθροισμα, μέγιστο) ανάμεσα στα νήματα.
4. **Χρονομέτρηση (`omp_get_wtime`)**:
   - Μετρά τον χρόνο εκτέλεσης για ανάλυση απόδοσης.
5. **Collapse**:
   - Χρησιμοποιείται για τη συγχώνευση ένθετων βρόχων στην παραλληλοποίηση για βελτίωση της απόδοσης.

## Παραδείγματα Προγραμμάτων

Τα παρακάτω παραδείγματα προγραμμάτων από τον κατάλογο παραδειγμάτων του OpenMP δείχνουν συγκεκριμένες έννοιες:

1. **omp20.c**: Επίδειξη της εντολής `reduction` για το άθροισμα τιμών ανάμεσα στα νήματα και τη μέτρηση χρόνου εκτέλεσης.
   - **Συμβουλή**: Δοκιμάστε να ρυθμίσετε τον αριθμό νημάτων με τη `omp_set_num_threads()` για να δείτε αλλαγές στην απόδοση.
   
2. **omp14.c**: Δείχνει τη χρήση της εντολής `parallel for` για ένθετους βρόχους, σε συνδυασμό με `collapse`.
   - **Συμβουλή**: Πειραματιστείτε με την εντολή `collapse` για να δείτε την επίδρασή της στην παραλληλοποίηση ένθετων βρόχων.

## Οδηγίες και Ασκήσεις

1. **Έλεγχος Διαγώνιας Κυριαρχίας**:
   - Για έναν πίνακα \( A \), ελέγξτε αν \( |A_{ii}| \geq \sum |A_{ij}| \) (για \( i \neq j \)) για να διαπιστώσετε αν ο πίνακας είναι διαγωνίως κυρίαρχος.
   - Περιλαμβάνεται παράδειγμα κώδικα για την υλοποίηση ενός βρόχου που ελέγχει τη διαγώνια κυριαρχία κάθε σειράς.

2. **Εύρεση Μέγιστου Στοιχείου με Παράλληλη Μείωση**:
   - Υλοποιήστε μια λειτουργία μείωσης για να βρείτε το μέγιστο στοιχείο σε έναν πίνακα \( A \).
   - **Parallel Directive**: Χρησιμοποιήστε `parallel for reduction(max:m)` για παράλληλη μείωση του μέγιστου.

3. **Άσκηση Μετασχηματισμού Πίνακα**:
   - Τροποποιήστε τα στοιχεία του πίνακα \( B \) ως εξής: \( B_{ij} = m - |A_{ij}| \) για \( i \neq j \) και \( B_{ij} = m \) για \( i = j \).
   - Εξασκηθείτε με την `collapse` στους ένθετους βρόχους.

4. **Προχωρημένα Παραδείγματα**:
   - **omp12.c**: Εξερευνά τη `reduction` με προηγμένη χρήση.
   - **omp13.c**: Δείχνει τη χρήση των εντολών `atomic` και `critical`, εισάγοντας έννοιες συγχρονισμού σε λεπτομερές επίπεδο.

---

Καλή επιτυχία με τον OpenMP!
