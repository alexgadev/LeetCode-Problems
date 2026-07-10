CXX      := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra
BUILD    := build

SRC  := $(wildcard $(N)-*.cpp)
NAME := $(basename $(SRC))
BIN  := $(BUILD)/$(NAME)

.PHONY: run build clean

run: build
	@./$(BIN)

build:
	@if [ -z "$(N)" ]; then echo "Usage: make [run|build] N=<problem_number>"; exit 1; fi
	@if [ -z "$(SRC)" ]; then echo "No source file found matching '$(N)-*.cpp'"; exit 1; fi
	@mkdir -p $(BUILD)
	@$(CXX) $(CXXFLAGS) $(SRC) -o $(BIN)

clean:
	rm -rf $(BUILD)
