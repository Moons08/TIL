n = 6
a = '-4 3 -9 0 4 1'
arr = list(a.strip().split(' '))
print(arr)

def mk():
    po = 0
    ne = 0
    zr = 0
    for i in arr:
        if int(i) == 0:
            zr += 1
        elif int(i) < 0:
            ne += 1
        else:
            po += 1
    print("{0:.5f}".format(po/n))
    print("{0:.5f}".format(ne/n))
    print("{0:.5f}".format(zr/n))
mk()
