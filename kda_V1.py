from random import randint


def getnota() :
    nota = randint(0,10)
    return nota

kda1 = [ ]
kda2 = [ ]
kda3 = [ ]
kda4 = [ ]
kda5 = [ ]

def gerarkda() :
    kda = ['K','D','A']
    kda[0] = getnota()
    kda[1] = getnota()
    kda[2] = getnota()
    return kda

turma= {
    'Jungler' : kda1 , 
    'Toplaner' : kda2 , 
    'Midlaner' : kda3 , 
    'Support' : kda4 , 
    'Carry' : kda5
}

partida = 1
flag = 1

while flag :
    turma['Jungler'] = gerarkda()
    turma['Toplaner'] = gerarkda()
    turma['Midlaner'] = gerarkda()
    turma['Support'] = gerarkda()
    turma['Carry'] = gerarkda()
    partida+=1

    if float(turma['Jungler'][1]) == 0 :
        flag = 0
        break

    elif float(turma['Toplaner'][1]) == 0 :
        flag = 0
        break 
    elif float(turma['Midlaner'][1]) == 0 :
        flag = 0
        break 
    elif float(turma['Support'][1]) == 0 :
        flag = 0
        break 
    elif float(turma['Carry'][1]) == 0 :
        flag = 0
        break 


print(f"Partida: {partida} \n Jungler  \nKill = { turma['Jungler'][0] } \nDeath = {turma['Jungler'][1]}\nAssist = {turma['Jungler'][2]}")
print(f"\n Toplaner  \nKill = { turma['Toplaner'][0] } \nDeath = {turma['Toplaner'][1]}\nAssist = {turma['Toplaner'][2]}")
print(f"\n Midlaner  \nKill = { turma['Midlaner'][0] } \nDeath = {turma['Midlaner'][1]}\nAssist = {turma['Midlaner'][2]}")
print(f"\n Support  \nKill = { turma['Support'][0] } \nDeath = {turma['Support'][1]}\nAssist = {turma['Support'][2]}")
print(f"\n Carry  \nKill = { turma['Carry'][0] } \nDeath = {turma['Carry'][1]}\nAssist = {turma['Carry'][2]}")