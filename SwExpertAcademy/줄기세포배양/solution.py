import sys
import os
from pprint import pprint
GRID_LEN = 370

def Cell(lifespan):
    return {
        "lifespan": lifespan,
        "left": lifespan,
        "state": "U"
    }
def getNumOfAliveCells():
    num = 0
    for r in range(GRID_LEN):
        for c in range(GRID_LEN):
            cell = grids[r][c]
            if cell and (cell["state"] == "U" or cell["state"] == "A"):
                num += 1
    return num

def getBred(row, col, lifespan):
    arounds = [[row-1, col], [row+1, col], [row, col-1], [row, col+1]]
    return [(idx[0], idx[1], lifespan) for idx in arounds]

def breed(indexes):
    indexes.sort(key=lambda e:e[2], reverse=True)
    for idx in indexes:
        row, col = idx[0], idx[1]
        if not grids[row][col]:
            grids[row][col] = Cell(idx[2]) 

def cellTimeRuns(row, col):
    bred = []
    cell = grids[row][col]
    if cell["state"] == "U":
        cell["left"] -= 1
        if cell["left"] == 0:
            cell["state"] = "A"
            cell["left"] = cell["lifespan"]
    elif cell["state"] == "A":
        cell["left"] -= 1
        if cell["lifespan"] - cell["left"] == 1:
            bred = getBred(row, col, cell["lifespan"])
        if cell["left"] == 0:
            cell["state"] = "D"
    else:
        pass
    return bred

def timeRuns():
    new_bred = []
    for row in range(GRID_LEN):
        for col in range(GRID_LEN):
            if grids[row][col]:
                new_bred += cellTimeRuns(row, col)

    breed(new_bred)

def mapCells(cells):
    for r in range(len(cells)):
        for c in range(len(cells[r])):
            if cells[r][c] != 0:
                grids[r+(GRID_LEN-50)//2][c+(GRID_LEN-50)//2] =  \
                    Cell(cells[r][c])
def resetGrids():
    global grids
    grids = []
    for i in range(GRID_LEN):
        grids.append([None for j in range(GRID_LEN)])

def solution(N, M, K, cells):
    mapCells(cells)
    for i in range(K):
        timeRuns()     
    res = getNumOfAliveCells()
    return str(res)

grids = []
if __name__ == "__main__":
    INPUT_PATH = os.path.dirname(__file__)+"/"+"sample_input.txt"  
    sys.stdin = open(INPUT_PATH, "r")

    T = int(input())
    for test_case in range(1, T + 1):
        NMK = input().split()
        N, M, K = int(NMK[0]), int(NMK[1]), int(NMK[2])
        cells = []
        for i in range(N):
            cells.append([int(elem) for elem in input().split()])
            
        resetGrids()
        actual = "#"+str(test_case)+" "+solution(N, M, K, cells)
        print(actual)
