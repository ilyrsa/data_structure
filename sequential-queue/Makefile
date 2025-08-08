# Define o compilador C++
CXX = g++

# Define as flags de compilação (padrões recomendados)
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# Define o nome do executável final
TARGET = programa_fila

# Define os arquivos de código-fonte
SOURCES = main.cpp

# Regra principal: compila o programa
all: $(TARGET)

# Regra para linkar os arquivos objeto e criar o executável
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

# Regra para limpar os arquivos gerados (executável e objetos)
clean:
	rm -f $(TARGET) *.o

# Regra para executar o programa
run: $(TARGET)
	./$(TARGET)