import io
if __name__ == '__main__':
	while True:
		try:
			n = io.readline()
		except EOFError:
			break
		n = int(n)
		num = (n+1)/2
		if n % 2 == 0:
			print num*(num+1)
		else:
			print num**2