from datetime import date
class Utente:
    def __init__(self,nome,cognome):
        self.nome = nome
        self.cognome = cognome
        self.movimenti = []

    def scheda(self):
        return f"{self.nome} {self.cognome}"

    def addMovimento(self,movimento):
        self.movimenti.append(movimento)

    def storico(self,dataIn="",dataFine=""):
        print("Movimenti (valore,tipo,data):")
        if dataIn == "":
            for m in self.movimenti:
                print(m.stampa())
        else:
            tot = 0
            for m in self.movimenti:
                if m.data >= dataIn and m.data <= dataFine:
                    print(m.stampa())
                    if m.tipo == "Prelievo":
                        tot += m.valore
                    else:
                        tot -= m.valore
            print("Totale movimenti del periodo selezionato: ",tot)


class Movimento:
    def __init__(self,valore,tipo,data):
        self.valore = valore
        self.tipo = tipo
        self.data = data

    def stampa(self):
        return f"{self.valore} {self.tipo} {self.data}"

def creaData(dataStr):
    data = dataStr.split("-")
    data = [int(x) for x in data]
    data = date(*data)

    return data