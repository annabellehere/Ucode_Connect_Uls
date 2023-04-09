CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -g #-L/usr/lib/x86_64-linux-gnu -lacl
NAME = uls

OBJ = obj
INC = inc
SRC = src

OBJ_FILES = $(addprefix $(OBJ)/, $(notdir $(SRC_FILES:%.c=%.o)))
INC_FILES = $(wildcard $(INC)/*.h)
SRC_FILES = $(wildcard $(SRC)/*.c)

LIB_DIR = libmx
LIB_INC = $(LIB_DIR)/inc
LIB_A = $(LIB_DIR)/libmx.a

RM = rm -rf
MKDIR = mkdir -p
LIBMX = make -sC

all: $(LIB_A) $(NAME) clean

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -L$(LIB_DIR) -lmx -o $@

$(OBJ_FILES): | $(OBJ)

$(OBJ)/%.o: $(SRC)/%.c $(INC_FILES)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC) -I$(LIB_INC)

$(OBJ):
	@$(MKDIR) $@

$(LIB_A):
	@$(LIBMX) $(LIB_DIR)

clean:
	@$(RM) $(OBJ)

uninstall: clean
	@$(LIBMX) $(LIB_DIR) $@
	@$(RM) $(NAME)

reinstall: uninstall all

