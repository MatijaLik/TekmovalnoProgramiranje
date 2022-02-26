from numpy import append
import parse
import operator

DAYS_WEIGHT = 1
ROLES_WEIGHT = 1
SCORE_WEIGHT = -1
DEADLINE_WEIGHT = 1

for name, p in projsl:
    p.value = p.days*DAYS_WEIGHT + len(p.roles)*ROLES_WEIGHT + p.score*SCORE_WEIGHT + p.deadline*DEADLINE_WEIGHT

contr, proj = parse.read()
projekti = []
contributors = []

for key, p in proj.values():
    projekti.append(p)
    projekti[-1].ime = key

for key, c in contr.values():
    contributors.append(p)
    contributors[-1].ime = key

DAYS_WEIGHT = 500
ROLES_WEIGHT = 2000
SCORE_WEIGHT = 1
DEADLINE_WEIGHT = 0

for p in projekti:
    p.value = p.days*DAYS_WEIGHT + len(p.roles)*ROLES_WEIGHT + p.score*SCORE_WEIGHT + p.deadline*DEADLINE_WEIGHT

projekti = sorted(projekti, key=(operator.attrgetter("value")))

for c in contributors:
    c.prost = 0

solution = []

for p in projekti:
    dan_zacetka = 1e99
    osebe = []
    valid = True
    for r in p.roles:
        najprvi = -1
        najprvi_cas = 1e99
        #najdi tazga, ki bo najhitreje PROST (saufi saufi)
        skill, level = r
        for c in contributors:
            if skill in c.skills and c.prost < najprvi_cas:
                najprvi_cas, najprvi = c.prost, c

        if najprvi_cas == 1e99:
            valid = False
            break

        najprvi.prost = najprvi_cas+p.days
        osebe.append(c.ime)

    solution.append((p.ime, osebe))

parse.write(solution)
        
                

