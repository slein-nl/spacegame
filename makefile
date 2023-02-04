CXX = g++
CXXFLAGS = -O2 -Wall

all: spacegame

spacegame: spacegame.cpp
	$(CXX) $(CXXFLAGS) spacegame.cpp -o spacegame

install: spacegame
	install -m 0755 spacegame /usr/local/bin

clean:
	rm -f spacegame