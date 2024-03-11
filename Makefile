all: add-nbo

add-nbo: main.cpp
	g++ -std=c++11 -o $@ $^

clean:
	rm -f add-nbo

