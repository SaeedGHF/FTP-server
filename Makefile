CC=g++ -std=c++11
FLAGS=-w
SRC_DIR=src

client: $(SRC_DIR)/Client.cpp server
	$(CC) $(FLAGS) $(SRC_DIR)/Client.cpp -o client

server: $(SRC_DIR)/Server.cpp
	$(CC) $(FLAGS) $(SRC_DIR)/Server.cpp -o server

clean:
	-rm -f *.o
	-rm ./client
	-rm ./server
	-rm ./log