try:
    a = 10
    b = 0
    result = a / b
except ZeroDivisionError:
    print('0で割っとるがな')
finally:
    print('ここは必ず通るやで')
