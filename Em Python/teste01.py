def triangulo(linhas):
    for i in range(1,linhas):
        count = 1
        while count <= i:
            print(end="# ")
            count += 1
        print(" ")

linhas = int(input("Qual o numero de linhas do triangulo? "))
triangulo(linhas + 1)
