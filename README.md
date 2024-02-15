My Version is not 100% correct => Do not rely on it. Update planned for 30/03/2024<br>
<br>
Parfois le texte est bien imprimé, et parfois il beug.<br>
Il rentre dans une boucle "infinie" lorsque le avec "cc -Wall -Wextra -Werror main.c get_next_line_utils.c get_next_line.c -D BUFFER_SIZE=21"<br>
Je dirais que c'est une histoire de buffer et d'allocation memoire. <br>
Parfois avec la meme compilation mais plusieurs sorties de a.out differentes, le programme ne donne pas le meme resultat.<br>
Il me semble que le probleme est au niveau de la lecture du buffer de la fonction read (2). J'ajoute a ma variable statique (nommee stash) tous les caracteres du buffer, alors que je pense que je devrais voir s'il y a un saut a la ligne dans ce buffer pour ajouter dans la stash que ce qui se trouve apres le '\n'. Je pense que je devrais aussi utiliser la fonction strchr qui imprime tous les caracteres qui se trouve apres un caractere en particulier, ici le '\n'<br>
<br>
 -fsanitize=address -g renvoie<br>
==41991==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x603000001735 at pc 0x00010590709e bp 0x7ffeea2fb6e0 sp 0x7ffeea2fb6d8<br>
READ of size 1 at 0x603000001735 thread T0<br>
    #0 0x10590709d in ft_strjoin get_next_line_utils.c:66<br>
    #1 0x1059075b6 in get_next_line get_next_line.c:105<br>
    #2 0x105906d45 in main main.c:54<br>
    #3 0x7fff6779dcc8 in start+0x0 (libdyld.dylib:x86_64+0x1acc8)<br>

0x603000001735 is located 0 bytes to the right of 21-byte region [0x603000001720,0x603000001735)
allocated by thread T0 here:<br>
    #0 0x10596317d in wrap_malloc+0x9d (libclang_rt.asan_osx_dynamic.dylib:x86_64h+0x4917d)<br>
    #1 0x105907514 in get_next_line get_next_line.c:98<br>
    #2 0x105906d45 in main main.c:54<br>
    #3 0x7fff6779dcc8 in start+0x0 (libdyld.dylib:x86_64+0x1acc8)<br>
