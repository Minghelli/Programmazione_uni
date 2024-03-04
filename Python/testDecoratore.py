from time import time

def execTime(fun):
    def f(*args,**kwargs):
        start = time()
        val = fun(*args,**kwargs)
        end = time()
        print("Tempo di esecuzione:",end - start)
        return val
    return f

@execTime
def quad(x):
    return x**2

print(quad(3))