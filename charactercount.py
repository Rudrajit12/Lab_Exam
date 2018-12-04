file = open('sample.txt','r')
d = {}

for i in file.read():
	d[i] = d.get(i,0) + 1

for k,v in d.items():
	print("{} : {}".format(k,v))