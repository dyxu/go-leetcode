EXE = /tmp/main
SRC = main.cpp
CC = clang++

.PHONY: run clean
run: $(EXE)
	@$(EXE)

$(EXE): $(SRC)
	@$(CC) -o $(EXE) $< -std=c++11

clean:
	@ [ -f $(EXE) ] && rm $(EXE)