# Lem-In-Epitech-

Le projet Lem-In consiste à trouver le chemin le plus court et le plus optimisé afin de déplacer un lot de fourmis le plus rapidement possible d'un point à un autre.

Pour utiliser le programme nous lisons une configuration écrite sur l'entrée standard.
Le nombre de fourmis sont définis au lancement, puis vient les pièces de début, fin et autres déclarées comme-ci "nom, x, y",
puis ensuite sont déclarés les connexions entre pièces.

Exemples d'utilisations : 
$>cat anthill
4         #Nombre de fourmis
##start
0 1 2     #coordonnées pièce de départ
##end
1 2 3     #coordonnées pièce de fin
2 3 4
4 5 6
0-1
0-2
2-4
2-1
4-1

$>./lem_in < anthill
#number_of_ants
4
#rooms
##start
0 1 2
##end
1 2 3
2 3 4
4 5 6
#tunnels
0-1
0-2
2-4
2-1
4-1
#moves
P1-1
P2-1
P3-1
P4-1

Réalisés par :
Yohan Le Quéré (yohan.le-quere@epitech.eu)
Swann Giboureau (swann.giboureau@epitech.eu)
Thomas Yvert (thomas.yvert@epitech.eu)
Clément Quillateau (clement.quillateau@epitech.eu)
