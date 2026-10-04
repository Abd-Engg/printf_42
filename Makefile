source = ft_printf.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_puthex.c  ft_put_unsigned_nbr_fd.c
lib = libftprintf.a
obj =$(source:.c=.o)

all : $(lib)

$(lib) : $(obj)
	ar rcs $(lib) $(obj)

%.o : %.c
	cc -Wall -Wextra -Werror -c $< -o $@

clean :
	rm -f $(obj)

fclean : clean
	rm -f $(lib)

re : fclean all

.PHONY : all clean fclean re