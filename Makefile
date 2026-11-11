CC      := gcc
CFLAGS  := -Wall -Wextra -std=c11 -D_POSIX_C_SOURCE=200809L
TARGET  := program
SRCS    := $(wildcard src/*.c src/cli/*.c)
HEADERS := $(wildcard src/*.h src/cli/*.h)

.PHONY: build clean run

build: $(TARGET)

$(TARGET): $(SRCS) $(HEADERS)
	@echo "Building program..."
	$(CC) $(CFLAGS) -o $@ $(SRCS)
	@echo "Finished building the program..."

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
