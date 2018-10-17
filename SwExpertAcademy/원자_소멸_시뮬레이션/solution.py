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
    if (0 <= x <= 2000) and (0 <= y <= 2000):
        return False
    return True

def atomTimeRuns(idx):
    src, diff, energy = atoms[idx]
    dst = (src[0] + diff[0], src[1] + diff[1])
    atoms[idx][0] = dst

def timeRuns():
    global atoms
    energy = 0
    for atom_idx in range(len(atoms)):
        atomTimeRuns(atom_idx)
    atoms = [atom for atom in atoms if not outOfBound(atom[0])]
    locas = set([atom[0] for atom in atoms])
    if len(locas) != len(atoms):
        duplicates = set()
        for atom in atoms:
            sameLocaAtoms = filter(lambda e: e[0]==atom[0], atoms)
            if len(list(sameLocaAtoms)) > 1:
                duplicates.add(atom[0])
                energy += atom[2]
        atoms = [atom for atom in atoms if atom[0] not in duplicates]
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
            atoms.append([(int(x)+1000, int(y)+1000), INT_TO_DIFF[dir], int(energy)])
        actual = "#"+str(test_case)+" "+str(solution())
        print(actual)
        
N = 0
atoms = []