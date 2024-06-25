NAME			=	HelloWorld

SOURCES			=	HelloWorld.s
OBJECTS			=	*.o

ASSEMBLER		=	nasm
ASSEMBLER_FLAGS	=	-f macho64

LINKER			=	ld
LINKER_FLAGS	=	-lsystem -e _start

all:	$(NAME)

$(OBJECTS):
	$(ASSEMBLER) $(ASSEMBLER_FLAGS) $(SOURCES)

$(NAME):	$(OBJECTS)
	$(LINKER) $(LINKER_FLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean:	clean
	rm $(NAME)

re: fclean all
