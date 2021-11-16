#!bin/bash/
BUFF=32

make -C libft
case ${1} in
    "-ll")	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$BUFF libft/libft.a get_next_line.c lblmain.c -o gnl 
        ;;
    *)		gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$BUFF libft/libft.a get_next_line.c fbfmain.c -o gnl 
esac
make fclean -C libft
