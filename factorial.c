import pygame
import random
pygame.init()
# Window setup
WIDTH, HEIGHT = 300, 600
win = pygame.display.set_mode((WIDTH + 150, HEIGHT))
pygame.display.set_caption("Tetris")
ROWS, COLS = 20, 10
CELL_SIZE = 30
BLACK = (0, 0, 0)
GRAY = (50, 50, 50)
WHITE = (255, 255, 255)
colors = [
 (0, 255, 255), (255, 165, 0), (0, 255, 0),
 (255, 0, 0), (0, 0, 255), (128, 0, 128), (255, 255, 0)
]
SHAPES = [
 [[1, 1, 1, 1]],
 [[1, 1], [1, 1]],
 [[0, 1, 0], [1, 1, 1]],
 [[1, 0, 0], [1, 1, 1]],
 [[0, 0, 1], [1, 1, 1]],
 [[1, 1, 0], [0, 1, 1]],
 [[0, 1, 1], [1, 1, 0]]
]
font = pygame.font.SysFont('Arial', 24)
grid = [[0 for _ in range(COLS)] for _ in range(ROWS)]
score = 0
high_score = 0
class Piece:
 def __init__(self):
 self.shape = random.choice(SHAPES)
 self.color = random.choice(colors)
 self.x = COLS // 2 - len(self.shape[0]) // 2
 self.y = 0
 def rotate(self):
 self.shape = [list(row) for row in zip(*self.shape[::-1])]
 if not self.valid():
 self.shape = [list(row) for row in zip(*self.shape)][::-1]
 def valid(self):
 for i, row in enumerate(self.shape):
 for j, cell in enumerate(row):
 if cell:
 x, y = self.x + j, self.y + i
 if x < 0 or x >= COLS or y >= ROWS or (y >= 0 and grid[y][x]):
 return False
 return True
 def draw(self):
 for i, row in enumerate(self.shape):
 for j, cell in enumerate(row):
 if cell:
 pygame.draw.rect(win, self.color, (self.x * CELL_SIZE + j * CELL_SIZE,
 self.y * CELL_SIZE + i * CELL_SIZE,
 CELL_SIZE, CELL_SIZE))
 def move(self, dx, dy):
 self.x += dx
 self.y += dy
 if not self.valid():
 self.x -= dx
 self.y -= dy
 return False
 return True
 def lock(self):
 global score
for i, row in enumerate(self.shape):
 for j, cell in enumerate(row):
 if cell:
 grid[self.y + i][self.x + j] = self.color
 clear_lines()
def draw_grid():
 for y in range(ROWS):
 for x in range(COLS):
 color = grid[y][x] if grid[y][x] else GRAY
 pygame.draw.rect(win, color, (x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE), 0)
 pygame.draw.rect(win, BLACK, (x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE), 1)
def clear_lines():
 global score
 lines = 0
 for i in range(ROWS - 1, -1, -1):
 if all(grid[i]):
 del grid[i]
 grid.insert(0, [0 for _ in range(COLS)])
 lines += 1
 score += lines * 100
def draw_text(text, x, y):
 surface = font.render(text, True, WHITE)
 win.blit(surface, (x, y))
def draw_next_piece(piece):
 draw_text("Next:", WIDTH + 10, 20)
 for i, row in enumerate(piece.shape):
 for j, cell in enumerate(row):
 if cell:
 pygame.draw.rect(win, piece.color, (WIDTH + 10 + j * CELL_SIZE,
 50 + i * CELL_SIZE,
 CELL_SIZE, CELL_SIZE))
def game_loop():
 global score, high_score, grid
 run = True
 clock = pygame.time.Clock()
 fall_time = 0
 fall_speed = 0.5
 current_piece = Piece()
 next_piece = Piece()
 while run:
 fall_time += clock.get_rawtime()
 clock.tick()
 if fall_time / 1000 > fall_speed:
 if not current_piece.move(0, 1):
 current_piece.lock()
 current_piece = next_piece
 next_piece = Piece()
 if not current_piece.valid():
 if score > high_score:
 high_score = score
 return
 fall_time = 0
 for event in pygame.event.get():
 if event.type == pygame.QUIT:
 pygame.quit()
 exit()
 elif event.type == pygame.KEYDOWN:
 if event.key == pygame.K_LEFT:
 current_piece.move(-1, 0)
 elif event.key == pygame.K_RIGHT:
 current_piece.move(1, 0)
 elif event.key == pygame.K_DOWN:
 current_piece.move(0, 1)
 elif event.key == pygame.K_UP:
 current_piece.rotate()
 win.fill(BLACK)
draw_grid()
 current_piece.draw()
 draw_next_piece(next_piece)
 draw_text(f"Score: {score}", WIDTH + 10, 200)
 draw_text(f"High Score: {high_score}", WIDTH + 10, 240)
 pygame.display.update()
def main():
 global score, grid
 while True:
 grid = [[0 for _ in range(COLS)] for _ in range(ROWS)]
 score = 0
 game_loop()
 win.fill(BLACK)
 draw_text("Game Over", WIDTH // 2 - 70, HEIGHT // 2 - 40)
 draw_text(f"Score: {score}", WIDTH // 2 - 60, HEIGHT // 2)
 draw_text("Press R to Restart or Q to Quit", WIDTH // 2 - 130, HEIGHT // 2 + 40)
 pygame.display.update()
 wait = True
 while wait:
 for event in pygame.event.get():
 if event.type == pygame.QUIT:
 pygame.quit()
 exit()
 elif event.type == pygame.KEYDOWN:
 if event.key == pygame.K_r:
 wait = False
 elif event.key == pygame.K_q:
 pygame.quit()
 exit()
if __name__ == "__main__":
 main()