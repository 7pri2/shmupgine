.SUFFIXES:
# directories
OBJ=obj/
HEADERS=include/
SRC=src/
TESTS=tests/

CXX=g++
CXXFLAGS=-Wall -Werror -Wextra -std=c++11 -pedantic-errors -I$(HEADERS)
SFML=-lsfml-graphics -lsfml-window -lsfml-system
EXECUTABLES=test
DEBUG=-g

all: executables

debug: CXXFLAGS+=$(DEBUG) -DDEBUG
debug: executables

windows: CXX=x86_64-w64-mingw32-g++
windows: CXXFLAGS+= -I/usr/include/
windows: SFML= -L/usr/lib/ $(SFML)
windows: executables

executables: $(EXECUTABLES)

FILES=systems.o			\
	  entity.o			\
	  graphicrenderer.o	\
	  gmanager.o		\
	  physics.o			\
	  scene.o			\
	  controls.o		\
	  attribute.o		\
	  destructor.o		\
	  spawner.o			\
	  debug.o			\
	  bar.o

OBJS=$(patsubst %,$(OBJ)%,$(FILES))

test: $(TESTS)test.cpp $(HEADERS)shmupgine.h $(OBJS)
	$(CXX) $(CXXFLAGS) $< -o $(TESTS)$@ $(SFML) $(OBJS)

$(OBJ)bullet.o: $(SRC)bullet.cpp $(HEADERS)bullet.h $(HEADERS)graphicrenderer.h $(HEADERS)physics.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ)physics.o: $(SRC)physics.cpp $(HEADERS)physics.h $(HEADERS)systems.h $(HEADERS)entity.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ)scene.o: $(SRC)scene.cpp $(HEADERS)scene.h $(HEADERS)systems.h $(HEADERS)entity.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ)controls.o: $(SRC)controls.cpp $(HEADERS)controls.h $(HEADERS)entity.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ)attribute.o: $(SRC)attribute.cpp $(HEADERS)attribute.h $(HEADERS)entity.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ)destructor.o: $(SRC)destructor.cpp $(HEADERS)destructor.h $(HEADERS)entity.h $(HEADERS)scene.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ)spawner.o: $(SRC)spawner.cpp $(HEADERS)spawner.h $(HEADERS)entity.h $(HEADERS)scene.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ)%.o:	$(SRC)%.cpp $(HEADERS)%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)*.o

mrproper: clean
	rm -rf executables
