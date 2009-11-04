#!/usr/bin/python

COMMENT = """
	生成2604.c所需要的映射表

"""

brace = []
ele = []

for i in range(0,52):
	ele.append(0)
	brace.append(ele[:])
brace[0][0] = 1	
brace[1][1] = 1
brace[2][1] = 1
brace[2][2] = 1
brace[3][1] = 1
brace[3][2] = 3
brace[3][3] = 1

def left(i,d):
	if( d<=1 or i<= 1):
		return 1
	if(d > i):
		d = i
	return brace[i][d]

def right(i,d):
	if( d<=1 or i<= 1):
		return 1
	if(d > i):
		d = i
	t = 0
	for k in range(1,d+1):
		t = t + brace[i][k]
	return t

def calc(n,k):
	if(brace[n][k]):
		return brace[n][k]
	if(n < 1 or k < 1):
		return 1
	t = 0 
	for i in range(0,n-k+1):
		for j in range(0,i+1):
			t = t + right(j,k-1) * calc(n-i-1,k-1) * right(i-j,k)
	if(t < 1):		
		t	= 1
	brace[n][k] = t
#	print "t =",t
	return t

for x in range(4,52):
	brace[x][1] = 1
	for y in range(1,x+1):
#		print "calc... ", x,y
		calc(x,y)
for x in range(1,52):
	for y in range(1,x+1):
		print "\ttable[", x, "][",y ,"] = \"" + str(brace[x][y]) + "\";"
