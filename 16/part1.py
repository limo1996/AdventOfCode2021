
def parsePacket(packet, i):
  print('parsePacket', i, end=', ')
  version = int(packet[i:i+3], 2)
  type = int(packet[i+3:i+6], 2)
  print('type=', type)
  if type == 4:
    j = i+6
    while packet[j] != '0':
      j+=5
    return (version, j+5)

  if packet[i+6] == '0':
    length = int(packet[i+7:i+22], 2)
    v, n = parsePacket(packet, i+22)
    version += v
    while n < i+22+length:
      v, n = parsePacket(packet, n)
      version += v
    return (version, n)
  else: # packet[i+6] == '1'
    length = int(packet[i+7:i+18], 2)
    v, n = parsePacket(packet, i+18)
    version += v
    for j in range(length-1):
      v, n = parsePacket(packet, n)
      version += v
    return (version, n)

with open('input', 'r') as f:
  binary = f.read().strip()
packet = ""
for c in binary:
  packet += str(bin(int(c, 16)))[2:].zfill(4)

# print(packet)
print(parsePacket(packet, 0)[0])