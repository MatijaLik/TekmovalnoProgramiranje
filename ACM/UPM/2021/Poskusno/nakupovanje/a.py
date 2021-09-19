zivila = []
import sys
flag = 0

bestPrice = 999999
bestShop = ''
##1 - pred trgovino
##2 - naslov
##3 - zivila

ime = ''
dicc = {}

for line in sys.stdin:
    if len(zivila) == 0:
        zivila = [e.strip() for e in line.split(', ')]
        continue

    if line == '\n':
        
        if flag == 0:
            flag = 2
            continue
        else:
            flag = 2
            ##oceni
            cost = 0
            for e in zivila:
                try:
                    cost += dicc[e]
                except:
                    cost += 99999

            dicc.clear()
            if(cost < bestPrice):
                bestPrice = cost
                bestShop = ime
            
    
    elif flag == 2:
        ime = line.strip()
        flag = 3
    
    elif flag == 3:
        e = line.rsplit(' ', 1)
        dicc[e[0]] = int(float(e[1])*100)


print(bestShop + " " + str(bestPrice/100))