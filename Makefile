CXX       := g++
CXXFLAGS  := -O2 --debug
LDFLAGS   := -lm -lfmt

SRC       := $(wildcard *.cpp)
TARGETS   := $(patsubst %.cpp, %.out, $(SRC))

.PHONY: all clean format

all: $(TARGETS)

$(TARGETS): %.out: %.cpp
	$(CXX) $< $(CXXFLAGS) $(LDFLAGS) -o $@

clean:
	rm -f $(TARGETS)

format:
	clang-format -style=Microsoft -i *.cpp
