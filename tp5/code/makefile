# source files.

SRC = $(wildcard src/*.cpp)

OBJ = $(patsubst src%, obj%.o, $(SRC))

OUT = bin/cgra-tp5

# include directories
INCLUDES = -I. -I./include/  -I./include/CGF -I/usr/local/include

# C++ compiler flags (-g -O2 -Wall)
CCFLAGS = -g

# compiler
CCC = g++

# library paths
LIBS = -Llib -L/usr/local/lib -L/usr/lib  -lCGF -lm -lglut -lglui -lGL -lGLU

# compile flags
LDFLAGS = -g

.SUFFIXES: .cpp

default: $(OUT)

obj/%.o: src/%
	mkdir -p obj
	$(CCC) $(INCLUDES) $(CCFLAGS) -c $< -o $@

$(OUT): $(OBJ)
	mkdir -p bin
	$(CCC) $(INCLUDES) $(CCFLAGS) $(OBJ) $(LIBS) -o $(OUT)

all: $(OUT)

obj/%.o: src/%
	mkdir -p obj
	$(CCC) $(INCLUDES) $(CCFLAGS) -c $< -o $@

$(OUT): $(OBJ)
	mkdir -p bin
	$(CCC) $(INCLUDES) $(CCFLAGS) $(OBJ) $(LIBS) -o $(OUT)

clean:
	rm -f $(OBJ) $(OUT)
	rm -rf obj

test:
	echo $(SRC)
	echo $(OBJ)

