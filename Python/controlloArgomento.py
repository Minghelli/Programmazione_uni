def argumentCheck(fun):
    def f(arg):
        print("Argomento",arg)
        inp = input("Vuoi modificare l'argomento? (y/n): ")
        if inp == 'y':
            newArg = input("Nuovo argomento: ")
            newArg = int(newArg)
            return fun(newArg)
        else:
            return fun(arg)
    return f

@argumentCheck
def quad(x):
    return x**2

print(quad(4))
