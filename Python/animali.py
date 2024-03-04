from abc import ABC, abstractmethod
class animale(ABC):
    def __init__(self,zampe,eta,sesso):
        self.zampe = zampe
        self.eta = eta
        self.sesso = sesso
        self.__malato = False
        self.__spavaldo = False

    @property
    def malato(self):
        if self.__spavaldo == True:
            return False
        return self.__malato

    @malato.setter
    def malato(self,ma):
        self.__malato=ma

    @property
    def spavaldo(self):
        return self.__spavaldo
    @spavaldo.setter
    def spavaldo(self,spa):
        self.__spavaldo=spa

    def cammina(self):
        print("cammino")
    def corre(self):
        print("corre")
        
    def __add__(self,other):
        if self.sesso != other.sesso and type(self) == type(other):
            cucciolo = type(self)(4,0,"Cucciolo",False,False)
            return cucciolo
        else:
            raise AttributeError

    @abstractmethod
    def verso(self):
        pass

class cane(animale):
    def __init__(self,zampe,eta,sesso,ma,spa):
        self.__malato=ma
        self.__spavaldo=spa
        super().__init__(zampe,eta,sesso)

    def verso(self):
        print("abbaia")

class gatto(animale):
    def __init__(self,zampe,eta,sesso,ma,spa):
        self.__malato=ma
        self.__spavaldo=spa
        super().__init__(zampe,eta,sesso)

    def verso(self):
        print("miagola")

paso = cane(4,3,"Maschio",False,False)
doggo = cane(4,4,"Maschio",False,False)
bubi = gatto(4,6,"Femmina",False,False)

try:
    c = doggo + bubi
    print(c.sesso)
except AttributeError as e:
    print("Niente bimbo",e)

doggo.verso()
bubi.verso()

print(type(doggo))