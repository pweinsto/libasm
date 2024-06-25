NAME		=	libasm.a
TEST		=	test

# Source files for assembly
SSOURCES	=	HelloWorld.s \
				ft_write.s \
				ft_read.s

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

# Compiler and compiler flags
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

# Default target to build the library
all:	$(NAME)

# Pattern rule to compile .s files to .o files
%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

# Rule to create the static library from object files
$(NAME):	$(SOBJECTS)
	$(AR) $(ARFLAGS) $(NAME) $(SOBJECTS)

# Rule to build and run the test
test:	all
	$(CC) $(CFLAGS) $(CSOURCES) $(NAME) -o $(TEST)

# Rule to clean up object files
clean:
	rm -f $(SOBJECTS)

# Rule to clean up everything including the library and test executable
fclean:	clean
	rm -f $(NAME) $(TEST)

# Rule to force a rebuild
re: fclean all
