import importlib
import os
import sys
TEST_FLAG = 1

'''
This template can be used to test problems of SW Expert Academy,
whose test cases consist of a certain number('inputLines') of lines.
Usage: python template.py {name of problem directory}
'''
def getInputLines(input_path):
    with open(input_path, 'r') as file:
        text = file.read().split("\n")
        num_of_cases = int(text[0])
        return len(text[1:])//num_of_cases

if __name__ == "__main__":
    TEST_DIR = sys.argv[1]
    SCRIPT_DIR = os.path.dirname(__file__)
    INPUT_PATH = SCRIPT_DIR+"/"+TEST_DIR+"/"+"sample_input.txt"    
    OUTPUT_PATH = SCRIPT_DIR+"/"+TEST_DIR+"/"+"sample_output.txt"
    mod = importlib.import_module(TEST_DIR+".solution")
    solution = getattr(mod, "solution")
    
    expecteds = open(OUTPUT_PATH, "r").read().split("\n")
    sys.stdin = open(INPUT_PATH, "r")
    
    T = int(input())
    inputLines = getInputLines(INPUT_PATH)
    for test_case in range(1, T + 1):
        inputs = [input() for i in range(inputLines)]
        actual = "#"+str(test_case)+" "+solution(tuple(inputs))
        ##### For submission, delete here AND set var inputLines #####
        if TEST_FLAG:
            expected = expecteds.pop(0)
            if (expected != actual):
                print("FAIL: ", inputs, "\n",\
                    "\tExpect result:", expected, "\n"\
                    "\tActual result:", actual, "")
            else:
                print("PASS")
            continue
        ###################################################3##########
        print(actual)