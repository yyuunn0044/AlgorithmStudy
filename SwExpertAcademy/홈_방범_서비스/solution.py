import sys
import os

def countHomes(center, K, N):
    home = 0
    c_x, c_y = center
    start_x, start_y = c_x-(K-1), c_y-(K-1)
    for i in range(K*2-1):
        for j in range(K*2-1):
            x, y = start_x+i, start_y+j
            if abs(c_x-x)+abs(c_y-y) > K-1:
                pass
            else:
                if 0 <= x <= N-1 and 0 <= y <= N-1:
                    spot = city[x][y]
                    if spot == 1:
                        home += 1
    return home

def calcBenefit(K, homes, M):
    return homes*M- (K*K+(K-1)*(K-1))

def solution(N, M):
    if N % 2 == 1:
        K = N
    else:
        K = N+1
    allCenters = []
    for i in range(N):
        for j in range(N):
            allCenters.append((i, j))
    while K > 0:
        candidate = []
        for center in allCenters:
            homes = countHomes(center, K, N)
            if calcBenefit(K, homes, M) >= 0:
                candidate.append(homes)
        if len(candidate) > 0:
            return max(candidate)
        K -= 1
    return None

if __name__ == "__main__":
    INPUT_PATH = os.path.dirname(__file__)+"/"+"sample_input.txt"  
    sys.stdin = open(INPUT_PATH, "r")

    T = int(input())
    for test_case in range(1, T + 1):
        global city
        info = input().split()
        N, M = int(info[0]), int(info[1])
        city = []
        for i in range(N):
            city.append([int(elem) for elem in input().split()])
        actual = "#"+str(test_case)+" "+str(solution(N, M))
        print(actual)

city = []