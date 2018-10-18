import sys
import os

def canBuild(line, RUNWAY_LEN):
    N = len(line)
    diff = []
    prev = line[0]
    for this in line[1:]:
        diff.append(this-prev)
        prev = this
    #print(diff)
    built = []
    for i in range(len(diff)):
        if diff[i] == 0:
            pass
        elif diff[i] == 1:
            
            candidate = [j for j in range(max(0, i-RUNWAY_LEN+1), i)]
            #print(candidate)
            if len(candidate) != RUNWAY_LEN -1:
                return 0
            if not all(diff[c] == 0 and (c not in built) for c in candidate):
                return 0
            built += candidate
            
        elif diff[i] == -1:
            
            candidate = [j for j in range(i+1, min(i+RUNWAY_LEN, N-1))]
            if len(candidate) != RUNWAY_LEN -1:
                return 0
            if not all(diff[c] == 0 and (c not in built) for c in candidate):
                return 0
            built += candidate
        else:
            return 0
        #print("build?", built)
    return 1

def solution(terrain, RUNWAY_LEN):
    #print(RUNWAY_LEN, "------------------")
    N = len(terrain)
    num = 0
    for t in terrain:
        #print(t)
        num += canBuild(t, RUNWAY_LEN)
        #print("\n")
        #print(num)
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
    