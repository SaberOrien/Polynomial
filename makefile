headers = Poly.h
sources = Poly.cpp TestPoly.cpp
executable = TestPoly
$(executable): $(headers) $(sources)
	g++ -g -Wall -pedantic $(sources) -o $(executable)
.PHONY: clean
	rm $(executable)
.PHONY: check
check: $(executable)
	valgrind --leak-check=full --track-origins=yes ./$(executable)
