target = 11658

all:
	g++ -g -std=c++17 $(target).cpp -o $(target)
test:
	g++ -g -std=c++17 B07*.cpp -o $(target)-2
compress:
	make clean # in order not to compress recursively
	zip -r B073040019-蔡孟師-$(target) ./*
clean:
	rm -f $(target) B073040019-蔡孟師-$(target).zip