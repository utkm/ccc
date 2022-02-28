# CCC '19 S1 - Flipper

out = [
    [1, 2],
    [3, 4]
]

sequence = input()

vert = sequence.count('V')
hor = sequence.count('H')

vert = vert % 2
hor = hor % 2

if vert:
    out[0][0], out[0][1] = out[0][1], out[0][0]
    out[1][0], out[1][1] = out[1][1], out[1][0]

if hor:
    out[0][0], out[1][0] = out[1][0], out[0][0]
    out[0][1], out[1][1] = out[1][1], out[0][1]

for l in out:
    print(str(l[0]) + " " + str(l[1]))