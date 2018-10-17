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
    1: {"D": "R", "L": "U"},
    2: {"U": "R", "L": "D"},
    3: {"U": "L", "R": "D"},
    4: {"D": "L", "R": "U"},
}
flat = {
    "D": "U",
    "U": "D",
    "R": "L",
    "L": "R"
}

def get_index(kind):
    indexes = []
    for row in range(N):
        for col in range(N):
            if board[row][col] == kind:
                indexes.append((row, col))
    return indexes

def out_of_board(dst):
    r, c = dst[0], dst[1]
    if r < 0 or r > N-1:
        return True
    elif c < 0 or c > N-1:
        return True
    else:
        return False

def go(src, src_direc):
    point = 0
    r, c = src
    r_diff, c_diff = digit_direction[src_direc]
    dst = (r+r_diff, c+c_diff)
    dst_direc = src_direc

    if out_of_board(dst):
        dst, dst_direc, tmp_point = go(dst, flat[dst_direc])
        point += 1 + tmp_point
    else:
        kind = board[dst[0]][dst[1]]
        if 1 <= kind <= 5:
            try:
                dst_direc = side[kind][src_direc]
            except KeyError:
                dst_direc = flat[src_direc]
            point += 1
        elif 6 <= kind <= 10:
            wormholes = get_index(kind)
            wormholes.remove(dst)
            dst = wormholes[0]
        elif kind == -1:
            dst = None
        else:
            pass

    return dst, dst_direc, point


def totalRoute(unvisited):
    route = []
    total_point = 0
    start = src = unvisited[0:2]
    src_direc = unvisited[2]
    while True:
        route += [(src[0], src[1], src_direc)]
        #print(src, src_direc)
        dst, dst_direc, point = go(src, src_direc)
        #print(dst, dst_direc, point)
        total_point += point 
        src = dst
        src_direc = dst_direc
        if src is None or start == src:
            break
    #print("this route",total_point)
    return route, total_point

def getAllDeparture():
    unvisited = []
    for r in range(N):
        for c in range(N):
            if board[r][c] == 0:
                unvisited.extend([(r, c, direc) for direc in DIRECTION])
    return unvisited

def solution():
    maxScore = 0
    unvisited = getAllDeparture()
    while len(unvisited) != 0:
        u = unvisited[0]
        route, score = totalRoute(u)
        unvisited = unvisited[1:]
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
        actual = "#"+str(test_case)+" "+str(solution())
        print(actual)
        

board = []
N = 0 