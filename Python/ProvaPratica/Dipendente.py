class Dipendente:
    ruolo = ""
    def __init__(self,nome,stipendio):
        self.nome = nome
        self.stipendio = stipendio

    def scheda(self):
        scheda = f"Nome: {self.nome}\nRuolo: {self.ruolo}\nStipendio orario: {self.stipendio}\n"

        return scheda

class Responsabile(Dipendente):
    ruolo = "responsabile"
    
    def __init__(self,nome,stipendio):
        super().__init__(nome,stipendio)
        self.richiesteSub = []

class Subordinato(Dipendente):
    ruolo = "subordinato"
    
    def __init__(self,nome,stipendio,res):
        super().__init__(nome,stipendio)
        self.res = res
        self.richieste = []

    def nuovaRichiesta(self,richiesta):
        self.richieste.append(richiesta)
        self.res.richiesteSub.append(richiesta)

    def conteggioOre(self):
        totOre = 0
        for r in self.richieste:
            if r.stato == "Accettata!":
                totOre += r.ore

        saldo = totOre * self.stipendio

        return (totOre,saldo)


def checkDipendente(nome,lista):
    for d in lista:
        if nome == d.nome:
            if d.ruolo == "responsabile":
                return d
            else:
                return -1 
    return -2