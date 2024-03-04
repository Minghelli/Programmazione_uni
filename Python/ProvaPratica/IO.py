from Dipendente import *
from Richieste import Richiesta

def writeDipendenti(list):
    file = open("C:/Users/Minghe/Desktop/Python/ProvaPratica/dipendenti.txt","w")

    c = 0
    for dip in list:
        l = [dip.nome,str(dip.stipendio)]
        if dip.ruolo == "subordinato":
            l.append(dip.res.nome)
        else:
            l.append("none")

        buffer = " ".join(l)           #Lista convertita in stringa separata da spazi e scritta sul file
        file.write(buffer)

        c += 1                         #Andata a capo, per l'ultimo dipendente viene omessa
        if c != len(list):
            file.write("\n")

    file.close()

def readDipendenti(arg=""):
    if arg == "":
        file = open("C:/Users/Minghe/Desktop/Python/ProvaPratica/dipendenti.txt","r")
    else:
        file = open(arg,"r")

    dipendenti = []
    buffer = file.read()              #Stringa contenente tutto il file
    list = buffer.split("\n")         #Lista contenente ogni riga del file

    for row in range(len(list)):
        l = list[row]                   
        l = l.split(" ")              #Lista contenente ogni elemento della riga

        if l[2] == "none":
            newDip = Responsabile(l[0],int(l[1]))
        else:
            l[2] = checkDipendente(l[2],dipendenti)
            newDip = Subordinato(l[0],int(l[1]),l[2])

        dipendenti.append(newDip)

    file.close()
    return dipendenti

def writeRequest(dip,exfile=""):
    if exfile == "":
        file = open("C:/Users/Minghe/Desktop/Python/ProvaPratica/richieste.txt","a")
    else:
        file = open(exfile,"w")

    for r in dip.richieste:
        l = [r.id,str(r.ore),r.dipendente,r.stato]
        buffer = " ".join(l)
        file.write(buffer)
        file.write("\n")

    file.close()

def readRequest(dip):
    file = open("C:/Users/Minghe/Desktop/Python/ProvaPratica/richieste.txt","r")
    req = []

    buffer = file.read()
    list = buffer.split("\n")

    for r in range(len(list)-1):
        row = list[r]
        
        row = row.split(" ",3)

        if row[2] == dip.nome:
            newReq = Richiesta(row[0],int(row[1]),row[2])
            if row[3] == "Accettata!":
                newReq.accept()
            elif row[3] == "Rifiutata!":
                newReq.reject()
            req.append(newReq)
    
    return req