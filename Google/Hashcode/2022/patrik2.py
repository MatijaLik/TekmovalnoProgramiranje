# tvoja mami
from cgi import test
from parse import read, write
from collections import defaultdict
import tester

class Person:
    def __init__(self, name, skills):
        self.name = name
        self.skills = skills

    def __repr__(self):
        return self.name


contrs, projs = read()
people = []

for name, skills in contrs.items():
    people.append(Person(name, skills))


def find_person(title, level, taken):
    # print(title, level, taken)
    for p in people:
        if p in taken:
            # print(p)
            continue
        if p.skills.get(title, 0) >= level:
            return p
    return None


def find_team(roles, check=False):
    tbd = []
    taken = [None for __ in range(len(roles))]
    mentor = defaultdict(lambda: 0)
    tbd.extend([(i, role) for i, role in enumerate(roles)])
    previ = -1
    loop_succ = False
    while tbd:
        i, role = tbd.pop(0)

        if previ >= i:
            if not loop_succ:
                return None
            loop_succ = False

        previ = i

        pers = find_person(role[0], role[1]-mentor[role[0]], taken)
        if pers is None:
            tbd.append((i, role))
            continue

        taken[i] = pers

        for rtitle, rval in pers.skills.items():
            for rt2, rv2 in roles:
                if rt2 == rtitle and rval >= rv2:
                    mentor[rtitle] = 1

        loop_succ = True

    if None in taken:
        print("svet se sežge")
    return taken


projsl = list(projs.items())
for name, p in projsl:
    mx = 0
    for r in p.roles:
        mx = max(mx, r[1])
    p.zahtevnost = 4000*mx
    
projsl.sort(key=lambda projtup: projtup[1].__dict__["zahtevnost"])
solution = []

iters = 0
added = 0

for name, proj in projsl:
    iters += 1
    # print(iters)
    if iters > 2*(len(projsl) - added):
        break

    taken = find_team(proj.roles)
    if taken is None:
        projsl.append((name, proj))
        added += 1
        continue 

    for p, rt in zip(taken, proj.roles):
        rl = p.skills.get(rt[0], 0)
        if rt[1] >= rl:
            p.skills[rt[0]] = rl+1

    solution.append([name, [p.name for p in taken]])

    # for title, level in proj.roles:
    #     pers = find_person(title, level, taken)
    #     if pers is None:
    #         projsl.append((name, proj))
    #         added += 1
    #         break
    #     taken.append(pers)
    # else:
        # for p, rt in zip(taken, proj.roles):
        #     if rt[1] >= p.skills[rt[0]]:
        #         p.skills[rt[0]] += 1

    #     solution.append([name, [p.name for p in taken]])

write(solution)
print(tester.evalviraj_ali_ko_sto_se_kaze(contrs, projs, solution))