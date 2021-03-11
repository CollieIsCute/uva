def isEqualSquare(guess, bigNum):
	guessSq = guess*guess
	if guessSq == bigNum:
		return True
	return False

def mySqrt(bigNum):
	length = len(bigNum)
	guessBig = bigNum = int(bigNum)
	guessSmall = int(0)
	guess = (guessBig+guessSmall)//2
	guessSq = guess*guess
	while not isEqualSquare(guess, bigNum):
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