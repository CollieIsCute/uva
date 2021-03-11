def isAlmostEqualSquare(guess, bigNum):
	guessSq = guess*guess
	if guessSq == bigNum:
		return True
#	elif guessSq<bigNum and (guess+1)*(guess+1)>bigNum:
#		return True
	return False

def mySqrt(bigNum):
	length = len(bigNum)
	guessBig = bigNum = int(bigNum)
	guessSmall = int(0)
	if(length>10):
		guessBig = int('1'*(length//7*4))
		guessSmall = int('1'*(length//7*3))
	guess = (guessBig+guessSmall)//2
	guessSq = guess*guess
	while not isAlmostEqualSquare(guess, bigNum):
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