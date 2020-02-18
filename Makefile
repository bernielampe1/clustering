CC := g++
CFLAGS := -g -Wall -std=c++11

BIN := cluster
SRCS := main.cc

.PHONY: all
all: $(BIN)

$(BIN): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: format
format:
	clang-format -i *.cc *.h *.inl

.PHONY: clean
clean:
	rm -rf *.o *.dSYM $(BIN)

