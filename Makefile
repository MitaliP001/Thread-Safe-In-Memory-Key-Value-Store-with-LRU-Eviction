CXX=clang++
CXXFLAGS=-std=c++17 -Wall -Wextra -O2

SRC=src/main.cpp src/kv_store.cpp src/lru_cache.cpp
TARGET=kv_store

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
