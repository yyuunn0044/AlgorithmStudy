import sys
import os
from pprint import pprint
def success(column):
    for r in range(K - 1, D):
        continuous = column[r - K + 1:r + 1]
        if len(set(continuous)) == 1:
            return True
    return False


def getFailColumns(film):
    fails = []
    for c in range(W):
        column = [film[r][c] for r in range(D)]
        if not success(column):
            fails.append(column)
    return fails

def filterAlreadyInjected(col, injects, already):
    for inject in injects:
        if inject[0] in already and inject[1] != col[inject[0]]:
            return list()
    return [inject for inject in injects if inject[0] not in already]

def injectChoices(col, already):
    material = ['A', 'B']
    choices = []

    for r in range(K - 1, D):
        continuous = range(r - K + 1, r + 1)
        for m in material:
            injects = [(i, m) for i in continuous if col[i] != m]
            injects = filterAlreadyInjected(col, injects, already)
            if len(injects) != 0:
                choices.append(tuple(injects))

    return choices

def recv(film, injected):
    #print("------")
    #pprint(film, width=200)
    #print("injected", end=" ")
    #pprint(injected)
    global D, W, K
    if len(injected) >= K:
        return
    choices = []
    fails = getFailColumns(film)
    if len(fails) == 0:
        global minInjection
        if len(injected) < minInjection:
            #print(injected)
            minInjection = len(injected)
        return
    for fail in fails:
        choices += injectChoices(fail, injected)
    choices = list(set(choices))

    #print("choices", end=" ")
    #pprint(choices)
    for injections in choices:
        copy = [row[:] for row in film]
        for injection in injections:
            copy[injection[0]] = [injection[1]]*W
        recv(copy, injected+[injection[0] for injection in injections])

def solution(film):
    recv(film, [])
    global minInjection
    m = minInjection
    return m


if __name__ == "__main__":
    INPUT_PATH = os.path.dirname(__file__)+"/"+"sample_input.txt"  
    sys.stdin = open(INPUT_PATH, "r")

    T = int(input())
    for test_case in range(1, T + 1):
        info = input().split()
        global D, W, K
        global minInjection
        D, W, K = int(info[0]), int(info[1]), int(info[2])

        minInjection = K
        original_film = []
        for i in range(D):
            original_film.append(['A' if int(elem) ==0 else 'B' for elem in input().split()])
        actual = "#"+str(test_case)+" "+str(solution(original_film))
        print(actual)
