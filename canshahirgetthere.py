# VM7WC '16 #3 Silver - Can Shahir even get there?!
# https://dmoj.ca/problem/vmss7wc16c3p2

import sys
input = sys.stdin.readline

houses, roads, starting_point, destination = map(int, input().split())

neighbors = [[] for i in range(houses+1)]

for i in range(roads):
  v1, v2 = map(int, input().split())
  neighbors[v1].append(v2) 
  neighbors[v2].append(v1) 
  
def BFS(begin, end):
  visited = []
  queue = [begin]

  while queue:
    current = queue.pop(0)
    if current not in visited:
      visited.append(current)
      for neighbor in neighbors[current]:
        if neighbor == end:
          return True
        else:
          queue.append(neighbor)
  return False

if BFS(starting_point, destination) or roads == 0:
  print('GO SHAHIR!')
elif not BFS(starting_point, destination):
  print('NO SHAHIR!')