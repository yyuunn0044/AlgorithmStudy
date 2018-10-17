import sys
import os
from pprint import pprint
DIRECTION = ['U', 'D', 'L', 'R']
digit_direction = {
    "U": (-1, 0),
    "D": (1, 0),
    "L": (0, -1),
    "R": (0, 1)
}
side = {
    1: { "D":"R", "L":"U" },
    2: {"U":"R", "L":"D"},
    3:{"U":"L", "R":"D"},
    4:{"D":"L", "R":"U"},
}
flat = {
    "D": "U",
    "U": "D",
    "R": "L",
    "L": "R"
}

def getIndex(i):
    indexes = []
    for row in range(N):
        for col in range(N):
            if board[row][col] == i:
                indexes.append((row, col))
    return indexes
def outOfBoard(r, c):
    if r < 0 or r > N-1:
        return True
    elif c < 0 or c > N-1:
        return True
    else:
        return False
def go(start, direction):
    print(start, direction)
    point = 0
    r, c = start
    r_diff, c_diff = digit_direction[direction]
    n_r, n_c = r+r_diff, c+c_diff
    if outOfBoard(n_r, n_c):
        n_r, n_c = r, c
        end = board[n_r][n_c]
        next_direction = flat[direction]
        point += 1
    else:
        end = board[n_r][n_c]
        next_direction = direction
    if end >= 1 and end <= 5:
        try:
            next_direction = side[end][direction]
        except KeyError:
            next_direction = flat[direction]
        point += 1
    elif end >= 6 and end <= 10:
        end = getIndex(end).remove((n_r, n_c))[0]
    elif end == -1:
        point = -1
    else:
        pass

    return ((n_r, n_c), next_direction, point)
def totalRoute(unvisited):
    route = []
    total_point = 0
    start = src = unvisited[0:2]
    src_direc = unvisited[2]
    while not start in route:
        dst, dst_direc, point = go(src, src_direc)
        print(dst, dst_direc, point)
        if point == -1:
            break
        total_point += point 
        src = dst
        src_direc = dst_direc
        route += [(src[0], src[1], src_direc)]
    print("this route",total_point)
    return total_point

def getUnvisitedRoute():
    unvisited = []
    for r in range(N):
        for c in range(N):
            if board[r][c] == 0:
                unvisited.extend([(r, c, direc) for direc in DIRECTION])
    return unvisited

def removeUnvisited(unvisited, route):
    for r in route:
        other = tuple(r[0:2] + flat[r[2]])
        unvisited.remove(r)
        unvisited.remove(other)
    return unvisited

def solution(N, board):
    maxScore = 0
    unvisited = getUnvisitedRoute()
    while len(unvisited) != 0:
        u = unvisited[0]
        route, score = totalRoute(u)
        unvisited = removeUnvisited(unvisited, route)
        if score > maxScore:
            maxScore = score
    return maxScore

if __name__ == "__main__":
    INPUT_PATH = os.path.dirname(__file__)+"/"+"sample_input.txt"  
    sys.stdin = open(INPUT_PATH, "r")

    T = int(input())
    for test_case in range(1, T + 1):
        global N 
        global board 
        N = int(input())
        board = []
        for i in range(N):
            board.append([int(elem) for elem in input().split()])
        actual = "#"+str(test_case)+" "+str(solution(N, board))
        print(actual)
        

board = []
N = 0 