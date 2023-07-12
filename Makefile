CXX = g++ -std=c++17

CXXFLAGS = -Wall -Werror

LIBRARY_NAME = wrapper

SOURCES = src/main/java/com/edu/school21/smartcalc/core/*.cc

LIBRARY_OUTPUT = $(LIBRARY_NAME).so

default: all

all: $(LIBRARY_OUTPUT)


$(LIBRARY_OUTPUT): $(SOURCES)
	$(CXX) -fPIC -shared -arch arm64 -o $@ $^

clean:
	rm -f $(LIBRARY_OUTPUT)


