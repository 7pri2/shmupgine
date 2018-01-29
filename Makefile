.SUFFIXES:
# directories
OBJ=obj/
HEADERS=include/
SRC=src/
TESTS=tests/

CXX=g++
CXXFLAGS=-Wall -Werror -Wextra -std=c++11 -pedantic-errors -I$(HEADERS)
SFML=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
EXECUTABLES=demo
DEBUG=-g

all: executables

debug: CXXFLAGS+=$(DEBUG) -DDEBUG
debug: executables

windows: CXX=x86_64-w64-mingw32-g++
windows: CXXFLAGS+= -I/usr/include/
windows: SFML= -L/usr/lib/ $(SFML)
windows: executables

executables: $(EXECUTABLES)

OBJFILES=systems.o			\
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
	  soundmanager.o	\
	  movement.o

OBJS=$(patsubst %,$(OBJ)%,$(OBJFILES))

demo: $(TESTS)demo.cpp $(HEADERS)shmupgine.h $(OBJS)
	$(CXX) $(CXXFLAGS) $< -o $(TESTS)$@ $(SFML) $(OBJS)

$(OBJ)bullet.o: $(HEADERS)graphicrenderer.h $(HEADERS)physics.h
$(OBJ)physics.o: $(HEADERS)systems.h $(HEADERS)entity.h
$(OBJ)scene.o: $(HEADERS)systems.h $(HEADERS)entity.h
$(OBJ)controls.o: $(HEADERS)entity.h
$(OBJ)attribute.o: $(HEADERS)entity.h
$(OBJ)destructor.o: $(HEADERS)entity.h $(HEADERS)scene.h
$(OBJ)spawner.o: $(HEADERS)entity.h $(HEADERS)scene.h

$(OBJ)%.o:	$(SRC)%.cpp $(HEADERS)%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)*.o
