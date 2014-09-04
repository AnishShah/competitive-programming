import sys
for n in sys.stdin.readlines():
	n = int(n)
	if n == 1:
		print 1
	else:
		print 2*(n-1)