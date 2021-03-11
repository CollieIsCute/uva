def isEqualSquare(guessSq, bigNum):
	return guessSq == bigNum

def mySqrt(bigNum):
	length = len(bigNum)
	guessBig = bigNum = int(bigNum)
	guessSmall = int(0)
	guess = (guessBig+guessSmall)//2
	guessSq = guess*guess
	while not isEqualSquare(guessSq, bigNum):
		if guessSq > bigNum:
			guessBig = guess-1
		else:
			guessSmall = guess+1
		guess = (guessBig+guessSmall)//2
		guessSq = guess*guess
	return guess

n = input()
for i in range(int(n)):
	inp = input()
	while(inp==""):
		inp = input()
	output = mySqrt(inp)
	print(output, end="\n\n")