CC=g++
CFLAGS=-Wall
SRC_DIR=src
OBJ_DIR=obj
BIN_DIR=bin
FILES=\
$(addprefix $(OBJ_DIR)/, \
$(addsuffix .o, \
main log \
)) # Add filenames without extensions to line above
BIN=what

all: $(BIN_DIR)/$(BIN)

$(BIN_DIR)/$(BIN): $(FILES) | $(BIN_DIR)
	$(CC) $^ -o $@

$(FILES): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR):
	mkdir $(BIN_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	rm -rf bin obj
