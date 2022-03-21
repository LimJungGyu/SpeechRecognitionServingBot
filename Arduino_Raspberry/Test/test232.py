import pygame
import time

pygame.mixer.init()
bang = pygame.mixer.Sound("order.wav")

bang.play()
time.sleep(2.8)
