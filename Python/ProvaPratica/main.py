from Dipendente import *
from Richieste import Richiesta
from IO import *
from os import system

dipendenti = []

while True:
    print("Dipendenti presenti:\n")

    i = 1
    for d in dipendenti:
        print(i,d.scheda())
        i +=1

    inp = input("\n1: Seleziona\n2: Crea\n3: Salva lista dei dipendenti \n4. Leggi lista dipendenti\n5: Esci\n")

    if inp == '1':
        if dipendenti == []:
            print("Nessun dipendente presente.\n")
        else:
            num = input("Seleziona numero lista: ")
            num = int(num)-1

            d = dipendenti[num]

            if d.ruolo == "subordinato":
                print("\n")
                print(d.scheda())

                opt = input("1: Visualizza richieste\n2: Nuova richiesta\n3: Richiedi conteggio\n4. Salva richieste\n5. Importa Richieste\n")

                if opt == '1':
                    print("Richieste (data, ore di lavoro, stato richiesta):\n")
                    for i in d.richieste:
                        print(i.id,i.ore,i.stato)

                    system("pause")
                    
                if opt == '2':
                    id = input("Id: ")
                    ore = input("Ore di lavoro: ")
                    ore = int(ore)

                    r = Richiesta(id,ore,d.nome)

                    d.nuovaRichiesta(r)

                    print("Richiesta inviata.\n")
                    system("pause")
                if opt == '3':
                    cont = d.conteggioOre()

                    print("Ore/Saldo:")
                    print(*cont)
                    system("pause")
                if opt == '4':
                    if d.richieste == []:
                        print("Nessuna richiesta presente")
                        system("pause")
                    else:
                        writeRequest(d)
                if opt == '5':
                    newRequests = readRequest(d)
                    if newRequests == []:
                        print("Nessuna richiesta importata.")
                    else:
                        d.richieste = newRequests
                        d.res.richiesteSub.extend(newRequests)
            else:
                if d.richiesteSub == []:
                    print("Nessuna richiesta di pagamento.")
                else:
                    print("Richieste Subordinati di ",d.nome)
                    n = 1
                    for i in d.richiesteSub:
                        print(n,i.dipendente,i.id,i.ore)
                        n += 1

                    inp = input("Seleziona richiesta: ")

                    if inp == '0':
                        pass
                    else:
                        esito = input("0: Accetta\n1: Rifiuta\n")
                        inp = int(inp)-1
                        if esito == '0':
                            d.richiesteSub[inp].accept()
                            del d.richiesteSub[inp]
                        else:
                            d.richiesteSub[inp].reject()
                            del d.richiesteSub[inp]

    if inp == '2':
        print("Nuovo Dipendente:\n")
        nome = input("Nome: ")
        stipendio = input("Stipendio: ")
        stipendio = int(stipendio)

        while True:
            ruolo = input("Ruolo (sub/res): ")
            if ruolo not in ("res","sub"):
                print("\nRuolo errato! reinserire.\n")
            else:
                break
            
        if ruolo == "res":
            nuovoDip = Responsabile(nome,stipendio)
            dipendenti.append(nuovoDip)

        elif ruolo == "sub":
            while True:
                resNome = input("Responsabile (Nome): ")
                if checkDipendente(resNome,dipendenti) == -2:
                    print("Utente non presente! Impossibile creare nuovo dipendente")
                elif checkDipendente(resNome,dipendenti) == -1:
                    print("L' utente selezionato è un subordinato")
                else:
                    res = checkDipendente(resNome,dipendenti)
                    nuovoDip = Subordinato(nome,stipendio,res)
                    dipendenti.append(nuovoDip)
                    break

    if inp == '3':
        if dipendenti == []:
            print("Nessun dipendente presente.")
            system("pause")
        else:
            writeDipendenti(dipendenti)

    if inp == '4':
        if dipendenti != []:
            inp = input("Sei sicuro di cancellare la lista attuale? s/n: ")
            if inp == 's':
                dipendenti.clear()
                dipendenti = readDipendenti()
            elif inp == 'n':
                pass
        else:
            dipendenti = readDipendenti()

    if inp == '5':
        exit()