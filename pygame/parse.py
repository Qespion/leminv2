import pygame
import sys


class   island:
    def __init__(self, name, x, y, boomBoomBateau):
        self.name = name
        self.x = x
        self.y = y
        self.link = []
        self.boomBoomBateau = boomBoomBateau
    

class   lemin:
    
parse = 0
boomBoomBateau = 0
for line in sys.stdin:
    if parse == 0:
        if line[0] != '#':
            ant_nb = int(line)
            parse += 1
    if parse == 1:
        print (line)
        if line == "##start\n":
            if (boomBoomBateau == 0):
                boomBoomBateau = 1
            if (boomBoomBateau == 2):
                print("start is end")
        elif line == "##end\n":
            if (boomBoomBateau == 0):
                boomBoomBateau = 2
            if (boomBoomBateau == 1):
                print("end is start")
        elif line[0] == '#' and line[1] != '#':
            continue
        else:
            continue

exit()
RED = (255,0,0)
radius = 10
BACKGROUND = (0,0,0)

pygame.init()
display_height = 680
display_width = 720
screen = pygame.display.set_mode((display_width, display_height))
screen.fill(BACKGROUND)

def game_loop():
    done = False
    while not done:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                done = True
        pygame.display.flip()

game_loop()
pygame.quit()
quit()