def mySqrt(bigNum):
	length = len(bigNum)
	guessBig = bigNum = int(bigNum)
	guessSmall = int(0)
#	if length > 10:
#		guessBig = int('9'*(length//7*4))
#		guessSmall = int('1'*(length//7*3))
	guess = (guessBig+guessSmall)//2
	guessSq = guess*guess
	while guessSq != bigNum:
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