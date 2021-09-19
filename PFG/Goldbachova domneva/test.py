
test = open("./test0.in", 'r').read()
usrOut = open("./out", 'r').read()



def grader(test, usrOut, officialOut):
    
    ##naredi reseto
    prastevilo = [True for i in range(1000001)]
    
    prastevilo[0] = False
    prastevilo[1] = False
    
    for i in range(2, 1000001):
        if prastevilo[i]:
            for j in range(i ** 2, 1000001, i):
                prastevilo[j] = False
    
    
    poizvedbe = test.splitlines()
    resitve = usrOut.strip().splitlines()
    Q = int(poizvedbe[0])
    
    for i in range(Q):
        ##print("////")
        ##print(i)
        try:
            stevili = list(map(int, resitve[i].split()))
            ##print(stevili)
            ##print(poizvedbe[i+1])
            a = stevili[0]
            b = stevili[1]
            assert int(poizvedbe[i+1]) == a + b
            assert prastevilo[a]
            assert prastevilo[b]
            
        except:
            print("Jaoo bruke nea štima")
            return 0
            
    return 1

    
grader(test, usrOut, None)