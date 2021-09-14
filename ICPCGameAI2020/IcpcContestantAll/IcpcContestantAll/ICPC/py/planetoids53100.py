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
DANGER_ZONE = 5000

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

    # def __repr__(self):
    #     return "X: " + str(self.x) + ", Y: " + str(self.y)

class Artifact(Object):
    def __init__(self, x, y):
        super().__init__(x, y)

    # def __repr__(self):
    #     return super(Artifact, self).__repr__()

class Asteroid(Object):
    def __init__(self, x, y, size):
        super().__init__(x, y)
        self.size = int(size) - 48

    # def __repr__(self):
    #     return super(Asteroid, self).__repr__() + ", Size: " + str(self.size)

class Bullet(Object):
    def __init__(self, x, y, src):
        super().__init__(x, y)
        self.src = int(src) - 48

    # def __repr__(self):
    #     return super(Bullet, self).__repr__() + ", Src: " + str(self.src)

class Ship(Object):
    def __init__(self, x, y, r):
        super().__init__(x, y)
        self.r = r

    # def __repr__(self):
    #     return super(Ship, self).__repr__() + ", R: " + str(self.r)

class Ufo(Object):
    def __init__(self, x, y, size):
        super().__init__(x, y)
        self.size = int(size) - 48

    # def __repr__(self):
    #     return super(Ufo, self).__repr__() + ", Size: " + str(self.size)


#####################################################################
# Game Environment Details
#####################################################################
# Ship Details
ship = Ship(0, 0, 0)

# Artifact Details
artifacts = []
for i in range(9):
    artifacts.append(Artifact(0,0))

# Asteroid Details
ast    = {}
astNum = 0

# UFO Details
ufo    = {}
ufoNum = 0

# Bullet Details
bul    = {}
bulNum = 0
  

#####################################################################
# Game State
#####################################################################
# currentScore = 0
# currentTime  = 0
# currentRound = 0
# lives        = 0


#####################################################################
# Helper Functions
#####################################################################

def update_state(data):
    # Update Game State variables
    # global currentScore
    # currentScore = data["currentScore"]
    # global currentTime
    # currentTime  = data["currentTime"]
    # global currentRound
    # currentRound = data["currentRound"]
    # global lives
    # lives        = data["lives"]

    # Update ship pos
    ship.x, ship.y, ship.r = data["shipPos"][0], data["shipPos"][1], data["shipR"] % 360.0

    # Update artifact pos
    newArt = data["artfPos"]
    if artifacts[0].x != newArt[0] or artifacts[0].y != newArt[1]:
        artifacts[0].x, artifacts[0].y = newArt[0], newArt[1]
        
        # Duplicates (8 Copies out of bounds)
        # Left
        artifacts[1].x, artifacts[1].y = newArt[0] - WORLD_WIDTH, newArt[1]

        # Top Left
        artifacts[2].x, artifacts[2].y = newArt[0] - WORLD_WIDTH, newArt[1] + WORLD_HEIGHT

        # Top
        artifacts[3].x, artifacts[3].y = newArt[0], newArt[1] + WORLD_HEIGHT

        # Top Right
        artifacts[4].x, artifacts[4].y = newArt[0] + WORLD_WIDTH, newArt[1] + WORLD_HEIGHT

        # Right
        artifacts[5].x, artifacts[5].y = newArt[0] + WORLD_WIDTH, newArt[1]

        # Bottom Right
        artifacts[6].x, artifacts[6].y = newArt[0] + WORLD_WIDTH, newArt[1] - WORLD_HEIGHT

        # Bottom
        artifacts[7].x, artifacts[7].y = newArt[0], newArt[1] - WORLD_HEIGHT

        # Bottom Left
        artifacts[8].x, artifacts[8].y = newArt[0] - WORLD_WIDTH, newArt[1] - WORLD_HEIGHT


    # Update asteroids  
    # global astNum  
    # astNum = data["astNum"]
    for i, a in enumerate(data["astIds"]):
        if a in ast:
            ast[a].x, ast[a].y, ast[a].size = data["astPos"][i][0], data["astPos"][i][1], data["astSizes"][i] - 48
        else:
            ast[a] = Asteroid(
                data["astPos"][i][0],
                data["astPos"][i][1],
                data["astSizes"][i]
            )

    # Update bullets
    # global bulNum  
    # bulNum = data["bulNum"]
    for i, b in enumerate(data["bulIds"]):
        if b in bul:
            bul[b].x, bul[b].y, bul[b].src = data["bulPos"][i][0], data["bulPos"][i][1], data["bulSrc"][i] - 48
        else:
            bul[b] = Bullet(
                data["bulPos"][i][0],
                data["bulPos"][i][1],
                data["bulSrc"][i]
            )

    # Update UFOs    
    # global ufoNum
    # ufoNum = data["ufoNum"]
    for i, u in enumerate(data["ufoIds"]):
        if u in ufo:
            ufo[u].x, ufo[u].y, ufo[u].src = data["ufoPos"][i][0], data["ufoPos"][i][1], data["ufoSizes"][i] - 48
        else:
            ufo[u] = Ufo(
                data["ufoPos"][i][0],
                data["ufoPos"][i][1],
                data["ufoSizes"][i]
            )

    # DEBUG
    # print_state()


def find_closest_artifact():
    minDistance = inf
    minIdx = 0
    for i, _ in enumerate(artifacts):
        dx, dy = abs(artifacts[i].x - ship.x), abs(artifacts[i].y - ship.y)
        distance = (dx * dx) + (dy * dy)
        if distance < minDistance:
            minDistance, minIdx = distance, i
    
    return minIdx


def immediate_danger():
    for a in ast:
        dx, dy = abs(ast[a].x - ship.x), abs(ast[a].y - ship.y)
        distance = (dx * dx) + (dy * dy)
        if distance <= DANGER_ZONE:
            return True

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

    # Move towards artifact
    dx, dy = artifacts[idx].x - ship.x, artifacts[idx].y - ship.y
    ang = (degrees(atan2(dy, dx))) % 360.0

    distance = (dx * dx) + (dy * dy)

    # if LOGGING:
    #     logging.debug("ANG:" + str(ang))
    #     logging.debug("SHIPR:" + str(ship.r))
    #     logging.debug("DIS:" + str(distance))

    # ENGINE CONTROLS
    if distance > STOP_DISTANCE and abs(ang - ship.r) > STOP_DEGREE:
        string = "0"
    else:
        string = "1"

    # TURNING CONTROLS
    if ship.r + 360 < ang + 360:
        string = "".join((string, "011"))
    elif ship.r + 360 > ang + 360:
        string = "".join((string, "101"))
    else:
        string = "".join((string, "001"))

    # WARP CONTROLS
    if immediate_danger():
        string = "".join((string,"11"))
    else:
        string = "".join((string,"01"))

    # Emit command.
    # if LOGGING: logging.debug("COMMAND:" + string)
    sys.stdout.write("".join((string,"\n")))
    sys.stdout.flush()


# def print_state():
#     print("GAME STATE =============================================")
#     print("currentScore", currentScore)
#     print("currentTime", currentTime)
#     print("currentRound", currentRound)
#     print("lives", lives)
#     print("SHIP DETAILS ===========================================")
#     print("ship", ship)
#     print("ARTIFACT DETAILS =======================================")
#     print("artifact", artifacts)
#     print("ASTEROID DETAILS =======================================")
#     print("astNum", astNum)
#     print("ast", ast)
#     print("UFO DETAILS ============================================")
#     print("ufoNum", ufoNum)
#     print("ufo", ufo)
#     print("BULLET DETAILS =========================================")
#     print("bulNum", bulNum)
#     print("bul", bul)


#####################################################################
# Game Loop
#####################################################################
# logging.basicConfig(filename='test.log', level=logging.DEBUG)
# if LOGGING:
#     logging.debug('\n\nSTARTING LOG')

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
    update_state(data)

    # Act upon given game state
    act_on_state()

    # if LOGGING:
    #     toc = time.perf_counter()
    #     s = f"Frame took {toc - tic:0.6f} seconds"
    #     logging.debug("TIME: " + s)

# if LOGGING:
#     logging.debug("GAME OVER")