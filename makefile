CXX = g++
CXXFlag = -Wall -g -std=c++17 

build/%.o : src/%.cpp
	$(CXX) $(CXXFlag) $< -c -o $@

main : build/printAffichage.o build/Color.o build/Carte.o build/Joueur.o build/Creature.o build/Terrain.o build/Enchantement.o build/Partie.o build/Deck.o build/main.o
	g++ -std=c++17 $^ -o $@


clean:
	rm -f build/*.o main

