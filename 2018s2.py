sunflower = []
n = int(input())

for i in range(n):
    temp = [int(i) for i in input().split()]
    sunflower.append(temp)

# sunflower [
#     [1, 3], 
#     [2, 9]
#     ]

while sunflower[0][0] > sunflower[0][-1] or sunflower[-1][0] < sunflower[0][0]:
    copy = []
    new = []
    # rotate 90 cw
    for i in range(len(sunflower)):
        for j in range(len(sunflower)-1, -1, -1):
            copy.append(sunflower[j][i])

        new.append(copy)
        #print(new)
        copy = []
    sunflower = new


for r in sunflower:
    print(" ".join(str(i) for i in r))