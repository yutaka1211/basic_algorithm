
ar = [2,3,5,6,8,1]

def bubble_sort(ar):

    change = True
    while change:
        change = False
        for i in range(len(ar)-1):
            if ar[i] > ar[i+1]:
                x = ar[i]
                ar[i] = ar[i+1]
                ar[i+1] = x
                change = True
    return ar

print('Before:', ar)

ar=bubble_sort(ar)

print('After: ', ar)