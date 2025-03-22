def positivonegativo(x):
    if x > 0:
        return 'P'
    elif x < 0:
        return 'N'
    else:
        return '0'

num = int(input("Digite um numero inteiro: "))
print(f"O numero é {positivonegativo(num)}")