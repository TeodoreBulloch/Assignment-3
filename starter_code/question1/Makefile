.DEFAULT_GOAL := all

PROGRAMS := program
SOURCES := main.cpp Patient.cpp PatientRegister.cpp WaitingList.cpp
OBJECTS := $(SOURCES:.cpp=.o)
CXXFLAGS := -Wall -Werror -std=c++14 -g -O

all: $(PROGRAMS)

clean:
	rm -rf $(PROGRAMS) $(OBJECTS) *.dSYM

$(PROGRAMS): $(OBJECTS)
	g++ $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	g++ $(CXXFLAGS) -c -o $@ $^
