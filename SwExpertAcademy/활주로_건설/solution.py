import sys
import os

def canBuild(line, RUNWAY_LEN):
    N = len(line)
    prev = line[0]
    built = []
    for i in range(1, N):
        this = line[i]
        diff = this-prev
        if diff == 0:
            pass
        elif diff == 1:
            candidate = range(max(0, i-RUNWAY_LEN), i)
            if len(candidate) != RUNWAY_LEN:
                return 0
            if not all(line[c] == this-1 and (c not in built) for c in candidate):
                return 0
            built += candidate
            
        elif diff == -1:
            candidate = range(i, min(i+RUNWAY_LEN, N))
            if len(candidate) != RUNWAY_LEN :
                return 0
            if not all(line[c] == this and (c not in built) for c in candidate):
                return 0
            built += candidate
        else:
            return 0
        prev = this
    return 1

def solution(terrain, RUNWAY_LEN):
    N = len(terrain)
    num = 0
    for t in terrain:
        num += canBuild(t, RUNWAY_LEN)
    vertical_terrain = []
    for i in range(N):
        vertical_terrain.append([t[i] for t in terrain])
    for v_t in vertical_terrain:
        num += canBuild(v_t, RUNWAY_LEN)
    return num

if __name__ == "__main__":
    INPUT_PATH = os.path.dirname(__file__)+"/"+"sample_input.txt"  
    sys.stdin = open(INPUT_PATH, "r")

    T = int(input())
    for test_case in range(1, T + 1):
        N, RUNWAY_LEN= input().split()
        N, RUNWAY_LEN = int(N), int(RUNWAY_LEN)
        terrain = []
        for i in range(N):
            terrain.append([int(elem) for elem in input().split()])
        actual = "#"+str(test_case)+" "+str(solution(terrain, RUNWAY_LEN))
        print(actual)
    