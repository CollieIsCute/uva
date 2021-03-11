def mySqrt(bigNum):
	length = len(bigNum)
	guessBig = bigNum = int(bigNum)
	guessSmall = int(0)
#	if length > 10:
#		guessBig = int('9'*(length//7*4))
#		guessSmall = int('1'*(length//7*3))
	guess = (guessBig+guessSmall)//2
	guessSq = guess*guess
	while True:
		if guessSmall==guessBig: break
		elif guessSq > bigNum:
			guessBig = guess-1
		elif guessSq < bigNum:
			guessSmall = guess+1
		else: break
		guess = (guessBig+guessSmall)//2
		guessSq = guess*guess
	return guess

n = input()
for i in range(int(n)):
	inp = input()
	while(inp==""):
		print(inp)
		inp = input()
	output = mySqrt(inp)
	print(output)