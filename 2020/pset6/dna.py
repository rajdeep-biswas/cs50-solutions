import sys
import pandas as pd

# check for the correct number CL arguments
if len(sys.argv) != 3:
	print("Usage: python dna.py data.csv sequence.txt")
	exit()

# fetching the csv and txt filepaths
[csvpath, seqpath] = sys.argv[1:]

# reading from the csv and txt and storing them in variables
df = pd.read_csv(csvpath)
seq = ""
with open(seqpath, "r") as f:
	for line in f:
		seq += line

# getting each of the csv headers (the STRs) except the 0th one (the name of person)
dnathings = [thing for thing in df][1:]

# initializing output to a "No match"
name = "No match"

# iterating through each csvrow
for index, row in df.iterrows():

	# checking if each STR sequence repeated n number of times, appears in the specified text file
	# (where n is each person's STR occurrence)
	# an all 'True' list would mean complete appearance of each STR
	if False not in [item * int(row[[item]]) in seq for item in dnathings]:
		name = row["name"]
		break

print(name)