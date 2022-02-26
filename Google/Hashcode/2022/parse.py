import sys 
class Project:
    def __init__(self):
        self.roles = []
    def __repr__(self):
        return str(self.__dict__)

def read():
    ncontr, nproj = list(map(int, input().split()))
    contr = dict()
    proj = dict()
    for i in range(ncontr):
        name, nskills = input().split()
        nskills = int(nskills)
        skills = dict()
        for j in range(nskills):
            skillname, level = input().split()
            skills[skillname] = int(level)
        contr[name] = skills
    for i in range(nproj):
        name, days, score, deadline, nroles = input().split()
        proj[name] = Project()
        proj[name].days = int(days)
        proj[name].score = int(score)
        proj[name].deadline = int(deadline)
        for j in range(int(nroles)):
            rolename, level = input().split()
            proj[name].roles.append((rolename, int(level)))
    return (contr, proj)

def write(solution, f=sys.stdout):
    global print
    _print = print
    def print(*args, **kwargs):
        kwargs['file'] = f
        _print(*args, **kwargs)
    print(len(solution))
    for s in solution:
        print(s[0])
        for name in s[1]:
            print(name, end=' ')
        print()


if __name__ == '__main__':
    inp = read()
    print(inp)
