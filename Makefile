NAME		=	libasm.a
TEST		=	tester

# Source files for assembly
SSOURCES	=	src/ft_write.s \
				src/ft_read.s \
				src/ft_strlen.s \
				src/ft_strcpy.s \
				src/ft_strcmp.s \
				src/ft_strdup.s

# Object files derived from the assembly source files
SOBJECTS	=	$(SSOURCES:.s=.o)

# Assembler and assembler flags
AS			=	nasm
ASFLAGS		=	-f macho64

# Archive tool and flags
AR			=	ar
ARFLAGS		=	rcs

# Source files for C
CSOURCES	=	test/main.c \
				test/cerror.c \
				test/read_test.c \
				test/write_test.c \
				test/strlen_test.c \
				test/strcmp_test.c \
				test/strcpy_test.c \
				test/strdup_test.c

# Object files derived from the C source files
COBJECTS    =   $(CSOURCES:.c=.o)

# Compiler and compiler flags
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

# Linker flags
LDFLAGS		=	-L. -lasm

# Default target to build the library
all:	$(NAME) $(TEST)

# Pattern rule to compile .s files to .o files
%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

# Pattern rule to compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the static library from object files
$(NAME):	$(SOBJECTS)
	$(AR) $(ARFLAGS) $(NAME) $(SOBJECTS)

# Rule to build the test executable only if necessary
$(TEST):	$(COBJECTS) $(NAME)
	$(CC) $(COBJECTS) $(NAME) $(LDFLAGS) -o $(TEST)

# Rule to clean up object files
clean:
	rm -f $(SOBJECTS) $(COBJECTS)

# Rule to clean up everything including the library and test executable
fclean:	clean
	rm -f $(NAME) $(TEST)

# Rule to force a rebuild
re: fclean all
