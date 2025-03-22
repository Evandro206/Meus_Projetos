def receberMatriz(tam):
    mtz = []
    linhas = tam
    colunas = tam
    for i in range(linhas * colunas):
        if i % colunas == 0:
            mtz.append([])
        valor = int(input(f"Digite o valor para a posição [{i // colunas}][{i % colunas}]: "))
        mtz[-1].append(valor)
    return mtz

def imprimirMatriz(mtz):
    print("A matriz resultante é:")
    for linha in mtz:
        print(linha)

def diagonalMatriz(mtz):
    coluna = 0
    print("A diagonal principal da matriz é: ")
    for linha in mtz:
        print(linha[coluna], end=" ")
        coluna += 1
    print(" ")

def positivoNegativo(mtz):
    positivo = 0
    negativo = 0
    for linha in mtz:
        for i in linha:
            if(i > 0):
                positivo += 1
            else:
                negativo += 1      
    print(f"{positivo} numeros são positivos e {negativo} numeros são negativos.")

tam = int(input("Qual a ordem da matrix: "))
mtz = receberMatriz(tam)
imprimirMatriz(mtz)
diagonalMatriz(mtz)
positivoNegativo(mtz)