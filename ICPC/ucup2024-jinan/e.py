def solve():
    a, b, c, x, y, d = map(int, input().split())

    # ans1: 全用起步费
    ans1 = (d // x) * a + (a if d % x != 0 else 0)

    # ans2: 全用第一程里程费
    if d >= x + y:
        ans2 = (d // (x + y)) * (a + b * y) + (
            0 if d % (x + y) == 0 else (a if (d % (x + y)) < x else (a + b * ((d % (x + y)) - x)))
        )
    else:
        ans2 = float("inf")

    # ans3: 打一辆车坐到底
    if d >= x + y:
        ans3 = a + b * y + (d - (x + y)) * c
    else:
        ans3 = float("inf")

    # print(f"ans1: {ans1}, ans2: {ans2}, ans3: {ans3}")

    ans = min(ans1, ans2, ans3)
    print(ans)


if __name__ == "__main__":
    # print("bu shi ge men")
    _ = int(input())
    for __ in range(_):
        solve()
