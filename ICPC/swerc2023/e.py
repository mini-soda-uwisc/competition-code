from fractions import Fraction

if __name__ == '__main__':
    n = int(input())
    h = list(map(int, input().split()))
    for i in range(len(h)):
        h[i] = Fraction(h[i], 1)

    def get_x(x1, y1, x2, y2, y):
        return (y - y1) / (y2 - y1) * (x2 - x1) + x1