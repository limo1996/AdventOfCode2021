import collections

def ins(m, k, v=1):
  if k in m:
    m[k] += v
  else:
    m[k] = v

with open('input', 'r+') as file:
  lines=file.readlines()

initStr=lines[0].strip()
mapping={}
for line in lines[2:]:
  tmp=line.strip().split(' -> ')
  mapping[tmp[0]]=tmp[1]

pairs={}
for i in range(len(initStr)-1):
  tmp=initStr[i]+initStr[i+1]
  ins(pairs, tmp)

for i in range(40):
  newPairs = {}
  for k in pairs:
    if k in mapping:
      ins(newPairs, k[0]+mapping[k], pairs[k])
      ins(newPairs, mapping[k]+k[1], pairs[k])
    else:
      ins(newPairs, k, pairs[k])
  pairs = newPairs

counts = {}
ins(counts, initStr[0])
ins(counts, initStr[-1])
for k in pairs:
  ins(counts, k[0], pairs[k])
  ins(counts, k[1], pairs[k])

mmax, mmin = 0, 9999999999999999
for k in counts:
  mmax = max(mmax, counts[k])
  mmin = min(mmin, counts[k])

print(int((mmax - mmin)/2))