Parfois le texte est bien imprimé, et parfois il beug.
Il rentre dans une boucle "infinie" lorsque le avec "cc -Wall -Wextra -Werror main.c get_next_line_utils.c get_next_line.c -D BUFFER_SIZE=10000000"
Je dirais que c'est une histoire de buffer et d'allocation memoire. 
Parfois la meme compilation mais plusieurs sorties de a.out differentes ne donne pas le meme resultat.
