#!/usr/bin/env python3
# ^^^ Important - tells kattis this is python3 vs python2

import sys
import json
from math import atan2, inf, degrees
# import logging
# import time

#####################################################################
# AI Params
#####################################################################
# Enable writing to test.log
LOGGING = True

# Distance at which to stop engines and focus on pointing towards artifact
STOP_DISTANCE = 100000

# Difference in angles to trigger the engine stopping
STOP_DEGREE = 4

# Radius around the ship to be considered the danger zone
DANGER_ZONE = 2000

#####################################################################
# Constants
#####################################################################
# General
WORLD_WIDTH  = 7600
WORLD_HEIGHT = 4200

# Scoring Constants
# Destroy UFO
D_UFO   = 1500
# Collect Artifact
C_ARTF  = 2000
# Ship Damaged
DAMAGED = -350
# Asteroid Small
D_ASTS  = 150
# Asteroid Med
D_ASTM  = 300
# Asteroid Large
D_ASTL  = 300

# Asteroid Radii
AST_R_S = 50
AST_R_M = 100
AST_R_L = 200

# UFO Radii
UFO_R_S = 40
UFO_R_L = 80


#####################################################################
# Class Definitions
#####################################################################

class Object:
    def __init__(self, x, y):
        self.x, self.y = x, y

    def __repr__(self):
        return "X: " + str(self.x) + ", Y: " + str(self.y)

class Artifact(Object):
    def __init__(self, x, y):
        super().__init__(x, y)

    def __repr__(self):
        return super(Artifact, self).__repr__()

class Asteroid(Object):
    def __init__(self, x, y, size):
        super().__init__(x, y)
        self.size = int(size) - 48

    def __repr__(self):
        return super(Asteroid, self).__repr__() + ", Size: " + str(self.size)

class Bullet(Object):
    def __init__(self, x, y, src):
        super().__init__(x, y)
        self.src = int(src) - 48

    def __repr__(self):
        return super(Bullet, self).__repr__() + ", Src: " + str(self.src)

class Ship(Object):
    def __init__(self, x, y, r):
        super().__init__(x, y)
        self.r = r

    def __repr__(self):
        return super(Ship, self).__repr__() + ", R: " + str(self.r)

class Ufo(Object):
    def __init__(self, x, y, size):
        super().__init__(x, y)
        self.size = int(size) - 48

    def __repr__(self):
        return super(Ufo, self).__repr__() + ", Size: " + str(self.size)

class GameState:
    def __init__(self):
        self.currentScore = 0
        self.currentTime  = 0

        self.ship = Ship(0,0,0)
        self.artifacts = []
        for _ in range(9):
            self.artifacts.append(Artifact(0,0))

        self.ast = {}
        self.astNum = 0

        self.ufo = {}
        self.ufoNum = 0

        self.bul = {}
        self.bulNum = 0

    def update_state(self, data):
        # Update Game State variables
        # self.currentScore = data["currentScore"]
        # self.currentTime  = data["currentTime"]

        # Update ship pos
        self.ship.x, self.ship.y, self.ship.r = data["shipPos"][0], data["shipPos"][1], data["shipR"] % 360.0

        # Update artifact pos
        newArt = data["artfPos"]
        if self.artifacts[0].x != newArt[0] or self.artifacts[0].y != newArt[1]:
            self.artifacts[0].x, self.artifacts[0].y = newArt[0], newArt[1]
            
            # Duplicates (8 Copies out of bounds)
            # Left
            self.artifacts[1].x, self.artifacts[1].y = newArt[0] - WORLD_WIDTH, newArt[1]

            # Top Left
            self.artifacts[2].x, self.artifacts[2].y = newArt[0] - WORLD_WIDTH, newArt[1] + WORLD_HEIGHT

            # Top
            self.artifacts[3].x, self.artifacts[3].y = newArt[0], newArt[1] + WORLD_HEIGHT

            # Top Right
            self.artifacts[4].x, self.artifacts[4].y = newArt[0] + WORLD_WIDTH, newArt[1] + WORLD_HEIGHT

            # Right
            self.artifacts[5].x, self.artifacts[5].y = newArt[0] + WORLD_WIDTH, newArt[1]

            # Bottom Right
            self.artifacts[6].x, self.artifacts[6].y = newArt[0] + WORLD_WIDTH, newArt[1] - WORLD_HEIGHT

            # Bottom
            self.artifacts[7].x, self.artifacts[7].y = newArt[0], newArt[1] - WORLD_HEIGHT

            # Bottom Left
            self.artifacts[8].x, self.artifacts[8].y = newArt[0] - WORLD_WIDTH, newArt[1] - WORLD_HEIGHT


        # Update asteroids    
        self.astNum = data["astNum"]
        for i, a in enumerate(data["astIds"]):
            if a in self.ast:
                self.ast[a].x, self.ast[a].y, self.ast[a].size = data["astPos"][i][0], data["astPos"][i][1], data["astSizes"][i] - 48
            else:
                self.ast[a] = Asteroid(
                    data["astPos"][i][0],
                    data["astPos"][i][1],
                    data["astSizes"][i]
                )

        # Update bullets
        self.bulNum = data["bulNum"]
        for i, b in enumerate(data["bulIds"]):
            if b in self.bul:
                self.bul[b].x, self.bul[b].y, self.bul[b].src = data["bulPos"][i][0], data["bulPos"][i][1], data["bulSrc"][i] - 48
            else:
                self.bul[b] = Bullet(
                    data["bulPos"][i][0],
                    data["bulPos"][i][1],
                    data["bulSrc"][i]
                )

        # Update UFOs    
        self.ufoNum = data["ufoNum"]
        for i, u in enumerate(data["ufoIds"]):
            if u in self.ufo:
                self.ufo[u].x, self.ufo[u].y, self.ufo[u].src = data["ufoPos"][i][0], data["ufoPos"][i][1], data["ufoSizes"][i] - 48
            else:
                self.ufo[u] = Ufo(
                    data["ufoPos"][i][0],
                    data["ufoPos"][i][1],
                    data["ufoSizes"][i]
                )


#####################################################################
# Helper Functions
#####################################################################

def navigate(pos):
    dx, dy = pos[0] - G.ship.x, pos[1] - G.ship.y
    ang = (degrees(atan2(dy, dx))) % 360.0

    distance = (dx * dx) + (dy * dy)

    if distance > STOP_DISTANCE and abs(ang - G.ship.r) > STOP_DEGREE:
        string = "0"
    else:
        string = "1"

    if G.ship.r + 360 < ang + 360:
        string = "".join((string, "011"))
    elif G.ship.r + 360 > ang + 360:
        string = "".join((string, "101"))
    else:
        string = "".join((string, "001"))

    return string, distance


def find_closest_artifact():
    minDistance = inf
    minIdx = 0
    for i, _ in enumerate(G.artifacts):
        dx, dy = abs(G.artifacts[i].x - G.ship.x), abs(G.artifacts[i].y - G.ship.y)
        distance = (dx * dx) + (dy * dy)
        if distance < minDistance:
            minDistance, minIdx = distance, i
    
    return minIdx


def immediate_danger():
    for a in G.ast:
        dx, dy = abs(G.ast[a].x - G.ship.x), abs(G.ast[a].y - G.ship.y)
        distance = (dx * dx) + (dy * dy)
        if distance <= DANGER_ZONE:
            return True

    # CANT DO BULLETS BECAUSE GAME IS BAD >:(
    # for b in bul:
    #     dx, dy = abs(bul[b].x - ship.x), abs(bul[b].y - ship.y)
    #     distance = (dx * dx) + (dy * dy)
    #     if distance <= DANGER_ZONE:
    #         return True

    return False


def act_on_state():
    string = ""

    # Find closest artifact
    idx = find_closest_artifact()

    # NAVIGATION CONTROLS
    string, distance = navigate((G.artifacts[idx].x, G.artifacts[idx].y))

    # WARP CONTROLS
    if immediate_danger():
        string = "".join((string,"11"))
    else:
        string = "".join((string,"01"))

    # Emit command.
    # if LOGGING: logging.debug("COMMAND:" + string)
    sys.stdout.write("".join((string,"\n")))
    sys.stdout.flush()


#####################################################################
# Game Loop
#####################################################################
# logging.basicConfig(filename='test.log', level=logging.DEBUG)
# if LOGGING:
#     logging.debug('\n\nSTARTING LOG')

G = GameState()

while True:
    # if LOGGING: tic = time.perf_counter()

    raw_data = sys.stdin.readline()
    # Exit if stdin is closed.
    if not raw_data:
        break
    
    data = json.loads(raw_data)

    # Exit if we hit Game Over.
    if "gameOver" in data and data["gameOver"]:
        break

    # Update game state with new data
    G.update_state(data)

    # Act upon given game state
    act_on_state()

    # if LOGGING:
    #     toc = time.perf_counter()
    #     s = f"Frame took {toc - tic:0.6f} seconds"
    #     logging.debug("TIME: " + s)

# if LOGGING:
#     logging.debug("GAME OVER")