import sys
import os

def getNumberOfCase(N):
    num = pow(2, N)
    cases = range(0, num)
    cases = [bin(c)[2:].zfill(N) for c in cases]
    return cases

def getLastUserGoneTime(timeline):
    lastOnStair = 0
    for i in range(len(timeline)):
        if len(timeline[i]) > 0:
            lastOnStair = i
    return lastOnStair + 1

def fillStairTimelines(timeline, user, arrived_time, stair_len):
    for moving in timeline[arrived_time:]:
        if len(moving) < 3 and stair_len > 0:
            moving.append(user)
            stair_len -= 1
    for gap in range(arrived_time - len(timeline)):
        timeline.append([])
    for left in range(stair_len):
        timeline.append([user])
    return timeline

def getMinTime(selection, arrived_list, stair_lens):
    timelines = [[[] for i in range(10)], [[] for i in range(10)]]
    for arrived in arrived_list:
        stair, user, time = arrived 
        if selection[user] != str(stair):
            continue
        timelines[stair] = fillStairTimelines(timelines[stair], user, time, stair_lens[stair])
    lastTime = 0
    for timeline in timelines:
        thisTime = getLastUserGoneTime(timeline)
        if thisTime > lastTime:
            lastTime = thisTime
    return lastTime

def solution(N, room):
    users = []
    stairs = []
    stair_lens = []
    for i in range(N):
        for j in range(N):
            if room[i][j] == 1:
                users.append([i, j])
            elif 2 <= room[i][j] <= 10:
                stairs.append([i, j])
                stair_lens.append(room[i][j])
    arrived_list = []
    for uid in range(len(users)):
        for sid in range(len(stairs)):
            arrived_list.append((sid, uid, 1+ abs(stairs[sid][0]-users[uid][0]) + abs(stairs[sid][1]-users[uid][1])))
    arrived_list.sort(key=lambda e: e[2])
    minTime = 200
    
    for selection in getNumberOfCase(len(users)):
        time = getMinTime(selection, arrived_list, stair_lens)
        if time < minTime:
            minTime = time
    return minTime

if __name__ == "__main__":
    INPUT_PATH = os.path.dirname(__file__)+"/"+"sample_input.txt"  
    sys.stdin = open(INPUT_PATH, "r")

    T = int(input())
    for test_case in range(1, T + 1):
        N = int(input())
        room = []
        for i in range(N):
            room.append([int(elem) for elem in input().split()])
        actual = "#"+str(test_case)+" "+str(solution(N, room))
        print(actual)
    