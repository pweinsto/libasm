NAME		=	libasm.a
TEST		=	test

SSOURCES	=	HelloWorld.s
SOBJECTS	=	*.o

AS			=	nasm
ASFLAGS		=	-f macho64

AR			=	ar
ARFLAGS		=	rcs

CSOURCES	=	main.c

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra


all:	$(NAME)

$(SOBJECTS):
	$(AS) $(ASFLAGS) $(SSOURCES)

$(NAME):	$(SOBJECTS)
	$(AR) $(ARFLAGS) $(NAME) $(SOBJECTS)

test:	all
	$(CC) $(CFLAGS) $(CSOURCES) $(NAME) -o $(TEST)

clean:
	rm -f $(SOBJECTS)

fclean:	clean
	rm -f $(NAME) $(TEST)

re: fclean all
