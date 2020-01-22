# ***** Variables *****
LIBNAME   = PILA_MAX

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

all: $(BIN)/usoPila

$(BIN)/usoPila : $(OBJ)/usoPila.o
	$(CXX) -o $@ $^

$(OBJ)/usoPila.o : $(SRC)/usoPila.cpp
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
	@tar --exclude='.vscode' -zcvf ../PilaMax.tgz ../PILA_MAX