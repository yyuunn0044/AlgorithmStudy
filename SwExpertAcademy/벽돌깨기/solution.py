import sys
import os

W = 0
H = 0
minBricks = 200

def drop(bricks):
    for col in range(W):
        left = []
        for row in range(H-1, -1, -1):
            if bricks[row][col] != 0:
                left.append(bricks[row][col])
        for row in range(H-1, -1, -1):
            if len(left) != 0:
                bricks[row][col] = left[0]
                left = left[1:]
            else:
                bricks[row][col] = 0        
    return bricks
    
def blast(bricks, row, col):
    leng = bricks[row][col]
    bricks[row][col] = 0
    for i in range(1, leng):
        if row-i >= 0 and bricks[row-i][col] != 0:
            bricks = blast(bricks, row-i, col)
        if row+i <= H-1 and bricks[row+i][col] != 0:
            bricks = blast(bricks, row+i, col)
        if col-i >= 0 and bricks[row][col-i] != 0:
            bricks = blast(bricks, row, col-i)
        if col+i <= W-1 and bricks[row][col+i] != 0:
            bricks = blast(bricks, row, col+i)
    return bricks

def getTopIndexs(bricks):
    tops = []
    for col in range(W):
        for row in range(H):
            if bricks[row][col] != 0:
                tops.append([row, col])
                break
    return tops

def getNumOfBricks(bricks):
    num = 0
    for row in range(H):
        for col in range(W):
            if bricks[row][col] != 0:
                num += 1
    return num
            
def recv(N, bricks):
    global minBricks
    if N == 0:
        num = getNumOfBricks(bricks)
        if num < minBricks:
            minBricks = num
        return
    tops = getTopIndexs(bricks)
    if len(tops) == 0:
        minBricks = 0
        return
    for top in tops:
        copied_bricks = [row[:] for row in bricks]
        updated_bricks = blast(copied_bricks, top[0], top[1])
        updated_bricks = drop(updated_bricks)
        recv(N-1, updated_bricks)

def solution(N, rows):
    bricks = []
    for i in range(H):
        bricks.append([int(elem) for elem in rows[i].split()])
    recv(N, bricks)
    return str(minBricks)

if __name__ == "__main__":
    INPUT_PATH = os.path.dirname(__file__)+"/"+"sample_input.txt"  
    sys.stdin = open(INPUT_PATH, "r")

    T = int(input())
    for test_case in range(1, T + 1):
        global W, H, minBricks
        NWH = input().split()
        N = int(NWH[0])
        W = int(NWH[1])
        H = int(NWH[2])
        minBricks = 200
        rows = []
        for i in range(H):
            rows.append(input())
        actual = "#"+str(test_case)+" "+solution(N, rows)
        print(actual)
