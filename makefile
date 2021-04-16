target = autoUpdateUVA
all:
	g++ -std=c++17 $(target).cpp -o $(target)
	./$(target)
	rm $(target)