if __name__ == '__main__':
    m, n = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    sum_a = sum(a) + m
    sum_b = sum(b) + n
    if sum_a > sum_b:
        print("ALICE")
    elif sum_a < sum_b:
        print("BOB")
    else:
        print("TIED")
