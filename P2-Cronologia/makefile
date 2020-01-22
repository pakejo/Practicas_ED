# ***** Variables *****
LIBNAME   = cronologia

# ****** Directorios ********
INCLUDE   = include
LIB       = lib
OBJ       = obj
SRC       = src
BIN       = bin
DOC       = doc

# ****** Opciones de compilación ********
AR        = ar
CXX       = g++
CXXFLAGS  = -Wall -g -std=c++11 -c -I./$(INCLUDE)
LDFLAGS   = -L./$(LIB)
LDLIBS    = -l$(LIBNAME)


# ****** Compilación de módulos **********

.PHONY: all docs clean mrproper

all: $(BIN)/usoCronologia

$(BIN)/usoCronologia : $(OBJ)/usoCronologia.o $(LIB)/lib$(LIBNAME).a
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

$(LIB)/lib$(LIBNAME).a : $(OBJ)/FechaHistorica.o $(OBJ)/cronologia.o
	ar rvs $@ $^

$(OBJ)/usoCronologia.o : $(SRC)/usoCronologia.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

$(OBJ)/FechaHistorica.o : $(SRC)/FechaHistorica.cpp $(INCLUDE)/FechaHistorica.h
	$(CXX) $(CXXFLAGS) -o $@ $<

$(OBJ)/cronologia.o : $(SRC)/cronologia.cpp $(INCLUDE)/cronologia.h
	$(CXX) $(CXXFLAGS) -o $@ $<


# ************ Generación de documentación **************
docs:
	doxygen $(DOC)/doxys/Doxifile
	@echo "Documentación disponible en $(DOC)/html"


# ************ Limpieza ************

clean:
	-@rm -f $(OBJ)/* $(LIB)/*
	@echo "Limpiando..."

mrproper: clean
	-@rm -f $(BIN)/* $(LIB)/* -rf $(DOC)/html/*
	@echo "Limpieza completada."

# ************ Empaquetamiento ************
empaquetar: clean
	-@rm -f $(BIN)/* $(LIB)/* -rf $(DOC)/html/*
	@tar zcvf ../cronologia.tgz ../Cronologia