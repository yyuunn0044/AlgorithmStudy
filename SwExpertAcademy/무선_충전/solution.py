import sys
import os

DIRECTION_TO_DIFF= {
    "0": (0, 0),
    "1": (0, -1),
    "2": (1, 0),
    "3": (0, 1),
    "4": (-1, 0)
}

def move(now, diff):
    diff = DIRECTION_TO_DIFF[diff]
    return now[0]+diff[0], now[1]+diff[1]

def getTop2AvailableBCs(now, BCinfo):
    user_x, user_y = now
    available = [(0, 0, 0, 0), (0, 0, 0, 0)]
    for BCkey in BCinfo.keys():
        x, y, c, p = val = BCinfo[BCkey]
        if abs(user_x - x) + abs(user_y - y) <= c:
            available.append(val)
    available.sort(key=lambda e: e[3], reverse=True)
    return tuple(available[:2])

def solution(direcA, direcB, BCinfo):
    direcA, direcB = ['0'] + direcA, ['0'] + direcB
    secs = len(direcA)
    nowA = [1, 1]
    nowB = [10, 10]
    maxCharge = 0
    for sec in range(secs):
        nowA, nowB = move(nowA, direcA[sec]), move(nowB, direcB[sec])
        firstA, secondA = getTop2AvailableBCs(nowA, BCinfo)
        firstB, secondB = getTop2AvailableBCs(nowB, BCinfo)
        if firstA == firstB:
            if secondA[3] == 0 and secondB[3] == 0:
                charge = firstA[3]
            else:
                charge = firstA[3] + max(secondA[3], secondB[3])
        else:
            charge = firstA[3] + firstB[3]
        maxCharge += charge
    return maxCharge

if __name__ == "__main__":
    INPUT_PATH = os.path.dirname(__file__)+"/"+"sample_input.txt"  
    sys.stdin = open(INPUT_PATH, "r")

    T = int(input())
    for test_case in range(1, T + 1):
        BC = int(input().split()[1])
        direcA = input().split()
        direcB = input().split()
        BCinfo = {}
        for i in range(BC):
            BCinfo[i] = tuple([int(i) for i in input().split()])
        actual = "#"+str(test_case)+" "+str(solution(direcA, direcB, BCinfo))
        print(actual)
