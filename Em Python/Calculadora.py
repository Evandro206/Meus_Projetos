def main():
    continuation = True
    numMemori = 0
    resultado = 0
    while continuation == True: # loop para continuar a fazer operações
        menu(resultado)
        operation = input("Digite a operação: ")

        # condições para as operações
        if operation == "+":
            num = float(input("Digite o numero pelo qual vai somar: "))
            resultado = summ(numMemori, num)
            numMemori = resultado
        elif operation == "-":
            num = float(input("Digite o numero pelo qual vai subtrair: "))
            resultado = sub(numMemori, num)
            numMemori = resultado
        elif operation == "/":
            num = float(input("Digite o numero pelo qual vai dividir: "))
            resultado = division(numMemori, num)
            numMemori = resultado
        elif operation == "x":
            num = float(input("Digite o numero pelo qual vai multiplicar: "))
            resultado = multipli(numMemori, num)
            numMemori = resultado
        elif operation == "e":
            num = float(input("Digite o numero pelo qual vai elevar: "))
            resultado = Exponential(numMemori, num)
            numMemori = resultado
        elif operation == "r":
            num = float(input("Digite o numero pelo qual vai tirar a raiz: "))
            resultado = root(numMemori, num)
            numMemori = resultado
        elif operation == "c":
            numMemori = 0
            resultado = 0
        elif operation == "=":
            continuation = False
            
def menu(resultado): # função para mostrar o menu
    print("   _______________________ \n")
    print("  |                       | \n")
    print(f"  |%22.2f |\n" % resultado)
    print("   _______________________ \n")
    print("  |_______________________| \n")
    print("  |       |       |       | \n")
    print("  |   1   |   2   |   +   | \n")
    print("  |_______|_______|_______| \n")
    print("  |       |       |       | \n")
    print("  |   3   |   4   |   -   | \n")
    print("  |_______|_______|_______| \n")
    print("  |       |       |       | \n")
    print("  |   5   |   6   |   /   | \n")
    print("  |_______|_______|_______| \n")
    print("  |       |       |       | \n")
    print("  |   8   |   7   |   x   | \n")
    print("  |_______|_______|_______| \n")
    print("  |       |       |       | \n")
    print("  |   9   |   0   |   c   | \n")
    print("  |_______|_______|_______| \n")
    print("  |       |       |       | \n")
    print("  |   E   |   R   |   =   | \n")
    print("  |_______|_______|_______| \n")

def summ(numMemori, num): # função para somar
    numMemori += num
    return  numMemori

def sub(numMemori, num): # função para subtrair
    numMemori -= num
    return  numMemori
    
def multipli(numMemori, num): # função para multiplicar
    numMemori = numMemori * num
    return  numMemori

def division(numMemori, num): # função para dividir
    numMemori = numMemori / num
    return  numMemori

def Exponential(numMemori, num): # função para elevar
    numMemori = numMemori ** num
    return  numMemori

def root(numMemori, num): # função para tirar a raiz
    numMemori = numMemori ** (1/num)
    return numMemori

main()