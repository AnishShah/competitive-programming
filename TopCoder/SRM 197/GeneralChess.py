class GeneralChess:
  def attackPositions(self, pieces):
    ans = []
    steps = [(-2,-1), (-2,1), (-1,-2), (-1,2), (1,-2), (1,2), (2,-1), (2,1)]
    for idx, p in enumerate(pieces):
      x = int(p.split(',')[0])
      y = int(p.split(',')[1])
      attacks = []
      for s in steps:
	temp_x = x + s[0]
	temp_y = y + s[1]
	attacks.append(str(temp_x)+","+str(temp_y))
      if idx == 0:
	ans = attacks
      else:
	ans = list(set(attacks).intersection(set(ans)))
    ans.sort(key=lambda x: [int(y) for y in x.split(',')])
    return tuple(ans)