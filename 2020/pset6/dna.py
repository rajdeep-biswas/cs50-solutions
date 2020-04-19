import sys
import pandas as pd
import re

if len(sys.argv) != 3:
	print("Usage: python dna.py data.csv sequence.txt")
	exit()

[csvpath, seqpath] = sys.argv[1:]

df = pd.read_csv(csvpath)
seq = ""
with open(seqpath, "r") as f:
	for line in f:
		seq += line

strs = [st for st in df][1:]

name = "No match"

for index, row in df.iterrows():
	if False not in [st * int(row[[st]]) in seq for st in strs]:

		truth = []
		for st in strs:
			truth.append(seq[seq.find(st * int(row[st])) + len(st * (int(row[st]))):][:len(st)] == st)

		if True not in truth:
			name = row["name"]

print(name)
