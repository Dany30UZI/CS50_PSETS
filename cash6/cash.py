from cs50 import get_float


count = 0
while True:
    money = get_float("Input money: ")
    money = round(money * 100)
    if money > 0:
        break

while money > 0:
    if money - 25 >= 0:
        money = money - 25
        count += 1
    elif money - 10 >= 0:
        money = money - 10
        count += 1
    elif money - 5 >= 0:
        money = money - 5
        count += 1
    elif money - 1 >= 0:
        money = money - 1
        count += 1

print(count)
