class cane():
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

    def verso(self):
        print("abbaia")

print(__name__)