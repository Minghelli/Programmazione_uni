values = list()
while 1:
    inp = input("Valore: ")
    if inp == '#':
        break
    try:
        inp = int(inp)
    except:
        print('Tipo valore errato.')
    else:
        values.append(inp)

print(*map(lambda x: x**2,values))
