import pygame
import sys

class Ant:
    def __init__(self, id, pos):
        self.id = id
        self.pos = pos

class   Island:
    def __init__(self, name, x, y):
        self.name = name
        self.x = x
        self.y = y
        self.link = []
    
    def get_pos(self):
        return self.x, self.y

class   lemin:
    def __init__(self):
        self.n = 0
        self.rooms = dict()
        self.movements = list()
        self.ants = list()
        self.start = None
        self.end = None


parse = 0
boomBoomBateau = 0
# for line in sys.stdin:
#     if parse == 0:
#         if line[0] != '#':
#             ant_nb = int(line)
#             parse += 1
#     if parse == 1:
#         # print (line)
#         if line == "##start\n":
#             if (boomBoomBateau == 0):
#                 boomBoomBateau = 1
#             if (boomBoomBateau == 2):
#                 print("start is end")
#         elif line == "##end\n":
#             if (boomBoomBateau == 0):
#                 boomBoomBateau = 2
#             if (boomBoomBateau == 1):
#                 print("end is start")
#         elif line[0] == '#' and line[1] != '#':
#             continue
#         else:
#             continue

RED = (255,0,0)
radius = 10
BACKGROUND = (0,0,0)

if __name__ == '__main__':
    parse = lemin();
