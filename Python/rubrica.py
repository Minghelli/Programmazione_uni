rubrica = dict()

while 1 :
    print("1 stampa\n2 aggiungi\n3 rimuovi\n4 esci")
    inp = input()
    if inp == '1' :
        print(rubrica.items())
    elif inp == '2' :
        name = input("Nome: ")
        num = input("Numero: ")
        rubrica[name] = num
    elif inp == '3' :
        key = input("Chiave del contatto: ")
        rubrica.pop(key)
    elif inp == '4' :
        break

