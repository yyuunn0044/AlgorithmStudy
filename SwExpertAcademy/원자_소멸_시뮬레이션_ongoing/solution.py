import sys
import os

INT_TO_DIFF= {
    "0": (0, 1),
    "1": (0, -1),
    "2": (-1, 0),
    "3": (1, 0)
}
def outOfBound(atom_xy):
    x, y = atom_xy
    if (-2000 <= x <= 2000) and (-2000 <= y <= 2000):
        return False
    return True

def removeGoneAtoms():

    upMax = 1000
    downMax = -1000
    leftMax = -1000
    rightMax = 1000
    for atom in atoms:
        x, y = atom[0]
        upMax = upMax if y <= upMax else y
        downMax = downMax if y >= downMax else y
        leftMax = leftMax if x >= leftMax else x
        rightMax = rightMax if x <= rightMax else x
    for atom in atoms:
        x, y = atom[0]
        direction = atom[1]
        if y == upMax and direction == (0, 1) \
            or y == downMax and direction == (0, -1) \
            or x == leftMax and direction == (-1, 0) \
            or x == rightMax and direction == (1, 0):
            del atom


def atomTimeRuns(atom):
    src, diff, energy = atom
    dst = (src[0] + diff[0], src[1] + diff[1])
    return dst, diff, energy

def timeRuns():
    global atoms
    energy = 0
    for i in range(100):
        atoms = [atomTimeRuns(atom) for atom in atoms if not outOfBound(atom[0])]
        locas = [atom[0] for atom in atoms]
        duplicates = [loca for loca in locas if locas.count(loca) > 1]
        removed_atoms = [atom for atom in atoms if atom[0] in duplicates]
        for removed in removed_atoms:
            energy += removed[2]
            atoms.remove(removed)

    return energy

def solution():
    energy = 0
    while len(atoms) != 0:
        energy += timeRuns()
        removeGoneAtoms()
    return energy

if __name__ == "__main__":
    INPUT_PATH = os.path.dirname(__file__)+"/"+"sample_input.txt"  
    sys.stdin = open(INPUT_PATH, "r")

    T = int(input())
    for test_case in range(1, T + 1):
        global N
        global atoms
        N = int(input())
        atoms = []
        for i in range(N):
            x, y, dir, energy = input().split()
            atoms.append([(int(x)*2, int(y)*2), INT_TO_DIFF[dir], int(energy)])
        actual = "#"+str(test_case)+" "+str(solution())
        print(actual)
        
N = 0
atoms = []