#!/usr/bin/python

stair = []
for i in range(0,520):
	stair.append(0)

heap = []
for i in range(0,520):
	heap.append(stair[:])
	for j in range(0,520):
		heap[i][j] = -1
	heap[i][0] = 0

heap[0][0] = 1

def calc(n,k):
	t = 0
	if( k> n):
		k = n
	if(heap[n][k] >=0):
		return heap[n][k]
	if(n <= 2):
		if(k >= n):
			heap[n][k] = 1
		else :
			heap[n][k] = 0
		return heap[n][k]
	i = k
	while(i*(i+1) >= 2*n):
		lim = i -1;
		if(lim > n-i):
			lim = n-i
		t += calc(n-i,lim);
		i = i -1
	heap[n][k] = t
	return t

def fun(n):
	if(stair[n]):
		return
	if(n < 3):
		return
	t = 0
	i = n -1
	while(i > n-i):
		fun(n-i)
		t += stair[n-i]+1
		i -= 1
	while(i*(i+1) >= 2 * n):
		lim = i -1;
		if(lim > n-i):
			lim = n -i;
		calc(n-i,lim)
		t += heap[n-i][lim]
		i -= 1
	stair[n] = t

for i in range(3,510):
	fun(i)
for i in range(0,510):
	print "stair[",i,"]=",stair[i]

