def soma_lista(lista):
    soma = 0
    for i in range(len(lista)):
        soma += lista[i]
    return soma

lista = []

for i in range(4):
    numero = int(input("Digite um numero: "))
    lista.append(numero)

print(soma_lista(lista))