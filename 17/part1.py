# target area: x=230..283, y=-107..-57
#target_area = ((20, 30), (-10, -5))
target_area = ((230, 283), (-107, -57))

def is_in(x, y):
  return target_area[0][0] <= x and x <= target_area[0][1] and target_area[1][0] <= y and y <= target_area[1][1]

result = 0
for i in range(100):
  for j in range(1000):
    vel_x, vel_y = i, j
    x, y = 0, 0
    max_y = 0
    while y > target_area[1][1] and x <= target_area[0][1]:
      x += vel_x
      y += vel_y
      vel_x = max(0, vel_x-1)
      vel_y -= 1
      max_y = max(max_y, y)
      if is_in(x, y):
        print('Velocity ({0}, {1}) reaches the target at ({2}, {3}) with max height of {4}'.format(i, j, x, y, max_y))
        result = max(result, max_y)

print ('result', result)
