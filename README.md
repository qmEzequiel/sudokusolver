Una prima idea è fare una matrice 3d booleana che rappresenta il sudoku:
il piano 2d è una griglia 9x9 e ad ogni casella è assegnato un vettore booleano che rappresenta i numeri da 1 a 9.
Un sudoku è risolto quando ogni casella ha un vettore con un unico 1 e otto 0.
La risoluzione è un ciclo che ripete una complessa equazione booleana per ogni cifra per ogni casella (efficiente no ma per ora va bene).
Il ciclo finisce quando tutte le caselle sono nello stato di risolto.