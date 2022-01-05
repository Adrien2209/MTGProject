CXX = g++
CXXFlag = -std=c++14 

%.o : %.cpp
	$(CXX) $(CXXFlag) $< -c -o $@

main : Main.o
	g++ -std=c++14 $^ -o $@
	./$@
