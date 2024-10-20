l = input().split(' ')

numbers = [l[0], l[2], l[4]]

_numbers = ["", "", ""]

def check():
    if l[1] == '+':
        return int(_numbers[0]) + int(_numbers[1]) == int(_numbers[2])
    elif l[1] == '*':
        return int(_numbers[0]) * int(_numbers[1]) == int(_numbers[2])

    assert False

for i in range(0, 3):
    for j in range(i + 1, 3):
        a, b = numbers[i], numbers[j]
        c = numbers[3 - i - j]
        for l1 in range(1, len(a)):
            for l2 in range(1, len(b)):
                _a = b[:l2] + a[l1:]
                _b = a[:l1] + b[l2:]

                _numbers[i] = _a
                _numbers[j] = _b
                _numbers[3 - i - j] = c

                if check():
                    print(_numbers[0], l[1], _numbers[1], l[3], _numbers[2])
                    exit(0)