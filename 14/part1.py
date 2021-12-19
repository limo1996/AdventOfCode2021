import collections

with open('input', 'r+') as file:
  lines=file.readlines()

initStr=lines[0].strip()
mapping={}
for line in lines[2:]:
  tmp=line.strip().split(' -> ')
  mapping[tmp[0]]=tmp[1]

for k in range(10):
  newStr=""
  for i in range(len(initStr)-1):
    tmp=initStr[i]+initStr[i+1]
    if tmp in mapping:
      newStr += initStr[i] + mapping[tmp]
    else:
      newStr += initStr[i]
  initStr = newStr+initStr[-1]

counts = collections.Counter(initStr).most_common()
print(counts[0][1] - counts[-1][1])
