NAME		=	libasm.a
TEST		=	test

# Source files for assembly
SSOURCES	=	HelloWorld.s \
				ft_write.s \
				ft_read.s \
				ft_strlen.s \
				ft_strcpy.s \
				ft_strcmp.s \
				ft_strdup.s

# Object files derived from the assembly source files
SOBJECTS	=	$(SSOURCES:.s=.o)

# Assembler and assembler flags
AS			=	nasm
ASFLAGS		=	-f macho64

# Archive tool and flags
AR			=	ar
ARFLAGS		=	rcs

# Source files for C
CSOURCES	=	main.c

# Object files derived from the C source files
COBJECTS    =   $(CSOURCES:.c=.o)

# Compiler and compiler flags
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

# Default target to build the library
all:	$(NAME)

# Pattern rule to compile .s files to .o files
%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

# Pattern rule to compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the static library from object files
$(NAME):	$(SOBJECTS)
	$(AR) $(ARFLAGS) $(NAME) $(SOBJECTS)

# Rule to build and run the test
test:	all $(COBJECTS)
	$(CC) $(COBJECTS) $(NAME) -o $(TEST)

# Rule to clean up object files
clean:
	rm -f $(SOBJECTS) $(COBJECTS)

# Rule to clean up everything including the library and test executable
fclean:	clean
	rm -f $(NAME) $(TEST)

# Rule to force a rebuild
re: fclean all
