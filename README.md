Parfois le texte est bien imprimé, et parfois il beug.<br>
Il rentre dans une boucle "infinie" lorsque le avec "cc -Wall -Wextra -Werror main.c get_next_line_utils.c<br>
get_next_line.c -D BUFFER_SIZE=10000000"<br>
Je dirais que c'est une histoire de buffer et d'allocation memoire. <br>
Parfois la meme compilation mais plusieurs sorties de a.out differentes ne donne pas le meme resultat.<br>
Il me semble que le probleme est au niveau de la lecture du buffer de la fonctione read (2). J'ajoute a ma variable statique (nommee stash) tous les caracteres du buffer, alors que je pense que je devrais voir s'il y a un saut a la ligne dans ce buffer pour ajouter dans la stash que ce qui se trouve apres le '\n'. Je pense que je devrais aussi utiliser la fonction strchr qui imprime tous les caracters qui il y a apres un caractere en particulier, ici le '\n'<br>
<br>
 -fsanitize=address renvoie<br>
 ==30417==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x61b000000d8e at pc 0x00010f5f4159 bp 0x7ffee060e6b0 sp 0x7ffee060e6a8<br>
WRITE of size 1 at 0x61b000000d8e thread T0<br>
    #0 0x10f5f4158 in ft_strjoin+0x188 (a.out:x86_64+0x100003158)<br>
    #1 0x10f5f45b6 in get_next_line+0xb6 (a.out:x86_64+0x1000035b6)<br>
    #2 0x10f5f3d45 in main+0x55 (a.out:x86_64+0x100002d45)<br>
    #3 0x7fff6779dcc8 in start+0x0 (libdyld.dylib:x86_64+0x1acc8)<br>
<br>
0x61b000000d8e is located 0 bytes to the right of 1550-byte region [0x61b000000780,0x61b000000d8e)<br>
allocated by thread T0 here:<br>
    #0 0x10f65017d in wrap_malloc+0x9d (libclang_rt.asan_osx_dynamic.dylib:x86_64h+0x4917d)<br>
    #1 0x10f5f4438 in ft_calloc+0x28 (a.out:x86_64+0x100003438)<br>
    #2 0x10f5f4018 in ft_strjoin+0x48 (a.out:x86_64+0x100003018)<br>
    #3 0x10f5f45b6 in get_next_line+0xb6 (a.out:x86_64+0x1000035b6)<br>
    #4 0x10f5f3d45 in main+0x55 (a.out:x86_64+0x100002d45)<br>
    #5 0x7fff6779dcc8 in start+0x0 (libdyld.dylib:x86_64+0x1acc8)<br>
