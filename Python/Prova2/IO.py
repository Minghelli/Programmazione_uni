from Utente import *

def writeUtenti(users):
    file = open("C:/Users/Minghe/Desktop/Python/Prova2/utenti.txt","w")

    c = 0
    for u in users:
        l = [u.nome,u.cognome]
        buffer = " ".join(l)

        file.write(buffer)

        c += 1
        if c != len(users):
            file.write("\n")

    file.close()

    for u in users:
        writeMovimenti(u)

def writeMovimenti(user):
    file = open("C:/Users/Minghe/Desktop/Python/Prova2/movimenti.txt","a")

    for mov in user.movimenti:
        l = [str(mov.valore),mov.tipo,str(mov.data),user.nome,user.cognome]
        buffer = " ".join(l)
        
        file.write(buffer)
        file.write("\n")

    file.close()

def readUtenti():
    file = open("C:/Users/Minghe/Desktop/Python/Prova2/utenti.txt","r")

    utenti = []

    buffer = file.read()
    rows = buffer.split("\n")

    for r in rows:
        r = r.split(" ")
        newUser = Utente(r[0],r[1])
        utenti.append(newUser)

    file.close()
    return utenti

def writeBackup(users):
    file = open("C:/Users/Minghe/Desktop/Python/Prova2/utenti.txt","w")
    c = 0
    for u in users:
        l = [u.nome,u.cognome]
        buffer = " ".join(l)

        file.write(buffer)
        file.write("\n")

        if u.movimenti != []:
            writeMovimenti2(u,file)

        c += 1
        if c != len(users):
            file.write("+\n")

    file.close()

def writeMovimenti2(user,file,check=0):
    for mov in user.movimenti:
        
        l = [str(mov.valore),mov.tipo,str(mov.data)]
        buffer = " ".join(l)

        if check == 0:
            file.write("$\n")
        file.write(buffer)
        file.write("\n")

def readBackup():
    file = open("C:/Users/Minghe/Desktop/Python/Prova2/utenti.txt","r")

    utenti = []
    buffer = file.read()
    buffer = buffer.replace("\n","")
    buffer = buffer.split("+")
    print(buffer)
    for user in buffer:
        user = user.split("$")
        newUser = user[0].split(" ")
        newUser = Utente(newUser[0],newUser[1])
        utenti.append(newUser)
        for i in range(1,len(user)):
            newMov = user[i].split(" ")
            data = creaData(newMov[2])
            newMov = Movimento(int(newMov[0]),newMov[1],data)
            newUser.addMovimento(newMov)
    
    file.close()
    return utenti