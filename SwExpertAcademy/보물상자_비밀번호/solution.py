
def solution(inputs):
    NK, digits = inputs
    N, K = NK.split()
    digits = digits.strip()
    L = int(N)//4
    nums = set()
    for shift in range(L):
        a, b, c, d = digits[:L], digits[L:L*2], digits[L*2:L*3], digits[L*3:]
        nums = nums.union({a, b, c, d})
        digits = digits[1:]+digits[0]
    nums = [int(num, 16) for num in nums]
    nums.sort(reverse=True)
    return str(nums[int(K)-1])
