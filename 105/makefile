target = 105
all:
	g++ -g -std=c++17 $(target).cpp -o $(target)
compress:
	make clean # in order not to compress recursively
	zip -r B073040019-蔡孟師-$(target) ./*
clean:
	rm -f $(target) B073040019-蔡孟師-$(target).zip
dclean:
	rm -f $(target) B073040019-蔡孟師-$(target).zip *input* *output*