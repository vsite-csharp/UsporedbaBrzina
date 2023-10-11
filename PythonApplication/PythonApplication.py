from datetime import datetime

def Loop(count, output):
    total = 0

    for row in range(1, count):
        for column in range(1, count):
            total += row + column
            if output:
                print(row * column)
    
    return total


for repeat in range(0, 10):

    start = datetime.now()

    total = Loop(11, True)

    end = datetime.now()

    timedelta = end - start

    print(f'{repeat}. Python total: {total}')
    print(f'{repeat}. Python execution: {timedelta.microseconds} us')

print()

for repeat in range(0, 10):

    start = datetime.now()

    total = Loop(1001, False)

    end = datetime.now()

    timedelta = end - start

    print(f'{repeat}. Python total: {total}')
    print(f'{repeat}. Python execution: {timedelta.microseconds} us')


