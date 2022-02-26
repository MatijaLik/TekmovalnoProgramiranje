# tvoja mami
from parse import read, write

def solve(contrs, projs, A, B, C, D):
    class Person:
        def __init__(self, name, skills):
            self.name = name
            self.skills = skills

        def __repr__(self):
            return self.name


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


    def find_team(roles):
        tbd = []
        taken = [None for __ in range(len(roles))]
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

            pers = find_person(role[0], role[1], taken)
            if pers is None:
                tbd.append((i, role))
                continue

            taken[i] = pers
            loop_succ = True

        if None in taken:
            print("svet se sežge")
        return taken

    projsl = list(projs.items())

    DAYS_WEIGHT = A
    ROLES_WEIGHT = B
    SCORE_WEIGHT = -C
    DEADLINE_WEIGHT = D

    for name, p in projsl:
        p.value = p.days*DAYS_WEIGHT + len(p.roles)*ROLES_WEIGHT + p.score*SCORE_WEIGHT + p.deadline*DEADLINE_WEIGHT

    
    projsl.sort(key=lambda projtup: projtup[1].__dict__["value"])

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
            if rt[1] >= p.skills[rt[0]]:
                p.skills[rt[0]] += 1

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

    return solution
