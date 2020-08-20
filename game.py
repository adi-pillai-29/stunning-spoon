"""
Adi Pillai - arp3np
Final Submission
How to accomplish user input:
Mouse: a click will be used upon a location on the screen where a asteroid/trajectory is intended to hit a
planet in a group of cycling planets far opposite a asteroid "cannon" - player 1
The asteroid can further be controlled by dragging the mouse in the direction of the planet to be destroyed
Keyboard to control a spaceship intended to destroy the launched asteroids - player 2
Graphics/Images:
Background: starry space
Spacheship = player 2
Start Screen:
To be displayed and removed after a certain amount of time
game name, student names (and IDs), and basic game instructions
Window:
800,600
-----------------------------------------------
Animation:
The asteroid will change its appearance through animation/space sprite sheet to give off the impression of rotating in 3D
Collectibles:
The planets will be collectibles
Increases a counter of planets destroyed by the asteroid
Timer:
Counting down
Two players simultaneously:
Player 1 - mouse controlled asteroids
Player 2 - keyboard controlled spaceship that is intended to destroy the asteroid before it
can destroy the cycling planets
"""
#Aditya Pillai - arp3np

import pygame
import gamebox
import random
import math

camera = gamebox.Camera(800, 600)
planets = []
planet1 = gamebox.from_image(600, 80, 'planet1.png')
planet1.scale_by(.07)
planet2 = gamebox.from_image(600, 180, 'planet2.png')
planet2.scale_by(.07)
planet3 = gamebox.from_image(600, 280, 'planet3.png')
planet3.scale_by(.12)
planet4 = gamebox.from_image(600, 380, 'planet4.png')
planet4.scale_by(.12)
planet5 = gamebox.from_image(600, 480, 'planet5.png')
planet5.scale_by(.12)
planet6 = gamebox.from_image(600, 545, 'planet6.png')
planet6.scale_by(.07)
planets = [planet1, planet2, planet3, planet4, planet5, planet6]
spaceship = gamebox.from_image(330, 50, 'spaceship.png')
spaceship.scale_by(.25)
number_of_frames = 8
sheet = gamebox.load_sprite_sheet("comet_spritesheet.png", 8, 8)
frame = 0
counter = 0
comet = gamebox.from_image(50, 300, sheet[frame])
comet.scale_by(.5)
stars = []
counter = 0
radians = 0
scores = 0
ticks_time = 900
ticks = 0


def start():
    start_box1 = gamebox.from_text(400, 100, "ASTEROIDS VS ASTRONAUTS", 24, "white")
    start_box2 = gamebox.from_text(400, 200, "Aditya Pillai - arp3np", 24, "white")
    start_box3 = gamebox.from_text(400, 300, "PLAYER 1: Use mouse clicks and drags near planets to destroy planets with asteroids and avoid the spaceship", 20, "white")
    start_box4 = gamebox.from_text(400, 400, "PLAYER 2: Use the arrow keys to stop the asteroids with the spaceship", 24, "white")
    start_box5 = gamebox.from_text(400, 500, "If all planets are destroyed, the asteroids win.", 24, "white")
    start_box6 = gamebox.from_text(400, 550, "Good luck! You have 20 seconds!", 32, 'white')
    start_boxes = [start_box1, start_box2, start_box3, start_box4, start_box5, start_box6]
    if ticks_time > 600:
        for starts in start_boxes:
            camera.draw(starts)

def planets_move():
    gravity = 3
    for planet in planets:
        planet.y += gravity
        if planet.y >= 600:
            planet.y = 0
    for planet in planets:
        if ticks % 5 == 0:
            planet.speedx = random.randint(-5, 5)
            planet.move_speed()

def starry_background():
    global counter
    counter += 1
    if counter % 5 == 0:
        numstars = random.randint(0, 7)
        for i in range(numstars):
            stars.append(gamebox.from_color(random.randint(5, 800 - 5), 0, "white", 3, 3))
    for star in stars:
        star.y += 8
        if star.y > 600:
            stars.remove(star)
        camera.draw(star)

def comet_move():
    global radians
    global ticks_time
    if (ticks_time / 30) > 0:
        seconds = str(int((ticks_time / 30))).zfill(2)
    else:
        seconds = "00"
    if seconds != "00":
        if camera.mouseclick == True:
            if camera.mousex > 300:
                x, y = camera.mouse
                y1, x1 = (y - comet.y), (x - comet.x)
                radian = math.atan2(y1, x1)
                degrees = (radian * 180) / (22/7)
                degrees  = -1 * degrees
                comet.rotate(degrees)
                radians = math.radians(degrees)
                comet.speedy = 10 * -math.sin(radians)
                comet.speedx = 10 * math.cos(radians)
    else:
        comet.move(50 - comet.x, 300 - comet.y)
        camera.draw(comet)
    if comet.x >= 800 or comet.x <= 1:
        comet.move(50 - comet.x, 300 - comet.y)
        comet.rotate(-radians)
        comet.speedx = 0
        comet.speedy = 0
        comet.move_speed()
        comet.rotate(-radians)
    elif comet.y >= 600 or comet.y <= 1:
        comet.move(50, 300)
        comet.move(50 - comet.x, 300 - comet.y)
        comet.rotate(-radians)
        comet.speedx = 0
        comet.speedy = 0
        comet.move_speed()
        comet.rotate(-radians)
    camera.draw(comet)

def spaceship_move():
    if spaceship.y >= 600 or spaceship.y <= -10:
        spaceship.speedx, spaceship.speedy = 0, 0
        spaceship.move_speed()
        spaceship.y = 0

def collision():
    global scores
    for planet in planets:
        if comet.touches(planet):
            planets.remove(planet)
            comet.move(50 - comet.x, 300 - comet.y)
            comet.rotate(-radians)
            comet.speedx = 0
            comet.speedy = 0
            comet.move_speed()
            comet.rotate(-radians)
            scores += 1
    if spaceship.touches(comet):
        spaceship.move(330 - spaceship.x, 50 - comet.y)
        comet.move(50 - comet.x, 300 - comet.y)
        comet.rotate(-radians)
        comet.speedx = 0
        comet.speedy = 0
        comet.move_speed()
        comet.rotate(-radians)

def score_time():
    global scores
    score_box = gamebox.from_text(90, 30, "Planets Hit: " + str(scores), 32, "white")
    if (ticks_time / 30) > 0:
        seconds = str(int((ticks_time / 30))).zfill(2)
    else:
        seconds = "00"
    if seconds != "00":
        time_box = gamebox.from_text(650, 30, "Time Remaining: " + seconds, 32, "white")
    elif seconds == "00":
        time_box = gamebox.from_text(650, 30, "Time Remaining: 00", 32, "white")
        comet.move_speed()
    camera.draw(score_box)
    camera.draw(time_box)
    if len(planets) == 0:
        win_box = gamebox.from_text(400, 300, "THE ASTEROIDS HAVE WON!", 48, "white")
        camera.draw(win_box)
    elif (seconds == "00") and (len(planets) != 0):
        win_box = gamebox.from_text(400, 300, "THE ASTRONAUTS HAVE WON!", 48, "white")
        camera.draw(win_box)

def tick(keys):
    global ticks_time
    global counter
    global frame
    global number_of_frames
    global ticks
    if frame == number_of_frames:
        frame = 0
    if counter % 1 == 0:
        comet.image = sheet[frame]
    frame += 1
    counter += 1
    ticks_time -= 1
    ticks += 1
    camera.clear('black')
    if pygame.K_RIGHT in keys:
        spaceship.speedx += .6
    if pygame.K_LEFT in keys:
        spaceship.speedx -= .6
    if pygame.K_UP in keys:
        spaceship.speedy -= .6
    if pygame.K_DOWN in keys:
        spaceship.speedy += .6
    spaceship.move_speed()
    spaceship_move()
    starry_background()
    planets_move()
    comet_move()
    comet.move_speed()
    collision()
    for planet in planets:
        camera.draw(planet)
    camera.draw(spaceship)
    score_time()
    start()
    camera.display()

gamebox.timer_loop(30, tick)

