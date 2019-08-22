#!/bin/python3
import  math
import  pygame
import  fileinput

scale = 1;

bgd_color = (0, 27, 42)

room_color = (0, 199, 199)
room_size = scale * 32
room_x = 100
room_y = 100


width = 600 * scale
height = 600 * scale

def read_file():
    for line in fileinput.input():
        print(line)

def draw_pipes(win, nb_rooms):
    pygame.draw.line(win, (255, 255, 255), (room_x, room_y), (room_x + 100, room_y + 100), 10 * scale)
    

def draw_rooms(win, nb_rooms):
    #for i in range(nb_rooms)
    pygame.draw.circle(win, room_color, (room_x, room_y), room_size, 0)
    pygame.draw.circle(win, (255, 255, 255), (room_x, room_y), room_size, int(room_size / 8))
    pygame.draw.circle(win, room_color, (room_x + 100, room_y + 100), room_size, 0)
    pygame.draw.circle(win, (255, 255, 255), (room_x + 100, room_y + 100), room_size, int(room_size / 8))

def render(win):
    win.fill(bgd_color)
    draw_pipes(win, 0)
    draw_rooms(win, 0)
    pygame.display.update()

def main():
    read_file()
    pygame.init()
    clock = pygame.time.Clock()
    win = pygame.display.set_mode((width, height))
    pygame.display.set_caption("Lem-in visualiser")
    pygame.key.set_repeat(1, 10)
    flag = True
    while flag:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                exit()
        render(win)
    pygame.quit()
main()
