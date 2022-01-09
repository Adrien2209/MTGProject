CXX = g++
CXXFlag = -Wall -g -std=c++14 

%.o : %.cpp
	$(CXX) $(CXXFlag) $< -c -o $@

main : Carte.o Creature.o main.o
	g++ -std=c++14 $^ -o $@
	./$@
