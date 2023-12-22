CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
LIBS = -lsndfile -lsfml-audio -lsfml-system

SRC_DIR = src
BIN_DIR = bin

audio_player: $(SRC_DIR)/main.cpp
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)/audio_player $(SRC_DIR)/main.cpp $(LIBS)

clean:
	rm -f $(BIN_DIR)/audio_player
