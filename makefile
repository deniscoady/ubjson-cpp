PROJECT_NAME = ubjson

CC=g++
CC_FLAGS= \
	-c \
	-std=c++0x \
	-Wall -Wno-unused-variable \
	-Iinclude

LD_FLAGS=
CPP_FILES= $(wildcard src/*.cpp)
OBJ_FILES=$(addprefix bin/,$(notdir $(CPP_FILES:.cpp=.o)))

all: $(CPP_FILES) $(PROJECT_NAME)

LIBRARY= lib$(PROJECT_NAME).a
EXECUTABLE= $(PROJECT_NAME).exe
	
$(PROJECT_NAME): $(OBJ_FILES) 
	@echo "[link]"
	@$(CC) $(OBJ_FILES) $(LD_FLAGS) -o $@
	@echo "[done] $(EXECUTABLE): Compilation finished!"

bin/%.o: src/%.cpp
	@echo "[make] $@"
	@$(CC) $(CC_FLAGS) $< -o $@

lib:
	ar rcs $(LIBRARY) $(OBJ_FILES)
	@echo "[make] $(LIBRARY): Compilation finished!"

clean:
	@echo "[make] clean: Deleting bin/*.o files"
	@rm -f $(OBJ_FILES) *.o core