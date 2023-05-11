import csv
import sys
from csv import reader, DictReader
from sys import argv, exit


def main():

    sequences = {}

    if len(sys.argv) < 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    def Getmax(dna, STR):
        i = 0
        j = len(STR)
        max = 0
        for x in range(len(dna)):
            if dna[i:j] == STR:
                temp = 0
                while dna[i:j] == STR:
                    temp += 1
                    i += len(STR)
                    j += len(STR)
                    if(temp > max):
                        max = temp
            else:
                i += 1
                j += 1
        return max

    with open(argv[2], 'r') as dnafile:
        dna = dnafile.read()

    with open(argv[1], "r") as sequenceFile:
        sequenceReader = reader(sequenceFile)
        for row in sequenceReader:
            header = row
            header.pop(0)
            for item in header:
                sequences[item] = 0
            break

    for key in sequences:
        ans = Getmax(dna, key)
        sequences[key] = ans

    with open(argv[1], "r") as sequenceFile:
        people = DictReader(sequenceFile)
        for person in people:
            match = 0
            for key in sequences:
                if int(person[key]) == sequences[key]:
                    match += 1
            if match == len(sequences):
                print(person["name"])
                exit(0)

        print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(suence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
