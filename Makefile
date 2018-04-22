.SUFFIXES:
# directories
OBJ=obj/
HEADERS=include/
SRC=src/
LIB=lib/
LCOV=lcov/
TESTS=tests/

CXX=g++
CXXFLAGS=-Wall -Werror -Wextra -std=c++11 -pedantic-errors -I$(HEADERS)
LDFLAGS=-L$(LIB) -lshmupgine -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
GCOVFLAGS=-fprofile-arcs -ftest-coverage -pg
DEBUG=-g
BROWSER=firefox

EXECUTABLES=$(TESTS)demo
LIBFILES=libshmupgine.a
OBJFILES=systems.o		\
	  entity.o			\
	  graphicrenderer.o	\
	  gmanager.o		\
	  physics.o			\
	  scene.o			\
	  controls.o		\
	  attribute.o		\
	  destructor.o		\
	  spawnslot.o		\
	  spawner.o			\
	  soundmanager.o	\
	  movement.o
OBJS=$(patsubst %,$(OBJ)%,$(OBJFILES))
LIBS=$(patsubst %,$(LIB)%,$(LIBFILES))

all: executables libs

tests: $(patsubst %.cpp,%,$(wildcard $(TESTS)test_*))

documentation: doxy-convert.conf
	doxygen $<
	#$(BROWSER) `pwd`/doc/doxygen/html/index.html &

debug: CXXFLAGS+=$(DEBUG) -DDEBUG $(GCOVFLAGS)
debug: all tests

executables: $(EXECUTABLES)
libs: $(LIBS)

coverage: $(EXECUTABLES) $(wildcard $(SRC)*)
	gcov -b -c -o $(OBJ) $^
	lcov --directory $(OBJ) -c -o $(LCOV)rapport.info
	genhtml $(LCOV)rapport.info --output-directory $(LCOV)
	$(BROWSER) `pwd`/$(LCOV)index.html

$(TESTS)demo: $(TESTS)demo.cpp $(HEADERS)shmupgine.h $(LIB)libshmupgine.a
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

$(TESTS)%: $(TESTS)%.cpp $(HEADERS)shmupgine.h $(LIB)libshmupgine.a
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

$(LIB)libshmupgine.a: $(OBJS)
	ar -cr $@ $^ 

$(OBJ)bullet.o: $(HEADERS)graphicrenderer.h $(HEADERS)physics.h
$(OBJ)physics.o: $(HEADERS)systems.h $(HEADERS)entity.h
$(OBJ)scene.o: $(HEADERS)systems.h $(HEADERS)entity.h
$(OBJ)controls.o: $(HEADERS)entity.h
$(OBJ)attribute.o: $(HEADERS)entity.h
$(OBJ)destructor.o: $(HEADERS)entity.h $(HEADERS)scene.h
$(OBJ)spawner.o: $(HEADERS)entity.h
$(OBJ)spawnslot.o: $(HEADERS)entity.h $(HEADERS)scene.h $(HEADERS)spawner.h

$(OBJ)%.o:	$(SRC)%.cpp $(HEADERS)%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	-rm -rf $(OBJ)*
	-rm -rf *.gcda
	-rm -rf $(EXECUTABLES) 
	-rm -rf $(patsubst %,$(LIB)%,$(LIBS)) 
