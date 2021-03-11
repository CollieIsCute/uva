import math

def isAlmostEqualSquare(guess, bigNum):
	if guess*guess == bigNum or (guess+1)*(guess+1)==bigNum:
		return True
	elif (guess*guess<bigNum) and (guess+1)*(guess+1)>bigNum:
		return True
	return False

def mySqrt(bigNum):
	length = len(str(bigNum))
	guessBig = int(bigNum)
	guessSmall = int(0)
	if(length>10):
		guessBig = int('1'*(length//7*4))
		guessSmall = int('1'*(length//7*3))
	guess = (guessBig+guessSmall)//2
	while not isAlmostEqualSquare(guess, bigNum):
		if guess*guess > bigNum:
			guessBig = guess
		else:
			guessSmall = guess
		guess = (guessBig+guessSmall)//2
	if (guess+1)*(guess+1) == bigNum:
		return guess+1
	else:
		return guess


n = input()
for i in range(int(n)):
	inp = input()
	while(inp==""):
		inp = input()
	inp = int(inp)
	output = mySqrt(inp)
	print(output, end="\n\n")