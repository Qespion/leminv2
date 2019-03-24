import pygame
import time

RED = (255,0,0)
radius = 15
BACKGROUND = (0,0,0)
pygame.init()
display_height = 1080
display_width = 1920
screen = pygame.display.set_mode((display_width, display_height))
screen.fill(BACKGROUND)

def text_objects(text, font):
    textSurface = font.render(text, True, RED)
    return textSurface, textSurface.get_rect()

def message_display(text):
    largeText = pygame.font.Font('freesansbold.ttf',115)
    TextSurf, TextRect = text_objects(text, largeText)
    TextRect.center = ((display_width/2),(display_height/2))
    screen.blit(TextSurf, TextRect)

    pygame.display.update()

    time.sleep(2)

    game_loop()

def game_loop():
    done = False
    while not done:
            for event in pygame.event.get():
                    if event.type == pygame.QUIT:
                        done = True
                    if event.type == pygame.MOUSEBUTTONDOWN and event.button == 1:
                        spot = event.pos
                        pygame.draw.circle(screen, RED, spot, radius)
                    if event.type == pygame.KEYDOWN:
                        message_display("coucou")
                        # pygame.display.update()
                    if event.type == pygame.KEYUP:
                        done = True
            pygame.display.flip()

game_loop()
pygame.quit()
quit()