class Richiesta:
    stato = "In Attesa..."
    def __init__(self,id,ore,dipendente):
        self.id = id
        self.ore = ore
        self.dipendente = dipendente

    def accept(self):
        self.stato = "Accettata!"

    def reject(self):
        self.stato = "Rifiutata!"

if __name__ == "__main__":
    from sys import argv
    from IO import *

    if len(argv) < 4:
        print("Inserisci argomenti corretti!")
        exit()

    backupFile = argv[1]
    exportFile = argv[2]
    user = argv[3]

    dipendenti = readDipendenti(backupFile)

    for d in dipendenti:
        if d.nome == user:
            req = readRequest(d)
            if d.richieste == [] or req == []:
                print("L'utente non ha richieste")
            else:
                d.richieste = req
                writeRequest(d,exportFile)
                break