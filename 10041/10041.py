def getDistance(num, arr):
    if num == 0 :
        return 0
    if num//2 < 0 or num//2 > len(arr) :
    	print("index out of range!")
    	exit()
    mid = arr[num//2]
    sum = 0
    for item in arr :
        sum += abs(mid-item)
    return sum

num = int(input())
for i in range(num):
    line = list( map(int, input().split()) )
    l = line[1:]
    l.sort()
    print( str(getDistance(line[0], l)) )
