#https://leetcode.com/problems/generate-random-point-in-a-circle/?envType=problem-list-v2&envId=geometry&difficulty=MEDIUM
import random
import math

class Solution:

    def __init__(self, radius: float, x_center: float, y_center: float):
        self.radius = radius
        self.x_center = x_center
        self.y_center = y_center        

    def randPoint(self) -> List[float]:
        r = self.radius * math.sqrt(random.random())
        theta = random.uniform(0, 2 * math.pi)
        x = self.x_center + r * math.cos(theta)
        y = self.y_center + r * math.sin(theta)
        return [x,y]

#Explanation
#Let us use polar coordinates:
x = R * cos(theta)
y = R * sin(theta).
#theta
theta = values between 0 and 2pi
