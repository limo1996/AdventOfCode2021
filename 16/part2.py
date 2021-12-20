from operator import mul
from functools import reduce

def parsePacket(packet, i):
  print('parsePacket', i, end=', ')
  version = int(packet[i:i+3], 2)
  type = int(packet[i+3:i+6], 2)
  print('type=', type)
  if type == 4:
    value, j = '', i+6
    while packet[j] != '0':
      value += packet[j+1:j+5]
      j+=5
    return (int(value + packet[j+1:j+5], 2), j+5)

  values = []
  if packet[i+6] == '0':
    length = int(packet[i+7:i+22], 2)
    v, n = parsePacket(packet, i+22)
    values.append(v)
    while n < i+22+length:
      v, n = parsePacket(packet, n)
      values.append(v)
  else: # packet[i+6] == '1'
    length = int(packet[i+7:i+18], 2)
    v, n = parsePacket(packet, i+18)
    values.append(v)
    for j in range(length-1):
      v, n = parsePacket(packet, n)
      values.append(v)

  if type == 0:
    return (sum(values), n)
  elif type == 1:
    return (reduce(mul, values, 1), n)
  elif type == 2:
    return (min(values), n)
  elif type == 3:
    return (max(values), n)
  elif type == 5:
    return (1 if values[0] > values[1] else 0, n)
  elif type == 6:
    return (1 if values[0] < values[1] else 0, n)
  elif type == 7:
    return (1 if values[0] == values[1] else 0, n)
  assert(False)

with open('input', 'r') as f:
  binary = f.read().strip()
packet = ""
for c in binary:
  packet += str(bin(int(c, 16)))[2:].zfill(4)

# print(packet)
print(parsePacket(packet, 0)[0])