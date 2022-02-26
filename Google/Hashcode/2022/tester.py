def evalviraj_ali_ko_sto_se_kaze(contrib, projekti, solution):

    available_time = dict()

    for name in contrib:
        available_time[name] = 0
    
    rezultat = 0

    for ime_projekta, folk in solution:

        p = projekti[ime_projekta]

        #poglej Gdaj po ta prvi frej
        start_time = -1
        for clouk in folk:
            start_time = max(start_time, available_time[clouk])

        end_time = start_time + p.days

        if end_time <= p.deadline:
            rezultat += p.score
        else:
            rezultat += max(0, p.score - (end_time - p.deadline))

        for clouk in folk:
            available_time[clouk] = end_time

    return rezultat

