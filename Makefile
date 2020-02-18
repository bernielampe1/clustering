CC := g++
CFLAGS := -g -Wall

BIN := cluster
SRCS := main.cc

.PHONY: all
all: $(BIN)

$(BIN): $(SRCS)
	$(CC) $(FLAGS) $^ -o $@

.PHONY: format
format:
	clang-format -i *.cc *.h *.inl

.PHONY: clean
clean:
	rm -rf *.o *.dSYM $(BIN)

