# ****** Directorios ********
INCLUDE   = include
OBJ       = obj
SRC       = src
BIN       = bin
DOC       = doc

# ****** Opciones de compilación ********
CXX       = g++
CXXFLAGS  = -g -std=c++11 -c -I./include

# ****** Programas **********
all: $(BIN)/letrasSET $(BIN)/letrasARB $(BIN)/cantidadLetras

$(BIN)/letrasSET : $(OBJ)/Diccionario.o $(OBJ)/Diccionario2.o $(OBJ)/BolsaLetras.o $(OBJ)/ConjuntoLetras.o $(OBJ)/Letras.o $(OBJ)/IA.o $(SRC)/letras.cpp
	$(CXX) -g -std=c++11 -D SET -o $@ $^ -I./include

$(BIN)/letrasARB : $(OBJ)/Diccionario.o $(OBJ)/Diccionario2.o $(OBJ)/BolsaLetras.o $(OBJ)/ConjuntoLetras.o $(OBJ)/Letras.o $(OBJ)/IA.o $(SRC)/letras.cpp
	$(CXX) -g -std=c++11 -D ARB -o $@ $^ -I./include

$(BIN)/cantidadLetras : $(OBJ)/Diccionario.o $(OBJ)/Letras.o $(SRC)/cantidadLetras.cpp
	$(CXX) -g -std=c++11 -o $@ $^ -I./include

#*************** Archivos .o *******************
$(OBJ)/Diccionario.o : $(SRC)/Diccionario.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

$(OBJ)/Diccionario2.o : $(SRC)/Diccionario2.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

$(OBJ)/BolsaLetras.o : $(SRC)/BolsaLetras.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

$(OBJ)/ConjuntoLetras.o : $(SRC)/ConjuntoLetras.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

$(OBJ)/Letras.o : $(SRC)/Letra.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

$(OBJ)/IA.o : $(SRC)/IA.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# ************ Generación de documentación **************
docs:
	doxygen $(DOC)/doxys/Doxifile
	@echo "Documentación disponible en $(DOC)/html"


# ************ Limpieza ************

clean:
	-@rm -rf $(OBJ)/* $(DOC)/html $(DOC)/latex $(BIN)/*
	@echo "Limpiando..."