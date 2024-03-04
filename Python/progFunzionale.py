from functools import reduce
#a = "wertyuioplkjhgoiuytrsxcvbnm"
#print(*map(lambda x:x.upper(),filter(lambda x:x not in ['a','e','i','o','u','A','E','I','O','U'],a)))

a = "wsxefvertyhjkmnbvc"
b = "fvbnmgfdertyuikl"
c = "sdfghjkl.,mnbvftyui"
d = "ertyuioplkjhgfdsxcvbnred"

reduce(lambda x,y: x | {y: x.get(y, 0)+1},a,{})