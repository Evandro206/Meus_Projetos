from datetime import datetime, timedelta
import calendar
import time

tempo_atual = time.localtime()
ano = tempo_atual.tm_year
mes = tempo_atual.tm_mon
semana = int(time.strftime("%U", tempo_atual))
dia = tempo_atual.tm_mday
dia_da_semana = tempo_atual.tm_wday  
hora = tempo_atual.tm_hour
minuto = tempo_atual.tm_min
segundo = tempo_atual.tm_sec

def teste(x):
    print(f"O valor da variavél testada é: {x}")

def passagem_tempo():
    global ano, mes, semana, dia
    semana += 1

    dia += 7
    dias_no_mes = calendar.monthrange(ano, mes)[1]
    if dia > dias_no_mes:
        dia -= dias_no_mes
        mes += 1
        if mes > 12:
            mes = 1
            semana = 1
            ano += 1

def imprimir_quadro(): 
    global ano, mes, semana, dia, c
    for i in range(c):
        print(f"-------------------------------------------------------\n")
        print(f"----------| Semana: {semana} | Mes: {mes} | Ano: {ano} |----------\n")
        print(f"| Dia | Seg |   Ter   |   Qua   |   Qui   | Sex | Sab |\n")
        print(f"|  {dia}  | --- |  18:55  |  18:55  |  18:55  | --- | --- |\n")
        print(f"-------------------------------------------------------\n")
        passagem_tempo()

c = int(input("Quantas semanas terá o quadro de horários: "))
imprimir_quadro()