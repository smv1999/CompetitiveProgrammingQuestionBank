def span(price):
    hey = [1]*len(price)
    for i in range(1, len(price)):
        a = i
        while price[a] > price[i-1] and i > 0:
            hey[a] += 1
            i -= 1
    print(hey)


price = [100, 80, 60, 70, 60, 75, 85]
span(price)