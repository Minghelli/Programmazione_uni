from typing import Any

class test:
    __classAtt = 20
    def __init__(self):
        self.__att = 0
        self.__att2 = 25
    
    @property
    def att(self):
        return self.__att
    @att.setter
    def att(self,att):
        self.__att = att

    @property
    def att2(self):
        return self.__att2
    @att2.setter
    def att2(self,val):
        self.__att2 = val
    
    def __getattr__(self,attr):
        if attr == "att3":
            raise AttributeError("Campo inesistente")
        else:
            return super().__getattr__(attr)
    
class test2(test):
    def inc(self):
        self.att += 1

c = test2()
c.att = 7
test2.inc(c)
print(c.__dict__)