CXX = g++
CXXFLAGS = -std=c++17 -L/opt/X11/lib -I /opt/X11/include -I include -I include/fibonacci_heap/ -I include/eda_disjoint_set/include/ -o $@
TARGET = bin/main
DIRS = bin build
CXXLINK = -lX11 -ljpeg -lpng -lz

OBJFILES = $(patsubst src/%.cpp, build/%.o, $(wildcard src/*.cpp))
BINFILES = $(patsubst app/%.cpp, bin/%, $(wildcard app/*.cpp))

.PRECIOUS: $(OBJ)/%.o

all: $(DIRS) $(BINFILES)

$(DIRS):
	mkdir $@

bin/%: app/%.cpp $(OBJFILES)
	$(CXX) $(CXXFLAGS) $^ $(CXXLINK)

build/%.o: src/%.cpp include/%.hpp
	$(CXX) $(CXXFLAGS) -c $< $(CXXLINK)

clean:
	rm -rf $(DIRS)
