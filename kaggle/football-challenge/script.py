import csv
import random


MAX_BET = 500

with open('test.csv','r') as f:
    reader = csv.DictReader(f, delimiter=',')
    matches = list(reader)


with open('output.csv', 'w') as csvfile:
    fieldnames = ['ID', 'FTR']
    writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
    writer.writeheader()
    for match in matches:
        min_away = MAX_BET
        min_draw = MAX_BET
        min_home = MAX_BET
        for prop in match:
            if match[prop] == 'NA':
                continue
            if prop[-1:]  == 'D':
                min_draw = min(min_draw, float(match[prop]))
            elif prop[-1:] == 'A':
                min_away = min(min_away, float(match[prop]))
            elif prop[-1:] == 'H':
                min_home = min(min_home, float(match[prop]))
        min_bet = min(min_home, min_away, min_draw)

        results = ['W', 'A', 'D']
        writer.writerow({'ID': match['ID'], 'FTR': results[random.randint(0, 2)]})
        '''
        if min_bet == min_home:
            writer.writerow({'ID': match['ID'], 'FTR': 'H'})
        elif min_bet == min_draw:
            writer.writerow({'ID': match['ID'], 'FTR': 'D'})
        elif min_bet == min_away:
            writer.writerow({'ID': match['ID'], 'FTR': 'A'})'''

        