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
    if (-1000 <= x <= 1000) and (-1000 <= y <= 1000):
        return False
    return True

'''
def atomTimeRuns(atom):
    src, diff, energy = atom
    dst = (src[0] + diff[0], src[1] + diff[1])
    return dst, diff, energy
'''
def timeRuns():
    global atoms
    energy = 0
    for i in range(100):
        atoms = [[(atom[0][0] + atom[1][0], atom[0][1] + atom[1][1]), atom[1], atom[2]]
                    for atom in atoms if not outOfBound(atom[0])]
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
            atoms.append([(int(x), int(y)), INT_TO_DIFF[dir], int(energy)])
        actual = "#"+str(test_case)+" "+str(solution())
        print(actual)
        
N = 0
atoms = []