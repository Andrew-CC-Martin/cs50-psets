from sys import argv
import re
import csv

if len(argv) != 3:
    print('wrong number of arguments')
    exit()

# load database file
database = open(argv[1], 'r')
# load sequence file as a string
sequence = list(open(argv[2], 'r'))[0].strip()

# create list from first line of database
# (the first line of the csv are the headers,
# which represent the STRs we care about)
STRs = database.readline().strip().split(',')

# create a list of dictionaries, where each is a person to check,
# along with their STR counts
people = []
databaseReader = csv.DictReader(database, STRs)
for row in databaseReader:
    people.append(row)

# strip first entry (name) from STRs, so that only the STRs remain
STRs.pop(0)

# iterate over STRs
matches = {}
for STR in STRs:
    # for each sequence, count number of matches in sequence
    matchesList = re.findall(f'(?:{STR})+', sequence)
    if matchesList:
        matches[STR] = max(map(len, matchesList)) // len(STR)
    else:
        matches[STR] = 0

# iterate over people, and see if any are exact match
for person in people:
    name = person.popitem(False)[1]
    if all(matches[sequence[0]] == int(sequence[1]) for sequence in person.items()):
        print(name)
        exit()

print("No match")

