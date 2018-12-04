import re
import string
freq = {}
file = open('sample.txt','r')
text = file.read().lower()
pattern = re.findall(r'\b[a-z]{3,15}\b',text)

for word in pattern:
	count = freq.get(word,0)
	freq[word] = count + 1

freq_list = freq.keys()

for words in freq_list:
	print words, freq[words]