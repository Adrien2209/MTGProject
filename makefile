CXX = g++
CXXFlag = -Wall -g -std=c++14 

%.o : %.cpp
	$(CXX) $(CXXFlag) $< -c -o $@

main : Carte.o Joueur.o Creature.o Terrain.o main.o
	g++ -std=c++14 $^ -o $@
	./$@
