if __name__ == "__main__":
    from Utente import *
    from datetime import date
    from IO import *
    from os import system
    
    utenti = []

    while True:
        i = 1
        print("Utenti presenti:\n")
        for u in utenti:
            print(i,u.scheda())
            i += 1
        print("\n")

        inp = input("1. Crea Utente\n2. Seleziona\n3. Salva Dipendent\n4. Leggi Dipendenti\n")

        if inp == '1':
            nome = input("Nome: ")
            cognome = input("Cognome: ")

            newUser = Utente(nome,cognome)

            utenti.append(newUser)

        elif inp == '2':
            if utenti == []:
                print("Non ci sono0 utenti!")
            else:
                num = int(input("Seleziona numero utente: "))

                user = utenti[num-1]

                option = input("1. prelievo\n2. versamento\n3. visualizza storico\n4. storico con date e totale movimenti\n5. esporta movimenti\n")

                if option == '1' or option == '2':
                    valore = int(input("Valore: "))
                    try:
                        data = input("Data fromato YYYY-M-D: ")
                        data = creaData(data)
                    except ValueError as ex:
                        print("Data non valida!")

                    if option == '1':
                        newMov = Movimento(valore,"Prelievo",data)
                        user.addMovimento(newMov)
                    elif option == '2':
                        newMov = Movimento(valore,"Versamento",data)
                        user.addMovimento(newMov)
                    print("Movimento effettuato")
                    system("pause")

                elif option == '3':
                    user.storico()

                elif option == '4':
                    try:
                        print("data inizio:")
                        dataInizio = input("Data fromato YYYY-D-M: ")
                        dataInizio = creaData(dataInizio)

                        print("data fine:")
                        dataFine = input("Data fromato YYYY-D-M: ")
                        dataFine = creaData(dataFine)
                    except ValueError as ex:
                        print("Data non valida!")

                    user.storico(dataInizio,dataFine,1)

                elif option == '5':
                    if user.movimenti == []:
                        print("Nessun movimento presente.")
                    else:
                        file = input("Inserisci nome del file con estensione .txt: ")
                        file = open("C:/Users/Minghe/Desktop/Python/Prova2/transazioni/"+file,"a")

                        writeMovimenti2(user,file,1)

                        file.close()

        elif inp == '3':
            if utenti == []:
                print("Non ci sono utenti!")
            else:
                writeBackup(utenti)
        
        elif inp == '4':
            if utenti != []:
                inp = input("Sicuro di voler sovrascrivere gli attuali utenti? y/n")
                if inp == 'y':
                    utenti = readUtenti()
            else:
                utenti = readBackup()

        elif inp == '5':
            exit()