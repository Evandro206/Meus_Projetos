def filtrar(lst, max_val, min_val):
    listf = []
    for i, value in enumerate(lst):
        if min_val <= value <= max_val:
            listf.append(value)
    return listf

listp = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Max = 8
Min = 4
print(f"{filtrar(listp, Max, Min)}")
