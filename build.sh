#cd libft && make fclean && make && cd ..
#cd minilibx_macos && make re && cd ..
gcc -Wall -Werror -Wextra -framework OpenGL -framework AppKit src/fdf.c libft/libft.a minilibx_macos/libmlx.a -o fdf
./fdf
