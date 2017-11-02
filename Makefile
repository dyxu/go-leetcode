EXE = /tmp/main
SRC = main.cpp
CC = g++

.PHONY: run clean
run: $(EXE)
	@$(EXE)

$(EXE): $(SRC)
	@$(CC) -o $(EXE) $< -std=c++11 -g

clean:
	@ [ -f $(EXE) ] && rm $(EXE)
